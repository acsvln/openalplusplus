/**
 * OpenAL++ - an object oriented toolkit for spatial sound
 * Copyright (C) 2002 VRlab, Ume� University
 *
 * OpenAL++ was created using the libraries:
 *                 OpenAL (http://www.openal.org), 
 *              PortAudio (http://www.portaudio.com/), and
 *              CommonC++ (http://cplusplus.sourceforge.net/)
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA.
 */

#include "deviceupdater.h"

namespace openalpp {

static int RecordCallback(void *inputbuffer,void *outputbuffer,
			  unsigned long nframes,
			  PaTimestamp outtime, void *object) {
  ((DeviceUpdater *)object)->Enter();
  ((DeviceUpdater *)object)->CopyInput(inputbuffer,nframes);
  ((DeviceUpdater *)object)->Post();
  ((DeviceUpdater *)object)->Leave();
  return 0;
}

ALenum ALFormat(SampleFormat format) {
  switch(format) {
    case(Mono8):
      return AL_FORMAT_MONO8;
    case(Mono16):
      return AL_FORMAT_MONO16;
    case(Stereo8):
      return AL_FORMAT_STEREO8;
    case(Stereo16):
      return AL_FORMAT_STEREO16;
  }
  return 0;
}

DeviceUpdater::DeviceUpdater(int device, unsigned int frequency,unsigned int buffersize,
			     SampleFormat format,
			     ALuint buffer1,ALuint buffer2) 
			     :  StreamUpdater(buffer1,buffer2,ALFormat(format),frequency) {
  PaSampleFormat paformat;
  int nchannels;
  switch(format) {
    case(Mono8):
      format_=AL_FORMAT_MONO8;
      paformat=paInt8;
      nchannels=1;
      bytesperframe_=1;
      break;
    case(Mono16):
      format_=AL_FORMAT_MONO16;
      paformat=paInt16;
      nchannels=1;
      bytesperframe_=2;
      break;
    case(Stereo8):
      format_=AL_FORMAT_STEREO8;
      paformat=paInt8;
      nchannels=2;
      bytesperframe_=2;
      break;
    case(Stereo16):
      format_=AL_FORMAT_STEREO16;
      paformat=paInt16;
      nchannels=2;
      bytesperframe_=4;
      break;
  }

  PaDeviceID devid=paNoDevice;
  if(device<0)
    devid=Pa_GetDefaultInputDeviceID();
  else if(device<Pa_CountDevices()) {
    const PaDeviceInfo *devinfo=Pa_GetDeviceInfo((PaDeviceID)device);
    if(devinfo->maxInputChannels<nchannels)
      throw InitError("Requested number of channels not supported by device");
    devid=(PaDeviceID)device;
  } else
    throw InitError("No such device");
  if(devid==paNoDevice)
    throw InitError("Couldn't open device");  

  maxtmpbufsize_=buffersize;
  tmpbuffer_=new char[buffersize];
  
  PaError err=Pa_OpenStream(&stream_,
			    devid,nchannels,paformat,NULL,
			    paNoDevice,0,paformat,NULL,
			    frequency,buffersize/bytesperframe_,2,paClipOff,
			    RecordCallback,this);
}

DeviceUpdater::~DeviceUpdater() {
  Pa_CloseStream(stream_);
  delete[] tmpbuffer_;
}

void DeviceUpdater::Run() {
  Pa_StartStream(stream_);
  Wait();
  Enter();
  while(!Update(tmpbuffer_,tmpbufsize_)) {
    Leave();
    Wait();
    Enter();
  }
  Leave();
  Pa_StopStream(stream_);
}

void DeviceUpdater::CopyInput(void *tempbuffer,int length) {
  if(!tempbuffer)
    return;
  length*=bytesperframe_;
  if(length>maxtmpbufsize_)
    tmpbufsize_=maxtmpbufsize_;
  else
    tmpbufsize_=length;
  memcpy(tmpbuffer_,tempbuffer,tmpbufsize_);
}

}

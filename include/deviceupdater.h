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

#ifndef DEVICEUPDATER_H_INCLUDED_C419EA9C
#define DEVICEUPDATER_H_INCLUDED_C419EA9C

#include "streamupdater.h"
#include "error.h"
#include <portaudio.h>

namespace openalpp {

/**
 * Updater for sound input devices (like microphones).
 */
class DeviceUpdater : public StreamUpdater, public ost::Semaphore {
  PortAudioStream *stream_;
  ost::Mutex inputmutex;
  char *tmpbuffer_;
  int tmpbufsize_,maxtmpbufsize_;
  int bytesperframe_;
 public:
  /**
   * Constructor.
   * @param device is the number of the device (as PortAudio reports it).
   * TODO: Change this to something non-portaudio dependant.
   * @param frequency is the desired recording frequency.
   * @param buffersize is the desired buffersize.
   * @param format is the format of the sound.
   * @param buffer1 and..
   * @param buffer2 are the (OpenAL) buffers to use.
   */
  DeviceUpdater(int device, unsigned int frequency,unsigned int buffersize,
		SampleFormat format,
		ALuint buffer1,ALuint buffer2);

  /**
   * Destructor.
   */
  ~DeviceUpdater();

  /**
   * Inherited from Thread.
   * This will be called when the updater is Start():ed..
   */
  void Run();

  /**
   * Enter critical section.
   */
  inline void Enter() {inputmutex.enterMutex();}

  /**
   * Leave critical section.
   */
  inline void Leave() {inputmutex.leaveMutex();}

  /**
   * Copy input from callback to temporary buffer.
   * Update will copy the data from the temporary buffer to a sound buffer.
   * @param tempbuffer is a pointer to the buffer
   * @param length is the length - in bytes - of the buffer
   */
  void CopyInput(void *tempbuffer,int length);
};

}

#endif /* DEVICEUPDATER_H_INCLUDED_C419EA9C */

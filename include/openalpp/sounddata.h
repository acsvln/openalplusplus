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

#ifndef SOUNDDATA_H_INCLUDED_C4199A75
#define SOUNDDATA_H_INCLUDED_C4199A75

#include "openalpp/error.h"
#include "openalpp/audiobase.h"

namespace openalpp {

/**
 * Base class for sound data.
 */
class SoundData : public AudioBase {
 protected:
  /**
   * Protected class to handle generation/deletion of OpenAL buffers correctly.
   */
  class SoundBuffer {
    ALuint buffername_;
    int refcount_;
  public:
    SoundBuffer() throw (NameError);
    ~SoundBuffer();
    SoundBuffer *Reference();
    void DeReference() throw (FatalError);
    ALuint GetName() {return buffername_;}
  };
 public:
  /**
   * Get the OpenAL name for the buffer.
   * @return the OpenAL name.
   */
  ALuint GetAlBuffer() const;

  /**
   * Constructor.
   */
  SoundData() throw (NameError,InitError);

  /**
   * Copy constructor.
   */
  SoundData(const SoundData &sounddata);

  /**
   * Destructor.
   */
  ~SoundData();

  /**
   * Assignment operator.
   */
  SoundData &operator=(const SoundData &sounddata);
 protected:
  /**
   * See class SoundBuffer comment.
   */
  SoundBuffer *buffer_;

  /**
   * OpenAL name for the buffer.
   */
  ALuint buffername_;
};

}

#endif /* SOUNDDATA_H_INCLUDED_C4199A75 */
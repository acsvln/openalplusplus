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

#ifndef LISTENER_H_INCLUDED_C419EF1E
#define LISTENER_H_INCLUDED_C419EF1E
#include "openalpp/positionedobject.h"

namespace openalpp {

/**
 * Class for listeners.
 */
class Listener : public PositionedObject {
  float position_[3];
  float orientation_[6];
  float velocity_[3];
  static Listener *selectedlistener_;
  void Init(float x,float y,float z,
	    float vx,float vy,float vz,
	    float directionx, float directiony, float directionz,
	    float upx, float upy, float upz);
 public:
  /**
   * Constructor.
   * Creates the listener at the default position.
   */
  Listener();

  /**
   * Destructor.
   */
  ~Listener();
  
  /**
   * Copy constructor.
   */
  Listener(const Listener &listener);

  /**
   * Constructor.
   * Creates the listener at the specified position and orientation.
   * @param x x coordinate
   * @param y y coordinate
   * @param z z coordinate
   * @param directionx x value of the direction vector
   * @param directiony y value of the direction vector
   * @param directionz z value of the direction vector
   * @param upx x value of the up vector
   * @param upy y value of the up vector
   * @param upz z value of the up vector
   */
  Listener(float x,float y,float z,
	   float directionx,float directiony,float directionz,
	   float upx,float upy,float upz);
  
  /**
   * Constructor.
   * Creates the listener at the specified position.
   * @param x x coordinate
   * @param y y coordinate
   * @param z z coordinate
   */
  Listener(float x, float y, float z);

  /**
   * Select this listener.
   */
  void Select();

  /**
   * Check if this listener is currently selected.
   * @return true if this listener is selected, false otherwise.
   */
  bool IsSelected();

  /**
   * Set the current orientation of this listener.
   * @param directionx x value of the direction vector
   * @param directiony y value of the direction vector
   * @param directionz z value of the direction vector
   * @param upx x value of the up vector
   * @param upy y value of the up vector
   * @param upz z value of the up vector
   */
  void SetOrientation(float directionx,float directiony,float directionz,
		      float upx, float upy, float upz);

  /**
   * Get the current orientation of this listener.
   * @param directionx x value of the direction vector
   * @param directiony y value of the direction vector
   * @param directionz z value of the direction vector
   * @param upx x value of the up vector
   * @param upy y value of the up vector
   * @param upz z value of the up vector
   */
  void GetOrientation(float &directionx,float &directiony,float &directionz, 
		      float &upx, float &upy, float &upz) const;

  /**
   * Assignment operator.
   * @param listener is the object to make a copy of.
   */
  Listener &operator=(const Listener &listener);

  /**
   * Inherited from PositionedObject.
   */
  void SetPosition(float x, float y, float z);

  /**
   * Inherited from PositionedObject.
   */
  void GetPosition(float &x, float &y, float &z) const;

  /**
   * Inherited from PositionedObject.
   */
  void SetVelocity(float vx, float vy, float vz);

  /**
   * Inherited from PositionedObject.
   */
  void GetVelocity(float &vx, float &vy, float &vz) const;
};

}

#endif /* LISTENER_H_INCLUDED_C419EF1E */
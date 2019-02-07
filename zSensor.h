/*

*************************************************************************

ArmageTron -- Just another Tron Lightcycle Game in 3D.
Copyright (C) 2000  Manuel Moos (manuel@moosnet.de)

**************************************************************************

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

***************************************************************************

*/

#include "zZone.h"
#include "eSensor.h"
#include "eNetGameObject.h"
#include "nObserver.h"

class DetectZone;

typedef enum
{
	zSENSOR_TEAM,
	zSENSOR_DEATH,
	zSENSOR_NONE
}

zSensorZoneType;

class zSensor: public eSensor
{
	public:
		//Determine what kind of zone we are scanning.
		zSensorZoneType zoneType;

		 void DetectZone(zZone *Zone, REAL time);

		zSensor(eGameObject *o,const eCoord &start,const eCoord &d):
		//Probably need to create a function and avoid eSensor altogether..
		eSensor(o,start,d),
		zoneType(zSENSOR_NONE){}

		//Not currently used
		nObserverPtr <eNetGameObject> zone;

		eNetGameObject const *GetZone() const
		{
			return zone;
		}	

		//Deconstructor 
		 ~zSensor(){};

};

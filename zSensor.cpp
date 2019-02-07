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

#include "zSensor.h"
//Might need later for identifying zone types.
//#include "gWinZone.h"

class zSensorFinished{};

void zSensor::DetectZone(zZone *Zone, REAL time)
{
	if (!Zone)
	{
		return;
	}

	try
	{
		//Oh well, attempting to use eSensor anyways.
		eSensor::DetectZone(Zone, time);
	}

	catch (zSensorFinished &e)
	{
		zZone *targetZone = dynamic_cast <zZone *> (Zone);

		if (targetZone)
		{
			//Assume deathzone for now.
			zoneType = zSENSOR_DEATH;
		}

		throw;
	}

}
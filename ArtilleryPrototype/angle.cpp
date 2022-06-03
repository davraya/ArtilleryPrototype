//
//  angle.cpp
//  Lab03
//
//  Created by Michael LeFevre on 5/21/22.
//

#include "angle.h"

/******************************************************************************
 * NORMALIZE
 * Wraps a value around the range [0, 2PI)
 ******************************************************************************/
double Angle::normalize(double value)
{
   double normalizedRadianValue = value - (2.0 * PI * floor(value / (2.0 * PI)));
   return normalizedRadianValue;
}

/******************************************************************************
 * ADD
 * Increases the value of angle by specified amount.
 * Calls normaize to keep value within range.
 ******************************************************************************/
void Angle::add(double amount)
{
   double value = getRadians();
   value += amount;
   setRadians(value);
}


/******************************************************************************
 * SET DEGREES
 * Sets the angle to an amount in degrees.
 ******************************************************************************/
void Angle::setDegrees(double degrees)
{
   double radians = convertToRadians(degrees);
   angleRadians = normalize(radians);
}

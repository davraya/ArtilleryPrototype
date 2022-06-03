/***********************************************************************
 * Header File:
 *    Angle: Represents an Angle
 * Author:
 *    Michael LeFevre, David Raya
 * Summary:
 *    An angle
 ************************************************************************/

#pragma once
#include <iostream>
#include <math.h>
using namespace std;

#ifndef PI
#define PI 3.14159
#endif



/******************************************************************************
 * ANGLE
 * This class represents an angle.
 ******************************************************************************/
class Angle
{
public:

   // Setters
   void setDegrees(double degrees);
   void setRadians(double radians) { angleRadians = normalize(radians); }

   // Getters
   float getDegrees() { return convertToDegrees(getRadians()); }
   float getRadians() { return angleRadians; }
   
   void add(double amount);

private:

   double angleRadians;

   // Conversions
   double convertToDegrees(double radians) { return (180.0 * radians) / PI; }
   double convertToRadians(double degrees) { return (degrees * 2.0 * PI) / 360.0; }

   // Wraps a value around the range [0, 2PI)
   double normalize(double value);

};

#include <iostream>  // for CIN and COUT
#include <string>    // for STRING
#include <math.h>    // for SIN, COS, and POW

using namespace std;

#define WEIGHT 15103.00   // Weight in KG
#define GRAVITY -1.625    // Vertical acceleration due to gravity, in m/s^2
#define THRUST 45000.00   // Thrust of main engine, in Newtons (kg m/s^2)
#ifndef PI
#define PI 3.14159        // PI
#endif

/***************************************************
 * COMPUTE DISTANCE
 * Apply inertia to compute a new position using the distance equation.
 * The equation is:
 *     s = s + v t + 1/2 a t^2
 * INPUT
 *     s : original position, in meters
 *     v : velocity, in meters/second
 *     a : acceleration, in meters/second^2
 *     t : time, in seconds
 * OUTPUT
 *     s : new position, in meters
 **************************************************/
float computeDistance(float position, float velocity, float acceleration, float time)
{
   return position + (velocity * time) + (0.5 * acceleration * (time * time));
}

/**************************************************
 * COMPUTE ACCELERATION
 * Find the acceleration given a thrust and mass.
 * This will be done using Newton's second law of motion:
 *     f = m * a
 * INPUT
 *     f : force, in Newtons (kg * m / s^2)
 *     m : mass, in kilograms
 * OUTPUT
 *     a : acceleration, in meters/second^2
 ***************************************************/
float computeAcceleration(float force, float mass)
{
   return force / mass;
}
/***********************************************
 * COMPUTE VELOCITY
 * Starting with a given velocity, find the new
 * velocity once acceleration is applied. This is
 * called the Kinematics equation. The
 * equation is:
 *     v = v + a t
 * INPUT
 *     v : velocity, in meters/second
 *     a : acceleration, in meters/second^2
 *     t : time, in seconds
 * OUTPUT
 *     v : new velocity, in meters/second
 ***********************************************/
float computeVelocity(float velocity, float acceleration, float time)
{
   return velocity + (acceleration * time);
}


/***********************************************
 * COMPUTE VERTICAL COMPONENT
 * Find the vertical component of a velocity or acceleration.
 * The equation is:
 *     cos(a) = y / total
 * This can be expressed graphically:
 *      x
 *    +-----
 *    |   /
 *  y |  / total
 *    |a/
 *    |/
 * INPUT
 *     a : angle, in radians
 *     total : total velocity or acceleration
 * OUTPUT
 *     y : the vertical component of the total
 ***********************************************/
float computeVerticalComponent(float angle, float totalVelocity)
{
   return totalVelocity * cos(angle);
}


/***********************************************
 * COMPUTE HORIZONTAL COMPONENT
 * Find the horizontal component of a velocity or acceleration.
 * The equation is:
 *     sin(a) = x / total
 * This can be expressed graphically:
 *      x
 *    +-----
 *    |   /
 *  y |  / total
 *    |a/
 *    |/
 * INPUT
 *     a : angle, in radians
 *     total : total velocity or acceleration
 * OUTPUT
 *     x : the vertical component of the total
 ***********************************************/
double computeHorizontalComponent(double a, double total)
{
   return sin(a) * total;
}

/************************************************
 * COMPUTE TOTAL COMPONENT
 * Given the horizontal and vertical components of
 * something (velocity or acceleration), determine
 * the total component. To do this, use the Pythagorean Theorem:
 *    x^2 + y^2 = t^2
 * where:
 *      x
 *    +-----
 *    |   /
 *  y |  / total
 *    | /
 *    |/
 * INPUT
 *    x : horizontal component
 *    y : vertical component
 * OUTPUT
 *    total : total component
 ***********************************************/
double computeTotalComponent(double x, double y)
{
   return sqrt((x * x) + (y * y));
}


/*************************************************
 * RADIANS FROM DEGEES
 * Convert degrees to radians:
 *     radians / 2pi = degrees / 360
 * INPUT
 *     d : degrees from 0 to 360
 * OUTPUT
 *     r : radians from 0 to 2pi
 **************************************************/
double radiansFromDegrees(double d)
{
   return (d * 2.0 * PI) / 360.0;
}

double dragFroceEquation(double c, double p, double v, double a)
{
   return 0.5 * c * p * v * v * a;
}

double calculateArea(double r)
{
   return PI * r * r;
}

double angleFromComponent(double x, double y)
{
   return atan2(x, y);
}

double solveRange(double d, double r0, double d0, double r1, double d1) 
{
   return ((r1 - r0) / (d1 - d0) * (d - d0) + r0);
}

double solveDomain(double r, double r0, double d0, double r1, double d1)
{
   return ((d1 - d0) * (r - r0) / (r1 - r0) + d0);
}

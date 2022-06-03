#pragma once

/******************************************************************************
 * ACCELERATION
 * Keeps track of acceleration along the x and y axis.
 ******************************************************************************/
class Acceleration {
private:
   float ddx;
   float ddy;

public:
   Acceleration(): ddx(0.0), ddy(0.0) {}
   Acceleration(float ddx, float ddy) : ddx(ddx), ddy(ddy) {}

   // Getters
   float getDDX() { return ddx; }
   float getDDY() { return ddy; }

   // Setters
   void setDDY(float ddy) { this->ddy = ddy; }
   void setDDX(float ddx) { this->ddx = ddx; }
};

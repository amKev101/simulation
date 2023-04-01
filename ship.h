#ifndef SHIP_H_INCLUDED
#define SHIP_H_INCLUDED

#include "geometry.h"

class Ship {
  Point position;
  Vector forward, up, right;
  double speed;
public:
  Ship(Point initialPosition = Point(0, 0, 0));
  Point getPosition() {return position;}
  void fly() {position += speed * forward;}
  void teleport(Point newPosition) {position = newPosition;}
  Vector getDirection() {return forward;}
  Vector getVertical() {return up;}
  void pitch(double angle);
  void roll(double angle);
  void yaw(double angle);
  double getSpeed() {return speed;}
  void setSpeed(double newSpeed) {speed = newSpeed;}
};

inline Ship::Ship(Point initialPosition):
  position(initialPosition),
  forward(0, 0, -1),
  up(0, 1, 0),
  right(1, 0, 0),
  speed(0.01)
{
}

inline void Ship::pitch(double angle) {
  forward = unit(forward * cos(angle) + up * sin(angle));
  up = right.cross(forward);
}

inline void Ship::roll(double angle) {
  right = unit(right * cos(angle) + up * sin(angle));
  up = right.cross(forward);
}

inline void Ship::yaw(double angle) {
  right = unit(right * cos(angle) + forward * sin(angle));
  forward = up.cross(right);
}


#endif // SHIP_H_INCLUDED

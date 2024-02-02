#include <cmath>
#include <iostream>

#include "Coordinate.h"


Coordinate::Coordinate(unsigned int t_x, unsigned int t_y) {
   x = t_x;
   y = t_y;
}

void Coordinate::print() {
   std::cout<<"("<<x<<","<<y<<")";
}

void Coordinate::print(std::ofstream& out_stream) {
   out_stream<<"("<<x<<","<<y<<")";
}

unsigned int Coordinate::getX() {
   return x;
}

unsigned int Coordinate::getY() {
   return y;
}

unsigned int Coordinate::getDistance(Coordinate* secondPoint) {
//the shortest distance between two points is a straight line
//return the distance between this point and the secondPoint
   int deltaX = static_cast<int>(secondPoint->getX() - static_cast<int>(x));
   int deltaY = static_cast<int>(secondPoint->getY() - static_cast<int>(y));

   unsigned int squaredDistance = static_cast<unsigned int>(deltaX * deltaX + deltaY * deltaY);

   unsigned int distance = static_cast<unsigned int>(std::sqrt(squaredDistance));

   return distance;
}


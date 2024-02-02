#include <iostream>

#include "CoordinateList.h"

CoordinateList::CoordinateList(unsigned int size) {
   
   for (unsigned int i=0; i<size; i++) {
	   allPoints.push_back(new Coordinate((rand() % 100), (rand() % 100)));
      std::cout << i << std::endl;
	}
	center = nullptr;
	
}
	
void CoordinateList::print() {
   for (auto i:allPoints) {
      i->print();
      std::cout<<std::endl;
   }
}
void CoordinateList::print(std::ofstream& out_stream) {
   for (auto i:allPoints) {
      i->print();
      out_stream<<std::endl;
   }
}

void CoordinateList::createCenterPoint() {
//create a new Coordinate that is the center of the 
//points in the vector - (this will be a coordinate where x = average of all xs, and y=average of all ys)
//assign private variable center to this new object
   int sumX = 0;
   int sumY = 0;

   for (const auto& point : allPoints) {
      sumX += point->getX();
      sumY += point->getY();
   }

   unsigned int avgX = sumX / allPoints.size();
   unsigned int avgY = sumY / allPoints.size();

   center = new Coordinate(avgX, avgY);
}

unsigned int CoordinateList::getDistanceFromCenter(unsigned int index) {
   if (center == nullptr) {
      std::cout<<"ERROR getDistanceFromCenter called when center is still nullptr"<<std::endl;
      return -1;
   }
   return allPoints[index]->getDistance(center);
}

unsigned int CoordinateList::findNextClosest(unsigned int start) {
//given start, find the index of the next closest coordinate point to center remaining in the list 
//searching from start to the end of the vector
   unsigned int closestIndex = start;
   unsigned int minDistance = getDistanceFromCenter(start);

   for (unsigned int i = start + 1; i < allPoints.size(); ++i) {
      unsigned int distance = getDistanceFromCenter(i);

      if (distance < minDistance) {
         closestIndex = i;
         minDistance = distance;
      }
   }

   return closestIndex;
}

Coordinate* CoordinateList::getCenter() {
   return center;
}

void CoordinateList::orderListFromCenter() {
//using selection sort algorithm and the functions defined above
//initialize the center variable
//put the closest point to the center in location 0 in the vector
//continue to put the points in order one by one by finding the next closest and swapping with whatever is next
   createCenterPoint();
   for (unsigned int i = 0; i < allPoints.size() - 1; ++i) {
      unsigned int closestIndex = findNextClosest(i);

      std::swap(allPoints[i], allPoints[closestIndex]);
   }
}

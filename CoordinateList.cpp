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
   for (auto i : allPoints) {
      std::cout<<i<<std::endl;
   }
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
   return start;
}

Coordinate* CoordinateList::getCenter() {
   return center;
}

void CoordinateList::orderListFromCenter() {
//using selection sort algorithm and the functions defined above
//initialize the center variable
//put the closest point to the center in location 0 in the vector
//continue to put the points in order one by one by finding the next closest and swapping with whatever is next
 
}

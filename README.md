This week is all about different sorting methods. The purpose of this lab is to put a vector of coordinates in order. The order is specified by the distance from the centroid of the group of points. For purposes of this lab the selection sort is well adapted to solve this problem and will be the algorithm that you must use. You will be given a vector of points in the x,y plane. There is a test bench to verify your code. You will need to implement the following functions. Work through the tests in order, they are designed to gradually build the functionality. You will only have access to the tests in submit mode. In the Coordinate class: unsigned integer Coordinate::getDistance(Coordinate* secondPoint) { //the shortest distance between two points is a straight line //return the distance between this point and the secondPoint }

In CoordinateList Coordinate createCenterPoint() { //create a new Coordinate that is the center of the //points listed in the vector - (this will be a coordinate where x = average of all xs, and y=average of all ys) }

unsigned int findNextClosest(unsigned int start) { //given start, find the index of the next closest coordinate point to center remaining in the list //searching from start to the end of the vector //return the index of the next closest point }

void orderListFromCenter() //using selection sort algorithm and the functions defined above //find the center of mass and store it in the class //put the closest point to the center in location 0 in the vector //continue to put the points in order one by one by finding the next closest and swapping with whatever is next }

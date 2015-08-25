# 3d Vector c++ libary
Made by Jimmy van den Berg in The Netherlands
18 August 2015

c++ library for 3 dimensional vector calculations

## Example

**main.cpp**
```c++
#include <iostream>
#include "Vector3.hpp"

int main(void){
	Vector3 testVector1(1, 2, 3);
	Vector3 testVector2(3, 2, 1);
	std::cout << "testVector1 = " << testVector1 << std::endl
	<< "testVector2 = " << testVector2 << std::endl
	<< "testVector2 + testVector2 = " << testVector1 + testVector2 << std::endl
	<< "testVector2 - testVector2 = " << testVector1 - testVector2 << std::endl
	<< "testVector2 * testVector2 = " << testVector1 * testVector2 << std::endl
	<< "Vector3::dotProduct(testVector1, testVector2) = " << Vector3::dotProduct(testVector1, testVector2) << std::endl
	<< "Vector3::crossProduct(testVector1, testVector2) = " << Vector3::crossProduct(testVector1, testVector2) << std::endl;

	std::cout << "Press enter to exit." << std::endl;
	std::cin.get();
	return 1;
}
```
**output**
```
testVector1 = {1,2,3}
testVector2 = {3,2,1}
testVector2 + testVector2 = {4,4,4}
testVector2 - testVector2 = {-2,0,2}
testVector2 * testVector2 = {3,4,3}
Vector3::dotProduct(testVector1, testVector2) = 10
Vector3::crossProduct(testVector1, testVector2) = {-4,8,-4}
Press enter to exit.
```

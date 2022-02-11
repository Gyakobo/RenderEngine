#ifndef VECT_H
#define VECT_H

#include <iostream>
#include <cmath>
using namespace std;

struct vect{
	vect();
	vect(double x, double y);
	vect(double x, double y, double z);
	vect(double x, double y, double z, double w);

	double x=0.0, y=0.0, z=0.0, w=0.0;
	
	double module();
	double scalerProduct(const vect& a, const vect& b);
	
	vect operator+(const vect& a);
	vect operator+=(const vect& a);

	vect operator-(const vect& a);
	vect operator-=(const vect& a);

	// Added features
	friend std::ostream& operator<<(std::ostream& stream, const vect& other);
	bool operator==(const vect& other); // Doesn't work
};


vect vectorProduct2d(const vect& a, const vect& b);
vect vectorProduct3d(const vect& a, const vect& b);
vect vectorProduct4d(const vect& a, const vect& b);

vect operator*(const double& a, const vect& b);
vect operator*(const vect& b, const double& a);

#endif

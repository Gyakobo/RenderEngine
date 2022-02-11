#include "../headers/vect.h"

vect::vect(){}

vect::vect(double x, double y){
	this->x = x;
	this->y = y;
}

vect::vect(double x, double y, double z){
	this->x = x;
	this->y = y;
	this->z = z;
}


vect::vect(double x, double y, double z, double w){
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

double vect::module(){
	return sqrt(x*x + y*y + z*z + w*w);
}

double vect::scalerProduct(const vect& a, const vect& b){
	return (a.x*b.x + a.y*b.y + a.z*b.z, a.w*b.w);
}

vect vectorProduct2d(const vect& a, const vect& b){
	return vect(0, 0, a.x* b.y - b.x * a.y);
}

vect vectorProduct3d(const vect& a, const vect& b){
	return vect(a.y*b.z-a.z*b.y,  a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x);
}

vect vectorProduct4d(const vect& a, const vect& b){
	return vect(b.z*(a.y-a.w), b.w*(a.z-a.x), b.x*(a.w-a.y), b.y*(a.x-a.z));
}

vect vect::operator+(const vect& a){
	return vect(x + a.x, y + a.y, z + a.z, w + a.w);
}
vect vect::operator+=(const vect& a){
	return vect(x + a.x, y + a.y, z + a.z, w + a.w);
}




vect vect::operator-(const vect& a){
	return vect(x - a.x, y - a.y, z - a.z, w - a.w);
}
vect vect::operator-=(const vect& a){
	return vect(x - a.x, y - a.y, z - a.z, w - a.w);
}



vect operator*(const double& a, const vect& b){
	return vect(b.x * a, b.y * a, b.z * a, b.w * a);
}

vect operator*(const vect& b, const double& a){
	return vect(b.x * a, b.y * a, b.z * a, b.w * a);                                              
}


std::ostream& operator<<(std::ostream& stream, const vect& other) {
	stream << "vector (" << other.x << ", " << other.y << ", " << other.z << ", " << other.w << ")";
	
	return stream;
}


bool vect::operator==(const vect& other) { // Doesn't work properly
	if (x == x && y == y && z == z && w == w) return true;
	else return false;
}












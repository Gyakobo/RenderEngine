#include "../headers/vec3.h"

vec3::vec3() {
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}
vec3::vec3(const float& x, const float& y, const float& z) {
	this->x = x;
	this->y = y;
	this->z = z;
}





vec3& vec3::add(const vec3& other) {
	x += other.x;	
	y += other.y;	
	z += other.z;	

	return *this;
}
vec3& vec3::subtract(const vec3& other) {
	x -= other.x;	
	y -= other.y;	
	z -= other.z;	

	return *this;
}
vec3& vec3::multiply(const vec3& other) {
	x *= other.x;	
	y *= other.y;	
	z *= other.z;	

	return *this;
}
vec3& vec3::divide(const vec3& other) {
	x /= other.x;	
	y /= other.y;	
	z /= other.z;	

	return *this;
}




vec3& operator+(vec3 left, const vec3& right) {
	return left.add(right);
}
vec3& operator-(vec3 left, const vec3& right) {
	return left.subtract(right);
}
vec3& operator*(vec3 left, const vec3& right) {
	return left.multiply(right);
}
vec3& operator/(vec3 left, const vec3& right) {
	return left.divide(right);
}






vec3& vec3::operator+=(const vec3& other) {
	return add(other);
}
vec3& vec3::operator-=(const vec3& other) {
	return subtract(other);
}
vec3& vec3::operator*=(const vec3& other) {
	return divide(other);
}
vec3& vec3::operator/=(const vec3& other) {
	return multiply(other);
}


bool vec3::operator==(const vec3& other) {
	if (x == other.x && y == other.y) return true;
	else false;	
}
bool vec3::operator!=(const vec3& other) {
	return !(*this == other);	
}


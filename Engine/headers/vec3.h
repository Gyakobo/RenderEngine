#ifndef VEC3_H 
#define VEC3_H 

#include <iostream>

using namespace std;

struct vec3 {
	float x, y, z;

	vec3();
	vec3(const float& x, const float& y, const float& z);

	vec3& add(const vec3& other);
	vec3& subtract(const vec3& other);
	vec3& multiply(const vec3& other);
	vec3& divide(const vec3& other);

	friend vec3& operator+(vec3 left, const vec3& right);
	friend vec3& operator-(vec3 left, const vec3& right);
	friend vec3& operator*(vec3 left, const vec3& right);
	friend vec3& operator/(vec3 left, const vec3& right);

	vec3& operator+=(const vec3& other);
	vec3& operator-=(const vec3& other);
	vec3& operator*=(const vec3& other);
	vec3& operator/=(const vec3& other);

	bool operator==(const vec3& other);
	bool operator!=(const vec3& other);

	friend ostream& operator<<(ostream& stream, const vec3& vector)	{
		stream << "vec3: (" << vector.x << ", " << vector.y << ", " << vector.z <<  ")";
		return stream;
	}
};

#endif

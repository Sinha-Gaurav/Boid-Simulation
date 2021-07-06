#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>
#include "myvector.h"


MyVector:: MyVector(float xComp, float yComp)
{
	x = xComp;
	y = yComp;
}

void MyVector::set(float xComp, float yComp)
{
	x = xComp;
	y = yComp;
}

void MyVector::addVector(MyVector v)
{
	x += v.x;
	y += v.y;
}


void MyVector::addScalar(float s)
{
	x += s;
	y += s;
}

void MyVector::subVector(MyVector v)
{
	x -= v.x;
	y -= v.y;
}

MyVector MyVector::subTwoVector(MyVector v, MyVector v2)
{
	MyVector tmp;
	v.x -= v2.x;
	v.y -= v2.y;
	tmp.set(v.x, v.y);
	return tmp;
}

void MyVector::subScalar(float s)
{
	x -= s;
	y -= s;
}

void MyVector::mulScalar(float s)
{
	x *= s;
	y *= s;
}


void MyVector::divScalar(float s)
{
	x /= s;
	y /= s;
}

void MyVector::limit(double max)
{
	double size = magnitude();

	if (size > max) {
		set(x / size, y / size);
	}
}

float MyVector::distance(MyVector v) const
{
	float dx = x - v.x;
	float dy = y - v.y;
	float dist = sqrt(dx*dx + dy*dy);
	return dist;
}

float MyVector::dotProduct(MyVector v) const
{
	float dot = x * v.x + y * v.y;
	return dot;
}

float MyVector::magnitude() const
{
	return sqrt(x*x + y*y);
}

void MyVector::setMagnitude(float x)
{
	normalize();
	mulScalar(x);
}

float MyVector::angleBetween(MyVector v) const
{
	if (x == 0 && y == 0) return 0.0f;
	if (v.x == 0 && v.y == 0) return 0.0f;

	double dot = ((double)x * (double)v.x) + ((double)y * (double)v.y);
	double v1mag = sqrt(x * x + y * y);
	double v2mag = sqrt(v.x * v.x + v.y * v.y);
	double amt = dot / (v1mag * v2mag);
	if (amt <= -1) {
		return M_PI;
	}
	else if (amt >= 1) {
		return 0;
	}
	float tmp = acos(amt);
	return tmp;
}

void MyVector::normalize()
{
	float m = magnitude();

	if (m > 0) {
		set(x / m, y / m);
	}
	else {
		set(x, y);
	}
}

MyVector MyVector::copy(MyVector v)
{
	MyVector copy(v.x, v.y);
	return copy;
}

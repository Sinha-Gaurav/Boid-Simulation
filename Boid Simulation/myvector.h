#include <iostream>
using namespace std;

#ifndef MYVECTOR_H
#define MYVECTOR_H

/**
* A custom vector class. Used for custom vector manipulations.
*/
class MyVector {

public:
	float x;///< x-coordinate of the vector.
	float y;///< y-coordinate of the vector.

	/**
	* Default constructor.
	* Constructs a vector object.
	*/
	MyVector() = default;

	/**
	* Constructor.
	* Constructs a vector object.
	* @param[in] xComp x component of the vector.
	* @param[in] yComp y component of the vector.
	*/
	MyVector(float xComp, float yComp);

	/**
	* Function to set the value of current vector.
	* @param[in] x x component of the vector.
	* @param[in] y y component of the vector.
	* @return void.
	*/
	void set(float x, float y);

	/**
	* Function to add a vector to current vector.
	* @param[in] v a vector.
	* @return void.
	*/
	void addVector(MyVector v);

	/**
	* Function to add a scalar to each component of current vector.
	* @param[in] x a scalar.
	* @return void.
	*/
	void addScalar(float x);

	/**
	* Function to subtract a vector from current vector.
	* @param[in] v a vector.
	* @return void.
	*/
	void subVector(MyVector v);
	/**
	* A static function to subtract two vectors.
	* @param[in] v first vector.
	* @param[in] v2 second vector.
	* @return MyVector object.
	*/
	static MyVector subTwoVector(MyVector v, MyVector v2);
	/**
	* Function to subtract a scalar from each component of current vector.
	* @param[in] x a scalar.
	* @return void.
	*/
	void subScalar(float x);
	/**
	* Function to multiply a scalar to each component of current vector.
	* @param[in] x a scalar.
	* @return void.
	*/
	void mulScalar(float x);
	/**
	* Function to divide each component of current vector by a scalar.
	* @param[in] x a scalar.
	* @return void.
	*/
	void divScalar(float x);

	/**
	* Function to limit the magnitude of current vector.
	* @param[in] max magnitude limit of the vector.
	* @return void.
	*/
	void limit(double max);
	/**
	* Function to compute the distance between a vector and current vector.
	* @param[in] v a vector.
	* @return distance between tips of the vectors.
	*/
	float distance(MyVector v) const;
	/**
	* Function to compute the dot product of the current vector and another vector.
	* @param[in] v a vector.
	* @return value of dot product.
	*/
	float dotProduct(MyVector v) const;
	/**
	* Function to compute the magnitude of current vector.
	* @return magnitude.
	*/
	float magnitude() const;
	/**
	* Function to set the magnitude of current vector.
	* @param[in] x magnitude to set.
	* @return void.
	*/
	void setMagnitude(float x);
	/**
	* Function to compute the angle between current vector and another vector(as defined by the dot product).
	* @param[in] v a vector.
	* @return angle between the two vectors.
	*/
	float angleBetween(MyVector v) const;
	/**
	* Function to normalize the current vector.
	* @return void.
	*/
	void normalize();

	/**
	* A static function to create a copy of a vector.
	* @param[in] v a vector.
	* @return copy of the vector.
	*/
	static MyVector copy(MyVector v);
};

#endif

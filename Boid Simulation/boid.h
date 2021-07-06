#include "myvector.h"
#include <vector>

#ifndef BOID_H
#define BOID_H

/**
* A Boid class. Represents the boid object as described by Reynolds.
*/
class Boid {
public:
	bool isPredator;///< a boolean indicating whether the boid is a predator or a prey.
	MyVector location;///< location of the boid on the 2d viewport.
	MyVector velocity;///< velocity of the boid.
	MyVector acceleration;///< acceleration of the boid.
	float maxSpeed;///< speed limit of the boid.
	float maxForce;///< acceleration(magnitude) limit of the boid.

	/**
	* Constructor.
	* Used to create a boid object.
	* @param[in] x x coordinate of the position.
	* @param[in] y y coordinate of the position.
	*/
	Boid(float x, float y);

	/**
	* Constructor.
	* Used to create a boid object with custom type.
	* @param[in] x x coordinate of the position.
	* @param[in] y y coordinate of the position.
	* @param[in] pred a boolean indicator for predator.
	*/
	Boid(float x, float y, bool pred);

	/**
	* Function used to apply force on a boid.
	* @param[in] force force vector.
	* @return void.
	*/
	void applyForce(MyVector force);

	/**
	* Function to keep the boids away from each other.
	* @param[in] Boids vector of Boid.
	* @return direction to appropriate separation.
	*/ 
	MyVector Separation(vector<Boid> Boids);
	/**
	* Function to keep the boids aligned with each other.
	* @param[in] Boids vector of Boid.
	* @return direction to appropriate alignment.
	*/
	MyVector Alignment(vector<Boid> Boids);
	/**
	* Function to keep the boids close to each other.
	* @param[in] Boids vector of Boid.
	* @return direction to appropriate cohesion.
	*/
	MyVector Cohesion(vector<Boid> Boids);
	/**
	* Function to limit the maxSpeed and find necessary steering force and to normalize vectors.
	* @param[in] v a vector.
	* @return vector representing the steering force.
	*/
	MyVector seek(MyVector v);

	/**
	* Function that calls update(), flock() and borders().
	* @param[in] v vector of Boid.
	* @return void.
	*/
	void run(vector <Boid> v);
	/**
	* Function to apply the 3 rules of cohesion, separation and alignment to the current Boid.
	* @return void.
	*/
	void update();
	/**
	* Function to apply the 3 rules of cohesion, separation and alignment to the current flock.
	* @param[in] v vector of Boid.
	* @return void.
	*/
	void flock(vector <Boid> v);

	/**
	* Checks if boids go out of the window and if so, wraps them around to the other side.
	* @return void.
	*/
	void borders();
	/**
	* Calculates the angle for the velocity of a boid which allows the visual image to rotate in the direction that it is going in.
	* @param[in] v velocity of the boid.
	* @return angle to rotate.
	*/ 
	float getAngle(MyVector v) const;

	float desSep;///< desired separation value.
	float desAli;///< desired alignment value.
	float desCoh;///< desired cohesion value.
	float SepW;///< separation weight.
	float AliW;///< alignment weight.
	float CohW;///< cohesion weight.

	/**
	* Getter function to retreive the desired separation value.
	* @return desired separation value.
	*/
	float getDesSep() const;
	/**
	* Getter function to retreive the desired alignment value.
	* @return desired alignment value.
	*/
	float getDesAli() const;
	/**
	* Getter function to retreive the desired cohesion value.
	* @return desired cohesion value.
	*/
	float getDesCoh() const;
	/**
	* Getter function to retreive the separation weight.
	* @return separation weight.
	*/
	float getSepW() const;
	/**
	* Getter function to retreive the alignment weight.
	* @return alignment weight.
	*/
	float getAliW() const;
	/**
	* Getter function to retreive the cohesion weight.
	* @return cohesion weight.
	*/
	float getCohW() const;
	/**
	* Setter function to set the desired separation value.
	* @param[in] x desired separation value.
	* @return void.
	*/
	void setDesSep(float x);
	/**
	* Setter function to set the desired alignment value.
	* @param[in] x desired alignment value.
	* @return void.
	*/
	void setDesAli(float x);
	/**
	* Setter function to set the desired cohesion value.
	* @param[in] x desired cohesion value.
	* @return void.
	*/
	void setDesCoh(float x);
	/**
	* Setter function to set the separation weight.
	* @param[in] x separation weight.
	* @return void.
	*/
	void setSepW(float x);
	/**
	* Setter function to set the alignment weight.
	* @param[in] x alignment weight.
	* @return void.
	*/
	void setAliW(float x);
	/**
	* Setter function to set the cohesion weight.
	* @param[in] x cohesion weight.
	* @return void.
	*/
	void setCohW(float x);
};

#endif

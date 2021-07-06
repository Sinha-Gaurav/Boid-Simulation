#include <vector>
#include "boid.h"

#ifndef FLOCK_H
#define FLOCK_H

/**
* A Flock class which is a group of boids.
*/
class Flock {
public:
	vector<Boid> flock;///< vector of Boid.

	/**
	* Default constructor.
	*/
	Flock() = default;

	/**
	* Function to get the size of the flock.
	* @return size of the flock.
	*/
	int getSize() const;
	/**
	* Function to get the i-th Boid.
	* @param[in] i index.
	* @return Boid at that index.
	*/
	Boid getBoid(int i);
	
	/**
	* Function to add a boid to the flock.
	* @param[in] b a boid.
	* @return void.
	*/
	void addBoid(Boid b);

	/**
	* Call run method on each boid in the flock within a defined proximity.
	*/
	void flocking();

	/**
	* Function to get the number of preys.
	* @return the number of preys.
	*/
	int preyCount();
	/**
	* Function to get the number of predators.
	* @return the number of predators.
	*/
	int predCount();

	/**
	* Function to increment the desired separation value of each boid in the flock.
	* @return void.
	*/
	void addDesSep();
	/**
	* Function to decrement the desired separation value of each boid in the flock.
	* @return void.
	*/
	void subDesSep();
	/**
	* Function to increment the desired alignment value of each boid in the flock.
	* @return void.
	*/
	void addDesAli();
	/**
	* Function to decrement the desired alignment value of each boid in the flock.
	* @return void.
	*/
	void subDesAli();
	/**
	* Function to increment the desired cohesion value of each boid in the flock.
	* @return void.
	*/
	void addDesCoh();
	/**
	* Function to decrement the desired cohesion value of each boid in the flock.
	* @return void.
	*/
	void subDesCoh();

	/**
	* Function to increment the separation weight of each boid in the flock.
	* @return void.
	*/
	void addSepW();
	/**
	* Function to decrement the separation weight of each boid in the flock.
	* @return void.
	*/
	void subSepW();
	/**
	* Function to increment the alignment weight of each boid in the flock.
	* @return void.
	*/
	void addAliW();
	/**
	* Function to decrement the alignment weight of each boid in the flock.
	* @return void.
	*/
	void subAliW();
	/**
	* Function to increment the cohesion weight of each boid in the flock.
	* @return void.
	*/
	void addCohW();
	/**
	* Function to decrement the cohesion weight of each boid in the flock.
	* @return void.
	*/
	void subCohW();
};

#endif

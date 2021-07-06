#include "flock.h"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

#ifndef SIMULATION_H
#define SIMULATION_H

/**
* Class to handle the instantiation of a flock of boids, the model to compute the next step in the stimulation, and to handle all of the program's interaction with SFML. 
*/ 

class Simulation {
private:
	sf::RenderWindow _window;///< SFML window.
	int _window_width;///< window width.
	int _window_height;///< window height.

	Flock flock;///< flock object.
	float boidsSize;///< size of each boid.
	vector<sf::CircleShape> shapes;///< triangle representing each boid.

	/**
	* The render function handling the render loop.
	* @param[in] text2
	* @param[in] text3
	* @param[in] text4
	* @param[in] text5
	* @param[in] text6
	* @param[in] text7
	* @param[in] text8
	* @param[in] text9
	* @param[in] text10
	* @return void.
	*/
	void render(sf::Text text2, sf::Text text3, sf::Text text4, 
				sf::Text text5, sf::Text text6, sf::Text text7, sf::Text text8, sf::Text text9, sf::Text text10);

	/**
	* Function to add a boid to the flock and also create its shape.
	* @param[in] x x position of the boid.
	* @param[in] y y position of the boid.
	* @param[in] pred a boolean indicator for predator.
	* @param[in] fillColor color for the triangle representing the boid.
	* @return void.
	*/
	void createBoid(float x, float y, bool pred, sf::Color fillColor);

	/**
	* Function the handle the input event loop.
	* @return void.
	*/
	void handleInput();

public:
	/** 
	* Print instructions to console.
	* @return void.
	*/
	static void printInstructions();

	/**
	* Constructor.
	*/
	Simulation();

	/**
	* Function to run the simulation.
	* @return void.
	*/
	void run();
};

#endif

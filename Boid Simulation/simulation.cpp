#include "flock.h"
#include "simulation.h"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

#define BOIDS_NUM 1

Simulation::Simulation()
{
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	this->_window_height = desktop.height;
	this->_window_width = desktop.width;
	this->_window.create(sf::VideoMode(_window_width, _window_height, desktop.bitsPerPixel), "Boids", sf::Style::None);
	printInstructions();
}

void Simulation::run()
{
	for (int i = 0; i < BOIDS_NUM; i++) {
		createBoid(_window_width / 2, _window_height / 2, false, sf::Color::Cyan);
	}

	sf::Font font;
	font.loadFromFile("C:\\Users\\Syed Jamaluddin\\Documents\\project\\boid-simulation\\Boids\\src\\Monaco.ttf");

	sf::Text preyText("#preys: " + to_string(flock.preyCount()), font);
	preyText.setFillColor(sf::Color::Yellow);
	preyText.setCharacterSize(25);
	preyText.setPosition(5, 0);

	sf::Text predText("#predators: " + to_string(flock.predCount()), font);
	predText.setFillColor(sf::Color::Yellow);
	predText.setCharacterSize(25);
	predText.setPosition(5, 27);

	sf::Text boidText("#boids: " + to_string(flock.getSize()), font);
	boidText.setFillColor(sf::Color::Yellow);
	boidText.setCharacterSize(25);
	boidText.setPosition(5, 52);
	
	sf::Text dSepText("distance for separation: " + to_string(flock.getBoid(0).getDesSep()), font);
	dSepText.setFillColor(sf::Color::Yellow);
	dSepText.setCharacterSize(25);
	dSepText.setPosition(5, 102);

	sf::Text dAliText("distance for alignment: " + to_string(flock.getBoid(0).getDesAli()), font);
	dAliText.setFillColor(sf::Color::Yellow);
	dAliText.setCharacterSize(25);
	dAliText.setPosition(5, 127);

	sf::Text dCohText("distance for cohesion: " + to_string(flock.getBoid(0).getDesCoh()), font);
	dCohText.setFillColor(sf::Color::Yellow);
	dCohText.setCharacterSize(25);
	dCohText.setPosition(5, 152);

	sf::Text dSepWText("separation weight: " + to_string(flock.getBoid(0).getSepW()), font);
	dSepWText.setFillColor(sf::Color::Yellow);
	dSepWText.setCharacterSize(25);
	dSepWText.setPosition(5, 202);

	sf::Text dAliWText("alignment weight: " + to_string(flock.getBoid(0).getAliW()), font);
	dAliWText.setFillColor(sf::Color::Yellow);
	dAliWText.setCharacterSize(25);
	dAliWText.setPosition(5, 227);

	sf::Text dCohWText("cohesion weight: " + to_string(flock.getBoid(0).getCohW()), font);
	dCohWText.setFillColor(sf::Color::Yellow);
	dCohWText.setCharacterSize(25);
	dCohWText.setPosition(5, 252);


	while (_window.isOpen()) {
		
		handleInput();
		//fpsText, fps, 
		render(preyText, predText, boidText, 
				dSepText, dAliText, dCohText, dSepWText, dAliWText, dCohWText);
	}
}

void Simulation::handleInput()
{
	sf::Event event;
	while (_window.pollEvent(event)) {

		if ((event.type == sf::Event::Closed) ||
			(event.type == sf::Event::KeyPressed &&
			event.key.code == sf::Keyboard::Escape) ||
			(event.type == sf::Event::KeyPressed &&
			event.key.code == sf::Keyboard::BackSpace) ||
			(event.type == sf::Event::KeyPressed &&
			event.key.code == sf::Keyboard::X))
		{
			_window.close();
		}

		
		if (event.type == sf::Event::KeyPressed &&
			event.key.code == sf::Keyboard::Q)
		{
			flock.addDesSep();
		}

		if (event.type == sf::Event::KeyPressed &&
			event.key.code == sf::Keyboard::A)
		{
			flock.subDesSep();
		}

		if (event.type == sf::Event::KeyPressed &&
			event.key.code == sf::Keyboard::W)
		{
			flock.addDesAli();
		}

		if (event.type == sf::Event::KeyPressed &&
			event.key.code == sf::Keyboard::S)
		{
			flock.subDesAli();
		}

		if (event.type == sf::Event::KeyPressed &&
			event.key.code == sf::Keyboard::E)
		{
			flock.addDesCoh();
		}

		if (event.type == sf::Event::KeyPressed &&
			event.key.code == sf::Keyboard::D)
		{
			flock.subDesCoh();
		}

		if (event.type == sf::Event::KeyPressed &&
			event.key.code == sf::Keyboard::I)
		{
			flock.addSepW();
		}

		if (event.type == sf::Event::KeyPressed &&
			event.key.code == sf::Keyboard::J)
		{
			flock.subSepW();
		}

		if (event.type == sf::Event::KeyPressed &&
			event.key.code == sf::Keyboard::O)
		{
			flock.addAliW();
		}

		if (event.type == sf::Event::KeyPressed &&
			event.key.code == sf::Keyboard::K)
		{
			flock.subAliW();
		}

		if (event.type == sf::Event::KeyPressed &&
			event.key.code == sf::Keyboard::P)
		{
			flock.addCohW();
		}

		if (event.type == sf::Event::KeyPressed &&
			event.key.code == sf::Keyboard::L)
		{
			flock.subCohW();
		}
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		
		sf::Vector2i mouseCoords = sf::Mouse::getPosition(_window);
		createBoid(mouseCoords.x, mouseCoords.y, true, sf::Color::Magenta);
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {

		sf::Vector2i mouseCoords = sf::Mouse::getPosition(_window);
		createBoid(mouseCoords.x, mouseCoords.y, false, sf::Color::Cyan);
	}
}

void Simulation::createBoid(float x, float y, bool pred, sf::Color fillColor)
{
	int size = 20;
	Boid b(x, y, pred);
	sf::CircleShape shape(size, 3);
	shape.setPosition(x, y);
	shape.setFillColor(fillColor);
	

	flock.addBoid(b);
	shapes.push_back(shape);

}


void Simulation::render(sf::Text preyText, sf::Text predText, sf::Text boidText, 
				sf::Text dSepText, sf::Text dAliText, sf::Text dCohText, sf::Text dSepWText, sf::Text dAliWText, sf::Text dCohWText)
{
	_window.clear();

	
	//fpsText.setString("fps: " + to_string(int(fps + 0.5)));
	//_window.draw(fpsText);

	preyText.setString("#preys: " + to_string(flock.preyCount()));
	_window.draw(preyText);

	predText.setString("#predators: " + to_string(flock.predCount()));
	_window.draw(predText);

	boidText.setString("#boids: " + to_string(flock.getSize()));
	_window.draw(boidText);

	dSepText.setString("distance for separation: " + to_string(int(flock.getBoid(0).getDesSep() + 0.5)));
	_window.draw(dSepText);

	dAliText.setString("distance for alignment: " + to_string(int(flock.getBoid(0).getDesAli() + 0.5)));
	_window.draw(dAliText);

	dCohText.setString("distance for cohesion: " + to_string(int(flock.getBoid(0).getDesCoh() + 0.5)));
	_window.draw(dCohText);

	dSepWText.setString("separation weight: " + to_string(flock.getBoid(0).getSepW()));
	_window.draw(dSepWText);

	dAliWText.setString("alignment weight: " + to_string(flock.getBoid(0).getAliW()));
	_window.draw(dAliWText);

	dCohWText.setString("cohesion weight: " + to_string(flock.getBoid(0).getCohW()));
	_window.draw(dCohWText);

	for (int i = 0; i < shapes.size(); i++) {
		_window.draw(shapes[i]);



		shapes[i].setPosition(flock.getBoid(i).location.x, flock.getBoid(i).location.y);

		
		float theta = flock.getBoid(i).getAngle(flock.getBoid(i).velocity);
		shapes[i].setRotation(theta);


		if (shapes[i].getPosition().x > _window_width)
			shapes[i].setPosition(shapes[i].getPosition().x - _window_width, shapes[i].getPosition().y);

		if (shapes[i].getPosition().y > _window_height)
			shapes[i].setPosition(shapes[i].getPosition().x, shapes[i].getPosition().y - _window_height);

		if (shapes[i].getPosition().x < 0)
			shapes[i].setPosition(shapes[i].getPosition().x + _window_width, shapes[i].getPosition().y);

		if (shapes[i].getPosition().y < 0)
			shapes[i].setPosition(shapes[i].getPosition().x, shapes[i].getPosition().y + _window_height);
	}

	
	flock.flocking();

	_window.display();
}

void Simulation::printInstructions()
{
	cout << string(10, '\n');
	cout << "--------------Instructions--------------" << endl;
	cout << "Press 'Q' to increase distance for Separation Value" << endl;
	cout << "Press 'A' to decrease distance for Separation Value" << endl;
	cout << "Press 'W' to increase distance for Alignment Value" << endl;
	cout << "Press 'S' to decrease distance for Alignment Value" << endl;
	cout << "Press 'E' to increase distance for Cohesion Value" << endl;
	cout << "Press 'D' to decrease distance for Cohesion Value" << endl;
	cout << "Press 'I' to increase Separation Weight" << endl;
	cout << "Press 'J' to decrease Separation Weight" << endl;
	cout << "Press 'O' to increase Alignment Weight" << endl;
	cout << "Press 'K' to decrease Alignment Weight" << endl;
	cout << "Press 'P' to increase Cohesion Weight" << endl;
	cout << "Press 'L' to decrease Cohesion Weight" << endl;
	cout << "Left Click to add a predator Boid where you clicked" << endl;
	cout << "Right Click to add a prey Boid where you clicked" << endl;
	cout << "Press 'Esc', 'Backspace', or 'X' to Quit" << endl;
}
#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
#include "Boid.h"
#include "SFML/Window.hpp"

sf::VideoMode desktopTemp = sf::VideoMode::getDesktopMode();
const int window_height = desktopTemp.height;
const int window_width = desktopTemp.width;


Boid::Boid(float x, float y) : isPredator(false)
{
	acceleration = MyVector(0, 0);
	velocity = MyVector(rand() % 3 - 2, rand() % 3 - 2);
	location = MyVector(x, y);
	maxSpeed = 3.5;
	maxForce = 0.5;

	desSep = 20;
	desAli = 70;
	desCoh = 25;
	SepW = 1.5;
	AliW = 1.0;
	CohW = 1.0;
}

Boid::Boid(float x, float y, bool pred)
{
	isPredator = pred;
	if (pred == true) {
		maxSpeed = 5.5;
		maxForce = 1.5;
		velocity = MyVector(rand() % 4 - 1, rand() % 4 - 1);
	}
	else {
		maxSpeed = 3.5;
		maxForce = 0.5;
		velocity = MyVector(rand() % 4 - 2, rand() % 4 - 2);
	}
	acceleration = MyVector(0, 0);
	location = MyVector(x, y);

	desSep = 20;
	desAli = 70;
	desCoh = 25;
	SepW = 1.5;
	AliW = 1.0;
	CohW = 1.0;
}


void Boid::applyForce(MyVector force)
{
	acceleration.addVector(force);
}

MyVector Boid::Separation(vector<Boid> boids)
{
	
	float desiredseparation = desSep;
	MyVector steer(0, 0);
	int count = 0;
	
	for (int i = 0; i < boids.size(); i++) {
		
		float d = location.distance(boids[i].location);
		
		if ((d > 0) && (d < desiredseparation)) {
			MyVector diff(0, 0);
			diff = diff.subTwoVector(location, boids[i].location);
			diff.normalize();
			diff.divScalar(d);      
			steer.addVector(diff);
			count++;
		}
		
		if ((d > 0) && (d < desSep) && isPredator == true
			&& boids[i].isPredator == true) {
			MyVector pred2pred(0, 0);
			pred2pred = pred2pred.subTwoVector(location, boids[i].location);
			pred2pred.normalize();
			pred2pred.divScalar(d);
			steer.addVector(pred2pred);
			count++;
		}
		
		else if ((d > 0) && (d < desiredseparation + 70) && boids[i].isPredator == true) {
			MyVector pred(0, 0);
			pred = pred.subTwoVector(location, boids[i].location);
			pred.mulScalar(900);
			steer.addVector(pred);
			count++;
		}
	}
	
	if (count > 0)
		steer.divScalar(static_cast<float>(count));
	if (steer.magnitude() > 0) {
		
		steer.normalize();
		steer.mulScalar(maxSpeed);
		steer.subVector(velocity);
		steer.limit(maxForce);
	}
	return steer;
}


MyVector Boid::Alignment(vector<Boid> Boids)
{
	float neighbordist = desAli; 

	MyVector sum(0, 0);
	int count = 0;
	for (int i = 0; i < Boids.size(); i++) {
		float d = location.distance(Boids[i].location);

		if ((d > 0) && (d < neighbordist)) {
			sum.addVector(Boids[i].velocity);
			count++;
		}
	}
	
	if (count > 0) {
		sum.divScalar(static_cast<float>(count));
		sum.normalize();            
		sum.mulScalar(maxSpeed);   
		
		MyVector steer;
		steer = steer.subTwoVector(sum, velocity); 
		steer.limit(maxForce);
		return steer;
	}
	else {
		MyVector temp(0, 0);
		return temp;
	}
}


MyVector Boid::Cohesion(vector<Boid> Boids)
{
	float neighbordist = desCoh;
	MyVector sum(0, 0);
	int count = 0;
	for (int i = 0; i < Boids.size(); i++) {
		float d = location.distance(Boids[i].location);

		if (Boids[i].isPredator) neighbordist = 15;

		if ((d > 0) && (d < neighbordist)) {
			sum.addVector(Boids[i].location);
			count++;
		}
	}
	if (count > 0) {
		sum.divScalar(count);
		return seek(sum);
	}
	else {
		MyVector temp(0, 0);
		return temp;
	}
}


MyVector Boid::seek(MyVector v)
{
	MyVector desired;
	desired.subVector(v); 
	
	desired.normalize();
	desired.mulScalar(maxSpeed);
	
	acceleration.subTwoVector(desired, velocity);
	acceleration.limit(maxForce);  
	return acceleration;
}


void Boid::update()
{
	
	acceleration.mulScalar(.35);
	
	velocity.addVector(acceleration);
	
	velocity.limit(maxSpeed);
	location.addVector(velocity);
	
	acceleration.mulScalar(0);
}


void Boid::run(vector <Boid> v)
{
	flock(v);
	update();
	borders();
}


void Boid::flock(vector<Boid> v)
{
	MyVector sep = Separation(v);
	MyVector ali = Alignment(v);
	MyVector coh = Cohesion(v);
	
	sep.mulScalar(SepW);
	ali.mulScalar(AliW); 
	coh.mulScalar(CohW);
	
	applyForce(sep);
	applyForce(ali);
	applyForce(coh);
}


void Boid::borders()
{
	if (location.x < 0)    location.x += window_width;
	if (location.y < 0)    location.y += window_height;
	if (location.x > window_width) location.x -= window_width;
	if (location.y > window_height) location.y -= window_height;
}


float Boid::getAngle(MyVector v) const
{
	
	float angle = static_cast<float>(atan2(v.x, -v.y) * 180 / M_PI);
	return angle;
}

float Boid::getDesSep() const { return desSep; }

float Boid::getDesAli() const { return desAli; }

float Boid::getDesCoh() const { return desCoh; }

float Boid::getSepW() const { return SepW; }

float Boid::getAliW() const { return AliW; }

float Boid::getCohW() const { return CohW; }

void Boid::setDesSep(float x) { desSep += x; }

void Boid::setDesAli(float x) { desAli += x; }

void Boid::setDesCoh(float x) { desCoh += x; }

void Boid::setSepW(float x) { SepW += x; }

void Boid::setAliW(float x) { AliW += x; }

void Boid::setCohW(float x) { CohW += x; }
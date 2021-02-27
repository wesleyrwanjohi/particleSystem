#include "particle.h"

Particle::Particle() {
	//constructor -- initalising values 
	isColl = false;
	isAlive = true;
	life = 30; //lifetime of each particle
	time = 0;
	

	numCount = 0;
	
	radSize = 2; //initial radius size of particle
	sphere.setRadius(radSize);
	velocity = ofVec3f(ofRandom(-2, 2), ofRandom(-2, 2), ofRandom(-2, 2)); //initial velocity

	

	
}

Particle::~Particle() {
	//desctructor
}

void Particle::setPosition(float x, float y, float z) {
	//sets inital position of particles
	sphere.setPosition(x, y, z);
}

void Particle::move() {
	//function which moves particles
	

	sphere.move(velocity); //velocity variable passed into .move function as an ofVec3f
}

void Particle::update(float speedLimit ,float speed, float size) {

	if (isAlive == true) {
		checkCollision(speed, size); //limit set for bouncespeed & size set of boundary

		velocity = velocity.limit(speedLimit); //limits velocity of particles
		move();
		changeMatColor();

		time += 0.018;
		if (time > life) {
			isAlive = false; //when time reaches lifetime the particle is removed
		}

	}
}

void Particle::draw() {

	//if the particle is alive it is drawn
	if (isAlive == true) {
		material.begin();
		sphere.draw();
		material.end();
	}

}

void Particle::checkCollision(float speed, float size) {

	ofVec3f position = sphere.getPosition();
	ofVec3f inverse = ofVec3f(0, 0, 0) - position; //inverse of current position

	//conditional which checks if position on particle is greater than the size of the boundary in all planes
	if (inverse.length() > size) {
		inverse = inverse.normalize()*speed;
		velocity = inverse - velocity;


		isColl = true;
		
	}
	if (isColl == true) {
		sphere.setRadius(sphere.getRadius() + 1.0); //gets current radius and increments by an amount
		numCount += 1; //increments every time particle collides with boundary
		isColl = false; 
	 }
	

}

void Particle::changeMatColor() {

	//color of the particles changed when boundary is hit
	if (numCount == 0) {
		material.setDiffuseColor(ofFloatColor(0.129, 0.498, 0.992));
	}

	if (numCount == 1) {
		material.setDiffuseColor(ofFloatColor(0.223, 0.007, 0.890));
	}

	if (numCount == 2) {
		material.setDiffuseColor(ofFloatColor(0.450, 0.031, 0.749));
	}

	if (numCount == 3) {
		material.setDiffuseColor(ofFloatColor(0.690, 0.125, 0.996));
	}

	if (numCount == 4) {
		material.setDiffuseColor(ofFloatColor(0.749, 0.031, 0.313));
	}

	if (numCount == 5) {
		material.setDiffuseColor(ofFloatColor(0.882, 0.035, 0.094));
	}

	
}





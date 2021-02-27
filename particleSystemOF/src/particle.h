#pragma once
#ifndef PARTICLE_H
#define PARTICLE_H

#include "ofMain.h"

class Particle 
{

public:
	Particle();
	~Particle();

	void setPosition(float x, float y, float z);
	void draw();
	void move();
	void checkCollision(float speed, float size); 
	void changeMatColor();
	void update(float speedLimit, float speed, float size);

	float radSize; 

private:

	//private variables and objects
	ofSpherePrimitive sphere;
	ofVec3f velocity; 
	bool isAlive;
	bool isColl;
	int numCount;
	float life;
	float time;
	ofMaterial material;
	



};
#endif /* particle_h */
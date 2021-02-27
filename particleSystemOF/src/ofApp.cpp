#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){

	ofSetBackgroundColor(0);
	ofEnableNormalizedTexCoords();
	light.setPointLight(); //set point light
	light.setDiffuseColor(ofFloatColor(1.0, 1.0, 1.0)); //white light refected off particles -- user is able to see them clearly
	light.setAmbientColor(ofFloatColor(0.3, 0.3, 0.3)); //greyish shadow of particle
	light.setPosition(ofGetWidth()/2, ofGetHeight()/2, 500);

	box.setPosition(0, 0, 0);
	box.set(400);

	for (int i = 0; i < 200; i++) {
		Particle particles;
		
		parts.push_back(particles); //pushing particle objects into "parts" vector

	}



}

//--------------------------------------------------------------
void ofApp::update(){
	for (int i = 0; i < parts.size(); i++) {
		parts[i].update(2, ofRandom(0, 2), 280); //looping through vector and updating particles
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	ofEnableDepthTest();
	cam.begin(); 
	ofEnableLighting();
	light.enable();

	
	//box.drawWireframe();
	for (int i = 0; i < parts.size(); i++) {
		parts[i].draw(); //looping through vector and drawing particles
	}
	
	light.disable();
	ofDisableLighting();
	cam.end();

	ofDrawBitmapString("Press space to add more particles", 20, 20);

	

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
	// when space key is pressed 5 new particle objects are pushed into parts vector and drawn
	if (key == ' ') {
		for (int i = 0; i < 5; i++) {
			Particle newParts;
			parts.push_back(newParts);
		}
	}

	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

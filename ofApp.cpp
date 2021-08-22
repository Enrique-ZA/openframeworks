// Bezier (Formula)
// The Coding Train / Daniel Shiffman
// https://thecodingtrain.com/CodingChallenges/163-bezier.html
// https://youtu.be/zUgsYaUQNBk

// Basic: https://editor.p5js.org/codingtrain/sketches/Z53a719cQ
// Editor by Simon Tiger: https://editor.p5js.org/codingtrain/sketches/_R7RgtGfA
// bezierVertex: https://editor.p5js.org/codingtrain/sketches/O3_cLiOaw
// Time Table Cardioid with Bezier: https://editor.p5js.org/codingtrain/sketches/kZ8dpklQg
// Quadratic: https://editor.p5js.org/codingtrain/sketches/fJIMDmHcE
// Cubic: https://editor.p5js.org/codingtrain/sketches/S1Pt8lol1
// Bezier with Formula: https://editor.p5js.org/codingtrain/sketches/0XOLNHbvC

// https://github.com/CodingTrain/website/blob/main/CodingChallenges/CC_163_Bezier/bezier-formula/sketch.js
// C++ by https://github.com/Enrique-ZA (openframeworks v0.11.0)

#include "ofApp.h"

struct Particle {
	float x, y, dx, dy;
	Particle() {
		dx = ofRandom(-8, 8);
		dy = ofRandom(-8, 8);
	}
	void update() {
		x += dx;
		y += dy;
		if (x >= ofGetWidth() || x < 0) {
			dx *= -1;
		}
		if (y >= ofGetHeight() || y < 0) {
			dy *= -1;
		}
	}
};

ofVec2f cubic(Particle& p0, Particle& p1, Particle& p2, Particle& p3, float& t) {
	float x =
		pow(1 - t, 3) * p0.x +
		3 * pow(1 - t, 2) * p1.x +
		3 * pow(1 - t, 2) * pow(t, 2) * p2.x +
		pow(t, 3) * p3.x;
	float y =
		pow(1 - t, 3) * p0.y +
		3 * pow(1 - t, 2) * p1.y +
		3 * pow(1 - t, 2) * pow(t, 2) * p2.y +
		pow(t, 3) * p3.x;
	return ofVec2f(x, y);
}

Particle p0, p1, p2, p3;

//--------------------------------------------------------------
void ofApp::setup(){
	p0.x = 0;
	p0.y = ofGetHeight() / 2;
	p1.x = ofGetWidth() / 4;
	p1.y = 0;
	p2.x = (3 * ofGetWidth()) / 4;
	p2.y = ofGetHeight() / 2;
	p3.x = ofGetWidth();
	p3.y = ofGetHeight() / 2;
}

//--------------------------------------------------------------
void ofApp::update(){
	p0.update();
    p1.update();
    p2.update();
    p3.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetBackgroundColor(0);

	float delta = 0.03;

	ofPushStyle();
	ofNoFill();
	for (float t = 0; t <= 1; t += delta) {
		ofSetColor(ofColor::fromHsb(t * 360, 255, 255));
		float r = 2;
		auto v = cubic(p0, p1, p2, p3, t);
		ofEllipse(v.x,v.y,r,r);
	}
	ofPopStyle();

	ofPushStyle();
	ofNoFill();
	ofSetLineWidth(8);
	ofSetColor(255);
	ofDrawCurve(p0.x, p0.y, p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);
	ofPopStyle();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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

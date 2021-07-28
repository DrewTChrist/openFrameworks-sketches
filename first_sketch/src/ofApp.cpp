#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "ofApp.h"

std::vector<ofVec2f> circles;
int numCircles;
float t;

//--------------------------------------------------------------
void ofApp::setup(){	 
	ofBackground(150,150,150);	
    srand(time(NULL));
    t = 0.0;
    numCircles = 10000;
    for(int i = 0; i < numCircles; i++) {
        ofVec2f v;
        circles.push_back(v);
    }
}


//--------------------------------------------------------------
void ofApp::update(){
    t += 0.005;

    for(int i = 0; i < numCircles; i++) {
        circles[i].x = sin(t) * (rand() % ofGetHeight() + 50);
        circles[i].y = cos(t) * (rand() % ofGetWidth() + 50);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
    ofScale(2.0f, 2.0f);
    for(ofVec2f v : circles) {
        ofDrawEllipse(v.x, v.y, 1, 1);
    }
}


//--------------------------------------------------------------
void ofApp::keyPressed  (int key){ 
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

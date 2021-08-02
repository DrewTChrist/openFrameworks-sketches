#include <vector>
#include <time.h>
#include "ofApp.h"

std::vector<std::vector<ofVec2f>> downTriangles;
std::vector<std::vector<ofVec2f>> upTriangles;
float downRot = 0.0;
float upRot = 0.0;
float tLength = 75.0;
int rotateFrameCount = 0;
bool rotateDownTriangles = true;
bool rotateUpTriangles = false;


//--------------------------------------------------------------
void ofApp::setup() {
	ofBackgroundHex(0xe2ae6c);	
    for(int i = 0; i < ofGetHeight() + 50; i += tLength) {
        for(int j = 0; j < ofGetWidth() + 50; j += (tLength * (sqrt(3) / 2))) {
            downTriangles.push_back(downwardTriangleCoordinates(i, j));
        }
    }

    for(int i = -(tLength / 2); i < ofGetHeight() + 50; i += tLength) {
        for(int j = 0; j < ofGetWidth() + 50; j += (tLength * (sqrt(3) / 2))) {
            upTriangles.push_back(upwardTriangleCoordinates(i, j));
        }
    }
}

//--------------------------------------------------------------
void ofApp::update() {
    if (rotateDownTriangles) {
        if(downRot < 360.0) {
            downRot += 1.0;
        } else {
            downRot = 0.0;
            rotateUpTriangles = true;
            rotateDownTriangles = false;
        }
    } else if (rotateUpTriangles) {
        if(upRot < 360.0) {
            upRot += 1.0;
        } else {
            upRot = 0.0;
            rotateUpTriangles = false;
            rotateDownTriangles = true;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofPushStyle();
    ofSetHexColor(0xa37c82);
    for(std::vector<ofVec2f> v : downTriangles) {
        ofPushMatrix();
        ofTranslate(v[0].x + (tLength / 2), v[0].y + ((tLength * (sqrt(3) / 2)) / 2));
        ofRotateZDeg(downRot);
        ofDrawTriangle(-tLength/2, -((tLength * (sqrt(3) / 2)) / 2), tLength/2, -((tLength * (sqrt(3) / 2)) / 2), 0, (tLength * ((sqrt(3) / 2)) / 2));
        ofPopMatrix();
    }
    ofPopStyle();

    ofPushStyle();
    ofSetHexColor(0x6e304b);
    for(std::vector<ofVec2f> v : upTriangles) {
        ofPushMatrix();
        ofTranslate(v[0].x + (tLength / 2), v[0].y + ((tLength * (sqrt(3) / 2)) / 2));
        ofRotateZDeg(upRot);
        ofDrawTriangle(-tLength/2, ((tLength * (sqrt(3) / 2)) / 2), tLength/2, ((tLength * (sqrt(3) / 2)) / 2), 0, -(tLength * ((sqrt(3) / 2)) / 2));
        ofPopMatrix();
    }
    ofPopStyle();
}

std::vector<ofVec2f> ofApp::downwardTriangleCoordinates(float x, float y) {
    std::vector<ofVec2f> v;
    v.push_back(ofVec2f(x, y));
    v.push_back(ofVec2f(x + tLength, y));
    v.push_back(ofVec2f(x + (tLength / 2), y + (tLength * (sqrt(3) / 2))));
    return v;
}

std::vector<ofVec2f> ofApp::upwardTriangleCoordinates(float x, float y) {
    std::vector<ofVec2f> v;
    v.push_back(ofVec2f(x, y));
    v.push_back(ofVec2f(x - tLength, y));
    v.push_back(ofVec2f(x - (tLength / 2), y - (tLength * (sqrt(3) / 2))));
    return v;
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

#include <vector>
#include "ofApp.h"

std::vector<std::vector<ofVec2f>> downTriangles;
std::vector<std::vector<ofVec2f>> upTriangles;
float downRot = 0.0;
float upRot = 0.0;
float tLength = 50.0;

//--------------------------------------------------------------
void ofApp::setup() {
	ofBackground(0xe2ae6c);	
    for(int i = 0; i < ofGetHeight(); i += tLength) {
        for(int j = 0; j < ofGetWidth(); j += (tLength * (sqrt(3) / 2))) {
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
    //downRot += 1.0;
    upRot += 1.0;
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofPushStyle();
    ofSetHexColor(0xa37c82);
    for(int i = 0; i < 1; i++) {
        std::vector<ofVec2f> v = downTriangles[i];
        ofPushMatrix();
        //ofTranslate(v[2].x, v[2].y - ((tLength * (sqrt(3) / 2)) / 2));
        //ofTranslate(ofGetMouseX() - (tLength / 2), ofGetMouseY() - ((tLength * (sqrt(3) / 2)) / 2));
        ofTranslate(v[0].x, v[0].y);
        ofRotateZDeg(downRot);
        //ofDrawTriangle(0, 0, tLength, 0, tLength / 2, tLength * (sqrt(3) / 2));
        ofDrawTriangle(-tLength/2, 0, tLength/2, 0, tLength / 2, tLength * (sqrt(3) / 2));
        ofPopMatrix();
    }
    /*for(std::vector<ofVec2f> v : downTriangles) {
        ofPushMatrix();
        ofRotateZDeg(downRot);
        ofTranslate(v[2].x, v[2].y + ((tLength * (sqrt(3) / 2)) / 2));
        ofDrawTriangle(v[0].x, v[0].y, v[1].x, v[1].y, v[2].x, v[2].y);
        ofPopMatrix();
    }*/
    ofPopStyle();

    ofPushStyle();
    ofSetHexColor(0x6e304b);
    for(std::vector<ofVec2f> v : upTriangles) {
        //ofPushMatrix();
        //ofRotateZDeg(upRot);
        //ofDrawTriangle(v[0].x, v[0].y, v[1].x, v[1].y, v[2].x, v[2].y);
        //ofPopMatrix();
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

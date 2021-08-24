#include "ofApp.h"

float t;
float x_t;
float y_t;
ofPath path;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0);
    x_t = ofRandomf();
    y_t = ofRandomf();
    path.setFilled(false);
    path.setCircleResolution(100);
}

//--------------------------------------------------------------
void ofApp::update(){
    t = ofGetElapsedTimef();
    x_t += 0.0025;
    y_t += 0.0025;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    for(int i = 1; i < 500; i++) {
        float xnoise = ofMap(ofNoise(x_t), 0.0, 1.0, -100, 100);
        float ynoise = ofMap(ofNoise(y_t), 0.0, 1.0, -100, 100);

        // path.setStrokeWidth(sin(i * t));
        path.setStrokeWidth(1);
        // path.arc(ofGetWidth() / 2, ofGetHeight() / 2, (ofGetWidth() / 3) + i * sin(t), (ofGetHeight() / 3) + i * cos(t), 0, 360);
        path.arc(ofGetWidth() / 2, ofGetHeight() / 2, (ofGetWidth() / 3) + i * sin(t * i * 0.005), (ofGetHeight() / 3) + i * cos(t + i * 0.005), 0, 360);
        // path.arc(ofGetWidth() / 2, ofGetHeight() / 2, .5 * i * sin(t * i * 0.005), .5 * i * cos(t + i * 0.005), 0, 360);
        // path.arc(ofGetWidth() / 2, ofGetHeight() / 2, (ofGetWidth() / 10) + (i / 5) * sin(t), (ofGetHeight() / 10) + (i / 5) * cos(t), 0, 360);

        // ofSetColor(sin(t) * 127 + i, 0, sin(t) + 127 * i);
        path.setStrokeColor(ofColor(127 * sin(t * i * 0.01), 
                                    127 * sin(t * i * 0.011), 
                                    127 * sin(t * i * 0.012)));
        path.draw();
        path.clear();
    }
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

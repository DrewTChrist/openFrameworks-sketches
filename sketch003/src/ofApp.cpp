#include "ofApp.h"

void drawShape(float x, float y);

bool depth = false;

//-------------------------------------------------------------- void
void ofApp::setup() { ofSetCircleResolution(100); }

//--------------------------------------------------------------
void ofApp::update() {}

//--------------------------------------------------------------
void ofApp::draw() {
  for (int i = 0; i < ofGetHeight(); i += 25) {
    drawShape(i, 0);
  }
}

void drawShape(float x, float y) {
  float time = ofGetElapsedTimef();
  for (int i = 0; i < 500; i++) {
    ofSetColor(127 + 127 * sin(i * 0.01 + time),
               127 + 127 * sin(i * 0.011 + time),
               127 + 127 * sin(i * 0.012 + time));
    // ofDrawRectRounded(x + (i + 100 * sin(i * 0.02 + time)), y + i,
    //                  20 + 40 * sin(i * 0.005 + time),
    //                  20 + 40 * sin(i * 0.005 + time), 10);

    ofDrawLine(x + 100 * sin(0.01 * (time + x + i)), 0,
               x - 100 * sin(0.01 * (time + x + i)), 500);

    // ofDrawCurve(0, 0, x + 100 * sin(0.01 * (time + x + i)),
    //           x - 100 * sin(0.01 * (time + x + i)), 500, 500, 0, 0);
  }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {}

#include "ofApp.h"

bool save = false;
int numFrames = 1;
int toSave = 500;
ofFbo ssfbo;

//--------------------------------------------------------------
void ofApp::setup() {
  ofSetBackgroundColor(0);
  ofSetCircleResolution(100);
  ssfbo.allocate(3840, 2160);
}

//--------------------------------------------------------------
void ofApp::update() {}

//--------------------------------------------------------------
void ofApp::draw() {
  if (save) {
    ssfbo.begin();
    ofClear(ofColor(0, 0, 0));
  }
  float height = ofGetHeight();
  float width = ofGetWidth();
  float time = ofGetElapsedTimef();
  for (int i = 0; i < 7200; i++) {
    ofSetColor(127 * sin(i * 0.01 + time), 127 * sin(i * 0.011 + time),
               127 * sin(i * 0.012 + time));
    ofDrawCircle(i * sin(time * i * 0.0005), i * cos(time * i * 0.0005),
                 100 * sin(0.1 * i + time) + sin(i / time));
  }
  if (save && numFrames <= toSave) {
    ofPixels pixels;
    ssfbo.readToPixels(pixels);
    ofImage img;
    img.setFromPixels(pixels);
    ofSaveImage(img, ofToString(ofGetFrameNum()) + ".png");
    ssfbo.end();
    ssfbo.draw(0, 0);
    numFrames += 1;
  } else {
    save = false;
  }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
  if (key == 'r') {
    save = true;
  }
}

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

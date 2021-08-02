#include "ofMain.h"
#include "capture.h"


void Capture::captureFrame(string path) {
    //ofImage img;
    //img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
    //img.save(path);
    ofSaveFrame();
}

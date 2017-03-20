#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	ofSetupOpenGL(1800, 1800, OF_FULLSCREEN);			// <-------- setup the GL context
	ofRunApp(new ofApp());
}

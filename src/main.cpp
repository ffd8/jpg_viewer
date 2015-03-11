#include "ofMain.h"
#include "ofApp.h"


//========================================================================
int main( ){
	ofSetupOpenGL(360,800,OF_WINDOW);			// <-------- setup the GL context
    ofSetWindowPosition(0,0);
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}

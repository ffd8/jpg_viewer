#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    imgLoaded = false;
    scale = 1;
    ofSetColor(255, 255, 255);
    feedSize = 400;
    feedRandom = 90;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    if(imgLoaded){
        if((abs(ofGetWidth()-tmpImg.getWidth()*scale) >5 || abs(ofGetHeight()-tmpImg.getHeight()*scale)>5)){
            ofSetWindowShape(tmpImg.getWidth()*scale, tmpImg.getHeight()*scale);
            ofSetWindowPosition(0,0);
        }
        tmpImg.draw(0, 0, tmpImg.getWidth()*scale, tmpImg.getHeight()*scale);
        
        
        if (ofGetFrameNum() % 60 == 0){
            imgLoaded = false;
            tmpImg.loadImage(loadPath);
            imgLoaded = true;
        }
    }else{
        ofDrawBitmapString("jpg_viewer \n teddavis.org 2015 \n\n   for os x 10.10+ glitching \n    drag + drop jpg here \n\n      up/down keys = zoom \n       s = export ..._safe.png \n        d = export ..._%date%.png", 75,25);

        for(int i=0;i<feedSize;i+=1){
            if(ofRandom(100)>feedRandom)
            ofDrawBitmapString("FEED ME A JPG!", ofMap(i, 0, feedSize, -110, ofGetWidth()), ofMap(i, 0, feedSize, 0, ofGetHeight()));
        }
    }
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if(key == OF_KEY_UP){
        scale += .05;
    }
    
    if(key == OF_KEY_DOWN){
        scale -= .05;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

    if(key == 's'){
        //ofSystemSaveDialog(loadTitle, "Save Image As...");
        //string imgExt = ofFilePath(loadPath);
        string savePath = ofFilePath::removeExt(loadPath);
        tmpImg.saveImage(savePath+"_safe.png");
    }else if(key == 'd'){
        string savePath = ofFilePath::removeExt(loadPath);
        string sdate = ofGetTimestampString("%Y%m%d_%H%M%S%i");
        tmpImg.saveImage(savePath+"_"+sdate+".png");
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    if(!imgLoaded){
        feedSize = ofMap(x, 0, ofGetWidth(), 1000, 10, true);
        feedRandom = ofMap(y, 0, ofGetHeight(), 99, 1, true);
    }
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
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

    if(dragInfo.files.size()>0){
        cout<<dragInfo.files[0]<<endl;
        imgLoaded = false;
        tmpImg.loadImage(dragInfo.files[0]);
        loadTitle = ofFilePath::getFileName(dragInfo.files[0]);
        loadPath = dragInfo.files[0];
        imgLoaded = true;
    }

}

#pragma once

//Example of creating Denoising autoencoder. 
//The network is trained to restore noised sine functions of various amplitude and frequency.
//Press Space to generate new test.

#include "ofMain.h"
#include "ofxFANN.h"


class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	void generate_sine(vector<float> &input, vector<float> &output);

	void test();

	ofxFANN fann;

};

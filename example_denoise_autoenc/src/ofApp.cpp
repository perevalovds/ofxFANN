#include "ofApp.h"

//Example of creating Denoising autoencoder. 
//The network is trained to restore noised sine functions of various amplitude and frequency.
//Press Space to generate new test.


//dimensions
int Min = 20;
int Mout = Min;	//in this example input and output dimensions are equal

vector<float> test_input, test_output, predicted_output;


//--------------------------------------------------------------
void ofApp::setup(){
	//prepare train data
	int N = //1000;
		10000; 
	vector<vector<float> > inputs(N);
	vector<vector<float> > outputs(N);

	for (int k = 0; k < N; k++) {
		generate_sine(inputs[k], outputs[k]);
	}

	//setup network
	string hidden_layers = "10";
	fann.setup_fully_connected_network(Min, Mout, hidden_layers);

	ofxFANN_MLP_Train_Param param;
	param.algorithm = FANN::TRAIN_INCREMENTAL;
	//FANN::TRAIN_BATCH;
	param.max_epochs = 100;
	param.epochs_between_reports = 10;
	param.desired_error = 0.001;
	param.momentum = 0.1;

	fann.train(inputs, outputs, param);


	//perform test (press Space to generate other tests)
	test();
}

//--------------------------------------------------------------
void ofApp::generate_sine(vector<float> &input, vector<float> &output) {
	float sine_sample_rate = Min;
	float noise_amp = 0.3;


	float freq_Hz = ofRandom(1, 2);
	float amp = ofRandom(0.2, 1);
	float phase0 = ofRandom(0, 100);


	input.resize(Min);
	output.resize(Mout);
	for (int i = 0; i < Min; i++) {
		float phase = float(i) / sine_sample_rate * freq_Hz + phase0;
		float v = sin(phase * M_TWO_PI) * amp;
		v = ofMap(v, -1, 1, 0, 1);	//output of neural network is in 0..1

		input[i] = v + ofRandom(-noise_amp, noise_amp);
		output[i] = v;
	}
}

//--------------------------------------------------------------
void ofApp::test() {
	generate_sine(test_input, test_output);

	predicted_output = fann.predict(test_input);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	float W = ofGetWidth();
	float H = ofGetHeight();
	ofPushMatrix();
	ofTranslate(0, H / 2);
	ofScale(W / Min, H / 6);

	//green - ground truth
	ofSetColor(0, 128, 0);
	for (int i = 0; i < Min - 1; i++) {
		ofLine(i, test_output[i], i + 1, test_output[i + 1]);
	}
	//red - input
	ofSetColor(255, 0, 0);
	for (int i = 0; i < Min-1; i++) {
		ofLine(i, test_input[i], i + 1, test_input[i + 1]);
	}
	//white - predicted
	ofSetLineWidth(3);
	ofSetColor(255);
	for (int i = 0; i < Min - 1; i++) {
		ofLine(i, predicted_output[i], i + 1, predicted_output[i + 1]);
	}
	ofSetLineWidth(1);

	ofPopMatrix();

	std::ostringstream str;
	str << "Denoising autoencoder" << endl;
	str << "green - original, red - noised, white - restored by eutoencoder" << endl;
	str << "Press Space to generate next test" << endl;
	ofDrawBitmapStringHighlight(str.str(), 20, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == ' ') {
		test();
	}

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

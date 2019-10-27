#pragma once

#include "ofMain.h"

#include "floatfann.h"
#include "fann_cpp.h"

//TODO FANN lacks mini-batch and dropout
//so, emulate mini-batch by multiple runs of batches

struct ofxFANN_MLP_Train_Param {
	//TRAIN_INCREMENTAL learns at each train example
	//TRAIN_BATCH learns by whole batch
	//Mini-batch is currently absent
	int algorithm = FANN::TRAIN_INCREMENTAL;	
					
	float momentum = 0.1f;
	float desired_error = 0.001;

	int max_epochs = 3000;
	int epochs_between_reports = 10;
};


struct ofxFANN {
	/*Create fully connected network
	important: output is 0..1
	hidden_sizes - string of sizes, separated by ' ', for example, "10 3 10",
	*/
	bool setup_fully_connected_network(int input_dim, int output_dim, string hidden_sizes);
	bool setup_fully_connected_network(const vector<int> &layers_sizes);

	bool train(vector<vector<float> > &inputs, vector<vector<float> > &outputs, 
		ofxFANN_MLP_Train_Param &params = ofxFANN_MLP_Train_Param());

	//TODO void train_epoch
	//TODO void train_incremental  //dynamic training  net.train

	vector<float> predict(vector<float> &input);

	int input_dim = 0;
	int output_dim = 0;

	FANN::neural_net net;

};


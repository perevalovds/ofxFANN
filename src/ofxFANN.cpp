#include "ofxFANN.h"

//--------------------------------------------------------------------------------
bool ofxFANN::setup_fully_connected_network(int input_dim, int output_dim, string hidden_sizes) {
	vector<string> items = ofSplitString(hidden_sizes, " ");
	vector<int> sizes;
	sizes.push_back(input_dim);
	for (auto &it : items) {
		sizes.push_back(ofToInt(it));
	}
	sizes.push_back(output_dim);

	return setup_fully_connected_network(sizes);
}

//--------------------------------------------------------------------------------
bool ofxFANN::setup_fully_connected_network(const vector<int> &layers_sizes) {
	if (layers_sizes.size() < 2) {
		return false;
	}
	for (auto &size : layers_sizes) {
		if (size <= 0) {
			return false;
		}
	}

	int n = layers_sizes.size();
	this->input_dim = layers_sizes[0];
	this->output_dim = layers_sizes[n-1];

	//convert type
	vector<unsigned int> sizes(n);
	for (int i = 0; i < n; i++) {
		sizes[i] = layers_sizes[i];
	}
	net.create_standard_array(sizes);

	return true;
}

//--------------------------------------------------------------------------------
bool ofxFANN::train(vector<vector<float> > &inputs, vector<vector<float> > &outputs,
	ofxFANN_MLP_Train_Param &params) {

	if (inputs.empty() || inputs.size() != outputs.size() 
		|| inputs[0].size() != input_dim || outputs[0].size() != output_dim) {
		return false;
	}

	net.set_training_algorithm(FANN::training_algorithm_enum(params.algorithm));
	net.set_learning_momentum(params.momentum);

	FANN::training_data data;
	data.set_train_data(inputs, outputs);
	net.train_on_data(data, params.max_epochs, params.epochs_between_reports, params.desired_error);

	return true;
}

//--------------------------------------------------------------------------------
vector<float> ofxFANN::predict(vector<float> &input) {
	vector<float> result;
	if (input.size() != input_dim) {
		cout << "FANN error, ofxFANN::predict bad input" << endl;
		return result;
	}

	fann_type *calc_out = net.run(&input[0]);	//we shouldn't clear this memory

	result.resize(output_dim);
	for (int i = 0; i < output_dim; i++) {
		result[i] = calc_out[i];
	}
	return result;
}

//--------------------------------------------------------------------------------

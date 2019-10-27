# ofxFANN
ofxFANN is an openFrameworks addon. 
It's wrapper on FANN library for fast CPU working with neural networks in openFrameworks.

FANN library: http://leenissen.dk/fann/wp/ https://github.com/libfann/fann 

# Features
 
* Train multiple-layered netoworks in realtime.

* Run trained networks.

* Currently ofxFANN uses only float FANN computations. Double and fixed variants are currently not supported.

# Examples

* example_denoise_autoenc - example of creating denoising autoencoder. 
The network is trained to restore noised sine functions of various amplitude and frequency.
Press Space to generate new test.

![example_denoise_autoenc](https://raw.githubusercontent.com/perevalovds/ofxFANN/master/docs/images/denoising_autoencoder.png)

# Requirements

openframeworks 0.10.1.

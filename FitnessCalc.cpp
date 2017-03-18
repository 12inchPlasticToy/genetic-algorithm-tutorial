#include "FitnessCalc.h"
#include <memory>

std::vector<char> FitnessCalc::solution{64};

void FitnessCalc::setSolution(std::vector<char> _solution){
	solution = _solution;
}

// To make it easier we can use this method to set our candidate solution 
// with string of 0s and 1s
void FitnessCalc::setSolution(std::string newSolution){
	solution = std::vector<char>(newSolution.size());

	// Loop through each character of our string and save it in our byte 
	// array
	for (auto i = 0; i < newSolution.size(); ++i){
		auto character = newSolution.substr(i, i + 1);
		if (character == "0" || character == "1"){
			solution[i] = *character.c_str();
		}
		else{
			solution[i] = 0;
		}
	}
}

// Calculate inidividuals fittness by comparing it to our candidate solution
int FitnessCalc::getFitness(Individual* individual){
	int fitness = 0;
	// Loop through our individuals genes and compare them to our candidates
	for (int i = 0; i < individual->size() && i < solution.size(); i++){
		if (individual->getGene(i) == solution[i]){
			fitness++;
		}
	}
	return fitness;
}

int FitnessCalc::getMaxFitness(){
	return solution.size();
}

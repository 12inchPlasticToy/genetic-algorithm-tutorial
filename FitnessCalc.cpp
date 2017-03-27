#include "FitnessCalc.h"
#include <memory>
#include <iostream>
#include <string>
#include <iterator>

std::bitset<64> FitnessCalc::solution;


// To make it easier we can use this method to set our candidate solution 
// with string of 0s and 1s
void FitnessCalc::setSolution(std::string newSolution){
//	solution = std::vector<char>(newSolution.size());
//	std::copy(newSolution.begin(), newSolution.end(), std::back_inserter(solution));
	
	// Loop through each character of our string and save it in our byte 
	// array
	int bit{0};
	for(char c : newSolution){
		bit = 0;
		if(c == '1'){
			bit = 1;
		}
		solution <<= 1;
		solution |= bit;
	}
	std::cout << "Solution: " << solution << std::endl;
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

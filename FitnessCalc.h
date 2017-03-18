#pragma once
#include "Individual.h"

class FitnessCalc{
public:
	static std::vector<char> solution;
	
	static void setSolution(std::vector<char> _solution);
	static void setSolution(std::string newSolution);

	static int getFitness(Individual* individual);
	static int getMaxFitness();
};
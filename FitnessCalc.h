#pragma once
#include "Individual.h"
#include <bitset>

class FitnessCalc{
public:
	static std::bitset<64> solution;
	
	static void setSolution(std::string newSolution);

	static int getFitness(Individual* individual);
	static int getMaxFitness();
};

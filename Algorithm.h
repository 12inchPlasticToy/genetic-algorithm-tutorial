#pragma once
#include "Population.h"

class Algorithm{
public:
//	Algorithm();
//	~Algorithm();
	static Population evolvePopulation(Population pop);


private:
	static const double uniformRate;
	static const double mutationRate;
	static const int tournamentSize;
	static const bool elitism;

	static Individual crossover(Individual indiv1, Individual indiv2);
	static void mutate(Individual indiv);
	static Individual tournamentSelection(Population pop);


};


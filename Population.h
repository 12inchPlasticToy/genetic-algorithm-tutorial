#pragma once
#include "Individual.h"
#include <vector>

class Population{
public:
	Population(int populationSize, bool initialise);
	~Population();

	std::vector<Individual> individuals;

	Individual getIndividual(int index) const;
	Individual getFittest() const;
	int size() const;
	void saveIndividual(int index, Individual indiv);
};


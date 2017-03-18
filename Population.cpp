#include "Population.h"


Population::Population(int populationSize, bool initialise){
	individuals.resize(populationSize);
	if (initialise){
		for (int i = 0; i < size(); ++i){
			Individual newIndividual;
			newIndividual.generateIndividual();
			saveIndividual(i, newIndividual);
		}
	}
}

Population::~Population(){}

Individual Population::getIndividual(int index) const{
	return individuals.at(index);
}

Individual Population::getFittest() const{
	auto fittest = individuals[0];
	for (auto indiv: individuals)
		if (fittest.getFitness() <= indiv.getFitness())
			fittest = indiv;

	return fittest;
}

int Population::size() const{
	return individuals.size();
}

void Population::saveIndividual(int index, Individual indiv){
	individuals[index] = indiv;
}

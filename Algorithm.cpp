#include "Algorithm.h"


const double Algorithm::uniformRate = 0.5;
const double Algorithm::mutationRate = 0.015;
const int Algorithm::tournamentSize = 5;
const bool Algorithm::elitism = true;

Population Algorithm::evolvePopulation(Population pop){
	Population newPopulation{pop.size(), false};

	//Keep the best individual
	if (elitism){
		newPopulation.saveIndividual(0, pop.getFittest());
	}

	auto elitismOffset = 0;
	if (elitism){
		elitismOffset = 1;
	}

	// Loop over the population size and create new individuals with
	// crossover
	for (int i = elitismOffset; i < pop.size(); ++i){
		Individual indiv1{tournamentSelection(pop)};
		Individual indiv2{tournamentSelection(pop)};
		Individual newIndiv = crossover(indiv1, indiv2);
		newPopulation.saveIndividual(i, newIndiv);
	}

	// Mutate population
	for (int i = elitismOffset; i < newPopulation.size(); ++i){
		mutate(newPopulation.getIndividual(i));
	}

	return newPopulation;
}

Individual Algorithm::crossover(Individual indiv1, Individual indiv2){
	Individual newSol;
	// Loop through genes
	for (int i = 0; i < indiv1.size(); ++i)
	// Crossover
		if (static_cast<double>(rand()) / RAND_MAX <= uniformRate)
			newSol.setGene(i, indiv1.getGene(i));
		else
			newSol.setGene(i, indiv2.getGene(i));

	return newSol;
}

void Algorithm::mutate(Individual indiv){
	//	loop through genes 
	for (int i = 0; i < indiv.size(); i++)
		if (static_cast<double>(rand()) / RAND_MAX <= mutationRate){
			//		create new gene
			char gene = static_cast<char>(rand() % 2);
			indiv.setGene(i, gene);
		}
}

Individual Algorithm::tournamentSelection(Population pop){
	// create tournament population
	Population tournament{tournamentSize, false};
	// for each place in tournament, get a random individual
	for (int i = 0; i < tournamentSize; ++i){
		int randomId = static_cast<int>(rand() % pop.size());
		tournament.saveIndividual(i, pop.getIndividual(randomId));
	}
	// Get the fittest
	return tournament.getFittest();
}

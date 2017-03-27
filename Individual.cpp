#include <cmath>
#include <random>
#include <iostream>

#include "Individual.h"
#include <ctime>
#include "FitnessCalc.h"
#include <bitset>


Individual::Individual(){
}

Individual::~Individual(){}

void Individual::generateIndividual(){
	for (auto i = 0; i < size(); ++i)
		genes[i] = rand() % 2;
}

void Individual::setDefaultGeneLength(int length){
	defaultGeneLength = length;
}

bool Individual::getGene(int index) const{
	return genes[index];
}

void Individual::setGene(int index, bool value){
	genes[index] = value;
	fitness = 0;
}

int Individual::size() const{
	return genes.size();
}

int Individual::getFitness(){
	if (fitness == 0){
		fitness = FitnessCalc::getFitness(this);
	}
	return fitness;
}

std::ostream& operator <<(std::ostream& os, const Individual& indiv){
	//	std::string geneString{""};
	//	os << "";
		//		geneString += indiv.getGene(i);
	os << indiv.genes;

	return os;
};

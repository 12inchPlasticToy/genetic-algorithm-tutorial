#include <cmath>
#include <random>
#include <iostream>

#include "Individual.h"
#include <ctime>
#include "FitnessCalc.h"
#include <bitset>


Individual::Individual(){
	genes.resize(defaultGeneLength);
}

Individual::~Individual(){}

void Individual::generateIndividual(){
	srand(time(0));
	for (auto i = 0; i < size(); ++i){
		auto gene = static_cast<char>(rand() % 2);
		genes[i] = gene;
	}
}

void Individual::setDefaultGeneLength(int length){
	defaultGeneLength = length;
}

char Individual::getGene(int index) const{
	return genes[index];
}

void Individual::setGene(int index, char value){
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
	os << "";
	for (int i = 0; i < indiv.size(); i++ ){
//		geneString += indiv.getGene(i);
		os << indiv.getGene(i);

	}
	return os;
};


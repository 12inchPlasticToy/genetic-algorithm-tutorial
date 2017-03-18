#include <iostream>
#include "FitnessCalc.h"
#include "Population.h"
#include "Algorithm.h"


int main(int argc, char* argv[]){
	FitnessCalc::setSolution("1111000000000000000000000000000000000000000000000000000000001111");
	Population myPop{50, true};

	int generationCount = 0;

	while (myPop.getFittest().getFitness() < FitnessCalc::getMaxFitness()){
		generationCount++;
		std::cout << 
			"Generation: "<< generationCount << 
			" Fittest: " << myPop.getFittest().getFitness() << 
			std::endl;
		myPop = Algorithm::evolvePopulation(myPop);
	}

	std::cout << "Solution found!" << std::endl;
	std::cout << "Generation: " << generationCount << std::endl;
	std::cout << "Genes: " << myPop.getFittest() << std::endl;


}

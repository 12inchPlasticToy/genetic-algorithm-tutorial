#include <iostream>
#include "FitnessCalc.h"
#include "Population.h"
#include "Algorithm.h"
#include <ctime>
#include <array>
#include <string>


int main(int argc, char* argv[]){
	srand(time(0));
	
	FitnessCalc::setSolution("1111000000000000000000000000000000000000000000000000000000001111");
	Population myPop{100, true};
	std::cout << "#################\n#################" << std::endl;

	int generationCount = 0;

	while (generationCount <= 500 && myPop.getFittest().getFitness() < FitnessCalc::getMaxFitness()){
		generationCount++;
		std::cout <<
				"Generation: " << generationCount << std::endl <<
				" Fittest: " << myPop.getFittest() << std::endl <<
				" Fitness: " << myPop.getFittest().getFitness() <<
				std::endl;
		myPop = Algorithm::evolvePopulation(myPop);
	}

	std::cout << "Solution found!" << std::endl;
	std::cout << "Generation: " << generationCount << std::endl;
	std::cout << "Genes: " << myPop.getFittest() << std::endl;
	std::cout << std::endl;	

	system("Pause");
}

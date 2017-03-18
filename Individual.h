#pragma once
#include <vector>
#include <ostream>

class Individual{

public:
	int defaultGeneLength{64};
	Individual();
	~Individual();

	void generateIndividual();
	void setDefaultGeneLength(int length);
	char getGene(int index) const;
	void setGene(int index, char value);
	int size() const;
	int getFitness();

	friend std::ostream& operator <<(std::ostream& os, const Individual& indiv);
	
private:
	std::vector<char> genes;
	int fitness{0};
};


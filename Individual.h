#pragma once
#include <ostream>
#include <bitset>

class Individual{

public:
	int defaultGeneLength{64};
	Individual();
	~Individual();

	void generateIndividual();
	void setDefaultGeneLength(int length);
	bool getGene(int index) const;
	void setGene(int index, bool value);
	int size() const;
	int getFitness();

	friend std::ostream& operator <<(std::ostream& os, const Individual& indiv);
	
private:
	std::bitset<64> genes;
	int fitness{0};
};


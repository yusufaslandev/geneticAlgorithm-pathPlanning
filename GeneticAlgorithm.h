#include <list>
#include<iostream>
#include "myRobot.h"
#include<time.h>
#include<string>


#pragma once
using namespace std;
class GeneticAlgorithm
{
private:
	list<list<int>> pathPopulation;
    //list<list<string>> truePaths;
    list<string> truePaths;
	bool** myGrid;
	int generationNumber = 0;
	int popsize = 100;
	int pathlength = 30;
	double fitnessValue = 0;
    string stringTruePath;
public:
	GeneticAlgorithm(list<list<int>> _pathPopulation, bool** _myGrid);
	~GeneticAlgorithm();
	void copyOperation();
	void crossoverMutationOperation();
	void fitnessCalculate();
	void applyGeneticAlgorithm();
	void printMatrix2D(bool** myGrid);

    string getStringTruePath();
};


#include "GeneticAlgorithm.h"



GeneticAlgorithm::GeneticAlgorithm(list<list<int>> _pathPopulation, bool** _myGrid)
{
	pathPopulation = _pathPopulation;
	myGrid = _myGrid;
	//printMatrix2D(myGrid);
}


GeneticAlgorithm::~GeneticAlgorithm()
{
}

void GeneticAlgorithm::copyOperation()
{
	myRobot robot;
	list<list<int>> newPathPopulation;
	for (auto v0 : pathPopulation)
	{
		if (fitnessValue <= robot.calculateFitnessValueOfPath(myGrid, v0))
			newPathPopulation.push_back(v0);
	}
	/*myRobot robot;
    std::list<list<int>>::iterator it = pathPopulation.begin();

	for (auto v0 : pathPopulation)
	{
		if (fitnessValue > robot.calculateFitnessValueOfPath(myGrid, v0))
			pathPopulation.erase(it);
		else
			it++;
	}*/

	/*for (int i=0; i<pathPopulation.size(); i++)
	{
		pathPopulation.pop_back();
		
	}
	for (int i = 0; i < newPathPopulation.size(); i++)
	{
		pathPopulation.push_front(newPathPopulation.front());
		newPathPopulation.pop_front();
	}
	cout <<endl<< pathPopulation.size();*/

	pathPopulation = newPathPopulation;
	
}

void GeneticAlgorithm::crossoverMutationOperation()
{
	/*auto it1 = std::next(listOfStrs.begin(), 2);	LIST'TE INDEX ICIN BU YAPIYI KULLANDIM
	std::cout << "3rd element = " << *it1 << std::endl;*/


	list<int> parent1, parent2, child;
	int ppSize = pathPopulation.size();
	int pN1, pN2;


    pN1 = rand() % ppSize;
    pN2 = rand() % ppSize;



    auto it1 = std::next(pathPopulation.begin(), pN1);
	parent1 = *it1;
    auto it2 = std::next(pathPopulation.begin(), pN2);
    parent2 = *it1;
    int pSize = parent1.size();
//srand((unsigned)time(0));



    for (int i = 0; i < pSize; i++)
    {
        int p = rand() % 1000;
		
        if (p < 445)
		{
			auto it3 = std::next(parent1.begin(), i);
			int cromozom = *it3;
			child.push_back(cromozom);
		}
        else if (p <900)
		{
            auto it3 = std::next(parent2.begin(), i);
			int cromozom = *it3;
			child.push_back(cromozom);
		}
		else
		{
			int mutatedGene = (rand() % 8) + 1;
			child.push_back(mutatedGene);
		}
	}


	pathPopulation.push_back(child);
}

void GeneticAlgorithm::fitnessCalculate()
{
	myRobot robot;
	for (auto v0 : pathPopulation)
	{
		if (fitnessValue < robot.calculateFitnessValueOfPath(myGrid, v0))
			fitnessValue = robot.calculateFitnessValueOfPath(myGrid, v0);
		cout <<endl<< robot.calculateFitnessValueOfPath(myGrid, v0) << "++" << fitnessValue << endl;
	}
}

void GeneticAlgorithm::applyGeneticAlgorithm()
{
	bool pathFound = false;
	myRobot robot;
    while (/*pathFound == false*/generationNumber<=1000)
	{
		fitnessCalculate();
		copyOperation();

		while (pathPopulation.size()<popsize)
		{
			crossoverMutationOperation();
		}
		cout << endl << "Generatiion number: " << generationNumber << endl;
		for (auto v0 : pathPopulation)
		{
			if (robot.tryThePath(myGrid, v0) == true)
			{
				pathFound = true;
                stringTruePath=robot.calculateTruePath(myGrid, v0);
                truePaths.push_back(stringTruePath);


			}

			cout << "Path: ";
			for (auto v1 : v0)
			cout << v1 << " ";
			cout << endl;	
		}
		generationNumber++;
	}
    std::list<string>::iterator it = truePaths.begin();
    stringTruePath = *it;
    for (auto v0 : truePaths)
    {
        if(stringTruePath.size()>it->size())
            stringTruePath=v0;
        it++;
    }

}

void GeneticAlgorithm::printMatrix2D(bool ** myGrid)
{
	cout << "10x10 Grid: " << endl;
	for (int j = 9; j >= 0; j--)
	{
		for (int i = 0; i < 10; i++)
			printf("(%d,%d)%d  ", i, j, myGrid[i][j]);
		printf("\n");
    }
}

string GeneticAlgorithm::getStringTruePath()
{
    return stringTruePath;
}


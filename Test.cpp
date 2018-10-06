#include "myRobot.h"
#include "GeneticAlgorithm.h"
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <list>

using namespace std;

bool** createGrid(int numberOfObstacles, int startState[2], int goalState[2]);
list<int> createInitialPopulation(int startPosition[2], int goalPosition[2]);
//list<int> createInitialPopulation2(int startPosition[2], int goalPosition[2]);
void printMatrix2D(bool** myGrid);
void printPath(list<int> path);
string gridToString(bool **myGrid);
int main()
{
    int startPosition[2] = { 0,0 };
    int goalPosition[2] = { 9,9 };
    list<list<int>> pathPopulation;
    myRobot robot;
    bool** myGrid = createGrid(25, startPosition, goalPosition);

//burada engeller aktar?lacak
//buradaki silinecek
    //*burada engel g?nderme yap?lm?st?
    //return 0;






    list<int> initialPath = createInitialPopulation(startPosition, goalPosition);
    //list<int> initialPath2 = createInitialPopulation2(startPosition, goalPosition);
    pathPopulation.push_front(initialPath);
    //pathPopulation.push_front(initialPath2);
    GeneticAlgorithm GA(pathPopulation, myGrid);
    printMatrix2D(myGrid);
    printPath(initialPath);
    cout<<"Is the path convinent: "<<robot.tryThePath(myGrid, initialPath)<<endl;
    GA.applyGeneticAlgorithm();

    //?nce engel yollanacak ard?ndan tru path yollanacak

    string pathTrue=GA.getStringTruePath();
    cout<<"TRU"<<pathTrue;

    //son her?eyi buraya ekle



    string obt=gridToString(myGrid);
    //string path1=" 001122";
    string filename = "/home/gksl/Desktop/grid1.py ";
    //filename.append(path1);
    string command = "python3 ";
    command += filename;
    command +=obt;
    command +=" ";
    command +=pathTrue;
    cout<<"----"<<command;
    FILE* in = popen(command.c_str(), "r");
    pclose(in);










    /*for (auto v : pathPopulation)
        printPath(v);*/
    //system("pause");
    return 0;
}
//10'a 10'luk gridimizn engellerinin bulundugu noktalari belirleyen fonksiyon
bool** createGrid(int numberOfObstacles, int startState[2], int goalState[2])
{
    int i, j, index1, index2;
    bool** myGrid;
    myGrid = new bool*[10];

    for ( i = 0; i < 10; i++)
    {
        myGrid[i] = new bool[10];
        for(int j= 0; j < 10; j++)
            myGrid[i][j] = false;
    }

    int k=0;
    srand(time(NULL));

    for (int i = 0; i < numberOfObstacles; i++)
    {
        k++;
        j = rand() % 100;
        index1 = j / 10;
        index2 = j % 10;
        if (myGrid[index1][index2] != true && ((index1 != startState[0] || index2 != startState[1]) && (index1 != goalState[0] || index2 != goalState[1])))
        {
            myGrid[index1][index2] = true;//TRUE:obstacle FALSE:space
        }
        else
            i--;
    }

    return myGrid;
}

//populasyonun 1. path'ini olu?turan fonksiyon
list<int> createInitialPopulation(int startPosition[2],int goalPosition[2])
{
    list<int> path;
    /*int horizontalDistance, verticalDistance;
    horizontalDistance = goalPosition[0] - startPosition[0];
    verticalDistance = goalPosition[1] - startPosition[1];
    while (horizontalDistance > 0 && verticalDistance > 0)
    {
        path.push_back(1);
        horizontalDistance--;
        verticalDistance--;
    }
    while (horizontalDistance < 0 && verticalDistance > 0)
    {
        path.push_back(8);
        horizontalDistance++;
        verticalDistance--;
    }
    while (horizontalDistance > 0 && verticalDistance < 0)
    {
        path.push_back(4);
        horizontalDistance--;
        verticalDistance++;
    }
    while (horizontalDistance < 0 && verticalDistance < 0)
    {
        path.push_back(6);
        horizontalDistance++;
        verticalDistance++;
    }
    while (horizontalDistance > 0)
    {
        path.push_back(3);
        horizontalDistance--;
    }
    while (horizontalDistance < 0)
    {
        path.push_back(7);
        horizontalDistance++;
    }
    while (verticalDistance > 0)
    {
        path.push_back(2);
        verticalDistance--;
    }
    while (verticalDistance < 0)
    {
        path.push_back(5);
        verticalDistance++;
    }*/


    //srand(time(NULL));

    //for (int i = 0; i < 30; i++)
    //{

    //	path.push_back((rand()%8+1));
    //	//path.push_back(1);
    //}
srand(time(NULL));
    for (int i = 0; i < 30; i++)
    {

        //path.push_back((rand()%8+1));
        path.push_back(1);
    }


    return path;
}





void printMatrix2D(bool** myGrid)
{
    cout << "10x10 Grid: " << endl;
    for (int j = 9; j >= 0; j--)
    {

        for (int i = 0; i < 10; i++)
            printf("(%d,%d)%d  ", i, j, myGrid[i][j]);
        printf("\n");
    }
}

void printPath(list<int> path)
{
    cout << "Initial Path: ";
    for (auto v : path)
        cout << v << " ";
    cout << endl;
}
string gridToString(bool** myGrid)
{
    int i, j;
    string obstacles;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (myGrid[i][j])
            {
                obstacles.append(to_string(i));
                obstacles.append(to_string(j));
            }
        }
    }
    return obstacles;
}

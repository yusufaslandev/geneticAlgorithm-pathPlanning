#include <list>
#include<iostream>
#include<math.h>


#pragma once
using namespace std;
class myRobot
{
private:
	//Robotun o anki bulunduðu noktalarý belirtmek için:
	int coordinateX;
	int coordinateY;
public:
	myRobot();
	~myRobot();

	// X1, X2, X3, X4, X5, X6, X7, X8 robotun 1 adýmda gidebileceði 8 adet yönü belirtir.
	void movX1();//kuzeydoðu
	void movX2();//kuzey
	void movX3();//doðu
	void movX4();//güneydoðu
	void movX5();//güney
	void movX6();//güneybatý
	void movX7();//batý
	void movX8();//kuzeybatý

				 //Getters and Setters
	int getCoordinateX();
	void setCoordinateX(int _coordinateY);
	int getCoordinateY();
	void setCoordinateY(int _coordinateY);

	bool tryThePath(bool** myGrid,list<int> path);
	double calculateFitnessValueOfPath(bool** myGrid, list<int> path);

	void printMatrix2D(bool** myGrid);
    string calculateTruePath(bool** myGrid, list<int> path);

};

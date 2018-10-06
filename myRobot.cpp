#include "myRobot.h"


myRobot::myRobot()
{
}


myRobot::~myRobot()
{
}

void myRobot::movX1()
{
	coordinateX++;
	coordinateY++;
}

void myRobot::movX2()
{
	coordinateY++;
}

void myRobot::movX3()
{
	coordinateX++;
}

void myRobot::movX4()
{
	coordinateX++;
	coordinateY--;
}

void myRobot::movX5()
{
	coordinateY--;
}

void myRobot::movX6()
{
	coordinateX--;
	coordinateY--;
}

void myRobot::movX7()
{
	coordinateX--;
}

void myRobot::movX8()
{
	coordinateX--;
	coordinateY++;
}

int myRobot::getCoordinateX()
{
	return coordinateX;
}

void myRobot::setCoordinateX(int _coordinateX)
{
	coordinateX = _coordinateX;
}

int myRobot::getCoordinateY()
{
	return coordinateY;
}

void myRobot::setCoordinateY(int _coordinateY)
{
	coordinateY = _coordinateY;
}

bool myRobot::tryThePath(bool** myGrid,list<int> path)
{
	bool isWayConvenient = true;
	bool pathFound = false;
	setCoordinateX(0);
	setCoordinateY(0);
	for (auto v : path)
	{
		switch (v)
		{
		case 1:
		{
			//cout<<v<<" ";
			//printMatrix2D(myGrid);
			movX1();
			//cout <<"coordinate("<<coordinateX<<","<<coordinateY<<")"<< myGrid[coordinateX][coordinateY];
			if (coordinateX < 0 || coordinateX > 9 || coordinateY < 0 || coordinateY > 9 || myGrid[coordinateX][coordinateY] == true || (myGrid[coordinateX-1][coordinateY] == true && myGrid[coordinateX][coordinateY-1] == true))
				isWayConvenient = false;
			if (coordinateX == 9 && coordinateY == 9)
				pathFound = true;
		}
			
			break;
		case 2:
		{
			movX2();
			if (coordinateX < 0 || coordinateX > 9 || coordinateY < 0 || coordinateY > 9 || myGrid[coordinateX][coordinateY] == true)
				isWayConvenient = false;
			if (coordinateX == 9 && coordinateY == 9)
				pathFound = true;
		}
			break;
		case 3:
		{
			movX3();
			if (coordinateX < 0 || coordinateX > 9 || coordinateY < 0 || coordinateY > 9 || myGrid[coordinateX][coordinateY] == true)
				isWayConvenient = false;
			if (coordinateX == 9 && coordinateY == 9)
				pathFound = true;
		}
			break;
		case 4:
		{
			movX4();
			if (coordinateX < 0 || coordinateX > 9 || coordinateY < 0 || coordinateY > 9 || myGrid[coordinateX][coordinateY] == true || (myGrid[coordinateX - 1][coordinateY] == true && myGrid[coordinateX][coordinateY + 1] == true))
				isWayConvenient = false;
			if (coordinateX == 9 && coordinateY == 9)
				pathFound = true;
		}
			break;
		case 5:
		{
			movX5();
			if (coordinateX < 0 || coordinateX > 9 || coordinateY < 0 || coordinateY > 9 || myGrid[coordinateX][coordinateY] == true)
				isWayConvenient = false;
			if (coordinateX == 9 && coordinateY == 9)
				pathFound = true;
		}
			break;
		case 6:
		{
			movX6();
			if (coordinateX < 0 || coordinateX > 9 || coordinateY < 0 || coordinateY > 9 || myGrid[coordinateX][coordinateY] == true || (myGrid[coordinateX + 1][coordinateY] == true && myGrid[coordinateX][coordinateY + 1] == true))
				isWayConvenient = false;
			if (coordinateX == 9 && coordinateY == 9)
				pathFound = true;
		}
			break;
		case 7:
		{
			movX7();
			if (coordinateX < 0 || coordinateX > 9 || coordinateY < 0 || coordinateY > 9 || myGrid[coordinateX][coordinateY] == true)
				isWayConvenient = false;
			if (coordinateX == 9 && coordinateY == 9)
				pathFound = true;
		}
			break;
		case 8:
		{
			movX8();
			if (coordinateX < 0 || coordinateX > 9 || coordinateY < 0 || coordinateY > 9 || myGrid[coordinateX][coordinateY] == true || (myGrid[coordinateX + 1][coordinateY] == true && myGrid[coordinateX][coordinateY - 1] == true))
				isWayConvenient = false;
			if (coordinateX == 9 && coordinateY == 9)
				pathFound = true;
		}
			break;
		default:
			break;
		}
		if (isWayConvenient == false)
			break;
	}
	if (pathFound == true)
	{
		cout << "Path Found: True" << endl;
		
	}
	return pathFound;
	//return isWayConvenient;
}

double myRobot::calculateFitnessValueOfPath(bool ** myGrid, list<int> path)
{
	bool isWayConvenient = true;
	int fitnessV1 = 0;
	double fitnessV2 = 0;
	setCoordinateX(0);
	setCoordinateY(0);
	double fitnessValue;
	for (auto v : path)
	{
		switch (v)
		{
		case 1:
		{
			movX1();
			cout << v;
			if (coordinateX >= 0 && coordinateX <= 9 && coordinateY >= 0 && coordinateY <= 9 && myGrid[coordinateX][coordinateY] == false && (myGrid[coordinateX - 1][coordinateY] == false || myGrid[coordinateX][coordinateY - 1] == false))
				fitnessV1++;
			else
				isWayConvenient = false;
		}
			break;
		case 2:
		{
			movX2();
			if (coordinateX >= 0 && coordinateX <= 9 && coordinateY >= 0 && coordinateY <= 9 && myGrid[coordinateX][coordinateY] == false)
				fitnessV1++;
			else
				isWayConvenient = false;
		}
			break;
		case 3:
		{
			movX3();
			if (coordinateX >= 0 && coordinateX <= 9 && coordinateY >= 0 && coordinateY <= 9 && myGrid[coordinateX][coordinateY] == false)
				fitnessV1++;
			else
				isWayConvenient = false;
		}
			break;
		case 4:
		{
			movX4();
			if (coordinateX >= 0 && coordinateX <= 9 && coordinateY >= 0 && coordinateY <= 9 && myGrid[coordinateX][coordinateY] == false && (myGrid[coordinateX - 1][coordinateY] == false || myGrid[coordinateX][coordinateY - 1] == false))
				fitnessV1++;
			else
				isWayConvenient = false;
		}
			break;
		case 5:
		{
			movX5();
			if (coordinateX >= 0 && coordinateX <= 9 && coordinateY >= 0 && coordinateY <= 9 && myGrid[coordinateX][coordinateY] == true)
				fitnessV1++;
			else
				isWayConvenient = false;
		}
			break;
		case 6:
		{
			movX6();
			if (coordinateX >= 0 && coordinateX <= 9 && coordinateY >= 0 && coordinateY <= 9 && myGrid[coordinateX][coordinateY] == false && (myGrid[coordinateX + 1][coordinateY] == false || myGrid[coordinateX][coordinateY + 1] == false))
				fitnessV1++;
			else
				isWayConvenient = false;
		}
			break;
		case 7:
			movX7();
			if (coordinateX >= 0 && coordinateX <= 9 && coordinateY >= 0 && coordinateY <= 9 && myGrid[coordinateX][coordinateY] == false)
				fitnessV1++;
			else
				isWayConvenient = false;
			break;
		case 8:
		{
			movX8();
			if (coordinateX >= 0 && coordinateX <= 9 && coordinateY >= 0 && coordinateY <= 9 && myGrid[coordinateX][coordinateY] == false && (myGrid[coordinateX + 1][coordinateY] == false || myGrid[coordinateX][coordinateY - 1] == false))
				fitnessV1++;
			else
				isWayConvenient = false;
			break;
		}
		default:
			break;
		}
		if (isWayConvenient == false)
			break;
	}
    fitnessV2 = 1 / sqrt((10 - coordinateX)*(10 - coordinateX) + (10 - coordinateY)*(10 - coordinateY));
	//cout << fitnessV1*fitnessV2;
	fitnessValue = fitnessV1*fitnessV2;
	return fitnessValue;
}

void myRobot::printMatrix2D(bool ** myGrid)
{
	cout << "10x10 Grid: " << endl;
	for (int j = 9; j >= 0; j--)
	{
		for (int i = 0; i < 10; i++)
			printf("(%d,%d)%d  ", i, j, myGrid[i][j]);
		printf("\n");
	}
}

string myRobot::calculateTruePath(bool ** myGrid, list<int> path)
{
	int length = 0;
	bool pathFound = false;
	setCoordinateX(0);
	setCoordinateY(0);
	cout << "(" << coordinateX << "," << coordinateY << ") ";
    string stringPath;

	for (auto v : path)
	{
		switch (v)
		{
		case 1:
		{
			//cout<<v<<" ";
			//printMatrix2D(myGrid);
			movX1();
			cout << "1->(" << coordinateX << "," << coordinateY << ") ";
			if (coordinateX == 9 && coordinateY == 9)
				pathFound = true;
            stringPath.append(to_string(coordinateX));
            stringPath.append(to_string(coordinateY));
		}

		break;
		case 2:
		{
			movX2();
			cout << "2->(" << coordinateX << "," << coordinateY << ") ";
			if (coordinateX == 9 && coordinateY == 9)
				pathFound = true;
            stringPath.append(to_string(coordinateX));
            stringPath.append(to_string(coordinateY));
		}
		break;
		case 3:
		{
			movX3();
			cout << "3->(" << coordinateX << "," << coordinateY << ") ";
			if (coordinateX == 9 && coordinateY == 9)
				pathFound = true;
            stringPath.append(to_string(coordinateX));
            stringPath.append(to_string(coordinateY));
		}
		break;
		case 4:
		{
			movX4();
			cout << "4->(" << coordinateX << "," << coordinateY << ") ";
			if (coordinateX == 9 && coordinateY == 9)
				pathFound = true;
            stringPath.append(to_string(coordinateX));
            stringPath.append(to_string(coordinateY));
		}
		break;
		case 5:
		{
			movX5();
			cout << "5->(" << coordinateX << "," << coordinateY << ") ";
			if (coordinateX == 9 && coordinateY == 9)
				pathFound = true;
            stringPath.append(to_string(coordinateX));
            stringPath.append(to_string(coordinateY));
		}
		break;
		case 6:
		{
			movX6();
			cout << "6->(" << coordinateX << "," << coordinateY << ") ";
			if (coordinateX == 9 && coordinateY == 9)
				pathFound = true;
            stringPath.append(to_string(coordinateX));
            stringPath.append(to_string(coordinateY));
		}
		break;
		case 7:
		{
			movX7();
			cout << "7->(" << coordinateX << "," << coordinateY << ") ";
			if (coordinateX == 9 && coordinateY == 9)
				pathFound = true;
            stringPath.append(to_string(coordinateX));
            stringPath.append(to_string(coordinateY));
		}
		break;
		case 8:
		{
			movX8();
			cout << "8->(" << coordinateX << "," << coordinateY << ") ";
			if (coordinateX == 9 && coordinateY == 9)
				pathFound = true;
            stringPath.append(to_string(coordinateX));
            stringPath.append(to_string(coordinateY));
		}
		break;
		default:
			break;
		}
		if (pathFound == true)
			break;
	}
	cout << endl;
	printMatrix2D(myGrid);
    return stringPath;

}

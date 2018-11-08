// FilterApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//input file is input1.txt

//#include "stdafx.h"
#include "pch.h"
#include "filter.h"

#include <iostream>


string inputFile = "input1.txt";

const int MAX_DATA = 1000;  // the maximum size of the array for loading data 
const int DATE_SIZE = 19;  // the maximum size of a date as a null-terminated string
int main()
{
	int data[MAX_DATA];

	LoadMeasurements(inputFile, data, MAX_DATA);

#ifdef _DEBUG
	for (int i = 0; i < stack; i++)
	{
		cout << data[i] << endl;
	}
#endif // _DEBUG

	cout << "array loaded" << endl;
	system("pause");
}


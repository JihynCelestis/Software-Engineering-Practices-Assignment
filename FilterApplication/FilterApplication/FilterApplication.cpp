// FilterApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//input file is input1.txt

#include "stdafx.h"
#include "filter.h"
#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int data[MAX_DATA];

	LoadMeasurements(inputFile, data, MAX_DATA);
	system("pause");
}


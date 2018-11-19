// DynamicLib.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "filter.h"
int stack;
int parameters[4];

int Filter(int data[], int count, const WCHAR* parameterString)
{
	cout << "Data will be filtered according to the parameter list, Low: 1, High 9" << endl << endl;

	//outputs original data, just for comparison purposes
	for (int i = 0; i < count; i++)
	{
		cout << "Original entry for slot " << i << " is " << data[i] << endl;
	}
	cout << endl;

	for (int i = 0; i < 4; i++)
	{
		parameters[i] = parameterString[i] - '0';

	//This one just lets me know that it's got the correct ascii codes for each character in the Parameter List
	#ifdef  _DEBUG
		cout << "Entry " << i << " in the array is: " << parameters[i] << endl;
	#endif //  _DEBUG
		
	}

	//holy crap this is patchy but it does the job... If the parameters are between 0 and 9...
	//I need to find a way of.. "combining" 2 intergers that doesn't involving adding them together.
	//tried to Tokenise in a test solution (seperate), but wcstok was demanding wchar_t, and refused to use WCHAR..
	for (int i = 0; i < count; i++)
	{
		if (data[i] < parameters[0])
		{
			data[i] = parameters[0];
		}										//Basically, this just compares the original data to the parameters being passed
		else if (data[i] > parameters[2])		//if it's lower than 1, sets it to 1, if it's higher than 9, sets to 9.
		{										//parameters[0 and 2] are basically 1 and 9. 
			data[i] = parameters[2];
		}
		else
		{
			data[i];							//if it's between 1 and 9, leaves it alone.
		}
	}
	for (int i = 0; i <= count; i++)
	{
		if (i == count)
		{
			return count;
		}
		cout << "New entry for slot " << i << " is: " << data[i] << endl; //outputs new values that have been modified from the array.
		
	}

	return Failure;
}

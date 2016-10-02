/*
ID: sreenidhi
PROG: ride
LANG: C++
*/

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

#include <stdint.h>

using namespace std;

int ride() 
{
	ofstream fout("ride.out");
	ifstream fin("ride.in");

	string line1, line2;
	getline(fin, line1);
	getline(fin, line2);

	uint32_t prod1 = 1, prod2 = 1;
	for (size_t i = 0; i < line1.size(); i++)
	{
		prod1 *= line1[i] - 'A' + 1;
	}
	for (size_t i = 0; i < line2.size(); i++)
	{
		prod2 *= line2[i] - 'A' + 1;
	}

	if (prod1%47 == prod2%47)
	{
		fout <<"GO" << endl;
	}
	else
	{
		fout << "STAY" << endl;
	}

	fin.close();
	fout.close();

	return 0;
}
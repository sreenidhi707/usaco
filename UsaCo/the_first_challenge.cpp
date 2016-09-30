/*
ID: sreenidhi
PROG: test
LANG: C++
*/

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int the_first_challenge() {
	ofstream fout("test.out");
	ifstream fin("test.in");
	int a, b;
	fin >> a >> b;
	fout << a + b << endl;
	return 0;
}
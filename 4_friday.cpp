/*
ID: sreenidhi
PROG: gift1
LANG: C++11
*/

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include <stdint.h>

using namespace std;

enum months
{
	JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC, NUM_OF_MONTHS = 12
};

enum days
{
	SUN, MON, TUE, WED, THU, FRI, SAT, NUM_OF_DAYS = 7
};

const uint32_t START_YEAR = 1990;
const uint32_t START_MONTH = JAN;
const uint32_t START_DATE = 1;
const uint32_t START_DAY = MON;

uint32_t days_in_months[NUM_OF_MONTHS] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
uint32_t friday_hist[NUM_OF_DAYS] = {0, 0, 0, 0, 0, 0, 0};

int friday(void)
{
	ofstream fout("friday.out");
	ifstream fin("friday.in");

	string line;

	//Read number of years
	getline(fin, line);
	uint32_t n_years = stoi(line, NULL, 10);

	uint32_t current_day = MON;
	for (size_t year = START_YEAR; year < START_YEAR + n_years; year++)
	{
		bool leap_year = false;
		if (year % 100 == 0 && year % 400 == 0)
		{
			leap_year = true;
		}
		else if (year % 4 == 0)
		{
			leap_year = true;
		}
		
		for (size_t month = 0; month < NUM_OF_MONTHS; month++)
		{
			uint32_t num_of_days = (month == FEB) ? ((leap_year) ? 29: 28) : days_in_months[month];
			for (size_t date = 1; date <= num_of_days; date++)
			{
				if (date == 13)
				{
					friday_hist[current_day]++;
				}
				current_day = (current_day + 1) % NUM_OF_DAYS;
			}
		}
	}

	for (size_t day = SUN; day < NUM_OF_DAYS; day++)
	{
		fout << friday_hist[day] << " ";
	}
	

	fin.close();
	fout.close();
	return 0;
}

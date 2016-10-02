/*
ID: sreenidhi
PROG: gift1
LANG: C++11
*/

//#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include <stdint.h>

using namespace std;

vector<string> split_string(string s, char delimiter)
{
	istringstream ss(s);
	vector<string> words;

	while (!ss.eof())
	{
		string x;
		getline(ss, x, delimiter);
		words.push_back(x);
	}
	return words;
}

uint32_t get_id(vector< pair<string, int32_t> >& table, string s)
{
	for (size_t i = 0; i < table.size(); i++)
	{
		if (table[i].first == s)
		{
			return i;
		}
	}
}

void setval(vector< pair<string, int32_t> >& table, string s, int32_t value)
{
	table[get_id(table, s)].second = value;
}

int32_t getval(vector< pair<string, int32_t> >& table, string s)
{
	return table[get_id(table, s)].second;
}

int main(void)
{
	ofstream fout("gift1.out");
	ifstream fin("gift1.in");

	string line;
	vector< pair<string, int32_t> > table;

	//Read NP
	getline(fin, line);
	uint8_t np = stoi(line, NULL, 10);
	
	//Read Names
	for (size_t i = 0; i < np; i++)
	{
		getline(fin, line);
		table.push_back(make_pair(line, 0));
	}

	//Start processing NP groups of transactions
	for (size_t i = 0; i < np; i++)
	{
		getline(fin, line); //Name
		string giving_person = line;

		getline(fin, line); //Amount number_of_people
		vector<string> words = split_string(line, ' ');
		int32_t amount = stoi(words[0], NULL, 10);
		uint32_t number_of_people = stoi(words[1], NULL, 10);

		if (amount > 0 && number_of_people > 0)
		{
			uint32_t amount_per_person = amount / number_of_people;
			if (amount_per_person > 0)
			{
				uint32_t amount_given = amount_per_person * number_of_people;
				setval(table, giving_person, getval(table, giving_person) - amount_given);
				for (size_t i = 0; i < number_of_people; i++)
				{
					getline(fin, line); //Names of persons to give money
					setval(table, line, getval(table, line) + amount_per_person);
				}
			}
			else
			{
				setval(table, giving_person, getval(table, giving_person) + amount);
				//Read number_of_people dummy lines and ignore
				for (size_t i = 0; i < number_of_people; i++)
				{
					getline(fin, line);
				}
			}
		}
		else
		{
			//Read number_of_people dummy lines and ignore
			for (size_t i = 0; i < number_of_people; i++)
			{
				getline(fin, line);
			}
		}
	}
	
	//Write out the result
	for (size_t i = 0; i < table.size(); i++)
	{
		fout << table[i].first << " " << table[i].second << endl;
	}

	fin.close();
	fout.close();
	return 0;
}
#include"stdafx.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <vector>

using namespace std;


class Rubik {
	private:
		char Buff[55];
		char *Cube[6][9];
		int searchEdge(const char& ar, const char& ab) const;
		int searchCorner(const char& a, const char& iz, const char& de) const;
		void sequence(const string& sec, vector<char>& solution);
		void whiteCross(vector<char>& solution);
		void cornersFirstStep(vector<char>& solution);
		void secondStep(vector<char>& solution);
		void yellowCross(vector<char>& solution);
		void permutationFinalCorners(vector<char>& solution);
		void positionFinalCorners(vector<char>& solution);

	public:
		void getBuff(char(&buff)[55]);
		bool isSolved() const;
		void Rotate(vector<char>& solution, char& side);
		void solve(vector<char>& solution);
		void readRubik();
};

bool test(istream& is, char(*buff));

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


struct Center {
	char center;
};

struct Edge {
	char up, down;
};

struct Corner {
	char up, left, right;
};


class Rubik {
private:

	Center center[6];
	Edge edge[12];
	Corner corner[8];
	int searchEdge(const char& ar, const char& ab) const;
	int searchCorner(const char& a, const char& iz, const char& de) const;
	void sequence(const string& sec, vector<char>& solution);
	void firstStep(vector<char>& solution);
	void whiteCross(vector<char>& solution);
	void cornersFirstStep(vector<char>& solution);
	void secondStep(vector<char>& solution);
	void thirdStep(vector<char>& solution);
	void yellowCross(vector<char>& solution);
	void finalCorners(vector<char>& solution);
	void permutationFinalCorners(vector<char>& solution);
	void positionFinalCorners(vector<char>& solution);

public:


	bool isSolved() const;
	void R(vector<char>& solution);
	void R2(vector<char>& solution);
	void r(vector<char>& solution);
	void L(vector<char>& solution);
	void L2(vector<char>& solution);
	void l(vector<char>& solution);
	void D(vector<char>& solution);
	void D2(vector<char>& solution);
	void d(vector<char>& solution);
	void U(vector<char>& solution);
	void U2(vector<char>& solution);
	void u(vector<char>& solution);
	void F(vector<char>& solution);
	void F2(vector<char>& solution);
	void f(vector<char>& solution);
	void B(vector<char>& solution);
	void B2(vector<char>& solution);
	void b(vector<char>& solution);
	void solve(vector<char>& solution);
	void exportSolution(std::ostream& os = cout) const;
	void readRubik(char (&buff)[56]);
	
	Center getCenter(const int& position) const;
	Edge getEdge(const int& position) const;
	Corner getCorner(const int& position) const;
};


bool test(std::istream& is, char(*buff));

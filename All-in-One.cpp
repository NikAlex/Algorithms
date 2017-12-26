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





int Rubik::searchEdge(const char& ar, const char& ab) const {
	int position = 0;
	if ((edge[0].up == ar && edge[0].down == ab) || (edge[0].up == ab && edge[0].down == ar))
		position = 0;
	else if ((edge[1].up == ar && edge[1].down == ab) || (edge[1].up == ab && edge[1].down == ar))
		position = 1;
	else if ((edge[2].up == ar && edge[2].down == ab) || (edge[2].up == ab && edge[2].down == ar))
		position = 2;
	else if ((edge[3].up == ar && edge[3].down == ab) || (edge[3].up == ab && edge[3].down == ar))
		position = 3;
	else if ((edge[4].up == ar && edge[4].down == ab) || (edge[4].up == ab && edge[4].down == ar))
		position = 4;
	else if ((edge[5].up == ar && edge[5].down == ab) || (edge[5].up == ab && edge[5].down == ar))
		position = 5;
	else if ((edge[6].up == ar && edge[6].down == ab) || (edge[6].up == ab && edge[6].down == ar))
		position = 6;
	else if ((edge[7].up == ar && edge[7].down == ab) || (edge[7].up == ab && edge[7].down == ar))
		position = 7;
	else if ((edge[8].up == ar && edge[8].down == ab) || (edge[8].up == ab && edge[8].down == ar))
		position = 8;
	else if ((edge[9].up == ar && edge[9].down == ab) || (edge[9].up == ab && edge[9].down == ar))
		position = 9;
	else if ((edge[10].up == ar && edge[10].down == ab) || (edge[10].up == ab && edge[10].down == ar))
		position = 10;
	else if ((edge[11].up == ar && edge[11].down == ab) || (edge[11].up == ab && edge[11].down == ar))
		position = 11;

	return position;
}

int Rubik::searchCorner(const char& a, const char& iz, const char& de) const {
	int position = 0;
	if (((corner[0].up == a) && (corner[0].left == iz) && (corner[0].right == de)) ||
		((corner[0].up == a) && (corner[0].left == de) && (corner[0].right == iz)) ||
		((corner[0].up == iz) && (corner[0].left == a) && (corner[0].right == de)) ||
		((corner[0].up == de) && (corner[0].left == iz) && (corner[0].right == a)) ||
		((corner[0].up == de) && (corner[0].left == a) && (corner[0].right == iz)) ||
		((corner[0].up == iz) && (corner[0].left == de) && (corner[0].right == a)))
		position = 0;
	else if (((corner[1].up == a) && (corner[1].left == iz) && (corner[1].right == de)) ||
		((corner[1].up == a) && (corner[1].left == de) && (corner[1].right == iz)) ||
		((corner[1].up == iz) && (corner[1].left == a) && (corner[1].right == de)) ||
		((corner[1].up == de) && (corner[1].left == iz) && (corner[1].right == a)) ||
		((corner[1].up == de) && (corner[1].left == a) && (corner[1].right == iz)) ||
		((corner[1].up == iz) && (corner[1].left == de) && (corner[1].right == a)))
		position = 1;
	else if (((corner[2].up == a) && (corner[2].left == iz) && (corner[2].right == de)) ||
		((corner[2].up == a) && (corner[2].left == de) && (corner[2].right == iz)) ||
		((corner[2].up == iz) && (corner[2].left == a) && (corner[2].right == de)) ||
		((corner[2].up == de) && (corner[2].left == iz) && (corner[2].right == a)) ||
		((corner[2].up == de) && (corner[2].left == a) && (corner[2].right == iz)) ||
		((corner[2].up == iz) && (corner[2].left == de) && (corner[2].right == a)))
		position = 2;
	else if (((corner[3].up == a) && (corner[3].left == iz) && (corner[3].right == de)) ||
		((corner[3].up == a) && (corner[3].left == de) && (corner[3].right == iz)) ||
		((corner[3].up == iz) && (corner[3].left == a) && (corner[3].right == de)) ||
		((corner[3].up == de) && (corner[3].left == iz) && (corner[3].right == a)) ||
		((corner[3].up == de) && (corner[3].left == a) && (corner[3].right == iz)) ||
		((corner[3].up == iz) && (corner[3].left == de) && (corner[3].right == a)))
		position = 3;
	else if (((corner[4].up == a) && (corner[4].left == iz) && (corner[4].right == de)) ||
		((corner[4].up == a) && (corner[4].left == de) && (corner[4].right == iz)) ||
		((corner[4].up == iz) && (corner[4].left == a) && (corner[4].right == de)) ||
		((corner[4].up == de) && (corner[4].left == iz) && (corner[4].right == a)) ||
		((corner[4].up == de) && (corner[4].left == a) && (corner[4].right == iz)) ||
		((corner[4].up == iz) && (corner[4].left == de) && (corner[4].right == a)))
		position = 4;
	else if (((corner[5].up == a) && (corner[5].left == iz) && (corner[5].right == de)) ||
		((corner[5].up == a) && (corner[5].left == de) && (corner[5].right == iz)) ||
		((corner[5].up == iz) && (corner[5].left == a) && (corner[5].right == de)) ||
		((corner[5].up == de) && (corner[5].left == iz) && (corner[5].right == a)) ||
		((corner[5].up == de) && (corner[5].left == a) && (corner[5].right == iz)) ||
		((corner[5].up == iz) && (corner[5].left == de) && (corner[5].right == a)))
		position = 5;
	else if (((corner[6].up == a) && (corner[6].left == iz) && (corner[6].right == de)) ||
		((corner[6].up == a) && (corner[6].left == de) && (corner[6].right == iz)) ||
		((corner[6].up == iz) && (corner[6].left == a) && (corner[6].right == de)) ||
		((corner[6].up == de) && (corner[6].left == iz) && (corner[6].right == a)) ||
		((corner[6].up == de) && (corner[6].left == a) && (corner[6].right == iz)) ||
		((corner[6].up == iz) && (corner[6].left == de) && (corner[6].right == a)))
		position = 6;
	else if (((corner[7].up == a) && (corner[7].left == iz) && (corner[7].right == de)) ||
		((corner[7].up == a) && (corner[7].left == de) && (corner[7].right == iz)) ||
		((corner[7].up == iz) && (corner[7].left == a) && (corner[7].right == de)) ||
		((corner[7].up == de) && (corner[7].left == iz) && (corner[7].right == a)) ||
		((corner[7].up == de) && (corner[7].left == a) && (corner[7].right == iz)) ||
		((corner[7].up == iz) && (corner[7].left == de) && (corner[7].right == a)))
		position = 7;

	return position;
}
void Rubik::sequence(const string& sec, vector<char>& solution) {
	for (unsigned int i = 0; i<sec.size(); ++i) {
		if (sec[i] == 'R')
			R(solution);
		else if (sec[i] == 'r')
			r(solution);
		else if (sec[i] == 'L')
			L(solution);
		else if (sec[i] == 'l')
			l(solution);
		else if (sec[i] == 'D')
			D(solution);
		else if (sec[i] == 'd')
			d(solution);
		else if (sec[i] == 'U')
			U(solution);
		else if (sec[i] == 'u')
			u(solution);
		else if (sec[i] == 'F')
			F(solution);
		else if (sec[i] == 'f')
			f(solution);
		else if (sec[i] == 'B')
			B(solution);
		else if (sec[i] == 'b')
			b(solution);
	}
}
void Rubik::firstStep(vector<char>& solution) {
	whiteCross(solution);
	cornersFirstStep(solution);
}
void Rubik::whiteCross(vector<char>& solution) {
	int position = searchEdge('w', 'g'); // White, green.
	if (position == 0) {
		if (edge[0].down == 'w') // FuRU
			sequence("FuRU", solution);
	}
	else if (position == 1) {
		if (edge[1].up == 'w') // ruRU
			sequence("ruRU", solution);
		else // rf
			sequence("rf", solution);
	}
	else if (position == 2) {
		if (edge[2].up == 'w') // U2
			sequence("UU", solution);
		else // burU
			sequence("burU", solution);
	}
	else if (position == 3) {
		if (edge[3].up == 'w') // LUlu
			sequence("LUlu", solution);
		else // LF
			sequence("LF", solution);
	}
	else if (position == 4) {
		if (edge[4].up == 'w') // F2
			F2(solution);
		else // fuRU
			sequence("fuRU", solution);
	}
	else if (position == 5) {
		if (edge[5].up == 'w') // dF2
			sequence("dFF", solution);
		else // Rf
			sequence("Rf", solution);
	}
	else if (position == 6) {
		if (edge[6].up == 'w') // D2F2
			sequence("DDFF", solution);
		else // dRf
			sequence("dRf", solution);
	}
	else if (position == 7) {
		if (edge[7].up == 'w') // DF2
			sequence("DFF", solution);
		else // lF
			sequence("lF", solution);
	}
	else if (position == 8) {
		if (edge[8].up == 'w') // uRU
			sequence("uRU", solution);
		else // f
			sequence("f", solution);
	}
	else if (position == 9) {
		if (edge[9].up == 'w') // urU
			sequence("urU", solution);
		else // U2BU2
			sequence("UUBUU", solution);
	}
	else if (position == 10) {
		if (edge[10].up == 'w') // ULu
			sequence("ULu", solution);
		else // U2bU2
			sequence("UUbUU", solution);
	}
	else if (position == 11) {
		if (edge[11].up == 'w') // Ulu
			sequence("Ulu", solution);
		else // F
			sequence("F", solution);
	}

	position = searchEdge('w', 'r'); // White/red
	if (position == 1) {
		if (edge[1].down == 'w') // rUfu
			sequence("rUfu", solution);
	}
	else if (position == 2) {
		if (edge[2].up == 'w') // buBU
			sequence("buBU", solution);
		else // br
			sequence("br", solution);
	}
	else if (position == 3) {
		if (edge[3].up == 'w') // L2D2R2
			sequence("LLDDRR", solution);
		else // LUFu
			sequence("LUFu", solution);
	}
	else if (position == 4) {
		if (edge[4].up == 'w') // DR2
			sequence("DRR", solution);
		else // fRF
			sequence("fRF", solution);
	}
	else if (position == 5) {
		if (edge[5].up == 'w') // R2
			R2(solution);
		else // RUfu
			sequence("RUfu", solution);
	}
	else if (position == 6) {
		if (edge[6].up == 'w') // dR2
			sequence("dRR", solution);
		else // Br
			sequence("Br", solution);
	}
	else if (position == 7) {
		if (edge[7].up == 'w') // D2R2
			sequence("DDRR", solution);
		else // lUFu
			sequence("lUFu", solution);
	}
	else if (position == 8) {
		if (edge[8].up == 'w') // R
			sequence("R", solution);
		else // Ufu
			sequence("Ufu", solution);
	}
	else if (position == 9) {
		if (edge[9].up == 'w') // r
			sequence("r", solution);
		else // uBU
			sequence("uBU", solution);
	}
	else if (position == 10) {
		if (edge[10].up == 'w') // U2LU2
			sequence("UULUU", solution);
		else // ubU
			sequence("ubU", solution);
	}
	else if (position == 11) {
		if (edge[11].up == 'w') // U2lU2
			sequence("UUlUU", solution);
		else // UFu
			sequence("UFu", solution);
	}


	position = searchEdge('w', 'b'); // White/blue
	if (position == 2) {
		if (edge[2].down == 'w') // bUru
			sequence("bUru", solution);
	}
	else if (position == 3) {
		if (edge[3].up == 'w') // LulU
			sequence("LulU", solution);
		else // lb
			sequence("lb", solution);
	}
	else if (position == 4) {
		if (edge[4].up == 'w') // D2B2
			sequence("DDBB", solution);
		else // uFlU
			sequence("uFlU", solution);
	}
	else if (position == 5) {
		if (edge[5].up == 'w') // DB2
			sequence("DBB", solution);
		else // rBR
			sequence("rBR", solution);
	}
	else if (position == 6) {
		if (edge[6].up == 'w') // B2
			B2(solution);
		else // BUru
			sequence("BUru", solution);
	}
	else if (position == 7) {
		if (edge[7].up == 'w') // dB2
			sequence("dBB", solution);
		else // Lb
			sequence("Lb", solution);
	}
	else if (position == 8) {
		if (edge[8].up == 'w') // URu
			sequence("URu", solution);
		else // U2fU2
			sequence("UUfUU", solution);
	}
	else if (position == 9) {
		if (edge[9].up == 'w') // Uru
			sequence("Uru", solution);
		else // B
			B(solution);
	}
	else if (position == 10) {
		if (edge[10].up == 'w') // uLU
			sequence("uLU", solution);
		else // b
			b(solution);
	}
	else if (position == 11) {
		if (edge[11].up == 'w') // ulU
			sequence("ulU", solution);
		else // U2FU2
			sequence("UUFUU", solution);
	}

	position = searchEdge('w', 'o'); // White/orange
	if (position == 3) {
		if (edge[3].down == 'w') // LuFU
			sequence("LuFU", solution);
	}
	else if (position == 4) {
		if (edge[4].up == 'w') // dL2
			sequence("dLL", solution);
		else // Flf
			sequence("Flf", solution);
	}
	else if (position == 5) {
		if (edge[5].up == 'w') // D2L2
			sequence("DDLL", solution);
		else // dFlf
			sequence("dFlf", solution);
	}
	else if (position == 6) {
		if (edge[6].up == 'w') // DL2
			sequence("DLL", solution);
		else // bLB
			sequence("bLB", solution);
	}
	else if (position == 7) {
		if (edge[7].up == 'w') // L2
			L2(solution);
		else // luFU
			sequence("luFU", solution);
	}
	else if (position == 8) {
		if (edge[8].up == 'w') // U2RU2
			sequence("UURUU", solution);
		else //ufU
			sequence("ufU", solution);
	}
	else if (position == 9) {
		if (edge[9].up == 'w') // U2rU2
			sequence("UUrUU", solution);
		else // UBu
			sequence("UBu", solution);
	}
	else if (position == 10) {
		if (edge[10].up == 'w') // L
			L(solution);
		else // Ubu
			sequence("Ubu", solution);
	}
	else if (position == 11) {
		if (edge[11].up == 'w') // l
			l(solution);
		else // uFU
			sequence("uFU", solution);
	}
}
void Rubik::cornersFirstStep(vector<char>& solution) {
	int position = searchCorner('w', 'g', 'r'); // White, green and red
	if (position == 0) {
		if (corner[0].up == 'w') // LDlrdR
			sequence("LDlrdR", solution);
		else if (corner[0].right == 'w') // LrD2lRFDf
			sequence("LrDDlRFDf", solution);
		else if (corner[0].left == 'w') // LrDlR
			sequence("LrDlR", solution);
	}
	else if (position == 1) {
		if (corner[1].right == 'w') // rdRDrdR
			sequence("rdRDrdR", solution);
		else if (corner[1].left == 'w') // rDRFDf
			sequence("rDRFDf", solution);
	}
	else if (position == 2) {
		if (corner[2].up == 'w') // bdBFDf
			sequence("bdBFDf", solution);
		else if (corner[2].right == 'w') // bFdBf
			sequence("bFdBf", solution);
		else if (corner[2].left == 'w') // bDBdFDf
			sequence("bDBdFDf", solution);
	}
	else if (position == 3) { // BD2brdR
		if (corner[3].up == 'w')
			sequence("BDDbrdR", solution);
		else if (corner[3].right == 'w') // lFD2fL
			sequence("lFDDfL", solution);
		else if (corner[3].left == 'w') // BrD2Rb
			sequence("BrDDRb", solution);
	}
	else if (position == 4) {
		if (corner[4].up == 'w') // rD2RFDf
			sequence("rDDRFDf", solution);
		else if (corner[4].right == 'w') // DrdR
			sequence("DrdR", solution);
		else if (corner[4].left == 'w') // rDR
			sequence("rDR", solution);
	}
	else if (position == 5) {
		if (corner[5].up == 'w') // rD2RDrdR
			sequence("rDDRDrdR", solution);
		else if (corner[5].right == 'w') // rdR
			sequence("rdR", solution);
		else if (corner[5].left == 'w') // FDf
			sequence("FDf", solution);
	}
	else if (position == 6) {
		if (corner[6].up == 'w') // FD2frdR
			sequence("FDDfrdR", solution);
		else if (corner[6].right == 'w') // Fdf
			sequence("Fdf", solution);
		else if (corner[6].left == 'w') // dFDf
			sequence("dFDf", solution);
	}
	else if (position == 7) {
		if (corner[7].up == 'w') // rdRFDf
			sequence("rdRFDf", solution);
		else if (corner[7].right == 'w') // FD2f
			sequence("FDDf", solution);
		else if (corner[7].left == 'w') // rD2R
			sequence("rDDR", solution);
	}


	position = searchCorner('w', 'r', 'b'); // White, red and blue
	if (position == 0) {
		if (corner[0].up == 'w') // LD2lbdB
			sequence("LDDlbdB", solution);
		else if (corner[0].right == 'w') // fRD2rF
			sequence("fRDDrF", solution);
		else if (corner[0].left == 'w') // LbD2Bl
			sequence("LbDDBl", solution);
	}
	else if (position == 2) {
		if (corner[2].right == 'w') // bdBDbdB
			sequence("bdBDbdB", solution);
		else if (corner[2].left == 'w') // bDBRDr
			sequence("bDBRDr", solution);
	}
	else if (position == 3) {
		if (corner[3].up == 'w') // BDbRD2r
			sequence("BDbRDDr", solution);
		else if (corner[3].right == 'w') // lRdLr
			sequence("lRdLr", solution);
		else if (corner[3].left == 'w') // BDB2D2B
			sequence("BDBBDDB", solution);
	}
	else if (position == 4) {
		if (corner[4].up == 'w') // bdBRDr
			sequence("bdBRDr", solution);
		else if (corner[4].right == 'w') // RD2r
			sequence("RDDr", solution);
		else if (corner[4].left == 'w') // bD2B
			sequence("bDDB", solution);
	}
	else if (position == 5) {
		if (corner[5].up == 'w') // bD2BRDr
			sequence("bDDBRDr", solution);
		else if (corner[5].right == 'w') // DbdB
			sequence("DbdB", solution);
		else if (corner[5].left == 'w') // bDB
			sequence("bDB", solution);
	}
	else if (position == 6) {
		if (corner[6].up == 'w') // bD2BDbdB
			sequence("bDDBDbdB", solution);
		else if (corner[6].right == 'w') // bdB
			sequence("bdB", solution);
		else if (corner[6].left == 'w') // RDr
			sequence("RDr", solution);
	}
	else if (position == 7) {
		if (corner[7].up == 'w') // RD2rbdB
			sequence("RDDrbdB", solution);
		else if (corner[7].right == 'w') // Rdr
			sequence("Rdr", solution);
		else if (corner[7].left == 'w') // dRDr
			sequence("dRDr", solution);
	}

	position = searchCorner('w', 'b', 'o'); // White, blue and orange
	if (position == 0) {
		if (corner[0].up == 'w') // fdFBDb
			sequence("fdFBDb", solution);
		else if (corner[0].right == 'w') // fBdFb
			sequence("fBdFb", solution);
		else if (corner[0].left == 'w') // fDFdBDb
			sequence("fDFdBDb", solution);
	}
	else if (position == 3) {
		if (corner[3].right == 'w') // BdbldL
			sequence("BdbldL", solution);
		else if (corner[3].left == 'w') // BDbdBDb
			sequence("BDbdBDb", solution);
	}
	else if (position == 4) {
		if (corner[4].up == 'w') // fBD2Fb
			sequence("fBDDFb", solution);
		else if (corner[4].right == 'w') // Bdb
			sequence("Bdb", solution);
		else if (corner[4].left == 'w') // dBDb
			sequence("dBDb", solution);
	}
	else if (position == 5) {
		if (corner[5].up == 'w') // LD2lBdb
			sequence("LDDlBdb", solution);
		else if (corner[5].right == 'w') // BD2b
			sequence("BDDb", solution);
		else if (corner[5].left == 'w') // lD2L
			sequence("lDDL", solution);
	}
	else if (position == 6) {
		if (corner[6].up == 'w') // lD2LBDb
			sequence("lDDLBDb", solution);
		else if (corner[6].right == 'w') // DldL
			sequence("DldL", solution);
		else if (corner[6].left == 'w') // lDL
			sequence("lDL", solution);
	}
	else if (position == 7) {
		if (corner[7].up == 'w') // BdblD2L
			sequence("BdblDDL", solution);
		else if (corner[7].right == 'w') // ldL --> DLdl
			sequence("DldL", solution);
		//sequence("DLdl", solution)
		else if (corner[7].left == 'w') // BDb
			sequence("BDb", solution);
	}
}
void Rubik::secondStep(vector<char>& solution) {
	int position = searchEdge('g', 'o'); // Green/orange
	if (position == 4) {
		if (edge[4].down == 'g') // dfDF
			sequence("dfDF", solution);
		else if (edge[4].up == 'g') // Ldl
			sequence("Ldl", solution);
	}
	else if (position == 5) {
		if (edge[5].down == 'g') // fdF
			sequence("fdF", solution);
		else if (edge[5].up == 'g') // LD2l
			sequence("LDDl", solution);
	}
	else if (position == 6) {
		if (edge[6].up == 'g') // LDl
			sequence("LDl", solution);
		else if (edge[6].down == 'g') // fD2F
			sequence("fDDF", solution);
	}
	else if (position == 7) {
		if (edge[7].down == 'g') // fDF
			sequence("fDF", solution);
		else if (edge[7].up == 'g') // DLdl
			sequence("DLdl", solution);
	}
	else if (position == 8) {
		if (edge[8].down == 'g') // urD2RUfDF
			sequence("urDDRUfDF", solution);
		else if (edge[8].up == 'g') // urdRULdl
			sequence("urdRULdl", solution);
	}
	else if (position == 9) {
		if (edge[9].down == 'g') // U2bdBU2LD2l
			sequence("UUbdBUULDDl", solution);
		else if (edge[9].up == 'g') // U2bDBU2fDF
			sequence("UUbDBUUfDF", solution);
	}
	else if (position == 10) {
		if (edge[10].down == 'g') // UBD2buLdl
			sequence("UBDDbuLdl", solution);
		else if (edge[10].up == 'g') // UBDbufDF
			sequence("UBDbufDF", solution);
	}
	else if (position == 11) {
		if (edge[11].down == 'g') // LDldfDF
			sequence("LDldfDF", solution);
	}

	U(solution); //
	position = searchEdge('o', 'b'); // Orange/blue
	if (position == 4) {
		if (edge[4].down == 'o') // ldL
			sequence("ldL", solution);
		else if (edge[4].up == 'o') // BD2b
			sequence("BDDb", solution);
	}
	else if (position == 5) {
		if (edge[5].down == 'o') // lD2L
			sequence("lDDL", solution);
		else if (edge[5].up == 'o') // BDb
			sequence("BDb", solution);
	}
	else if (position == 6) {
		if (edge[6].down == 'o') // lDL
			sequence("lDL", solution);
		else if (edge[6].up == 'o') // DBdb
			sequence("DBdb", solution);
	}
	else if (position == 7) {
		if (edge[7].down == 'o') // DldL
			sequence("DldL", solution);
		else if (edge[7].up == 'o') // Bdb
			sequence("Bdb", solution);
	}
	else if (position == 8) {
		if (edge[8].down == 'o') // U2rDRU2lDL
			sequence("UUrDRUUlDL", solution);
		else if (edge[8].up == 'o') // U2rD2RU2Bdb
			sequence("UUrDDRUUBdb", solution);
	}
	else if (position == 9) {
		if (edge[9].down == 'o') // URDrulDL
			sequence("URDrulDL", solution);
		else if (edge[9].up == 'o') // URD2ruBdb
			sequence("URDDruBdb", solution);
	}
	else if (position == 10) {
		if (edge[10].up == 'o') // BDbdlDL
			sequence("BDbdlDL", solution);
	}

	U(solution); //
	position = searchEdge('r', 'b'); // Blue/red
	if (position == 4) {
		if (edge[4].down == 'r') // RDr
			sequence("RDr", solution);
		else if (edge[4].up == 'r') // bD2B
			sequence("bDDB", solution);
	}
	else if (position == 5) {
		if (edge[5].down == 'r') // dRDr
			sequence("dRDr", solution);
		else if (edge[5].up == 'r') // bDB
			sequence("bDB", solution);
	}
	else if (position == 6) {
		if (edge[6].down == 'r') // Rdr
			sequence("Rdr", solution);
		else if (edge[6].up == 'r') // dbDB
			sequence("dbDB", solution);
	}
	else if (position == 7) {
		if (edge[7].down == 'r') // RD2r
			sequence("RDDr", solution);
		else if (edge[7].up == 'r') // bdB
			sequence("bdB", solution);
	}
	else if (position == 8) {
		if (edge[8].down == 'r') // UrdRuRDr
			sequence("UrdRuRDr", solution);
		else if (edge[8].up == 'r') // UrdRubD2B
			sequence("UrdRubDDB", solution);
	}
	else if (position == 9) {
		if (edge[9].up == 'r') // bD2BRDr
			sequence("bDDBRDr", solution);
	}

	U(solution);
	position = searchCorner('w', 'o', 'g'); // White, orange and green
	if (position == 4) {
		if (corner[4].up == 'w') // rD2RFDf
			sequence("rDDRFDf", solution);
		else if (corner[4].right == 'w') // DrdR
			sequence("DrdR", solution);
		else if (corner[4].left == 'w') // rDR
			sequence("rDR", solution);
	}
	else if (position == 5) {
		if (corner[5].up == 'w') // rD2RDrdR
			sequence("rDDRDrdR", solution);
		else if (corner[5].right == 'w') // rdR
			sequence("rdR", solution);
		else if (corner[5].left == 'w') // FDf
			sequence("FDf", solution);
	}
	else if (position == 6) {
		if (corner[6].up == 'w') // FD2frdR
			sequence("FDDfrdR", solution);
		else if (corner[6].right == 'w') // Fdf
			sequence("Fdf", solution);
		else if (corner[6].left == 'w') // dFDf
			sequence("dFDf", solution);
	}
	else if (position == 7) {
		if (corner[7].up == 'w') // rdRFDf
			sequence("rdRFDf", solution);
		else if (corner[7].right == 'w') // FD2f
			sequence("FDDf", solution);
		else if (corner[7].left == 'w') // rD2R
			sequence("rDDR", solution);
	}
	else if (position == 1) {
		if (corner[1].left == 'w') // rDRFDf
			sequence("rDRFDf", solution);
		else if (corner[1].right == 'w') // rdRDrdR
			sequence("rdRDrdR", solution);
	}

	U(solution);
	position = searchEdge('g', 'r'); // Green/red
	if (position == 4) {
		if (edge[4].down == 'g') // drDRDFdf
			sequence("drDRDFdf", solution);
		else if (edge[4].up == 'g') // D2FdfdrDR
			sequence("DDFdfdrDR", solution);
	}
	else if (position == 5) {
		if (edge[5].down == 'g') // D2rDRDFdf
			sequence("DDrDRDFdf", solution);
		else if (edge[5].up == 'g') // DFdfdrDR
			sequence("DFdfdrDR", solution);
	}
	else if (position == 6) {
		if (edge[6].down == 'g') // DrDRDFdf
			sequence("DrDRDFdf", solution);
		else if (edge[6].up == 'g') // FdfdrDR
			sequence("FdfdrDR", solution);
	}
	else if (position == 7) {
		if (edge[7].down == 'g') // rDRDFdf
			sequence("rDRDFdf", solution);
		else if (edge[7].up == 'g') // dFdfdrDR
			sequence("dFdfdrDR", solution);
	}
	else if (position == 8) {
		if (edge[8].down == 'g') // rdRDFDfDrDRDFdf
			sequence("rdRDFDfDrDRDFdf", solution);
	}
}
void Rubik::thirdStep(vector<char>& solution) {
	yellowCross(solution);
	finalCorners(solution);
}
void Rubik::yellowCross(vector<char>& solution) {
	bool repeat;
	if ((edge[4].down == 'y') && (edge[5].down == 'y') &&
		(edge[6].down == 'y') && (edge[7].down == 'y')) 
		sequence("LDBdblfrdRDF", solution);
	else if ((edge[4].down == 'y') && (edge[5].down != 'y') &&
		(edge[6].down == 'y') && (edge[7].down != 'y')) 
		sequence("frdRDF", solution);
	else if ((edge[4].down != 'y') && (edge[5].down == 'y') &&
		(edge[6].down != 'y') && (edge[7].down == 'y')) 
		sequence("lfdFDL", solution);

	else if ((edge[4].down != 'y') && (edge[5].down != 'y') &&
		(edge[6].down == 'y') && (edge[7].down == 'y'))
		sequence("LDBdbl", solution);

	else if ((edge[4].down != 'y') && (edge[5].down == 'y') &&
		(edge[6].down == 'y') && (edge[7].down != 'y'))
		sequence("BDRdrb", solution);
	else if ((edge[4].down == 'y') && (edge[5].down == 'y') &&
		(edge[6].down != 'y') && (edge[7].down != 'y'))
		sequence("RDFdfr", solution);
	else if ((edge[4].down == 'y') && (edge[5].down != 'y') &&
		(edge[6].down != 'y') && (edge[7].down == 'y'))
		sequence("FDLdlf", solution);
	else {
		int yellows = 0;
		int whistleBlower1, whistleBlower2;
		for (int i = 0; i < 4; ++i) {
			if (edge[i].up == 'y') {
				yellows++;
				whistleBlower2 = i;
			}
			else
				whistleBlower1 = i;
		}
	}

	repeat = true;
	int contador = 0;
	while (repeat) {
		if ((edge[4].down == 'r') && (edge[5].down == 'g') &&
			(edge[6].down == 'b') && (edge[7].down == 'o')) { // bdBdbD2Bd
			sequence("bdBdbDDBd", solution);
			repeat = false;
		}
		else if ((edge[4].down == 'o') && (edge[5].down == 'r') &&
			(edge[6].down == 'b') && (edge[7].down == 'g')) { 	// rdRdrD2Rd
			sequence("rdRdrDDRd", solution);
			repeat = false;
		}
		else if ((edge[4].down == 'g') && (edge[5].down == 'r') &&
			(edge[6].down == 'o') && (edge[7].down == 'b')) { // fdFdfD2F
			sequence("fdFdfDDFd", solution);
			repeat = false;
		}
		else if ((edge[4].down == 'g') && (edge[5].down == 'b') &&
			(edge[6].down == 'r') && (edge[7].down == 'o')) { 	// ldLdlD2Ld
			sequence("ldLdlDDLd", solution);
			repeat = false;
		}
		else if ((edge[4].down == 'b') && (edge[5].down == 'r') &&
			(edge[6].down == 'g') && (edge[7].down == 'o')) { 	// rdRdrD2RD2 && bdBdbD2B
			sequence("rdRdrDDRDDbdBdbDDBd", solution);
			repeat = false;
		}
		else if ((edge[4].down == 'g') && (edge[5].down == 'o') &&
			(edge[6].down == 'b') && (edge[7].down == 'r')) { 	// rdRdrD2R && fdFdfD2Fd
			sequence("rdRdrDDRfdFdfDDFd", solution);
			repeat = false;
		}
		else if ((edge[4].down == 'y') && (edge[5].down == 'y') &&
			(edge[6].down == 'y') && (edge[7].down == 'y')) {
			sequence("RldRldRldRldRldRldRldRld", solution);
			repeat = false;
		}
		else if ((edge[4].down == 'g') && (edge[5].down == 'r') &&
			(edge[6].down == 'b') && (edge[7].down == 'o'))
			repeat = false;
		else {
			D(solution);
			++contador;
			if (contador == 5) { // bdBdbD2Bd
				contador = 0;
				sequence("bdBdbDDBd", solution);
				return;
			}
		}
	} 
}
void Rubik::finalCorners(vector<char>& solution) {
	permutationFinalCorners(solution);
	positionFinalCorners(solution);
}
void Rubik::permutationFinalCorners(vector<char>& solution) {
	bool repeat = true;
	while (repeat) {
		if (searchCorner('y', 'o', 'g') == 4) {
			if (searchCorner('y', 'r', 'b') == 5) // rDLdRDld
				sequence("rDLdRDld", solution);
			else if (searchCorner('y', 'r', 'b') == 7) // BdfDbdFD
				sequence("BdfDbdFD", solution);

			repeat = false;
		}
		else if (searchCorner('y', 'g', 'r') == 5) {
			if (searchCorner('y', 'r', 'b') == 4) // bDFdBDfd
				sequence("bDFdBDfd", solution);
			else if (searchCorner('y', 'r', 'b') == 7) // LdrDldRD
				sequence("LdrDldRD", solution);

			repeat = false;
		}
		else if (searchCorner('y', 'b', 'o') == 7) {
			if (searchCorner('y', 'r', 'b') == 4) // RdlDrdLD
				sequence("RdlDrdLD", solution);
			else if (searchCorner('y', 'r', 'b') == 5) // fDBdFDbd
				sequence("fDBdFDbd", solution);

			repeat = false;
		}
		else if (searchCorner('y', 'r', 'b') == 6) {
			if (searchCorner('y', 'o', 'g') == 5) // FdbDfdBD
				sequence("FdbDfdBD", solution);
			else if (searchCorner('y', 'o', 'g') == 7) // lDRdLDrd
				sequence("lDRdLDrd", solution);

			repeat = false;
		}
		else // LdrDldRD
			sequence("LdrDldRD", solution);
	}
}
void Rubik::positionFinalCorners(vector<char>& solution) {

	if ((corner[4].up == 'y') && (corner[5].right == 'y') &&
		(corner[7].up == 'y') && (corner[6].left == 'y')) // RD2rdRdrlD2LDlDL
		sequence("RDDrdRdrlDDLDlDL", solution);
	else if ((corner[4].left == 'y') && (corner[5].up == 'y') &&
		(corner[7].right == 'y') && (corner[6].up == 'y')) // LD2ldLdlrD2RDrDR
		sequence("LDDldLdlrDDRDrDR", solution);
	else if ((corner[4].left == 'y') && (corner[5].right == 'y') &&
		(corner[7].right == 'y') && (corner[6].left == 'y')) // RD2rdRdrlD2LDlDL LD2ldLdlrD2RDrDR
		sequence("RDDrdRdrlDDLDlDLLDDldLdlrDDRDrDR", solution);
	else if ((corner[4].right == 'y') && (corner[5].left == 'y') &&
		(corner[7].up == 'y') && (corner[6].up == 'y')) // FD2fdFdfbD2BDbDB
		sequence("FDDfdFdfbDDBDbDB", solution);
	else if ((corner[4].up == 'y') && (corner[5].up == 'y') &&
		(corner[7].left == 'y') && (corner[6].right == 'y')) // BD2bdBdbfD2FDfDF
		sequence("BDDbdBdbfDDFDfDF", solution);
	else if ((corner[4].right == 'y') && (corner[5].left == 'y') && //
		(corner[7].left == 'y') && (corner[6].right == 'y')) // FD2fdFdfbD2BDbDB BD2bdBdbfD2FDfDF
		sequence("FDDfdFdfbDDBDbDBBDDbdBdbfDDFDfDF", solution);
	else if ((corner[4].up == 'y') && (corner[5].left == 'y') &&
		(corner[7].up == 'y') && (corner[6].right == 'y')) // ldLdlD2LRDrDRD2r
		sequence("ldLdlDDLRDrDRDDr", solution);
	else if ((corner[4].right == 'y') && (corner[5].up == 'y') &&
		(corner[7].left == 'y') && (corner[6].up == 'y')) // rdRdrD2RLDlDLD2l
		sequence("rdRdrDDRLDlDLDDl", solution);
	else if ((corner[4].up == 'y') && (corner[5].up == 'y') &&
		(corner[7].right == 'y') && (corner[6].left == 'y')) // fdFdfD2FBDbDBD2b
		sequence("fdFdfDDFBDbDBDDb", solution);
	else if ((corner[4].left == 'y') && (corner[5].right == 'y') &&
		(corner[7].up == 'y') && (corner[6].up == 'y')) // bdBdbD2BFDfDFD2f
		sequence("bdBdbDDBFDfDFDDf", solution);
	else if ((corner[4].left == 'y') && (corner[5].right == 'y') &&
		(corner[7].right == 'y') && (corner[6].left == 'y')) // fdFdfD2FBDbDBD2b bdBdbD2BFDfDFD2f
		sequence("fdFdfDDFBDbDBDDbbdBdbDDBFDfDFDDf", solution);
	else if ((corner[4].right == 'y') && (corner[5].left == 'y') &&
		(corner[7].right == 'y') && (corner[6].left == 'y')) // FD2fdFdfbD2BDbDB fdFdfD2FBDbDBD2b
		sequence("FDDfdFdfbDDBDbDBfdFdfDDFBDbDBDDb", solution);
	else if ((corner[4].left == 'y') && (corner[5].right == 'y') &&
		(corner[7].left == 'y') && (corner[6].right == 'y')) // bdBdbD2BFDfDFD2f BD2bdBdbfD2FDfDF
		sequence("bdBdbDDBFDfDFDDfBDDbdBdbfDDFDfDF", solution);
	else if ((corner[4].right == 'y') && (corner[5].right == 'y') &&
		(corner[7].left == 'y') && (corner[6].left == 'y')) // rdRdrD2RLDlDLD2l RD2rdRdrlD2LDlDL
		sequence("rdRdrDDRLDlDLDDlRDDrdRdrlDDLDlDL", solution);
	else if ((corner[4].left == 'y') && (corner[5].left == 'y') &&
		(corner[7].right == 'y') && (corner[6].right == 'y')) // LD2ldLdlrD2RDrDR ldLdlD2LRDrDRD2r
		sequence("LDDldLdlrDDRDrDRldLdlDDLRDrDRDDr", solution);


	int yellows = 0;
	for (int i = 0; i<4; i++) {
		if (corner[4 + i].up == 'y')
			++yellows;
	}
	if (yellows == 1) {
		if (corner[4].up == 'y') {
			if (corner[5].right == 'y') // RUruRUrudRUruRUrudRUruRUruD2
				sequence("RUruRUrudRUruRUrudRUruRUruDD", solution);
			else if (corner[5].left == 'y') // fuFUfuFUdfuFUfuFUdfuFUfuFUD2
				sequence("fuFUfuFUdfuFUfuFUd fuFUfuFUDD", solution);
		}
		else if (corner[5].up == 'y') {
			if (corner[4].right == 'y') // FUfuFUfuDFUfuFUfuDFUfuFUfuD2
				sequence("FUfuFUfuDFUfuFUfuDFUfuFUfuDD", solution);
			else if (corner[4].left == 'y') // luLUluLUDluLUluLUDluLUluLUD2
				sequence("luLUluLUDluLUluLUDluLUluLUDD", solution);
		}
		else if (corner[6].up == 'y') {
			if (corner[5].right == 'y') // RUruRUruDRUruRUruDRUruRUruD2
				sequence("RUruRUruDRUruRUruDRUruRUruDD", solution);
			else if (corner[5].left == 'y') // fuFUfuFUDfuFUfuF UDfuFUfuFUD2
				sequence("fuFUfuFUDfuFUfuFUDfuFUfuFUDD", solution);
		}
		else if (corner[7].up == 'y') {
			if (corner[5].right == 'y') // RUruRUruDRUruRUruD2RUruRUruD
				sequence("RUruRUruDRUruRUruDDRUruRUruD", solution);
			else if (corner[5].left == 'y') // fuFUfuFUDfuFUfuFUD2fuFUfuFUD
				sequence("fuFUfuFUDfuFUfuFUDDfuFUfuFUD", solution);
		}
	}
	else if (yellows == 2) {
		if ((corner[4].up != 'y') && (corner[6].up != 'y')) {
			if (corner[4].left == 'y') // luLUluLUD2luLUluLUluLUluLUD2
				sequence("luLUluLUDDluLUluLUluLUluLUDD", solution);
			else if (corner[4].right == 'y') // luLUluLUluLUluLUD2 luLUluLUD2
				sequence("luLUluLUluLUluLUDDluLUluLUDD", solution);
		}
		else if ((corner[5].up != 'y') && (corner[7].up != 'y')) {
			if (corner[5].left == 'y') // fuFUfuFUD2fuFUfuFUfuFUfuFUD2
				sequence("fuFUfuFUDDfuFUfuFUfuFUfuFUDD", solution);
			else if (corner[5].right == 'y') // fuFUfuFUfuFUf uFUD2fuFUfuFUD2
				sequence("fuFUfuFUfuFUfuFUDDfuFUfuFUDD", solution);
		}
	}
}
bool Rubik::isSolved() const {
	bool success;
	if ((corner[3].up == 'w') &&
		(edge[2].up == 'w') &&
		(corner[2].up == 'w') &&
		(edge[3].up == 'w') &&
		(center[0].center == 'w') &&
		(edge[1].up == 'w') &&
		(corner[0].up == 'w') &&
		(edge[0].up == 'w') &&
		(corner[1].up == 'w') &&

		(corner[3].right == 'o') &&
		(edge[3].down == 'o') &&
		(corner[0].left == 'o') &&
		(edge[10].down == 'o') &&
		(center[4].center == 'o') &&
		(edge[11].down == 'o') &&
		(corner[7].right == 'o') &&
		(edge[7].down == 'o') &&
		(corner[4].left == 'o') &&

		(corner[0].right == 'g') &&
		(edge[0].down == 'g') &&
		(corner[1].left == 'g') &&
		(edge[11].up == 'g') &&
		(center[1].center == 'g') &&
		(edge[8].up == 'g') &&
		(corner[4].right == 'g') &&
		(edge[4].down == 'g') &&
		(corner[5].left == 'g') &&

		(corner[1].right == 'r') &&
		(edge[1].down == 'r') &&
		(corner[2].left == 'r') &&
		(edge[8].down == 'r') &&
		(center[2].center == 'r') &&
		(edge[9].down == 'r') &&
		(corner[5].right == 'r') &&
		(edge[5].down == 'r') &&
		(corner[6].left == 'r') &&

		(corner[2].right == 'b') &&
		(edge[2].down == 'b') &&
		(corner[3].left == 'b') &&
		(edge[9].up == 'b') &&
		(center[3].center == 'b') &&
		(edge[10].up == 'b') &&
		(corner[6].right == 'b') &&
		(edge[6].down == 'b') &&
		(corner[7].left == 'b'))
		success = true;
	else
		success = false;

	return success;
}
void Rubik::R(vector<char>& solution) {
	Corner aux;
	Edge laux;

	laux = edge[1];
	edge[1] = edge[8];
	edge[8] = edge[5];
	edge[5] = edge[9];
	edge[9] = laux;

	aux.left = corner[1].right;
	aux.right = corner[1].up;
	aux.up = corner[1].left;

	corner[1].left = corner[5].up;
	corner[1].right = corner[5].right;
	corner[1].up = corner[5].left;

	corner[5].left = corner[6].up;
	corner[5].right = corner[6].left;
	corner[5].up = corner[6].right;

	corner[6].left = corner[2].left;
	corner[6].right = corner[2].up;
	corner[6].up = corner[2].right;

	corner[2] = aux;
	solution.push_back('R');
}
void Rubik::R2(vector<char>& solution) {
	R(solution);
	R(solution);
}
void Rubik::r(vector<char>& solution) {
	Corner aux;
	Edge laux;

	laux = edge[1];
	edge[1] = edge[9];
	edge[9] = edge[5];
	edge[5] = edge[8];
	edge[8] = laux;

	aux.left = corner[1].up;
	aux.right = corner[1].right;
	aux.up = corner[1].left;

	corner[1].left = corner[2].up;
	corner[1].right = corner[2].left;
	corner[1].up = corner[2].right;

	corner[2].left = corner[6].left;
	corner[2].right = corner[6].up;
	corner[2].up = corner[6].right;

	corner[6].left = corner[5].right;
	corner[6].right = corner[5].up;
	corner[6].up = corner[5].left;

	corner[5] = aux;
	solution.push_back('r');
}
void Rubik::L(vector<char>& solution) {
	Corner aux;
	Edge laux;

	laux = edge[3];
	edge[3] = edge[10];
	edge[10] = edge[7];
	edge[7] = edge[11];
	edge[11] = laux;

	aux.left = corner[0].left;
	aux.right = corner[0].up;
	aux.up = corner[0].right;

	corner[0].left = corner[3].right;
	corner[0].right = corner[3].up;
	corner[0].up = corner[3].left;

	corner[3].left = corner[7].up;
	corner[3].right = corner[7].right;
	corner[3].up = corner[7].left;

	corner[7].left = corner[4].up;
	corner[7].right = corner[4].left;
	corner[7].up = corner[4].right;

	corner[4] = aux;
	solution.push_back('L');
}
void Rubik::L2(vector<char>& solution) {
	L(solution);
	L(solution);
}
void Rubik::l(vector<char>& solution) {
	Corner aux;
	Edge laux;

	laux = edge[3];
	edge[3] = edge[11];
	edge[11] = edge[7];
	edge[7] = edge[10];
	edge[10] = laux;

	aux.left = corner[0].up;
	aux.right = corner[0].left;
	aux.up = corner[0].right;

	corner[0].left = corner[4].left;
	corner[0].right = corner[4].up;
	corner[0].up = corner[4].right;

	corner[4].left = corner[7].right;
	corner[4].right = corner[7].up;
	corner[4].up = corner[7].left;

	corner[7].left = corner[3].up;
	corner[7].right = corner[3].right;
	corner[7].up = corner[3].left;

	corner[3] = aux;
	solution.push_back('l');
}
void Rubik::D(vector<char>& solution) {
	Corner aux;
	Edge laux;

	laux = edge[4];
	edge[4] = edge[7];
	edge[7] = edge[6];
	edge[6] = edge[5];
	edge[5] = laux;

	aux = corner[5];
	corner[5] = corner[4];
	corner[4] = corner[7];
	corner[7] = corner[6];
	corner[6] = aux;
	solution.push_back('D');
}
void Rubik::D2(vector<char>& solution) {
	D(solution);
	D(solution);
}
void Rubik::d(vector<char>& solution) {
	Corner aux;
	Edge laux;

	laux = edge[4];
	edge[4] = edge[5];
	edge[5] = edge[6];
	edge[6] = edge[7];
	edge[7] = laux;

	aux = corner[5];
	corner[5] = corner[6];
	corner[6] = corner[7];
	corner[7] = corner[4];
	corner[4] = aux;
	solution.push_back('d');
}
void Rubik::U(vector<char>& solution) {
	Corner aux;
	Edge laux;

	laux = edge[0];
	edge[0] = edge[1];
	edge[1] = edge[2];
	edge[2] = edge[3];
	edge[3] = laux;

	aux = corner[0];
	corner[0] = corner[1];
	corner[1] = corner[2];
	corner[2] = corner[3];
	corner[3] = aux;
	solution.push_back('U');
}
void Rubik::U2(vector<char>& solution) {
	U(solution);
	U(solution);
}
void Rubik::u(vector<char>& solution) {
	Corner aux;
	Edge laux;

	laux = edge[0];
	edge[0] = edge[3];
	edge[3] = edge[2];
	edge[2] = edge[1];
	edge[1] = laux;

	aux = corner[1];
	corner[1] = corner[0];
	corner[0] = corner[3];
	corner[3] = corner[2];
	corner[2] = aux;
	solution.push_back('u');
}
void Rubik::F(vector<char>& solution) {
	Corner aux;
	Edge laux;

	laux.down = edge[0].up;
	laux.up = edge[0].down;
	edge[0].up = edge[11].down;
	edge[0].down = edge[11].up;
	edge[11].up = edge[4].down;
	edge[11].down = edge[4].up;
	edge[4].up = edge[8].down;
	edge[4].down = edge[8].up;
	edge[8] = laux;

	aux.left = corner[1].left;
	aux.right = corner[1].up;
	aux.up = corner[1].right;

	corner[1].left = corner[0].right;
	corner[1].right = corner[0].up;
	corner[1].up = corner[0].left;

	corner[0].left = corner[4].up;
	corner[0].right = corner[4].right;
	corner[0].up = corner[4].left;

	corner[4].left = corner[5].up;
	corner[4].right = corner[5].left;
	corner[4].up = corner[5].right;

	corner[5] = aux;
	solution.push_back('F');
}
void Rubik::F2(vector<char>& solution) {
	F(solution);
	F(solution);
}
void Rubik::f(vector<char>& solution) {
	Corner aux;
	Edge laux;

	laux.up = edge[8].down;
	laux.down = edge[8].up;
	edge[8].up = edge[4].down;
	edge[8].down = edge[4].up;
	edge[4].up = edge[11].down;
	edge[4].down = edge[11].up;
	edge[11].up = edge[0].down;
	edge[11].down = edge[0].up;
	edge[0] = laux;

	aux.left = corner[1].up;
	aux.right = corner[1].left;
	aux.up = corner[1].right;

	corner[1].left = corner[5].left;
	corner[1].right = corner[5].up;
	corner[1].up = corner[5].right;

	corner[5].left = corner[4].right;
	corner[5].right = corner[4].up;
	corner[5].up = corner[4].left;

	corner[4].left = corner[0].up;
	corner[4].right = corner[0].right;
	corner[4].up = corner[0].left;

	corner[0] = aux;
	solution.push_back('f');
}
void Rubik::B(vector<char>& solution) {
	Corner aux;
	Edge laux;

	laux.up = edge[9].down;
	laux.down = edge[9].up;
	edge[9].up = edge[6].down;
	edge[9].down = edge[6].up;
	edge[6].up = edge[10].down;
	edge[6].down = edge[10].up;
	edge[10].up = edge[2].down;
	edge[10].down = edge[2].up;
	edge[2] = laux;

	aux.left = corner[2].right;
	aux.right = corner[2].up;
	aux.up = corner[2].left;

	corner[2].left = corner[6].up;
	corner[2].right = corner[6].right;
	corner[2].up = corner[6].left;

	corner[6].left = corner[7].up;
	corner[6].right = corner[7].left;
	corner[6].up = corner[7].right;

	corner[7].left = corner[3].left;
	corner[7].right = corner[3].up;
	corner[7].up = corner[3].right;

	corner[3] = aux;
	solution.push_back('B');
}
void Rubik::B2(vector<char>& solution) {
	B(solution);
	B(solution);
}
void Rubik::b(vector<char>& solution) {
	Corner aux;
	Edge laux;

	laux.up = edge[10].down;
	laux.down = edge[10].up;
	edge[10].up = edge[6].down;
	edge[10].down = edge[6].up;
	edge[6].up = edge[9].down;
	edge[6].down = edge[9].up;
	edge[9].up = edge[2].down;
	edge[9].down = edge[2].up;
	edge[2] = laux;

	aux.left = corner[3].up;
	aux.right = corner[3].left;
	aux.up = corner[3].right;

	corner[3].left = corner[7].left;
	corner[3].right = corner[7].up;
	corner[3].up = corner[7].right;

	corner[7].left = corner[6].right;
	corner[7].right = corner[6].up;
	corner[7].up = corner[6].left;

	corner[6].left = corner[2].up;
	corner[6].right = corner[2].right;
	corner[6].up = corner[2].left;

	corner[2] = aux;
	solution.push_back('b');
}
void Rubik::solve(vector<char>& solution) {
	solution.clear();
	firstStep(solution); 
	secondStep(solution); 
	thirdStep(solution); 
	}
void Rubik::exportSolution(std::ostream& os) const {
	vector<char> solution;
	Rubik aux = *this;
	aux.solve(solution);

	for (unsigned int i = 0; i<solution.size(); ++i)
		os << solution[i];
}
void Rubik::readRubik(char(&buff)[56]) {

	int i=0;
	corner[3].up = buff[i++];
	edge[2].up = buff[i++];
	corner[2].up = buff[i++];
	edge[3].up = buff[i++];
	center[0].center = buff[i++];
	edge[1].up = buff[i++];
	corner[0].up = buff[i++];
	edge[0].up = buff[i++];
	corner[1].up = buff[i++];

	corner[3].right = buff[i++];
	edge[3].down = buff[i++];
	corner[0].left = buff[i++];
	edge[10].down = buff[i++];
	center[4].center = buff[i++];
	edge[11].down = buff[i++];
	corner[7].right = buff[i++];
	edge[7].down = buff[i++];
	corner[4].left = buff[i++];

	corner[0].right = buff[i++];
	edge[0].down = buff[i++];
	corner[1].left = buff[i++];
	edge[11].up = buff[i++];
	center[1].center = buff[i++];
	edge[8].up = buff[i++];
	corner[4].right = buff[i++];
	edge[4].down = buff[i++];
	corner[5].left = buff[i++];

	corner[1].right = buff[i++];
	edge[1].down = buff[i++];
	corner[2].left = buff[i++];
	edge[8].down = buff[i++];
	center[2].center = buff[i++];
	edge[9].down = buff[i++];
	corner[5].right = buff[i++];
	edge[5].down = buff[i++];
	corner[6].left = buff[i++];

	corner[2].right = buff[i++];
	edge[2].down = buff[i++];
	corner[3].left = buff[i++];
	edge[9].up = buff[i++];
	center[3].center = buff[i++];
	edge[10].up = buff[i++];
	corner[6].right = buff[i++];
	edge[6].down = buff[i++];
	corner[7].left = buff[i++];

	corner[4].up = buff[i++];
	edge[4].up = buff[i++];
	corner[5].up = buff[i++];
	edge[7].up = buff[i++];
	center[5].center = buff[i++];
	edge[5].up = buff[i++];
	corner[7].up = buff[i++];
	edge[6].up = buff[i++];
	corner[6].up = buff[i++];
}
Center Rubik::getCenter(const int& position) const {
	Center ret;
	ret.center = 'f';

	if (position >= 0 && position < 6)
		ret.center = center[position].center;

	return ret;
}
Edge Rubik::getEdge(const int& position) const {
	Edge ret;
	ret.up = ret.down = 'f';

	if (position >= 0 && position < 12) {
		ret.up = edge[position].up;
		ret.down = edge[position].down;
	}

	return ret;
}
Corner Rubik::getCorner(const int& position) const {
	Corner ret;
	ret.up = ret.left = ret.right = 'f';

	if (position >= 0 && position < 8) {
		ret.up = corner[position].up;
		ret.left = corner[position].left;
		ret.right = corner[position].right;
	}

	return ret;
}


bool test(std::istream& is, char (*buff)) {
	
	is.getline(buff, 56);
	bool rez = true;
	int c=0;
	if (buff[56]) rez = false;
	//cout << rez;
	for (int i = 0; i < 54; i++) {
		if (buff[i] == 'w') c = c + 100000;
		if (buff[i] == 'b') c = c + 10000;
		if (buff[i] == 'r') c = c + 1000;
		if (buff[i] == 'o') c = c + 100;
		if (buff[i] == 'y') c = c + 10;
		if (buff[i] == 'g') c = c + 1;
		
	}

	if (c != 999999) rez = false;

	return rez;
}


int main(int argc, char* argv[]) {
	Rubik rubik;
	char buff[56] = { "" };
	vector<char> solution;
	ifstream fin;
	ofstream fout;
	fin.open(argv[1]);
	fout.open(argv[2]);

	if (test(fin, buff) == false) {
		fout << "error";
		fin.close();
		fout.close();
		return 0;
	}

	fin.close();
	rubik.readRubik(buff);
	rubik.solve(solution);

	if (rubik.isSolved() == false) {
		fout << "error";
		fout.close();
		return 0;
	}

	for (int i = 0; i < solution.size(); i++) {
		fout << solution[i];
	}

	return 0;
}

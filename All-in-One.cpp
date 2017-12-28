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

void Rubik::getBuff(char(&buff)[55]) {
	for (int i = 0; i < 54; i++) {
		Buff[i] = buff[i];
	}
}

int Rubik::searchEdge(const char& ar, const char& ab) const {
	int position = 0;
	int u[] = { 7,5,1,3,46,50,52,48,23,39,41,21 };
	int d[] = { 19,28,37,10,25,34,43,16,30,32,12,14 };

	for (int i = 0; i < 12; i++) {
		if ((Buff[u[i]] == ar && Buff[d[i]] == ab) || (Buff[u[i]] == ab && Buff[d[i]] == ar))
				position = i;
	}
	return position;
}

int Rubik::searchCorner(const char& a, const char& iz, const char& de) const {
	int position = 0;
	int u[] = { 6,8,2,0,45,47,53,51 };
	int l[] = { 11,20,29,38,17,26,35,44 };
	int r[] = { 18,27,36,9,24,33,42,15 };
		
	for (int i = 0; i < 8; i++) {
		if (((Buff[u[i]] == a) && (Buff[l[i]] == iz) && (Buff[r[i]] == de)) ||
			((Buff[u[i]] == a) && (Buff[l[i]] == de) && (Buff[r[i]] == iz)) ||
			((Buff[u[i]] == iz) && (Buff[l[i]] == a) && (Buff[r[i]] == de)) ||
			((Buff[u[i]] == de) && (Buff[l[i]] == iz) && (Buff[r[i]] == a)) ||
			((Buff[u[i]] == de) && (Buff[l[i]] == a) && (Buff[r[i]] == iz)) ||
			((Buff[u[i]] == iz) && (Buff[l[i]] == de) && (Buff[r[i]] == a)))
				position = i;
	}
	return position;
}

void Rubik::sequence(const string& sec, vector<char>& solution) {
	char h;

	for (unsigned int i = 0; i<sec.size(); ++i) {
		if (sec == "") return;
		h = sec[i];
		Rotate(solution, h);
	}
}

void Rubik::whiteCross(vector<char>& solution) {
	


	int position = searchEdge('w', 'g'); // White, green.


	if (position == 0) {
		if (Buff[19] == 'w') // FuRU
			sequence("FuRU", solution);
	}
	else if (position == 1) {
		if (Buff[5] == 'w') // ruRU
			sequence("ruRU", solution);
		else // rf
			sequence("rf", solution);
	}
	else if (position == 2) {
		if (Buff[1] == 'w') // U2
			sequence("UU", solution);
		else // burU
			sequence("burU", solution);
	}
	else if (position == 3) {
		if (Buff[3] == 'w') // LUlu
			sequence("LUlu", solution);
		else // LF
			sequence("LF", solution);
	}
	else if (position == 4) {
		if (Buff[46] == 'w') // F2
			sequence("FF", solution);
		else // fuRU
			sequence("fuRU", solution);
	}
	else if (position == 5) {
		if (Buff[50] == 'w') // dF2
			sequence("dFF", solution);
		else // Rf
			sequence("Rf", solution);
	}
	else if (position == 6) {
		if (Buff[52] == 'w') // D2F2
			sequence("DDFF", solution);
		else // dRf
			sequence("dRf", solution);
	}
	else if (position == 7) {
		if (Buff[48] == 'w') // DF2
			sequence("DFF", solution);
		else // lF
			sequence("lF", solution);
	}
	else if (position == 8) {
		if (Buff[23] == 'w') // uRU
			sequence("uRU", solution);
		else // f
			sequence("f", solution);
	}
	else if (position == 9) {
		if (Buff[39] == 'w') // urU
			sequence("urU", solution);
		else // U2BU2
			sequence("UUBUU", solution);
	}
	else if (position == 10) {
		if (Buff[41] == 'w') // ULu
			sequence("ULu", solution);
		else // U2bU2
			sequence("UUbUU", solution);
	}
	else if (position == 11) {
		if (Buff[21] == 'w') // Ulu
			sequence("Ulu", solution);
		else // F
			sequence("F", solution);
	}

	position = searchEdge('w', 'r'); // White/red
	if (position == 1) {
		if (Buff[28] == 'w') // rUfu
			sequence("rUfu", solution);
	}
	else if (position == 2) {
		if (Buff[1] == 'w') // buBU
			sequence("buBU", solution);
		else // br
			sequence("br", solution);
	}
	else if (position == 3) {
		if (Buff[3] == 'w') // L2D2R2
			sequence("LLDDRR", solution);
		else // LUFu
			sequence("LUFu", solution);
	}
	else if (position == 4) {
		if (Buff[46] == 'w') // DR2
			sequence("DRR", solution);
		else // fRF
			sequence("fRF", solution);
	}
	else if (position == 5) {
		if (Buff[50] == 'w') // R2
			sequence("RR", solution);
		else // RUfu
			sequence("RUfu", solution);
	}
	else if (position == 6) {
		if (Buff[52] == 'w') // dR2
			sequence("dRR", solution);
		else // Br
			sequence("Br", solution);
	}
	else if (position == 7) {
		if (Buff[48] == 'w') // D2R2
			sequence("DDRR", solution);
		else // lUFu
			sequence("lUFu", solution);
	}
	else if (position == 8) {
		if (Buff[23] == 'w') // R
			sequence("R", solution);
		else // Ufu
			sequence("Ufu", solution);
	}
	else if (position == 9) {
		if (Buff[39] == 'w') // r
			sequence("r", solution);
		else // uBU
			sequence("uBU", solution);
	}
	else if (position == 10) {
		if (Buff[41] == 'w') // U2LU2
			sequence("UULUU", solution);
		else // ubU
			sequence("ubU", solution);
	}
	else if (position == 11) {
		if (Buff[21] == 'w') // U2lU2
			sequence("UUlUU", solution);
		else // UFu
			sequence("UFu", solution);
	}


	position = searchEdge('w', 'b'); // White/blue
	if (position == 2) {
		if (Buff[37] == 'w') // bUru
			sequence("bUru", solution);
	}
	else if (position == 3) {
		if (Buff[3] == 'w') // LulU
			sequence("LulU", solution);
		else // lb
			sequence("lb", solution);
	}
	else if (position == 4) {
		if (Buff[46] == 'w') // D2B2
			sequence("DDBB", solution);
		else // uFlU
			sequence("uFlU", solution);
	}
	else if (position == 5) {
		if (Buff[50] == 'w') // DB2
			sequence("DBB", solution);
		else // rBR
			sequence("rBR", solution);
	}
	else if (position == 6) {
		if (Buff[52] == 'w') // B2
			sequence("BB", solution);
		else // BUru
			sequence("BUru", solution);
	}
	else if (position == 7) {
		if (Buff[48] == 'w') // dB2
			sequence("dBB", solution);
		else // Lb
			sequence("Lb", solution);
	}
	else if (position == 8) {
		if (Buff[23] == 'w') // URu
			sequence("URu", solution);
		else // U2fU2
			sequence("UUfUU", solution);
	}
	else if (position == 9) {
		if (Buff[39] == 'w') // Uru
			sequence("Uru", solution);
		else // B
			sequence("B", solution);
	}
	else if (position == 10) {
		if (Buff[41] == 'w') // uLU
			sequence("uLU", solution);
		else // b
			sequence("b", solution);
	}
	else if (position == 11) {
		if (Buff[21] == 'w') // ulU
			sequence("ulU", solution);
		else // U2FU2
			sequence("UUFUU", solution);
	}

	position = searchEdge('w', 'o'); // White/orange
	if (position == 3) {
		if (Buff[10] == 'w') // LuFU
			sequence("LuFU", solution);
	}
	else if (position == 4) {
		if (Buff[46] == 'w') // dL2
			sequence("dLL", solution);
		else // Flf
			sequence("Flf", solution);
	}
	else if (position == 5) {
		if (Buff[50] == 'w') // D2L2
			sequence("DDLL", solution);
		else // dFlf
			sequence("dFlf", solution);
	}
	else if (position == 6) {
		if (Buff[52] == 'w') // DL2
			sequence("DLL", solution);
		else // bLB
			sequence("bLB", solution);
	}
	else if (position == 7) {
		if (Buff[48] == 'w') // L2
			sequence("LL", solution);
		else // luFU
			sequence("luFU", solution);
	}
	else if (position == 8) {
		if (Buff[23] == 'w') // U2RU2
			sequence("UURUU", solution);
		else //ufU
			sequence("ufU", solution);
	}
	else if (position == 9) {
		if (Buff[39] == 'w') // U2rU2
			sequence("UUrUU", solution);
		else // UBu
			sequence("UBu", solution);
	}
	else if (position == 10) {
		if (Buff[41] == 'w') // L
			sequence("L", solution);
		else // Ubu
			sequence("Ubu", solution);
	}
	else if (position == 11) {
		if (Buff[21] == 'w') // l
			sequence("l", solution);
		else // uFU
			sequence("uFU", solution);
	}
	

}

void Rubik::cornersFirstStep(vector<char>& solution) {

	int position = searchCorner('w', 'g', 'r'); // White, green and red
	if (position == 0) {
		if (Buff[6] == 'w') // LDlrdR
			sequence("LDlrdR", solution);
		else if (Buff[18] == 'w') // LrD2lRFDf
			sequence("LrDDlRFDf", solution);
		else if (Buff[11] == 'w') // LrDlR
			sequence("LrDlR", solution);
	}
	else if (position == 1) {
		if (Buff[27] == 'w') // rdRDrdR
			sequence("rdRDrdR", solution);
		else if (Buff[20] == 'w') // rDRFDf
			sequence("rDRFDf", solution);
	}
	else if (position == 2) {
		if (Buff[2] == 'w') // bdBFDf
			sequence("bdBFDf", solution);
		else if (Buff[36] == 'w') // bFdBf
			sequence("bFdBf", solution);
		else if (Buff[29] == 'w') // bDBdFDf
			sequence("bDBdFDf", solution);
	}
	else if (position == 3) { // BD2brdR
		if (Buff[0] == 'w')
			sequence("BDDbrdR", solution);
		else if (Buff[9] == 'w') // lFD2fL
			sequence("lFDDfL", solution);
		else if (Buff[38] == 'w') // BrD2Rb
			sequence("BrDDRb", solution);
	}
	else if (position == 4) {
		if (Buff[45] == 'w') // rD2RFDf
			sequence("rDDRFDf", solution);
		else if (Buff[24] == 'w') // DrdR
			sequence("DrdR", solution);
		else if (Buff[17] == 'w') // rDR
			sequence("rDR", solution);
	}
	else if (position == 5) {
		if (Buff[47] == 'w') // rD2RDrdR
			sequence("rDDRDrdR", solution);
		else if (Buff[33] == 'w') // rdR
			sequence("rdR", solution);
		else if (Buff[26] == 'w') // FDf
			sequence("FDf", solution);
	}
	else if (position == 6) {
		if (Buff[53] == 'w') // FD2frdR
			sequence("FDDfrdR", solution);
		else if (Buff[42] == 'w') // Fdf
			sequence("Fdf", solution);
		else if (Buff[35] == 'w') // dFDf
			sequence("dFDf", solution);
	}
	else if (position == 7) {
		if (Buff[51] == 'w') // rdRFDf
			sequence("rdRFDf", solution);
		else if (Buff[15] == 'w') // FD2f
			sequence("FDDf", solution);
		else if (Buff[44] == 'w') // rD2R
			sequence("rDDR", solution);
	}


	position = searchCorner('w', 'r', 'b'); // White, red and blue
	if (position == 0) {
		if (Buff[6] == 'w') // LD2lbdB
			sequence("LDDlbdB", solution);
		else if (Buff[18] == 'w') // fRD2rF
			sequence("fRDDrF", solution);
		else if (Buff[11] == 'w') // LbD2Bl
			sequence("LbDDBl", solution);
	}
	else if (position == 2) {
		if (Buff[36] == 'w') // bdBDbdB
			sequence("bdBDbdB", solution);
		else if (Buff[29] == 'w') // bDBRDr
			sequence("bDBRDr", solution);
	}
	else if (position == 3) {
		if (Buff[0] == 'w') // BDbRD2r
			sequence("BDbRDDr", solution);
		else if (Buff[26] == 'w') // lRdLr
			sequence("lRdLr", solution);
		else if (Buff[38] == 'w') // BDB2D2B
			sequence("BDBBDDB", solution);
	}
	else if (position == 4) {
		if (Buff[45] == 'w') // bdBRDr
			sequence("bdBRDr", solution);
		else if (Buff[24] == 'w') // RD2r
			sequence("RDDr", solution);
		else if (Buff[17] == 'w') // bD2B
			sequence("bDDB", solution);
	}
	else if (position == 5) {
		if (Buff[47] == 'w') // bD2BRDr
			sequence("bDDBRDr", solution);
		else if (Buff[33] == 'w') // DbdB
			sequence("DbdB", solution);
		else if (Buff[26] == 'w') // bDB
			sequence("bDB", solution);
	}
	else if (position == 6) {
		if (Buff[53] == 'w') // bD2BDbdB
			sequence("bDDBDbdB", solution);
		else if (Buff[42] == 'w') // bdB
			sequence("bdB", solution);
		else if (Buff[35] == 'w') // RDr
			sequence("RDr", solution);
	}
	else if (position == 7) {
		if (Buff[51] == 'w') // RD2rbdB
			sequence("RDDrbdB", solution);
		else if (Buff[15] == 'w') // Rdr
			sequence("Rdr", solution);
		else if (Buff[44] == 'w') // dRDr
			sequence("dRDr", solution);
	}

	position = searchCorner('w', 'b', 'o'); // White, blue and orange
	if (position == 0) {
		if (Buff[6] == 'w') // fdFBDb
			sequence("fdFBDb", solution);
		else if (Buff[18] == 'w') // fBdFb
			sequence("fBdFb", solution);
		else if (Buff[11] == 'w') // fDFdBDb
			sequence("fDFdBDb", solution);
	}
	else if (position == 3) {
		if (Buff[9] == 'w') // BdbldL
			sequence("BdbldL", solution);
		else if (Buff[38] == 'w') // BDbdBDb
			sequence("BDbdBDb", solution);
	}
	else if (position == 4) {
		if (Buff[45] == 'w') // fBD2Fb
			sequence("fBDDFb", solution);
		else if (Buff[24] == 'w') // Bdb
			sequence("Bdb", solution);
		else if (Buff[17] == 'w') // dBDb
			sequence("dBDb", solution);
	}
	else if (position == 5) {
		if (Buff[47] == 'w') // LD2lBdb
			sequence("LDDlBdb", solution);
		else if (Buff[33] == 'w') // BD2b
			sequence("BDDb", solution);
		else if (Buff[26] == 'w') // lD2L
			sequence("lDDL", solution);
	}
	else if (position == 6) {
		if (Buff[53] == 'w') // lD2LBDb
			sequence("lDDLBDb", solution);
		else if (Buff[42] == 'w') // DldL
			sequence("DldL", solution);
		else if (Buff[35] == 'w') // lDL
			sequence("lDL", solution);
	}
	else if (position == 7) {
		if (Buff[51] == 'w') // BdblD2L
			sequence("BdblDDL", solution);
		else if (Buff[15] == 'w') // ldL --> DLdl
			sequence("DldL", solution);
		//sequence("DLdl", solution)
		else if (Buff[44] == 'w') // BDb
			sequence("BDb", solution);
	}
}

void Rubik::secondStep(vector<char>& solution) {

	int position = searchEdge('g', 'o'); // Green/orange
	if (position == 4) {
		if (Buff[25] == 'g') // dfDF
			sequence("dfDF", solution);
		else if (Buff[46] == 'g') // Ldl
			sequence("Ldl", solution);
	}
	else if (position == 5) {
		if (Buff[34] == 'g') // fdF
			sequence("fdF", solution);
		else if (Buff[50] == 'g') // LD2l
			sequence("LDDl", solution);
	}
	else if (position == 6) {
		if (Buff[52] == 'g') // LDl
			sequence("LDl", solution);
		else if (Buff[43] == 'g') // fD2F
			sequence("fDDF", solution);
	}
	else if (position == 7) {
		if (Buff[16] == 'g') // fDF
			sequence("fDF", solution);
		else if (Buff[48] == 'g') // DLdl
			sequence("DLdl", solution);
	}
	else if (position == 8) {
		if (Buff[30] == 'g') // urD2RUfDF
			sequence("urDDRUfDF", solution);
		else if (Buff[23] == 'g') // urdRULdl
			sequence("urdRULdl", solution);
	}
	else if (position == 9) {
		if (Buff[32] == 'g') // U2bdBU2LD2l
			sequence("UUbdBUULDDl", solution);
		else if (Buff[39] == 'g') // U2bDBU2fDF
			sequence("UUbDBUUfDF", solution);
	}
	else if (position == 10) {
		if (Buff[12] == 'g') // UBD2buLdl
			sequence("UBDDbuLdl", solution);
		else if (Buff[41] == 'g') // UBDbufDF
			sequence("UBDbufDF", solution);
	}
	else if (position == 11) {
		if (Buff[14] == 'g') // LDldfDF
			sequence("LDldfDF", solution);
	}

	sequence("U", solution);
	position = searchEdge('o', 'b'); // Orange/blue
	if (position == 4) {
		if (Buff[25] == 'o') // ldL
			sequence("ldL", solution);
		else if (Buff[46] == 'o') // BD2b
			sequence("BDDb", solution);
	}
	else if (position == 5) {
		if (Buff[34] == 'o') // lD2L
			sequence("lDDL", solution);
		else if (Buff[50] == 'o') // BDb
			sequence("BDb", solution);
	}
	else if (position == 6) {
		if (Buff[43] == 'o') // lDL
			sequence("lDL", solution);
		else if (Buff[52] == 'o') // DBdb
			sequence("DBdb", solution);
	}
	else if (position == 7) {
		if (Buff[16] == 'o') // DldL
			sequence("DldL", solution);
		else if (Buff[48] == 'o') // Bdb
			sequence("Bdb", solution);
	}
	else if (position == 8) {
		if (Buff[30] == 'o') // U2rDRU2lDL
			sequence("UUrDRUUlDL", solution);
		else if (Buff[23] == 'o') // U2rD2RU2Bdb
			sequence("UUrDDRUUBdb", solution);
	}
	else if (position == 9) {
		if (Buff[32] == 'o') // URDrulDL
			sequence("URDrulDL", solution);
		else if (Buff[39] == 'o') // URD2ruBdb
			sequence("URDDruBdb", solution);
	}
	else if (position == 10) {
		if (Buff[41] == 'o') // BDbdlDL
			sequence("BDbdlDL", solution);
	}

	sequence("U", solution); 
	position = searchEdge('r', 'b'); // Blue/red
	if (position == 4) {
		if (Buff[25] == 'r') // RDr
			sequence("RDr", solution);
		else if (Buff[46] == 'r') // bD2B
			sequence("bDDB", solution);
	}
	else if (position == 5) {
		if (Buff[34] == 'r') // dRDr
			sequence("dRDr", solution);
		else if (Buff[50] == 'r') // bDB
			sequence("bDB", solution);
	}
	else if (position == 6) {
		if (Buff[43] == 'r') // Rdr
			sequence("Rdr", solution);
		else if (Buff[52] == 'r') // dbDB
			sequence("dbDB", solution);
	}
	else if (position == 7) {
		if (Buff[16] == 'r') // RD2r
			sequence("RDDr", solution);
		else if (Buff[48] == 'r') // bdB
			sequence("bdB", solution);
	}
	else if (position == 8) {
		if (Buff[30] == 'r') // UrdRuRDr
			sequence("UrdRuRDr", solution);
		else if (Buff[23] == 'r') // UrdRubD2B
			sequence("UrdRubDDB", solution);
	}
	else if (position == 9) {
		if (Buff[39] == 'r') // bD2BRDr
			sequence("bDDBRDr", solution);
	}

	sequence("U", solution);
	position = searchCorner('w', 'o', 'g'); // White, orange and green
	if (position == 4) {
		if (Buff[45] == 'w') // rD2RFDf
			sequence("rDDRFDf", solution);
		else if (Buff[24] == 'w') // DrdR
			sequence("DrdR", solution);
		else if (Buff[17] == 'w') // rDR
			sequence("rDR", solution);
	}
	else if (position == 5) {
		if (Buff[47] == 'w') // rD2RDrdR
			sequence("rDDRDrdR", solution);
		else if (Buff[33] == 'w') // rdR
			sequence("rdR", solution);
		else if (Buff[26] == 'w') // FDf
			sequence("FDf", solution);
	}
	else if (position == 6) {
		if (Buff[53] == 'w') // FD2frdR
			sequence("FDDfrdR", solution);
		else if (Buff[42] == 'w') // Fdf
			sequence("Fdf", solution);
		else if (Buff[35] == 'w') // dFDf
			sequence("dFDf", solution);
	}
	else if (position == 7) {
		if (Buff[51] == 'w') // rdRFDf
			sequence("rdRFDf", solution);
		else if (Buff[15] == 'w') // FD2f
			sequence("FDDf", solution);
		else if (Buff[44] == 'w') // rD2R
			sequence("rDDR", solution);
	}
	else if (position == 1) {
		if (Buff[20] == 'w') // rDRFDf
			sequence("rDRFDf", solution);
		else if (Buff[27] == 'w') // rdRDrdR
			sequence("rdRDrdR", solution);
	}

	sequence("U", solution);
	position = searchEdge('g', 'r'); // Green/red
	if (position == 4) {
		if (Buff[25] == 'g') // drDRDFdf
			sequence("drDRDFdf", solution);
		else if (Buff[46] == 'g') // D2FdfdrDR
			sequence("DDFdfdrDR", solution);
	}
	else if (position == 5) {
		if (Buff[34] == 'g') // D2rDRDFdf
			sequence("DDrDRDFdf", solution);
		else if (Buff[50] == 'g') // DFdfdrDR
			sequence("DFdfdrDR", solution);
	}
	else if (position == 6) {
		if (Buff[43] == 'g') // DrDRDFdf
			sequence("DrDRDFdf", solution);
		else if (Buff[52] == 'g') // FdfdrDR
			sequence("FdfdrDR", solution);
	}
	else if (position == 7) {
		if (Buff[16] == 'g') // rDRDFdf
			sequence("rDRDFdf", solution);
		else if (Buff[48] == 'g') // dFdfdrDR
			sequence("dFdfdrDR", solution);
	}
	else if (position == 8) {
		if (Buff[30] == 'g') // rdRDFDfDrDRDFdf
			sequence("rdRDFDfDrDRDFdf", solution);
	}
}

void Rubik::yellowCross(vector<char>& solution) {

	bool repeat;

	if ((Buff[25] == 'y') && (Buff[34] == 'y') &&
		(Buff[43] == 'y') && (Buff[16] == 'y'))
		sequence("LDBdblfrdRDF", solution);
	else if ((Buff[25] == 'y') && (Buff[34] != 'y') &&
		(Buff[43] == 'y') && (Buff[16] != 'y'))
		sequence("frdRDF", solution);
	else if ((Buff[25] != 'y') && (Buff[34] == 'y') &&
		(Buff[43] != 'y') && (Buff[16] == 'y'))
		sequence("lfdFDL", solution);
	else if ((Buff[25] != 'y') && (Buff[34] != 'y') &&
		(Buff[43] == 'y') && (Buff[16] == 'y'))
		sequence("LDBdbl", solution);
	else if ((Buff[25] != 'y') && (Buff[34] == 'y') &&
		(Buff[43] == 'y') && (Buff[16] != 'y'))
		sequence("BDRdrb", solution);
	else if ((Buff[25] == 'y') && (Buff[34] == 'y') &&
		(Buff[43] != 'y') && (Buff[16] != 'y'))
		sequence("RDFdfr", solution);
	else if ((Buff[25] == 'y') && (Buff[34] != 'y') &&
		(Buff[43] != 'y') && (Buff[16] == 'y'))
		sequence("FDLdlf", solution);

	repeat = true;
	int contador = 0;

	while (repeat) {
		if ((Buff[25] == 'r') && (Buff[34] == 'g') &&
			(Buff[43] == 'b') && (Buff[16] == 'o')) { // bdBdbD2Bd
			sequence("bdBdbDDBd", solution);
			repeat = false;
		}
		else if ((Buff[25] == 'o') && (Buff[34] == 'r') &&
			(Buff[43] == 'b') && (Buff[16] == 'g')) { 	// rdRdrD2Rd
			sequence("rdRdrDDRd", solution);
			repeat = false;
		}
		else if ((Buff[25] == 'g') && (Buff[34] == 'r') &&
			(Buff[43] == 'o') && (Buff[16] == 'b')) { // fdFdfD2F
			sequence("fdFdfDDFd", solution);
			repeat = false;
		}
		else if ((Buff[25] == 'g') && (Buff[34] == 'b') &&
			(Buff[43] == 'r') && (Buff[16] == 'o')) { 	// ldLdlD2Ld
			sequence("ldLdlDDLd", solution);
			repeat = false;
		}
		else if ((Buff[25] == 'b') && (Buff[34] == 'r') &&
			(Buff[43] == 'g') && (Buff[16] == 'o')) { 	// rdRdrD2RD2 && bdBdbD2B
			sequence("rdRdrDDRDDbdBdbDDBd", solution);
			repeat = false;
		}
		else if ((Buff[25] == 'g') && (Buff[34] == 'o') &&
			(Buff[43] == 'b') && (Buff[16] == 'r')) { 	// rdRdrD2R && fdFdfD2Fd
			sequence("rdRdrDDRfdFdfDDFd", solution);
			repeat = false;
		}
		else if ((Buff[25] == 'y') && (Buff[34] == 'y') &&
			(Buff[43] == 'y') && (Buff[16] == 'y')) {
			sequence("RldRldRldRldRldRldRldRld", solution);
			repeat = false;
		}
		else if ((Buff[25] == 'g') && (Buff[34] == 'r') &&
			(Buff[43] == 'b') && (Buff[16] == 'o'))
			repeat = false;
		else {
			sequence("D", solution);
			++contador;
			if (contador == 5) { // bdBdbD2Bd
				contador = 0;
				sequence("bdBdbDDBd", solution);
				return;
			}
		}
	}
}

void Rubik::permutationFinalCorners(vector<char>& solution) {

	bool repeat = true;
	int i = 0;
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

	if ((Buff[45] == 'y') && (Buff[33] == 'y') &&
		(Buff[51] == 'y') && (Buff[35] == 'y')) // RD2rdRdrlD2LDlDL
		sequence("RDDrdRdrlDDLDlDL", solution);
	else if ((Buff[17] == 'y') && (Buff[47] == 'y') &&
		(Buff[15] == 'y') && (Buff[53] == 'y')) // LD2ldLdlrD2RDrDR
		sequence("LDDldLdlrDDRDrDR", solution);
	else if ((Buff[17] == 'y') && (Buff[33] == 'y') &&
		(Buff[15] == 'y') && (Buff[35] == 'y')) // RD2rdRdrlD2LDlDL LD2ldLdlrD2RDrDR
		sequence("RDDrdRdrlDDLDlDLLDDldLdlrDDRDrDR", solution);
	else if ((Buff[24] == 'y') && (Buff[26] == 'y') &&
		(Buff[51] == 'y') && (Buff[53] == 'y')) // FD2fdFdfbD2BDbDB
		sequence("FDDfdFdfbDDBDbDB", solution);
	else if ((Buff[45] == 'y') && (Buff[47] == 'y') &&
		(Buff[44] == 'y') && (Buff[42] == 'y')) // BD2bdBdbfD2FDfDF
		sequence("BDDbdBdbfDDFDfDF", solution);
	else if ((Buff[24] == 'y') && (Buff[26] == 'y') && //
		(Buff[44] == 'y') && (Buff[42] == 'y')) // FD2fdFdfbD2BDbDB BD2bdBdbfD2FDfDF
		sequence("FDDfdFdfbDDBDbDBBDDbdBdbfDDFDfDF", solution);
	else if ((Buff[45] == 'y') && (Buff[26] == 'y') &&
		(Buff[51] == 'y') && (Buff[42] == 'y')) // ldLdlD2LRDrDRD2r
		sequence("ldLdlDDLRDrDRDDr", solution);
	else if ((Buff[24] == 'y') && (Buff[47] == 'y') &&
		(Buff[44] == 'y') && (Buff[53] == 'y')) // rdRdrD2RLDlDLD2l
		sequence("rdRdrDDRLDlDLDDl", solution);
	else if ((Buff[45] == 'y') && (Buff[47] == 'y') &&
		(Buff[15] == 'y') && (Buff[35] == 'y')) // fdFdfD2FBDbDBD2b
		sequence("fdFdfDDFBDbDBDDb", solution);
	else if ((Buff[17] == 'y') && (Buff[33] == 'y') &&
		(Buff[51] == 'y') && (Buff[53] == 'y')) // bdBdbD2BFDfDFD2f
		sequence("bdBdbDDBFDfDFDDf", solution);
	else if ((Buff[17] == 'y') && (Buff[33] == 'y') &&
		(Buff[15] == 'y') && (Buff[35] == 'y')) // fdFdfD2FBDbDBD2b bdBdbD2BFDfDFD2f
		sequence("fdFdfDDFBDbDBDDbbdBdbDDBFDfDFDDf", solution);
	else if ((Buff[24] == 'y') && (Buff[26] == 'y') &&
		(Buff[15] == 'y') && (Buff[35] == 'y')) // FD2fdFdfbD2BDbDB fdFdfD2FBDbDBD2b
		sequence("FDDfdFdfbDDBDbDBfdFdfDDFBDbDBDDb", solution);
	else if ((Buff[17] == 'y') && (Buff[33] == 'y') &&
		(Buff[44] == 'y') && (Buff[42] == 'y')) // bdBdbD2BFDfDFD2f BD2bdBdbfD2FDfDF
		sequence("bdBdbDDBFDfDFDDfBDDbdBdbfDDFDfDF", solution);
	else if ((Buff[24] == 'y') && (Buff[33] == 'y') &&
		(Buff[44] == 'y') && (Buff[35] == 'y')) // rdRdrD2RLDlDLD2l RD2rdRdrlD2LDlDL
		sequence("rdRdrDDRLDlDLDDlRDDrdRdrlDDLDlDL", solution);
	else if ((Buff[17] == 'y') && (Buff[26] == 'y') &&
		(Buff[15] == 'y') && (Buff[42] == 'y')) // LD2ldLdlrD2RDrDR ldLdlD2LRDrDRD2r
		sequence("LDDldLdlrDDRDrDRldLdlDDLRDrDRDDr", solution);

	int yellows = 0;
	if (Buff[45] == 'y') yellows++;
	if (Buff[47] == 'y') yellows++;
	if (Buff[51] == 'y') yellows++;
	if (Buff[53] == 'y') yellows++;

	if (yellows == 1) {
		if (Buff[45] == 'y') {
			if (Buff[33] == 'y') // RUruRUrudRUruRUrudRUruRUruD2
				sequence("RUruRUrudRUruRUrudRUruRUruDD", solution);
			else if (Buff[26] == 'y') // fuFUfuFUdfuFUfuFUdfuFUfuFUD2
				sequence("fuFUfuFUdfuFUfuFUd fuFUfuFUDD", solution);
		}
		else if (Buff[47] == 'y') {
			if (Buff[24] == 'y') // FUfuFUfuDFUfuFUfuDFUfuFUfuD2
				sequence("FUfuFUfuDFUfuFUfuDFUfuFUfuDD", solution);
			else if (Buff[17] == 'y') // luLUluLUDluLUluLUDluLUluLUD2
				sequence("luLUluLUDluLUluLUDluLUluLUDD", solution);
		}
		else if (Buff[53] == 'y') {
			if (Buff[33] == 'y') // RUruRUruDRUruRUruDRUruRUruD2
				sequence("RUruRUruDRUruRUruDRUruRUruDD", solution);
			else if (Buff[26] == 'y') // fuFUfuFUDfuFUfuF UDfuFUfuFUD2
				sequence("fuFUfuFUDfuFUfuFUDfuFUfuFUDD", solution);
		}
		else if (Buff[51] == 'y') {
			if (Buff[33] == 'y') // RUruRUruDRUruRUruD2RUruRUruD
				sequence("RUruRUruDRUruRUruDDRUruRUruD", solution);
			else if (Buff[26] == 'y') // fuFUfuFUDfuFUfuFUD2fuFUfuFUD
				sequence("fuFUfuFUDfuFUfuFUDDfuFUfuFUD", solution);
		}
	}
	else if (yellows == 2) {
		if ((Buff[45] != 'y') && (Buff[53] != 'y')) {
			if (Buff[17] == 'y') // luLUluLUD2luLUluLUluLUluLUD2
				sequence("luLUluLUDDluLUluLUluLUluLUDD", solution);
			else if (Buff[24] == 'y') // luLUluLUluLUluLUD2 luLUluLUD2
				sequence("luLUluLUluLUluLUDDluLUluLUDD", solution);
		}
		else if ((Buff[47] != 'y') && (Buff[51] != 'y')) {
			if (Buff[26] == 'y') // fuFUfuFUD2fuFUfuFUfuFUfuFUD2
				sequence("fuFUfuFUDDfuFUfuFUfuFUfuFUDD", solution);
			else if (Buff[33] == 'y') // fuFUfuFUfuFUf uFUD2fuFUfuFUD2
				sequence("fuFUfuFUfuFUfuFUDDfuFUfuFUDD", solution);
		}
	}
}

bool Rubik::isSolved() const {

	bool success = false;
	int test=0;
	for (int i = 0; i < 53; i++) {
		if (Buff[i] != Buff[i + 1]) test++;
	}
	if (test == 5) success = true;

	return success;
}

void Rubik::Rotate(vector<char>& solution, char& rot) {

	char cornerSave, sideSave, elementSave;
	char spotSave0, spotSave1, spotSave2;
	int b, c, d, e, f;
	int a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11;
	int side = 0;

	if (tolower(rot) == 'u') side = 0;
	else if (tolower(rot) == 'l') side = 1;
	else if (tolower(rot) == 'f') side = 2;
	else if (tolower(rot) == 'r') side = 3;
	else if (tolower(rot) == 'b') side = 4;
	else if (tolower(rot) == 'd') side = 5;

	if (tolower(rot) != rot) {
		cornerSave = *Cube[side][0];
		*Cube[side][0] = *Cube[side][6];
		*Cube[side][6] = *Cube[side][8];
		*Cube[side][8] = *Cube[side][2];
		*Cube[side][2] = cornerSave;

		sideSave = *Cube[side][1];
		*Cube[side][1] = *Cube[side][3];
		*Cube[side][3] = *Cube[side][7];
		*Cube[side][7] = *Cube[side][5];
		*Cube[side][5] = sideSave;

		if (side == 0) { b = 4; c = 3; d = 2; e = 1; a0 = 2; a1 = 1; a2 = 0; a3 = 2; a4 = 1; a5 = 0; a6 = 2; a7 = 1; a8 = 0; a9 = 2; a10 = 1; a11 = 0; }
		else if (side == 1) { b = 0; c = 2; d = 5; e = 4; a0 = 0; a1 = 3; a2 = 6; a3 = 0; a4 = 3; a5 = 6; a6 = 0; a7 = 3; a8 = 6; a9 = 8; a10 = 5; a11 = 2; }
		else if (side == 2) { b = 0; c = 3; d = 5; e = 1; a0 = 6; a1 = 7; a2 = 8; a3 = 0; a4 = 3; a5 = 6; a6 = 2; a7 = 1; a8 = 0; a9 = 8; a10 = 5; a11 = 2; }
		else if (side == 3) { b = 0; c = 4; d = 5; e = 2; a0 = 8; a1 = 5; a2 = 2; a3 = 0; a4 = 3; a5 = 6; a6 = 8; a7 = 5; a8 = 2; a9 = 8; a10 = 5; a11 = 2; }
		else if (side == 4) { b = 0; c = 1; d = 5; e = 3; a0 = 2; a1 = 1; a2 = 0; a3 = 0; a4 = 3; a5 = 6; a6 = 6; a7 = 7; a8 = 8; a9 = 8; a10 = 5; a11 = 2; }
		else if (side == 5) { b = 2; c = 3; d = 4; e = 1; a0 = 6; a1 = 7; a2 = 8; a3 = 6; a4 = 7; a5 = 8; a6 = 6; a7 = 7; a8 = 8; a9 = 6; a10 = 7; a11 = 8; }
	}

	if (tolower(rot) == rot) {

		cornerSave = *Cube[side][0];
		*Cube[side][0] = *Cube[side][2];
		*Cube[side][2] = *Cube[side][8];
		*Cube[side][8] = *Cube[side][6];
		*Cube[side][6] = cornerSave;

		sideSave = *Cube[side][1];
		*Cube[side][1] = *Cube[side][5];
		*Cube[side][5] = *Cube[side][7];
		*Cube[side][7] = *Cube[side][3];
		*Cube[side][3] = sideSave;

		if (side == 0) { b = 4; c = 1; d = 2; e = 3; a0 = 0; a1 = 1; a2 = 2; a3 = 0; a4 = 1; a5 = 2; a6 = 0; a7 = 1; a8 = 2; a9 = 0; a10 = 1; a11 = 2; }
		else if (side == 1) { b = 0; c = 4; d = 5; e = 2; a0 = 6; a1 = 3; a2 = 0; a3 = 2; a4 = 5; a5 = 8; a6 = 6; a7 = 3; a8 = 0; a9 = 6; a10 = 3; a11 = 0; }
		else if (side == 2) { b = 0; c = 1; d = 5; e = 3; a0 = 8; a1 = 7; a2 = 6; a3 = 2; a4 = 5; a5 = 8; a6 = 0; a7 = 1; a8 = 2; a9 = 6; a10 = 3; a11 = 0; }
		else if (side == 3) { b = 0; c = 2; d = 5; e = 4; a0 = 2; a1 = 5; a2 = 8; a3 = 2; a4 = 5; a5 = 8; a6 = 2; a7 = 5; a8 = 8; a9 = 6; a10 = 3; a11 = 0; }
		else if (side == 4) { b = 0; c = 3; d = 5; e = 1; a0 = 0; a1 = 1; a2 = 2; a3 = 2; a4 = 5; a5 = 8; a6 = 8; a7 = 7; a8 = 6; a9 = 6; a10 = 3; a11 = 0; }
		else if (side == 5) { b = 2; c = 1; d = 4; e = 3; a0 = 8; a1 = 7; a2 = 6; a3 = 8; a4 = 7; a5 = 6; a6 = 8; a7 = 7; a8 = 6; a9 = 8; a10 = 7; a11 = 6; }
	}

	spotSave0 = *Cube[b][a0];
	spotSave1 = *Cube[b][a1];
	spotSave2 = *Cube[b][a2];
	*Cube[b][a0] = *Cube[e][a9];
	*Cube[b][a1] = *Cube[e][a10];
	*Cube[b][a2] = *Cube[e][a11];
	*Cube[e][a9] = *Cube[d][a6];
	*Cube[e][a10] = *Cube[d][a7];
	*Cube[e][a11] = *Cube[d][a8];
	*Cube[d][a6] = *Cube[c][a3];
	*Cube[d][a7] = *Cube[c][a4];
	*Cube[d][a8] = *Cube[c][a5];
	*Cube[c][a3] = spotSave0;
	*Cube[c][a4] = spotSave1;
	*Cube[c][a5] = spotSave2;

	solution.push_back(rot);
}

void Rubik::solve(vector<char>& solution) {

	solution.clear();
	whiteCross(solution);
	cornersFirstStep(solution);
	secondStep(solution);
	yellowCross(solution);
	permutationFinalCorners(solution); 
	positionFinalCorners(solution);
}

void Rubik::readRubik() {

	int number = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 9; j++) {
			Cube[i][j] = &Buff[number];
			number++;
		}
	}
}

bool test(istream& is, char(*buff)) {

	bool rez = true;
	int c = 0;

	for (int i = 0; i < 55; i++) is >> buff[i];
	if (buff[54]) {
		rez = false;
		return rez;
	}

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
	char buff[55] = { "" };
	vector<char> solution;
	ifstream fin;
	ofstream fout;
	fin.open(argv[1]);
	fout.open(argv[2]);

	if (test(fin, buff) == false) {
		fout << "error";
		fin.close();
		fout.close();
		system("pause");
		return 0;
	}
	fin.close();
	rubik.getBuff(buff);
	rubik.readRubik(); 
	rubik.solve(solution);

	if (rubik.isSolved() == false) {
		fout << "error";
		fout.close();
		system("pause");
		return 0;
	}

	for (int i = 0; i < solution.size(); i++) {
		fout << solution[i];
	}
	
	return 0;
}

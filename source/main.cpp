#include "header.hpp"


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

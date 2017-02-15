// find the roots of a quadratic equation

// Start standsard opening

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

inline void keep_window_open() { char ch; cin >> ch; }

inline void simple_error(string s)	// write ``error: s and exit program
{
	cerr << "error: " << s << '\n';
	keep_window_open();		// for some Windows environments
	exit(1);
}

// End standard opening

// declarations
struct quad_data {
	double a{ 0 };
	double b{ 0 };
	double c{ 0 };
	double cc{ 0 };
	double determinate{ 0 };
	double sqrt_determintate{ 0 };
	double x1{ 0 };
	double x2{ 0 };
};

void print_q_d_l(vector<quad_data> & qdl);

int main() {
	quad_data temp_q_d;
	vector<quad_data> quad_data_list;
	ifstream ist{ "testdata.txt"};
	if (ist.bad()) simple_error("problemn with the file... exiting.");

	while (!ist.eof()) {
		for (int i = 0; i < 8; ++i) {
			ist >> temp_q_d.a;
			ist >> temp_q_d.b;
			ist >> temp_q_d.c;
			ist >> temp_q_d.cc;
			ist >> temp_q_d.determinate;
			ist >> temp_q_d.sqrt_determintate;
			ist >> temp_q_d.x1;
			ist >> temp_q_d.x2;
			quad_data_list.push_back(temp_q_d);
		}
	}
	print_q_d_l(quad_data_list);


	keep_window_open();
	return(0);
}

void print_q_d_l(vector<quad_data> & qdl) {
	cout << "a\tb\c\tcc\tdeterm\tsqr_det\tx1\tx2\n";
	for (int i = 0; i < qdl.size(); ++i) {
		cout << qdl[i].a << "\t";
		cout << qdl[i].b << "\t";
		cout << qdl[i].c << "\t";
		cout << qdl[i].cc << "\t";
		cout << qdl[i].determinate << "\t";
		cout << qdl[i].sqrt_determintate << "\t";
		cout << qdl[i].x1 << "\t";
		cout << qdl[i].x2 << "\t";
		cout << "\n";
	}
}
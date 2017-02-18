// find the roots of a quadratic equation
// note the term 'determinate' is used throughout - should be 'discrimant'

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
void print_q_d(quad_data & qd);
bool coefs_good(quad_data & qd);
double calc_determ(quad_data & qd);
bool calc_roots(quad_data & qd);

int main() {
	quad_data temp_q_d;
	vector<quad_data> quad_data_list;
	quad_data calced_q_d;
	ifstream ist{"testdata.txt"};
	if (!ist) simple_error("problemn with the file... exiting.");  // seems simplest way to check that file was opened

	while (!ist.eof()) {						//assumes no errors in input file
			ist >> temp_q_d.a;					//no error checking on the file reading
			ist >> temp_q_d.b;
			ist >> temp_q_d.c;
			ist >> temp_q_d.cc;
			ist >> temp_q_d.determinate;
			ist >> temp_q_d.sqrt_determintate;
			ist >> temp_q_d.x1;
			ist >> temp_q_d.x2;
			quad_data_list.push_back(temp_q_d);
	}
	print_q_d_l(quad_data_list);

	cout << "\nCalculating values...\n\n";
	cout << "a\tb\tc\tcc\tdeterm\tsqr_det\tx1\tx2\n";

	for (int i = 0; i < quad_data_list.size(); ++i) {
		print_q_d(quad_data_list[i]);	// outputs the version of quad data from the file
		if (!coefs_good) continue;		// checks that a is not zero

		else {			
			calced_q_d.a = quad_data_list[i].a;
			calced_q_d.b = quad_data_list[i].b;
			calced_q_d.c = quad_data_list[i].c;
			calced_q_d.determinate = calc_determ(calced_q_d);
		}
		if (!calc_roots(calced_q_d)) {
			cout << "AWKWARD: there are no real roots!\n";
			continue;
			}
		print_q_d(calced_q_d);
	}
	print_q_d_l(quad_data_list);
	keep_window_open();
	return(0);
}

void print_q_d_l(vector<quad_data> & qdl) {
	cout << "a\tb\tc\tcc\tdeterm\tsqr_det\tx1\tx2\n";
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

void print_q_d(quad_data & qd)
{
	cout << qd.a << "\t";
	cout << qd.b << "\t";
	cout << qd.c << "\t";
	cout << qd.cc << "\t";
	cout << qd.determinate << "\t";
	cout << qd.sqrt_determintate << "\t";
	cout << qd.x1 << "\t";
	cout << qd.x2 << "\t";
	cout << "\n";
}

bool coefs_good(quad_data & qd)
{
	if (qd.a == 0) return false;
	else return true;
}

double calc_determ(quad_data& qd)
{
	return((qd.b * qd.b) - (4 * qd.a * qd.c));
}

bool calc_roots(quad_data & qd)
{
	if (qd.determinate < 0) return false;
	else if (qd.determinate == 0) {
		qd.x1 = -qd.b / (2 * qd.a);
		qd.x2 = qd.x1;
		return true;
	}
	else {
		qd.x1 = (-qd.b + sqrt(qd.determinate)) / (2 * qd.a);
		qd.x2 = (-qd.b - sqrt(qd.determinate)) / (2 * qd.a);
		return true;
	}
}

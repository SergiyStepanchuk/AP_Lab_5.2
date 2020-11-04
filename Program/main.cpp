// Lab_5_2
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#define M_PI_2     1.57079632679489661923   // pi/2

double S(const double &x, const double &eps, int& n)
{
	n = 1;
	double a = x, dob_nopar = 1, dob_par = 1, s = x;
	while (abs(a) > eps) {
		dob_nopar *= 2. * n - 1,
		dob_par *= 2. * n;
		a = (dob_nopar * pow(x, 2 * n + 1)) /
			(dob_par * (2. * n + 1.));
		s += a;
		n++;
	}
	return M_PI_2 - s;
}

int main()
{
	double xp, xk, x, dx, eps, s = 0;
	int n = 0;
	cout.setf(ios::left);
	cout << fixed;

	cout << "xp = "; cin >> xp;
	cout << "xk = "; cin >> xk;
	cout << "dx = "; cin >> dx;
	cout << "eps = "; cin >> eps;
	
	cout << "--------------------------------------------------" << endl; // 50
	cout << "| " << setw(10) << "x" << "| "
		<< setw(10) << "arccos(x)" << "| "
		<< setw(10) << "S" << "| "
		<< setw(10) << "n" << " |"
		<< endl;
	cout << "--------------------------------------------------" << endl; // 50
	x = xp;
	while (x <= xk)
	{
		s = S(x, eps, n);
		cout << "| " << setw(10) << setprecision(7) << x << "| "
			<< setw(10) << setprecision(7) << acos(x) << "| "
			<< setw(10) << setprecision(7) << s << "| "
			<< setw(10) << n << " |"
			<< endl;
		x += dx;
	}
	cout << "--------------------------------------------------" << endl;
	return 0;
}



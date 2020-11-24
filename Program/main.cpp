// Lab_5_2
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#define M_PI_2     1.57079632679489661923   // pi/2

double get_r(const int& n, const double& x) {
	return (pow(2 * n - 1, 2) * pow(x, 2)) / (2. * n * (2. * n + 1));
}

double S(const double& x, const double& eps, int& n)
{
	n = 1;
	double a = pow(x, 3.)/6., s = x + a;
	do
	{
		n++;
		a *= get_r(n, x);
		s += a;
		
	} while (abs(a) >= eps);
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
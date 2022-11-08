#include <iostream>
#include <windows.h>
#include <math.h>
using namespace std;
double funct(double x);
double derivative(double x);
double bisection(double a, double b, double eps, int& it1);
double newtone(double p, double eps, int& it2);
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double x;
	double a;
	double b;
	double eps;
	double p;
	int it1;
	int it2;
	cout << "<FIRST SEGMENT>" << endl << endl;
	a = -3.2;
	b = -3;
	eps = 0.0001;
	cout << "BISECTION METHOD" << endl;
	cout << "---Left border of the segment: " << a << endl;
	cout << "---Right border of the segment: " << b << endl;
	cout << "---Accuracy value: " << eps << endl;
	cout << "---X=" << bisection(a, b, eps, it1) << endl;
	cout << "---NUMBER OF ITERATIONS:" << it1 << endl << endl;

	p = -3.2;
	cout << "NEWTONE METHOD" << endl;
	cout << "---X=" << newtone(p, eps, it2) << endl;
	cout << "---NUMBER OF ITERATIONS:" << it2 << endl;
	cout << "________________________________" << endl << endl;

	cout << "<SECOND SEGMENT>" << endl << endl;
	a = -1;
	b = -0.8;
	eps = 0.0001;
	cout << "BISECTION METHOD" << endl;
	cout << "---Left border of the segment: " << a << endl;
	cout << "---Right border of the segment: " << b << endl;
	cout << "---Accuracy value: " << eps << endl;
	cout << "---X=" << bisection(a, b, eps, it1) << endl;
	cout << "---NUMBER OF ITERATIONS:" << it1 << endl << endl;

	p = -0.8;
	cout << "NEWTONE METHOD" << endl;
	cout << "---X=" << newtone(p, eps, it2) << endl;
	cout << "---NUMBER OF ITERATIONS:" << it2 << endl;
	cout << "________________________________" << endl << endl;

	cout << "<THIRD SECTION>" << endl << endl;
	a = 1.4;
	b = 1.6;
	eps = 0.0001;
	cout << "BISECTION METHOD" << endl;
	cout << "---Left border of the segment: " << a << endl;
	cout << "---Right border of the segment: " << b << endl;
	cout << "---Accuracy value: " << eps << endl;
	cout << "---X=" << bisection(a, b, eps, it1) << endl;
	cout << "---NUMBER OF ITERATIONS:" << it1 << endl << endl;

	p = 1.4;
	cout << "NEWTONE METHOD" << endl;
	cout << "---X=" << newtone(p, eps, it2) << endl;
	cout << "---NUMBER OF ITERATIONS:" << it2 << endl;
	cout << "________________________________" << endl << endl;
}
double funct(double x)
{
	return 2 * x * x * x + 5 * x * x - 6 * x - 9;
}
double derivative(double x)
{
	return 6 * x * x + 10 * x - 6;
}
double bisection(double a, double b, double eps, int& it1)
{
	double y = funct(a);
	double x;
	double z;
	it1 = 0;
	while ((b - a) > eps)
	{
		x = (a + b) / 2;
		z = funct(x);
		if (y * z > 0)
		{
			a = x;
			y = z;
		}
		else
		{
			b = x;
		}
		it1++;
	}
	return x;
}
double newtone(double p, double eps, int& it2)
{
	double f;
	it2 = 0;
	do
	{
		f = funct(p);
		p = p - (f / derivative(p));
		it2++;
	} 	while (fabs(f) > eps);
	return p;
}
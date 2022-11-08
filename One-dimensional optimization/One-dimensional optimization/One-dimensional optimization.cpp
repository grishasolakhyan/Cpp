#include <iostream>
#include <windows.h>
#include <math.h>

using namespace std;

double fun(double x);
void svenn(double xa, double h, double& a, double& b);
double gold(double a, double b, double eps);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double xa = 1;
	double a;
	double b;
	double h = 0.5;
	double eps = 1e-3;
	svenn(xa, h, a, b);
	cout << "A=" << a << endl;
	cout << "B=" << b << endl;
	cout << "x=" << gold(a, b, eps) << endl;
	cout << "f(x)=" << fun(gold(a, b, eps)) << endl;
}
double fun(double x)
{
	return x * (x * (x * (3 * x - 1) + 7.5) + 18) + 3;
}
void svenn(double xa, double h, double& a, double& b)
{
	double f1 = fun(xa);
	double fm = fun(xa - h);
	double fp = fun(xa + h);
	double fun0;
	double x0;
	if (fm >= f1 && f1 <= fp)
	{
		a = xa - h;
		b = xa + h;
		return;
	}
	else if (fm >= f1 && f1 >= fp)
		xa += h;
	else if (fm <= f1 && f1 <= fp)
	{
		xa -= h;
		h = -h;
	}
	while (true)
	{
		fun0 = f1;
		x0 = xa;
		h *= 2;
		xa = x0 + h;
		f1 = fun(xa);
		if (f1 >= fun0)
			break;
	}
	if (h < 0)
	{
		a = xa;
		b = x0 - h / 2;
	}
	else
	{
		a = x0 - h / 2;
		b = xa;
	}
	return;
}
double gold(double a, double b, double eps)
{
	const double Z = (1 + sqrt(5)) / 2;
	double u = b - (b - a) / Z;
	double w = a + (b - a) / Z;
	double fu = fun(u);
	double fw = fun(w);
	while (fabs(b - a) > eps)
	{
		if (fu <= fw)
		{
			b = w;
			w = u;
			fw = fu;
			u = b - (b - a) / Z;
			fu = fun(u);
		}
		else
		{
			a = u;
			u = w;
			fu = fw;
			w = a + (b - a) / Z;
			fw = fun(w);
		}
	}
	return (a + b) / 2;
}
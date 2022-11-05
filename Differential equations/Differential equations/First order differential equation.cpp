#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<stdio.h>
#include<Windows.h>
#include<math.h>

using namespace std;

void rk2(double x1, double x2, double a[], int n);
void rk4(double x1, double x2, double a[], int n);
double fy(double x, double y);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double a[11];
	double b[21];
	double y = 4;
	double x1 = 1, x2 = 2;
	a[0] = y;
	b[0] = y;
	FILE* f1;
	int j = 0;
	double h, x, pogr;
	x = x1;
	int n = 10;
	h = (x2 - x1) / n;
	f1 = fopen("runge.txt", "a");

	if (f1 == NULL)
	{
		cout << "Can't work with file" << endl;
	}
	else
	{
		rk2(x1, x2, a, n);
		rk2(x1, x2, b, n * 2);
		fprintf(f1, "By the Runge-Kutta method of the 2nd order\n");
		for (int i = 0; i < n; i++)
		{
			j = i * 2;
			pogr = (b[j] - a[i]) / 3;
			fprintf(f1, "x[%i]=%.2f\ty=%lf\tERROR=%.10f\n", i, x, a[i], pogr);
			x += h;
		}
		x = x1;
		rk4(x1, x2, a, n);
		rk4(x1, x2, b, n * 2);
		fprintf(f1, "By the Runge-Kutta method of the 4th order\n");
		for (int i = 0; i < n; i++)
		{
			j = i * 2;
			pogr = (b[j] - a[i]) / 15;
			fprintf(f1, "x[%i]=%.2f\ty=%lf\tERROR=%.10f\n", i, x, a[i], pogr);
			x += h;
		}
		fclose(f1);
	}
	cout << "Open the runge.txt file to check" << endl;
}

double fy(double x, double y)
{
	return (y - 2) / (2 * x);
}

void rk2(double x1, double x2, double a[], int n)
{
	double h, x;
	x = x1;
	h = (x2 - x1) / n;
	for (int i = 0; i < n; i++)
	{
		a[i + 1] = a[i] + h / 2 * (fy(x, a[i]) + fy(x + h, a[i] + h * fy(x, a[i])));
		x += h;
	}
}

void rk4(double x1, double x2, double a[], int n)
{
	double h;
	double k1, k2, k3, k4;
	h = (x2 - x1) / n;
	for (int i = 0; i < n; i++)
	{
		k1 = fy(x1, a[i]);
		k2 = fy(x1 + h / 2, a[i] + h * k1 / 2);
		k3 = fy(x1 + h / 2, a[i] + h * k2 / 2);
		k4 = fy(x1 + h, a[i] + h * k3);
		a[i + 1] = a[i] + h / 6 * (k1 + 2 * k2 + 2 * k3 + k4);
		x1 += h;
	}
}
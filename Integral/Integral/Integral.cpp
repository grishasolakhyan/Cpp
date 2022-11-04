#include <iostream>
#include <Windows.h>
#include <math.h>

using namespace std;
double function(double x);
double function2(double x);
//для первой функции
double rectangle(double a, double b, int n);
double trapezium(double a, double b, int n);
double Simpson(double a, double b, int n);
//отдельно для второй функции
double rectangle2(double a, double b, int n);
double trapezium2(double a, double b, int n);
double Simpson2(double a, double b, int n);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//ДЛЯ ПЕРВОЙ ИССЛЕДУЕМОЙ ФУНКЦИИ
	double a = -2;
	double b = 1;
	double I = -24;
	int n = 30;
	int n2 = 20;
	double h = (b - a) / n;
	double sum;

	cout << "ПЕРВАЯ ФУНКЦИЯ - x^5+4*x^3-x" << endl;
	cout << "________________________________________" << endl << endl;
	cout << "ГРАНИЦЫ ИНТЕГРИРУЕМОГО ОТРЕЗКА" << endl;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "ТОЧНОЕ ЗНАЧЕНИЕ ИНТЕГРАЛА: " << I << endl;
	cout << "ЧИСЛО ОТРЕЗКОВ: 10 " << endl;
	cout << "________________________________________" << endl << endl;

	cout << "МЕТОД ПРЯМОУГОЛЬНИКОВ" << endl;
	cout << "I=" << rectangle(a, b, n) << endl;
	cout << "АБСОЛЮТНАЯ ПОГРЕШНОСТЬ=" << I - rectangle(a, b, n) << endl;
	cout << "ОТНОСИТЕЛЬНАЯ ПОГРЕШНОСТЬ=" << ((I - rectangle(a, b, n)) / I) * 100 << "%" << endl;
	cout << "________________________________________" << endl << endl;

	cout << "МЕТОД ТРАПЕЦИИ" << endl;
	cout << "I=" << trapezium(a, b, n) << endl;
	cout << "АБСОЛЮТНАЯ ПОГРЕШНОСТЬ=" << I - trapezium(a, b, n) << endl;
	cout << "ОТНОСИТЕЛЬНАЯ ПОГРЕШНОСТЬ=" << ((I - trapezium(a, b, n)) / I) * 100 << "%" << endl;
	cout << "________________________________________" << endl << endl;

	cout << "МЕТОД СИМПСОНА" << endl;
	cout << "I=" << Simpson(a, b, n) << endl;
	cout << "АБСОЛЮТНАЯ ПОГРЕШНОСТЬ=" << I - Simpson(a, b, n) << endl;
	cout << "ОТНОСИТЕЛЬНАЯ ПОГРЕШНОСТЬ=" << ((I - Simpson(a, b, n)) / I) * 100 << "%" << endl;
	cout << "________________________________________" << endl << endl;

	//ДЛЯ ВТОРОЙ ИССЛЕДУЕМОЙ ФУНКЦИИ
	a = -0.5;
	b = 0.8;
	cout << "ВТОРАЯ ФУНКЦИЯ - x/(cos(x)*cos(x)*cos(x))" << endl;
	cout << "________________________________________" << endl << endl;
	cout << "ГРАНИЦЫ ИНТЕГРИРУЕМОГО ОТРЕЗКА" << endl;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "КОЛИЧЕСТВО ОТРЕЗКОВ: 10 для I и 20 для In2: " << endl;
	cout << "________________________________________" << endl << endl;
	cout << "МЕТОД ПРЯМОУГОЛЬНИКОВ" << endl;
	cout << "I=" << rectangle2(a, b, n) << endl;
	cout << "In2=" << rectangle2(a, b, n2) << endl;
	cout << "ОЦЕНКА ПОГРЕШНОСТИ=" << (rectangle2(a, b, n2) - rectangle2(a, b, n)) / (4 - 1) << endl;
	cout << "УТОЧНЁННОЕ ЗНАЧЕНИЕ=" << (rectangle2(a, b, n2) - rectangle2(a, b, n)) / (4 - 1) + rectangle2(a, b, n2) << endl;
	cout << "________________________________________" << endl << endl;

	cout << "МЕТОД ТРАПЕЦИИ" << endl;
	cout << "I=" << trapezium2(a, b, n) << endl;
	cout << "In2=" << trapezium2(a, b, n2) << endl;
	cout << "ОЦЕНКА ПОГРЕШНОСТИ=" << (trapezium2(a, b, n2) - trapezium2(a, b, n)) / (4 - 1) << endl;
	cout << "УТОЧНЁННОЕ ЗНАЧЕНИЕ=" << (trapezium2(a, b, n2) - trapezium2(a, b, n)) / (4 - 1) + trapezium2(a, b, n2) << endl;
	cout << "________________________________________" << endl << endl;

	cout << "МЕТОД СИМПСОНА" << endl;
	cout << "I=" << Simpson2(a, b, n) << endl;
	cout << "In2=" << Simpson2(a, b, n2) << endl;
	cout << "ОЦЕНКА ПОГРЕШНОСТИ=" << (Simpson2(a, b, n2) - Simpson2(a, b, n)) / (16 - 1) << endl;
	cout << "УТОЧНЁННОЕ ЗНАЧЕНИЕ=" << (Simpson2(a, b, n2) - Simpson2(a, b, n)) / (16 - 1) + Simpson2(a, b, n2) << endl;
	cout << "________________________________________" << endl << endl;
}

double function(double x)
{
	return x * (x * (x * (x * x + 4)) - 1);
}

double function2(double x)
{
	double f = 1 / cos(x);
	return x * f * f * f;
}

double rectangle(double a, double b, int n)
{
	double h = (b - a) / n;
	double sum = 0;
	double x = a + h / 2;
	while (x < b)
	{
		sum += function(x);
		x += h;
	}
	return sum * h;
}

double trapezium(double a, double b, int n)
{
	double h = (b - a) / n;
	double x = a + h;
	double sum = (function(a) + function(b)) / 2;
	for (int i = 1; i <= n - 1; i++)
	{
		sum += function(x);
		x += h;
	}
	return sum * h;
}
double Simpson(double a, double b, int n)
{
	double x = a;
	double h = (b - a) / n;
	double sum = function(a) + function(b);
	double sum1 = 0;
	double sum2 = 0;
	for (int i = 1; i <= n - 1; i += 2)
	{
		sum1 += function(x + i * h);
	}
	for (int i = 2; i <= n - 1; i += 2)
	{
		sum2 += function(x + i * h);
	}
	sum = (h / 3) * (sum + 4 * sum1 + 2 * sum2);
	return sum;
}

double rectangle2(double a, double b, int n)
{
	double h = (b - a) / n;
	double sum = 0;
	double x = a + h / 2;
	while (x < b)
	{
		sum += function2(x) * h;
		x += h;
	}
	return sum;
}

double trapezium2(double a, double b, int n)
{
	double h = (b - a) / n;
	double sum = (function2(a) + function2(b)) * h / 2;
	double x = a + h;
	for (int i = 1; i <= n - 1; i++)
	{
		sum += function2(x) * h;
		x += h;
	}
	return sum;
}
double Simpson2(double a, double b, int n)
{
	double x = a;
	double h = (b - a) / (n);
	double sum = function2(a) + function2(b);
	double sum1 = 0;
	double sum2 = 0;
	for (int i = 1; i <= n - 1; i += 2)
	{
		sum1 += function2(x + i * h);
	}
	for (int i = 2; i <= n - 1; i += 2)
	{
		sum2 += function2(x + i * h);
	}
	sum = (h / 3) * (sum + 4 * sum1 + 2 * sum2);
	return sum;
}
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <windows.h>

using namespace std;

void differ (double x[], double y[], double x1, double xn, double y1, double yn, int p, int q, double h, int n);

int main ()
{	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double x1=-4;
	double xn=-1;
	double y1=-10;
	double yn=-58;
	
	int p=-6;
	int q=1;
	const int n=20;
	
	double h=(xn-x1)/n;	
	double x[n];
	double y[n];
		
	differ (x, y, x1, xn, y1, yn, p, q, h, n);
	FILE *f1=fopen("kraevayazadacha.txt", "w");
	fprintf(f1,"i\t x\t y\n");
   	for (int i=0; i<=n; i++)
	{
		fprintf(f1,"%.1i.\t%.2f\t%lf\n",i,x[i],y[i]);	
	}
	fclose(f1);
	cout<<"Close program and open kraevayazadacha.txt file to check";
	
	return 0;
}

double f(double x)
{
	return x*(x*x+17*x-28)-8;
}

void differ (double x[], double y[], double x1, double xn, double y1, double yn, int p, int q, double h, int n)
{	
	x[0]=x1;
	x[n]=xn;
	y[0]=y1;
	y[n]=yn;

	double a=1/(h*h)-p/(2*h);
	double b=1/(h*h)+p/(2*h);
	double c=-(q+2/(h*h));
	
	double *d=new double[n];
	double *u=new double[n];
	double *v=new double[n];
	
	for(int i=1;i<=n-1;i++)
	{
		x[i]=x1+i*h;
		d[i]=f(x[i]);
	}
		
	d[1]=f(x[1])-a*y1;
	d[n-1]=f(x[n-1])-b*yn;
	
	u[1]=d[1]/c;
	v[1]=-b/c;
	for (int i=2; i<=n-2;i++)
	{
		u[i]=(d[i]-a*u[i-1])/(a*v[i-1]+c); 
		v[i]=(-b)/(a*v[i-1]+c);
	}
	y[n-1]=(d[n-1]-a*u[n-2])/(a*v[n-2]+c);
			
	for(int i=n-2;i>=1;i--)
	{
		y[i]=u[i]+v[i]*y[i+1];	
	}
}

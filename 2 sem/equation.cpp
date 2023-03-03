#include <iostream>
#include <string>
#include <cmath>

using namespace std;

double a = -12, b = 5, h = 0.01, eps = 0.0001;

double F(double x)
{
	return pow(x, 3) + 10 * pow(x, 2) - 50;
}

double FindRoot(double x0, double x1, double epsilon)
{
	double x2, okr;
	do
	{
		x2 = x1 - F(x1) * (x1 - x0) / (F(x1) - F(x0));
		okr = fabs(x1 - x2);
		x0 = x1;
		x1 = x2;
	} while (okr > eps);
	return x1;
}


int main()
{
	int n = 0;
	cout <<"a = " + to_string(a)<<endl<< "b = " + to_string(b)<<endl<< "h = " + to_string(h)<<endl<<"e = " + to_string(eps) << endl << endl;
	for (double x = a; x <= b; x += h)
	{
		if (F(x) * F(x + h) < 0)
		{
			n++;
			cout << "x" + to_string(n) + " = " + to_string(FindRoot(x, x + h, eps)) << endl;
			cout << F(FindRoot(x, x + h, eps))<<endl;
		}
		
	}
	if (n == 0) cout << "no roots";
}
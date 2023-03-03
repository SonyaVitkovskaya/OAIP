#include <iostream>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void massiv(int n, int a[]);

int main()
{
	int a[100], k;
	cout << "vvedite kol-vo elementov ot 1 do 100" << endl;
	cin >> k;
	int n = k - 1;
	int sposob;
	cout << "random 1, vruchnuyu 2:";
	cin >> sposob;

	if (sposob == 2)
	{
		for (int i = 0; i <= n; i++)
		{
			cout << "Vvedite a[" << i << "]=";
			cin >> a[i];
		}
		massiv(n, a);
	}
	if (sposob == 1)
	{
		srand(time(NULL));
		for (int i = 0; i <= n; i++)
		{
			a[i] = rand() % 10;
		}
		massiv(n, a);
	}
	else { cout << "1 or 2"; }

}
void massiv(int n, int a[])
{
	cout << "Vash massiv:";
	for (int i = 0; i <= n; i++)
		cout << a[i] << " ";
	cout << endl;

	int sum = 0;
	if (a[n] == 0)
	{
		cout << "the last element is 0, impossible to find the sum";
	}

	bool find_0 = false;
	for (int i = n; i >= 0; i -= 1)
	{

		if (a[i] == 0)
		{
			for (int c = i; c <= n; c += 1)
			{
				sum += a[c];
			}
			find_0 = true;
			break;
		}
	}
	if (find_0)
	{
		cout << sum << endl;
	}
	else
	{
		cout << "there is no element '0'";
	}
}
#include <iostream>
using namespace std;

double Recursion(int n, int i)
{	
	if (i == n)
		return sqrt(n);
	else
		return sqrt(i + Recursion(n, i + 1));
}

int main()
{
	system("chcp 1251");
	system("cls");
	int n, action;
	float result;
	while (1)
	{
		cout << "Посчитать?(1-да, 2-нет)" << endl;
		cin >> action;
		if (action == 1)
		{
			cout << "n: ";
			cin >> n;
			cout << "Использовать рекурсивную функцию? (да - 1, нет - 2)" << endl;
			cin >> action;
			if (action == 1) result = Recursion(n,1);
			else
			{
				result = sqrt(n);
				for (int i = n; i > 1; i--) result = sqrt((i - 1) + result);
			}
			cout << "Результат : " << result << endl;
		}
		else break;
	}
}


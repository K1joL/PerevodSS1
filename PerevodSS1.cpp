#include <iostream>
#include <cmath>
using namespace std;

int perevodv10(int si)
{
	const int N = 37;
	char numb1;
	int a = 0, k = 0, l = 0, cc = 0;
	int prov = 0;

	char Alp[N] = { "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
	int num[N] = { 0 };

Start:
	cout << "Введите число. После числа поставьте точку.\nЧисло: ";

	cin.get(numb1);
	do
	{
		for (int i = 0; i < N; i++)
		{
			if (numb1 == Alp[i])
			{
				num[k] = i;

				prov = num[k] / (si);
				if (prov >= 1)
				{
					cout << "Число некорректно. (1)\n";
					goto Start;
				}
				k++;
			}
		}
	} while ((numb1 = getchar()) != ';');


	for (int i = 0; i < N; i++)
	{
		if (num[i] == 0)
			cc++;
	}

	if (cc == N)
	{
		cout << "\nЧисло некорректно. (2)\n";
		goto Start;
	}

	k--;
	a = 0;
	while (k >= 0)
	{
		a += num[l] * pow(si, k);
		k--;
		l++;
	}
	return a;
}

void perevodiz10(int a, int sv)
{
	int c = 1, l = 0, otv = 0;
	char Alp[37] = { "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ" };

	while (c * sv <= fabs(a))
	{
		c *= sv;
		++l;
	}

	while (c != 0)
	{
		otv = a / c;
		a %= c;
		c /= sv;
		--l;
		cout << Alp[otv];
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "ПЕРЕВОД ЧИСЕЛ В РАЗЛИЧНЫЕ СИСТЕМЫ СЧИСЛЕНИЯ\n";
	while (true)
	{
		int a = 0, sv, si;
		
		cout << "\nИсходное число записано в системе счисления: ";
		cin >> si;

		if (si != 10)
		{
			a = perevodv10(si);
			cout << "Число в десятичной СС: " << a;
		}
		else
		{
			cout << "\nВведите число: ";
			cin >> a;
		}

			cout << "\nВ какую систему перевести: ";
			cin >> sv;

			cout << "\nОтвет: ";
			perevodiz10(a, sv);
			cout << endl;
	}
	
	return 32;
}
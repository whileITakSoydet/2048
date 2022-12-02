#include <iostream>
#include <time.h>
#include <Windows.h>
#include <conio.h>

using namespace std;

int score;

void show(int arr[][4])
{
	for (int i = 0; i < 4; i++)
	{
		cout << "\t\t";
		for (int j = 0; j < 4; j++)
		{
			if (arr[i][j] > 0)
			{
				cout << arr[i][j] << "\t";
			}
			else
			{
				cout << ".\t";
			}
			
		}
		cout << "\n\n";
	}
}

void gen(int arr[][4], int sz)
{
	int a, i, j;
	bool flag;

	for (int k = 0; k < sz; k++)
	{
		flag = true;
		i = rand() % 4;
		j = rand() % 4;
		a = 2 + rand() % 3;
		if (a == 3)
		{
			flag = false;
			k--;
		}
		if (flag)
		{
			if (arr[i][j] == 0)
			{
				arr[i][j] = a;
			}
			else
			{
				k--;
			}
		}
	}
}

void right(int arr[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0, l = 0; j < 4; j++)
		{
			if (arr[i][j] > 0)
			{
				swap(arr[i][j], arr[i][l++]);
			}
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0, l = 0; j < 4; j++)
		{
			if (arr[i][j] == arr[i][j + 1])
			{
				arr[i][j] *= 2;
				score += arr[i][j];
				arr[i][j + 1] = 0;
			}
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0, l = 0; j < 4; j++)
		{
			if (arr[i][j] > 0)
			{
				swap(arr[i][j], arr[i][l++]);
			}
		}
	}
}

void left(int arr[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 3, r = 3; j >= 0; j--)
		{
			if (arr[i][j] > 0)
			{
				swap(arr[i][j], arr[i][r--]);
			}
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 3, r = 3; j >= 0; j--)
		{
			if (arr[i][j] == arr[i][j - 1])
			{
				arr[i][j] *= 2;
				score += arr[i][j];
				arr[i][j - 1] = 0;
			}
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 3, r = 3; j >= 0; j--)
		{
			if (arr[i][j] > 0)
			{
				swap(arr[i][j], arr[i][r--]);
			}
		}
	}
}

void up(int arr[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0, r = 0; j < 4; j++)
		{
			if (arr[j][i] > 0)
			{
				swap(arr[j][i], arr[r++][i]);
			}
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0, r = 0; j < 4; j++)
		{

			if (arr[j][i] == arr[j + 1][i])
			{
				arr[j][i] *= 2;
				score += arr[i][j];
				arr[j + 1][i] = 0;
			}
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0, r = 0; j < 4; j++)
		{
			if (arr[j][i] > 0)
			{
				swap(arr[j][i], arr[r++][i]);
			}
		}
	}
}

void down(int arr[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 3, r = 3; j >= 0; j--)
		{
			if (arr[j][i] > 0)
			{
				swap(arr[j][i], arr[r--][i]);
			}
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 3, r = 3; j >= 0; j--)
		{
			if (arr[j][i] == arr[j - 1][i])
			{
				arr[j][i] *= 2;
				score += arr[i][j];
				arr[j - 1][i] = 0;
			}
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 3, r = 3; j >= 0; j--)
		{
			if (arr[j][i] > 0)
			{
				swap(arr[j][i], arr[r--][i]);
			}
		}
	}
}

void check(int arr[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (arr[i][j] == 2048)
			{
				cout << "Вы выиграли!\n";
				return;
			}
		}
	}
	cout << "Продолжайте...\n";
}

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(0));

	int arr[4][4]{};
	char x;
	bool flag = false;
	gen(arr, 2);
	show(arr);
	while (true)
	{
		cout << "Выберете направление a - влево d - вправо w - вверх s - вниз e - выход c - проверка\n";
		cout << "Ваш счет: " << score << endl;
		x = _getch();

		switch (x)
		{
		case 97:	// Влево
			right(arr);
			gen(arr, 1);
			system("cls");
			show(arr);
			break;

		case 100:	// Вправо
			left(arr);
			gen(arr, 1);
			system("cls");
			show(arr);
			break;

		case 119:	// Вверх
			up(arr);
			gen(arr, 1);
			system("cls");
			show(arr);
			break;

		case 115:	// Вниз
			down(arr);
			gen(arr, 1);
			system("cls");
			show(arr);
			break;

		case 'c':
			system("cls");
			show(arr);
			check(arr);
			break;
		case 'e':
			cout << "До встречи!\n";
			return 0;

		default:
			cout << "Неверно введеный символ!" << endl;
			break;
		}
	}
}
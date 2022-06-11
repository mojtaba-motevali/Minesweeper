#include <iostream>
#include <vector>
#include <random>
using std::cin;
using std::cout;
using std::vector;
void fillVector(vector<vector<char>> &a, int row, int column)
{
	int i = 0;
	char c;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			cin >> c;
			a[i][j] = c;
		}
		cout << "\n";
	}
}
void findMine(vector<vector<char>> &a, int row, int column, int i)
{
	int k = 48;
	vector<vector<int>> b(row);

	for (vector<int> &c : b)
	{
		c.resize(column);
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			b[i][j] = 48;
		}
	}
	int starInt = static_cast<int>('*');
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (a[i][j] == '*')
			{
				b[i][j] = starInt;
				for (int f = i - 1; f <= i + 1; f++)
				{
					for (int h = j - 1; h <= j + 1; h++)
					{
						if (f >= 0 && f < row && h >= 0 && h < column && b[f][h] != starInt)
						{
							++b[f][h];
						}
					}
				}
			}
		}
	}
	cout << "Field #" << (i + 1) << ":"
		 << "\n";
	for (int i = 0; i < b.size(); i++)
	{
		for (int j = 0; j < column; j++)
		{
			cout << static_cast<char>(b[i][j]);
		}
		cout << "\n";
	}
	cout << "\n";
}

int main()
{
	int row, column;
	int i = 0;
	cout << "enter number of rows and columns:"
		 << "\n";
	while (cin >> row >> column)
	{

		if (row == 0 && column == 0)
		{
			break;
		}
		vector<vector<char>> a(row);

		for (vector<char> &c : a)
		{
			c.resize(column);
		}

		fillVector(a, row, column);
		findMine(a, row, column, i);
		i++;
	}

	return 0;
}

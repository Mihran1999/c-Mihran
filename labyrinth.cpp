#include <iostream>
#include <vector>
#include <string>

typedef std::vector<int> rowInt;
typedef std::vector<char> rowChar;
typedef std::vector<rowInt> iBoard;
typedef std::vector<rowChar> cBoard;

//symbols
const char me = 'P';
const char wall = '#';
const char empty = '.';
const char treasure = '$';

//destinations
std::pair<int, int> up = { 1, 0 };
std::pair<int, int> down = { -1, 0 };
std::pair<int, int> left = { 0, 1 };
std::pair<int, int> right = { 0, -1 };

std::vector <std::pair<int, int>> destinations
{
	up,
	down,
	left,
	right,
};

bool GetPath(iBoard&, cBoard&);
std::pair<int, int> GetTreasureCoords(cBoard&);
void print(iBoard& b)
{
	for (int i = 0; i < b.size(); ++i)
	{
		for (int j = 0; j < b[0].size(); ++j)
		{
			std::cout << b[i][j] << " ";
		}
		std::cout << "\n";
	}
}

int main()
{
	int n, m;
	std::cin >> n >> m;

	cBoard matC(n, rowChar(m));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j  < m; ++j)
		{
			std::cin >> matC[i][j];
		}
	}

	

	iBoard matI(n, rowInt(m, -1));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (matC[i][j] == me)
			{
				matI[i][j] = 0;
			}
		}
	}

	if (!GetPath(matI, matC))
	{
		std::cout << "Impossible";
		return 0;
	}
	print(matI);
}


bool GetPath(iBoard& matI, cBoard& matC)
{
	bool changed = true;
	std::pair<int, int> tr = GetTreasureCoords(matC);

	for (int moves = 0; ; ++moves)
	{
		changed = false;
		for (int i = 0; i < matC.size(); ++i)
		{
			for (int j = 0; j < matC[0].size(); ++j)
			{
				if (matI[i][j] == moves)
				{
					if (i + 1 < matI.size() && matC[i + 1][j] != wall && matI[i + 1][j] == -1)
					{
						matI[i + 1][j] = moves + 1;
						changed = true;
					}
					if (i > 0 && matC[i - 1][j] != wall && matI[i - 1][j] == -1)
					{
						matI[i - 1][j] = moves + 1;
						changed = true;
					}
					if (j + 1 < matI[0].size() && matC[i][j + 1] != wall && matI[i][j + 1] == -1)
					{
						matI[i][j + 1] = moves + 1;
						changed = true;
					}
					if (j > 0 && matC[i][j - 1] != wall && matI[i][j - 1] == -1)
					{
						matI[i][j - 1] = moves + 1;
						changed = true;
					}
				}
			}
		}

		if (matI[tr.first][tr.second] != -1)
		{
			return true;
		}
		else if (!changed)
		{
			return false;
		}

		//print(matI);
		//std::cout << tr.first << " " << tr.second;
		std::cout << matI[tr.first][tr.second];
		std::cout << "\n";
	}
}

std::pair<int, int> GetTreasureCoords(cBoard& b)
{
	for (int i = 0; i < b.size(); ++i)
	{
		for (int j = 0; j < b[0].size(); ++j)
		{
			if (b[i][j] == treasure)
			{
				return std::pair<int, int> (i, j);
			}
		}
	}
}
#include <iostream>
#include <vector>

typedef std::vector<int> Row;
typedef std::vector<Row> matrix;

int main()
{
	int n, m;
	std::cin >> n >> m;

	matrix mat(n, Row(m));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			std::cin >> mat[i][j];
		}
	}

	bool hasValue = false;
	int min;
	for (int j = 0; j < m; ++j)
	{
		int max = mat[0][j];
		for (int i = 1; i < n; ++i)
		{
			if (mat[i][j] > max)
			{
				max = mat[i][j];
			}
		}
		if (!hasValue)
		{
			min = max;
			hasValue = true;
		}
		else if (max < min)
		{
			min = max;
		}
	}
	std::cout << min << "\n";
}
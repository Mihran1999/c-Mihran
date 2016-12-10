#include <iostream>
#include <vector> 
#include <algorithm>

int main()
{
	int m, n;
	std::cin >> m >> n;

	std::vector<std::vector<int>> matrix(m, std::vector<int>(n));

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			std::cin >> matrix[i][j];
		}
	}

	
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i == 0 && j == 0)
			{
				continue;
			}
			if (i == 0)
			{
				matrix[i][j] += matrix[i][j - 1];
				continue;
			}
			if (j == 0)
			{
				matrix[i][j] += matrix[i - 1][j];
				continue;
			}
			matrix[i][j] += std::min(matrix[i][j - 1], matrix[i - 1][j]);
		}
	}
	std::cout << matrix[m - 1][n - 1];
}
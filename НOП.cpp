#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int n;
	std::cin >> n;

	std::vector<int> v_1(n);

	for (int i = 0; i < n; ++i)
	{
		std::cin >> v_1[i];
	}

	int m;
	std::cin >> m;

	std::vector<int> v_2(m);

	for (int i = 0; i < m; ++i)
	{
		std::cin >> v_2[i];
	}


	std::vector<std::vector<int>> matrix(n, std::vector<int>(m));
	if (v_1[0] == v_2[0])
	{
		matrix[0][0] = 1;
	}
	for (int i = 1; i < n; ++i)
	{
		if (v_1[i] == v_2[0])
		{
			matrix[i][0] = 1;
		}
		else
		{
			matrix[i][0] = matrix[i - 1][0];
		}
	}

	for (int i = 1; i < m; ++i)
	{
		if (v_1[0] == v_2[i])
		{
			matrix[0][i] = 1;
		}
		else
		{
			matrix[0][i] = matrix[0][i - 1];
		}
	}

	for (int i = 1; i < n; ++i)
	{
		for (int j = 1; j < m; ++j)
		{
			if (v_1[i] == v_2[j])
			{
				matrix[i][j] = matrix[i - 1][j - 1] + 1;
			}
			else
			{
				matrix[i][j] = std::max(matrix[i - 1][j], matrix[i][j - 1]);
			}
		}
	}
	std::cout << matrix[m - 1][n - 1] << " " << "\n";
}
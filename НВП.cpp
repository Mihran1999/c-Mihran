#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
	int n;
	std::cin >> n;

	std::vector<int> v(n);

	for (int i = 0; i < n; ++i)
	{
		std::cin >> v[i];
	}

	std::vector<int> v2(n);
	v2[0] = 1;
	int answer = 1;

	for (int i = 0; i < n; ++i)
	{
		int maximum = 0;
		for (int j = 0; j < i; ++j)
		{
			if (v[i] > v[j])
			{
				maximum = std::max(maximum, v2[j]);
			}
		}
		v2[i] = maximum + 1;
		if (v2[i] > answer)
		{
			answer = v2[i];
		}
	}

	std::cout << answer;
}
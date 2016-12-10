#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	
	long long int count = 3;
	for (int i = 0; i < n - 1; ++i)
	{
		count *= 2;
	}

	std::cout << count << "\n";
}
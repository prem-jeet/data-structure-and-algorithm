#include <iostream>

class Solution
{
public:
	int n; // number of disks
	char from, to, aux;

public:
	Solution() : from('A'), to('C'), aux('B') {}

	void solve(int n, char &from, char &to, char &aux, int &count)
	{
		count++;
		if (n == 1)
		{
			std::cout << from << " --> " << to << std::endl;
			return;
		}
		solve(n - 1, from, aux, to, count);
		std::cout << from << " --> " << to << std::endl;
		solve(n - 1, aux, to, from, count);
	}

	int toh(int n)
	{

		int count = 0;
		solve(n, from, to, aux, count);
		return count;
	}
};

int main()
{

	Solution s;

	std::cout << "----Solution for 1 disk----" << std::endl;
	std::cout << s.toh(1) << " Steps" << std::endl;

	std::cout << "----Solution for 2 disk----" << std::endl;
	std::cout << s.toh(2) << " Steps" << std::endl;

	std::cout << "----Solution for 3 disk----" << std::endl;
	std::cout << s.toh(3) << " Steps" << std::endl;

	std::cin.get();
}
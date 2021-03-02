#include <iostream>
#include <vector>

class Solution
{
public:
	void generate_string(int n)
	{
		std::vector<int> vec(n);
		generate_string_helper(vec, n, n);
	}

	void generate_string_helper(std::vector<int> &vec, int n, int &size)
	{
		if (n == 0)
		{
			print_vector(vec);
			return;
		}
		vec[size - n] = 0;
		generate_string_helper(vec, n - 1, size);
		vec[size - n] = 1;
		generate_string_helper(vec, n - 1, size);
	}

	void print_vector(std::vector<int> &vec)
	{
		for (auto &x : vec)
			std::cout << x;
		std::cout << std::endl;
	}
};

int main()
{
	Solution s;

	std::cout << "--- 2-bit string---" << std::endl;
	s.generate_string(2);

	std::cout << std::endl
			  << "--- 3-bit string---" << std::endl;
	s.generate_string(3);

	std::cout << std::endl
			  << "--- 4-bit string---" << std::endl;
	s.generate_string(4);

	exit(0);
}
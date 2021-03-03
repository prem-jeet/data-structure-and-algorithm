#include <iostream>
#include <vector>

class Solution
{
public:
	void generate_string(const std::vector<int> &input_array, int string_length)
	{
		std::vector<int> output_array(string_length, 0);
		generate_string_helper(input_array, output_array, string_length);
	}

private:
	void generate_string_helper(const std::vector<int> &input_array, std::vector<int> &output_array, int string_length)
	{
		if (string_length == 0)
		{
			print_vector(output_array);
			return;
		}

		for (const int &i : input_array)
		{
			output_array[output_array.size() - string_length] = i;
			generate_string_helper(input_array, output_array, string_length - 1);
		}
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

	std::vector<int> input_array = {1, 2, 3};

	std::cout << "--- string of length 1 ---" << std::endl;
	s.generate_string(input_array, 1);

	std::cout << "\n--- string of length 2 ---" << std::endl;
	s.generate_string(input_array, 2);

	std::cout << "\n--- string of length 3 ---" << std::endl;
	s.generate_string(input_array, 3);

	exit(0);
}
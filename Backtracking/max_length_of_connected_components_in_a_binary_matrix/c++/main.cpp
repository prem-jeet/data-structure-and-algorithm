#include <iostream>
#include <vector>

class Solution
{
private:
	std::vector<int> ROW;
	std::vector<int> COL;

public:
	Solution()
		: ROW({0, 0, -1, 1, -1, -1, 1, 1}),
		  COL({-1, 1, 0, 0, -1, 1, -1, 1}) {}

	int find_max_component(std::vector<std::vector<int>> input_grid)
	{
		int rows = input_grid.size();
		int cols = input_grid[0].size();
		int max = 0;
		for (int curr_row = 0; curr_row < rows; curr_row++)
		{
			for (int curr_col = 0; curr_col < cols; curr_col++)
			{
				if (input_grid[curr_row][curr_col])
				{

					int curr_max = find_component_length(input_grid, rows, cols, curr_row, curr_col);
					max = (curr_max > max ? curr_max : max);
				}
			}
		}
		return max;
	}

private:
	int find_component_length(
		std::vector<std::vector<int>> &input_grid,
		const int &rows,
		const int &cols,
		int curr_row, int curr_col)
	{
		if (curr_row < 0 || curr_row >= rows || curr_col < 0 || curr_col >= cols)
			return 0;
		if (input_grid[curr_row][curr_col] == 0)
			return 0;
		int sum = 1;
		input_grid[curr_row][curr_col] = 0;
		for (int i = 0; i < 8; i++)
		{
			sum += (find_component_length(input_grid, rows, cols, curr_row + ROW[i], curr_col + COL[i]));
		}
		return sum;
	}
};

int main()
{

	Solution s;

	std::vector<std::vector<int>> vec1;
	vec1.push_back({1, 1, 0, 0, 0});
	vec1.push_back({0, 1, 0, 1, 0});
	vec1.push_back({0, 0, 0, 1, 0});
	vec1.push_back({0, 0, 1, 0, 1});
	vec1.push_back({1, 0, 0, 1, 0});

	std::cout << s.find_max_component(vec1) << std::endl;

	std::vector<std::vector<int>> vec2;
	vec2.push_back({1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1});
	vec2.push_back({0, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1});

	std::cout << s.find_max_component(vec2) << std::endl;

	exit(0);
}
from solution import Solution

s = Solution()

input_grid = [
    [1, 1, 0, 0, 1],
    [0, 1, 0, 1, 0],
    [0, 0, 0, 0, 0],
    [0, 0, 1, 1, 1],
    [0, 0, 1, 1, 0]
]

print(s.find_max_component(input_grid))

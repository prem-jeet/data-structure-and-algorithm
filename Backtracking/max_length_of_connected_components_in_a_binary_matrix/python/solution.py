class Solution:
    def __init__(this):
        this.ROW = [0, 0, -1, 1, -1, -1, 1, 1]
        this.COL = [-1, 1, 0, 0, -1, 1, -1, 1]

    def find_max_component(this, input_grid):
        no_of_rows = len(input_grid)
        no_of_cols = len(input_grid[0])
        max = 0

        for row in range(no_of_rows):
            for col in range(no_of_cols):
                if(input_grid[row][col]):
                    curr_len = this.find_length(
                        input_grid, no_of_rows, no_of_cols, row, col)
                    max = curr_len if curr_len > max else max
        return max

    def find_length(this, input_grid, rows, cols, curr_row, curr_col):
        if(curr_row < 0 or curr_col < 0 or curr_row >= rows or curr_col >= cols):
            return 0
        if(not input_grid[curr_row][curr_col]):
            return 0

        sum = 1
        input_grid[curr_row][curr_col] = 0

        for i in range(8):
            sum += this.find_length(input_grid, rows, cols,
                                    curr_row+this.ROW[i], curr_col+this.COL[i])

        return sum

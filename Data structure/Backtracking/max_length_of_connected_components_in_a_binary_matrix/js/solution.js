class Solution {
  constructor() {
    this.ROW = [0, 0, -1, 1, -1, -1, 1, 1];
    this.COL = [-1, 1, 0, 0, -1, 1, -1, 1];
  }

  find_max_component(input_grid) {
    let max = 0;
    let rows = input_grid.length;
    let cols = input_grid[0].length;
    input_grid.forEach((row, curr_row_index) => {
      row.forEach((col_data, curr_col_index) => {
        if (col_data) {
          let curr_len = this.find_length(
            input_grid,
            rows,
            cols,
            curr_row_index,
            curr_col_index
          );
          max = curr_len > max ? curr_len : max;
        }
      });
    });

    return max;
  }

  find_length(input_grid, rows, cols, curr_row_index, curr_col_index) {
    if (
      curr_row_index < 0 ||
      curr_col_index < 0 ||
      curr_row_index >= rows ||
      curr_col_index >= cols
    )
      return 0;

    if (!input_grid[curr_row_index][curr_col_index]) return 0;

    input_grid[curr_row_index][curr_col_index] = 0;
    let sum = 1;

    for (let i = 0; i < 8; i++) {
      sum += this.find_length(
        input_grid,
        rows,
        cols,
        curr_row_index + this.ROW[i],
        curr_col_index + this.COL[i]
      );
    }
    return sum;
  }
}

module.exports = {
  Solution,
};

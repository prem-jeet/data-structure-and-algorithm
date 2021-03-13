const { Solution } = require("./solution");

const s = new Solution();

let input_grid = [
  [1, 1, 0, 0, 1],
  [0, 1, 0, 1, 0],
  [0, 0, 0, 0, 0],
  [1, 1, 1, 0, 0],
  [0, 0, 1, 1, 0],
];

console.log(s.find_max_component(input_grid));

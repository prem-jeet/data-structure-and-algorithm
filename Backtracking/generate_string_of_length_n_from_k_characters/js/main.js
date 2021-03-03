const { Solution } = require("./solution");

let s = new Solution();

let input_array = "ab";

console.log("--- string of length 1 ---");
s.generate_string(input_array, 1);

console.log("\n--- string of length 1 ---");
s.generate_string(input_array, 2);

console.log("\n--- string of length 1 ---");
s.generate_string(input_array, 3);

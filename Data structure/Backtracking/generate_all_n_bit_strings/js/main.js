const { Solution } = require("./solution");

let s = new Solution();

console.log("--- 2 bit strings --- ");
s.generate_string(2);

console.log("\n--- 3 bit strings --- ");
s.generate_string(3);

console.log("\n--- 4 bit strings --- ");
s.generate_string(4);

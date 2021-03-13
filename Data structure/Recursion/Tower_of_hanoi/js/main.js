const { Solution } = require("./solution");

let s = new Solution();

console.log("---- solution for 1 disk ----");
console.log(s.toh(1), " Steps", "\n");

console.log("---- solution for 2 disk ----");
console.log(s.toh(2), " Steps", "\n");

console.log("---- solution for 3 disk ----");
console.log(s.toh(3), " Steps");

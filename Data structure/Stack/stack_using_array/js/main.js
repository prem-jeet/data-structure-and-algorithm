const { Stack } = require("./stack");

const readline = require("readline-sync");

function interface() {
  console.log("------------------");
  console.log("    1. Push       ");
  console.log("    2. Pop        ");
  console.log("    3. Peek       ");
  console.log("    4. Size       ");
  console.log("    5. Is Empty   ");
  console.log("    6. Print      ");
  console.log("    7. Exit       ");
  console.log("------------------");
  console.log("");
}

const s = new Stack(4);

while (true) {
  interface();
  let choice = readline.questionInt("Enter your choice : ");

  switch (choice) {
    case 1: //Push
      {
        let data = readline.questionInt("Enter data : ");
        s.push(data);
      }
      break;

    case 2: // Pop
      {
        let data = s.pop();
        console.log(data, " was popped from the stack.");
      }
      break;

    case 3: // Peek
      {
        let data = s.peek();
        console.log("Top the stack contains ", data);
      }
      break;

    case 4: // size
      console.log("stack contains ", s.size(), " items.");
      break;

    case 5: // Empty
      console.log(s.empty());
      break;

    case 6: // Print
      s.print();
      break;
    case 7: // exit
      process.exit();

    default:
      console.log("Invalid choice");
  }
}

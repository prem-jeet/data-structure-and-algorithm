const { circularLL } = require("./circularLL");
const readline = require("readline-sync");

const L = new circularLL();

var interface = () => {
  console.log();
  console.log("*******************************");
  console.log("*   1.INSERT AT BEGINNING     *");
  console.log("*   2.INSERT AT END           *");
  console.log("*   3.INSERT AT POSITION      *");
  console.log("*   4.DELETE FROM BEGINNING   *");
  console.log("*   5.DELETE FROM END         *");
  console.log("*   6.DELETE FROM POSITION    *");
  console.log("*   7.PRINT lIST              *");
  console.log("*   8.EXIT                    *");
  console.log("*******************************");
};

while (true) {
  interface();
  let choice = readline.questionInt("Enter yout choice : ");

  switch (choice) {
    case 1:
      {
        let data = readline.questionInt("Enter data: ");
        L.insert_at_beginning(data);
      }
      break;

    case 2:
      {
        let data = readline.questionInt("Enter data : ");
        L.insert_at_end(data);
      }
      break;

    case 3:
      {
        let position = readline.questionInt("Entre the position : ");
        let data = readline.questionInt("Entre the data : ");
        L.insert_at_position(position, data);
      }
      break;

    case 4:
      L.delete_from_beginning();
      break;

    case 5:
      L.delete_from_end();
      break;

    case 6:
      {
        {
          let position = readline.questionInt("Entre the position : ");
          L.delete_from_position(position);
        }
      }
      break;

    case 7:
      L.print_list();
      break;

    case 8:
      process.exit();

    default:
      console.log("Invalid option");
  }
}

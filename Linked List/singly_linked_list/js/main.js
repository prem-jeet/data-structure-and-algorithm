const { Linklist } = require("./linklist");

const L = new Linklist();

// THE INPUTS

//INSERT 1 AT BEGINNING
L.insert_at_start(1);

//INSERT 2 AT END
L.insert_at_end(2);

//INSERT 3 AT BEGINNING
L.insert_at_start(3);

//INSERT 0 AT POSITION 3
L.insert_at_position(3, 0);

//INSERT 12 AT POSITION 5
L.insert_at_position(5, 12);

//PRINT LIST
Linklist.print_list(L); // 3 1 0 2 12 null

//DELETE FROM START
L.delete_from_beginning();

//DELETE FROM END
L.delete_from_end();

//PRINT LIST
Linklist.print_list(L); // 1 0 2 NULL

//DELETE FROM 2ND POSITION
L.delete_from_position(2);

//PRINT LIST
Linklist.print_list(L); // 1  2 NULL

//PRINT THE SIZE OF THE LIST
console.log("The list contain ", L.list_size(), " element");

//CLEAR LIST
Linklist.clear_list(L);

//PRINT LIST
Linklist.print_list(L); // 1  2 NULL

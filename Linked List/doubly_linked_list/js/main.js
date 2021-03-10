const { doublyLL } = require("./doublyLL");

const L = new doublyLL();

L.insert_at_beginning(1);
L.insert_at_end(2);
L.insert_at_beginning(3);
L.print_list(); // 3 1 2

L.insert_at_positon(1, 10);
L.insert_at_positon(L.size() + 1, 10);
L.insert_at_positon(3, 10);
L.print_list(); // 10 3 10 1 2 10

L.delete_from_end();
L.delete_from_beginning();
L.delete_from_position(2);
L.print_list(); // 3 1 2

L.clear_list();
L.print_list(); // null

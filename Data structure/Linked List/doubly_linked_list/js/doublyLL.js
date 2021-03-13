class Node {
  constructor(data) {
    this.data = data;
    this.next = null;
    this.prev = null;
  }
}

class doublyLL {
  constructor() {
    this.head = null;
    this.tail = null;
    this.count = 0;
  }

  //METHOD TO INSERT  AT BEGINNING
  insert_at_beginning(data) {
    this.count++;
    let new_node = new Node(data);

    if (this.count == 1) {
      this.head = this.tail = new_node;
      return;
    }

    new_node.next = this.head;
    this.head.prev = new_node;
    this.head = new_node;
  }

  //METHOF TO INSERT AT END
  insert_at_end(data) {
    this.count++;
    let new_node = new Node(data);

    if (this.count == 1) {
      this.head = this.tail = new_node;
      return;
    }

    this.tail.next = new_node;
    new_node.prev = this.tail;
    this.tail = new_node;
  }

  //METHOD TO INSERT AT A GIVEN POSIOTION
  insert_at_positon(position, data) {
    if (position < 1 || position > this.count + 1) {
      console.log("Invalid popsition.");
      return;
    }

    if (position == 1) {
      this.insert_at_beginning(data);
      return;
    }
    if (position == this.count + 1) {
      this.insert_at_end(data);
      return;
    }
    this.count++;
    let ptr = this.head;
    let index = 1;
    let new_node = new Node(data);
    while (index != position) {
      index++;
      ptr = ptr.next;
    }
    new_node.prev = ptr.prev;
    new_node.next = ptr;
    ptr.prev.next = new_node;
    ptr.prev = new_node;
  }

  //METHOD TO DELETE FROM BEGINNING
  delete_from_beginning() {
    if (this.count == 0) {
      console.log("Empty list.");
      return;
    }
    this.count--;
    this.head = this.head.next;
    if (this.count != 0) this.head.prev = null;
  }

  //METHOD TO DELETE FROM END
  delete_from_end() {
    if (this.count == 0) {
      console.log("Empty list.");
      return;
    }
    this.count--;
    this.tail = this.tail.prev;
    if (this.count != 0) this.tail.next = null;
  }

  //METHOD TO DELETE FROM A GIVEN POSITION
  delete_from_position(position) {
    if (position < 1 || position > this.count) {
      console.log("Invalid popsition.");
      return;
    }

    if (position == 1) {
      this.delete_from_beginning();
      return;
    }
    if (position == this.count) {
      this.delete_from_end();
      return;
    }

    this.count--;
    let ptr = this.head;
    let index = 1;
    while (index != position) {
      index++;
      ptr = ptr.next;
    }

    ptr.prev.next = ptr.next;
    ptr.next.prev = ptr.prev;
    ptr.next = null;
    ptr.prev = null;
  }

  //METHOD TO PRINT THE LIST
  print_list() {
    let ptr = this.head;
    while (ptr) {
      process.stdout.write(ptr.data + " <--> ");
      ptr = ptr.next;
    }
    console.log("null");
  }

  //MEHTHOD TO CLEAR THE LSIT
  clear_list() {
    this.head = this.tail = null;
    this.count = 0;
  }

  //METHOD RETURNS SIZE OF THE LIST
  size() {
    return this.count;
  }
}

module.exports = {
  doublyLL,
};

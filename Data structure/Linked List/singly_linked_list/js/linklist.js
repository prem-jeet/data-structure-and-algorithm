class Node {
  constructor(data) {
    this.data = data;
    this.next = null;
  }
}

class Linklist {
  constructor() {
    this.head = null;
    this.count = 0;
  }

  //MEHTHOD TO INSERT AT START
  insert_at_start(data) {
    let new_node = new Node(data);
    this.count++;

    if (this.head === null) {
      this.head = new_node;
      return;
    }

    new_node.next = this.head;
    this.head = new_node;
  }

  //MEHTHOD TO INSERT AT END
  insert_at_end(data) {
    let new_node = new Node(data);
    this.count++;

    if (this.head === null) {
      this.head = new_node;
      return;
    }

    let temp = this.head;
    while (temp.next != null) temp = temp.next;

    temp.next = new_node;
  }

  //MEHTHOD TO INSERT AT ANY POSITION
  insert_at_position(position, data) {
    if (position < 1 || position > this.count + 1) {
      console.log("Invalid position");
      return;
    }

    if (position === this.count + 1) {
      this.insert_at_end(data);
      return;
    }
    if (position === 1) {
      this.insert_at_start(data);
      return;
    }
    this.count++;
    let temp = this.head;
    let new_node = new Node(data);
    let index = 1;
    position -= 1;
    while (index != position) {
      temp = temp.next;
      index++;
    }

    new_node.next = temp.next;
    temp.next = new_node;
  }

  //MEHTHOD TO DELETE FROM BEGINNING
  delete_from_beginning() {
    if (this.count === 0) {
      console.log("Empty list");
      return;
    }
    this.count--;
    this.head = this.head.next;
  }

  //MEHTHOD TO DELETE FROM END
  delete_from_end() {
    if (this.count === 0) {
      console.log("Empty list");
      return;
    }
    this.count--;
    if (this.count === 1) {
      this.delete_from_beginning();
      return;
    }

    let temp = this.head;
    while (temp.next.next != null) temp = temp.next;
    temp.next = null;
  }

  //MEHTHOD TO DELETE FROM ANY GIVEN POSITION
  delete_from_position(position) {
    if (position < 1 || position > this.count) {
      console.log("Invalid position");
      return;
    }

    if (position === this.count) {
      this.delete_from_end();
      return;
    }
    if (position === 1) {
      this.deelte_from_beginning();
      return;
    }

    this.count--;
    let temp = this.head;
    position -= 1;
    let curr_index = 1;

    while (curr_index != position) {
      temp = temp.next;
      curr_index++;
    }

    temp.next = temp.next.next;
  }

  //METHOD RETRIVES THE DATA FROM A GIVEN POSITION
  get_data_from(position) {
    if (position < 1 || position > this.count) {
      console.log("Invalid Position.");
      return;
    }

    let index = 1;
    let ptr = this.head;
    while (index != position) {
      index++;
      ptr = ptr.next;
    }

    return ptr.data;
  }

  //METHOD TO PRINT THE LIST
  static print_list(list) {
    let temp = list.head;
    while (temp) {
      process.stdout.write(temp.data + "->");
      temp = temp.next;
    }
    console.log("null");
  }

  //METHOD RETURNS THE SIZE OF LIST
  list_size() {
    return this.count;
  }

  // METHOD TO CLEAR THE LIST
  static clear_list(list) {
    list.head = null;
    list.count = 0;
  }
}

module.exports = {
  Linklist,
};

class Node {
  constructor(data) {
    this.data = data;
    this.next = null;
  }
}

class circularLL {
  constructor() {
    this.head = null;
    this.count = 0;
  }

  //METHOD TO INSERT AT BEGINNING
  insert_at_beginning(data) {
    let new_node = new Node(data);
    // new_node.next = new_node;

    this.count++;
    if (this.count == 1) {
      this.head = new_node;
      this.head.next = this.head;
      return;
    }

    let ptr = this.head;
    while (ptr.next != this.head) ptr = ptr.next;

    new_node.next = ptr.next;
    ptr.next = new_node;
    this.head = new_node;
  }

  //METHOD TO INSERT AT END
  insert_at_end(data) {
    let new_node = new Node(data);
    new_node.next = new_node;

    this.count++;
    if (this.count == 1) {
      this.head = new_node;
      return;
    }

    let ptr = this.head;
    while (ptr.next != this.head) ptr = ptr.next;

    new_node.next = ptr.next;
    ptr.next = new_node;
  }

  //METHOD TO INSERT AT ANY POSITION
  insert_at_position(position, data) {
    if (position < 1 || position > this.count + 1) {
      console.log("Invalid Position");
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

    let new_node = new Node(data);
    let ptr = this.head;
    let index = 1;
    position--;

    while (index != position) {
      index++;
      ptr = ptr.next;
    }

    new_node.next = ptr.next;
    ptr.next = new_node;
  }

  //METHOD TO DELETE FROM BEGINNING
  delete_from_beginning() {
    if (this.count == 0) {
      console.log("Empty list");
      return;
    }

    this.count--;
    if (this.count == 0) {
      this.head = null;
      return;
    }

    let ptr = this.head;
    let temp = this.head;
    while (ptr.next != this.head) ptr = ptr.next;

    ptr.next = this.head.next;
    this.head = this.head.next;
    temp.next = temp;
  }

  //METHOD TO DELETE FROM END
  delete_from_end() {
    if (this.count == 0) {
      console.log("Empty list");
      return;
    }

    this.count--;
    if (this.count == 0) {
      this.head = null;
      return;
    }

    let ptr = this.head;

    while (ptr.next.next != this.head) ptr = ptr.next;

    let temp = ptr.next;
    ptr.next = this.head;
    temp.next = temp;
  }

  //METHOD TO DELETE FROM A POSITION
  delete_from_position(position) {
    if (position < 1 || position > this.count) {
      console.log("Invalid Position");
      return;
    }

    if (this.count == 0) {
      console.log("Empty list");
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
    position--;
    while (index != position) {
      index++;
      ptr = ptr.next;
    }
    let temp = ptr.next;
    ptr.next = temp.next;
    temp.next = temp;
  }

  //METHOD TO PRINT THE LIST
  print_list() {
    if (this.count == 0) {
      console.log("empty List.");
      return;
    }

    let ptr = this.head;
    process.stdout.write(ptr.data + " -> ");
    while (ptr.next != this.head) {
      ptr = ptr.next;
      process.stdout.write(ptr.data + " -> ");
    }
  }
}

module.exports = {
  circularLL,
};

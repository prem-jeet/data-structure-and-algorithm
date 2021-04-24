class Stack {
  constructor(n) {
    this.arr = new Array(n).fill(0);
    this.top = -1;

    this.capacity = n;
  }

  // Push inserts the item at end
  push(data) {
    if (this.isFull()) {
      console.log("Stack full.");
      return;
    }

    this.arr[++this.top] = data;
  }

  // Pop funstion removes the item from end and return it
  pop() {
    if (this.isEmpty()) {
      console.log("Stack Empty.");
      return;
    }
    let temp = this.arr[this.top--];
    return temp;
  }

  // Peek funtion gives the last item without removing it
  peek() {
    if (this.isEmpty()) {
      console.log("Stack Empty.");
      return;
    }
    let temp = this.arr[this.top];
    return temp;
  }

  print() {
    if (this.isEmpty()) {
      console.log("Stack is empty");
      return;
    }

    for (let i = this.top; i > -1; i--) console.log(this.arr[i]);
  }

  size() {
    return this.top + 1;
  }

  empty() {
    return this.isEmpty();
  }
  //Helper functions
  isEmpty() {
    return this.top == -1;
  }

  isFull() {
    return this.top == this.capacity - 1;
  }
}

module.exports = {
  Stack,
};

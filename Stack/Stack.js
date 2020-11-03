// create class with constructor for properties: items/data and size/count/top of array
class Stack {
  constructor() {
    this.items = [];
    this.size = 0;
  }

  // create methods for push, pop, and peek
  // when pushing increment the count/size
  push(element) {
    this.items[this.size] = element;
    this.size++;
    console.log(`added element: ${element}`);
  }

  // when popping/deleting decrement the count/size
  // delete item
  pop() {
    this.size--;
    console.log(`removed element: ${this.items.pop()}`);
    return this.items.pop();
  }

  peek() {
    console.log(`peek element: ${this.items[this.items.length - 1]}`);
    return this.items[this.items.length - 1];
  }

  // if the size === 0 then stack is empty
  isEmpty() {
    return this.size === 0;
  }
}

// test stack by creating new one
const stack = new Stack();

// perform operations
stack.isEmpty();

stack.push("dog");
stack.push("cat");

stack.peek()

stack.push("bear");
stack.push("owl")

stack.pop("cat");

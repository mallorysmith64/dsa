// LIFO - linear data structure

// create class with constructor for properties: items/data and size/count/top of array
class Stack {
  constructor() {
    this.items = [];
    this.size = 0;
  }

  // create methods for push, pop, and peek
  // when pushing increment the count/size
  push(element) {
    this.items.push(element);
    this.size++;
    console.log(`added element: ${element}`);
    return element; //this.items.push() works too
  }

  // if there is an element in the stack, decrement/pop item
  pop() {
    if (this.size > 0) 
    this.size--;
    console.log(`removed element: ${this.items.pop()}`);
    return this.items.pop();
  }

  peek() {
    console.log(`peek element: ${this.items[this.items.length - 1]}`);
    return this.items[this.items.length - 1];
  }

  getLength() {
    console.log(`size: ${this.size}`);
    return this.size;
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
stack.getLength();

stack.push("dog");
stack.push("cat");

stack.peek();

stack.push("bear");
stack.push("owl");

stack.pop("cat");

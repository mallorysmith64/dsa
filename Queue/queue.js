//FIFO - linear data structure

class Queue {
  constructor() {
    this.storage = [];
    this.head = 0;
    this.tail = 0;
  }

  //adding from back - tail is back
  enqueue(element) {
    this.storage[this.tail] = element;
    this.tail++;
    console.log(`added element: ${element}`);
  }

  //method 1: remove element from front/head
  // dequeue() {
  //   let removed = this.storage[this.head];
  //   delete this.storage[this.head];
  //   this.head++;
  //   console.log(`removed element: ${removed}`);
  //   return removed;
  // }

  // method 2: remove element from front/head
  dequeue() {
    if (this.isEmpty() === false) {
      this.tail--;
      console.log(`removed element: ${this.storage.shift()}`);
      return this.storage.shift();
    }
  }

  Length() {
    console.log(`length: ${this.tail}`);
    return this.tail;
  }

  isEmpty() {
    if (this.rear === 0) {
      console.log("The queue is empty!!!");
    }
  }
}

// test queue by performing operations
const queue = new Queue();
queue.enqueue("seahorse");
queue.enqueue("dolphin");
queue.enqueue("whale shark");

queue.dequeue();
queue.dequeue();

queue.Length();
queue.isEmpty();

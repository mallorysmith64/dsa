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

  //removing from front - head is front
  dequeue() {
    let removed = this.storage[this.head];
    delete this.storage[this.head];
    this.head++;
    console.log(`removed element: ${removed}`);
    return removed;
  }
}

// test queue by performing operations
const queue = new Queue();
queue.enqueue('seahorse')
queue.enqueue('dolphin')
queue.enqueue('whale shark')

queue.dequeue()
queue.dequeue()
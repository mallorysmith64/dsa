class DoublyLinkedNode {
  constructor(data) {
    this.data = data;
    this.prev = null;
    this.next = null;
  }
}

// create first node
const head = new DoublyLinkedNode(12);
// create second node, point head to second and second to head
const second = new DoublyLinkedNode(19);
head.next = second;
second.prev = head;

// add third node
const third = new DoublyLinkedNode(11);
second.next = third;
third.prev = second;

const tail = third;
console.log(head);

// traverse doubly linked list
let current = head;
while (current !== null) {
  console.log(`Traversed List: ${current.data}`);
  current = current.next;
}

// reverse doubly linked list
let currentBack = tail;
while (currentBack !== null) {
    console.log(`Reversed List: ${currentBack.data}`);
  currentBack = currentBack.prev;
}

// head and tail only accessed within class
class DoublyLinkedList {
  constructor() {
    this[head] = null;
    this[tail] = null;
  }

  push(data) {
    // create new node, place data in it
    const newNode = DoublyLinkedList(data);

    // if list is empty
    if (this[head] === null) {
      this[head] = newNode;
    } else {
      this[tail].next = newNode;
      newNode.prev = this[tail];
    }
    // make tail the newNode
    this[tail] = newNode;
  }
}

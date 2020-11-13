// dynamic data structure - can grow as needed
// def: each element is an object that has a pointer and a link to next object
// last node on the list points to null

// link list methods include: clear(), size(), getFirst(), and getLast()

// node
class LinkedListNode {
  constructor(data) {
    this.data = data;
    // next node is unknown at first
    this.next = null;
  }
}

// 1st node
const head = new LinkedListNode(12);
// second or next node
head.next = new LinkedListNode(99);
// add third or next node after that
head.next.next = new LinkedListNode(37);

// So, we have 12 -> 99 -> 37 -> null

// how to traverse/travel across the data in a linked list
let current = head;
while (current != head) {
    console.log(`traversed list: , ${current.data}`)
    current = current.next
}
class Node {
    constructor(value) {
        this.value = value;
        this.prev = null;
        this.next = null;
    }
}

// doubly linked list has 3 components: length, head, and tail/end
class DoublyLinkedList {
    constructor() {
        this.length = 0;
        this.head = null;
        this.tail = null;
    }
}

const newNode = new Node(1);
console.log(newNode);

const newList = new DoublyLinkedList(6);
console.log(newList);
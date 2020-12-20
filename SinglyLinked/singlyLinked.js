// dynamic data structure - can grow as needed
// def: each element is an object that has a pointer and a link to next object
// last node on the list points to null

// link list methods include: clear(), size(), getFirst(), and getLast()

// create node
class ListNode {
  constructor(data, next = null) {
   this.data = data;
   this.next = next;
  }
}

// create linked list, head is the 1st node
const head = new ListNode(12);
// second or next node
head.next = new ListNode(99);
// add third or next node after that
head.next.next = new ListNode(37);
head.next.next.next = new ListNode(100);
head.next.next.next.next = new ListNode(102);
console.log(head);

// So, we have 12 -> 99 -> 37 -> null

// traverse/travel across the data in a linked list
  let list = new ListNode(head)
  console.log(`element is: ${list.data.next.data}`)

// find middle node
  let fast = head, slow = head;

  while(fast && fast.next) {
    fast = fast.next.next;
    slow = slow.next;
  }
  console.log(`middle node is: ${slow.data}`);
  return slow;
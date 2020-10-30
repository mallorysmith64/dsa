import StackNode from './StackNode'

class Stack {
  constructor() {
    top = null

  }
  push(value) {
    console.log("PUSH")
    let node = new Node(value, top)
    top = node
  }
  print() {
    let ptr = top
    while (ptr) {
      console.log(ptr.value)
      ptr = ptr.nextNode
    }
    console.log('---')
  }
}

export default Stack
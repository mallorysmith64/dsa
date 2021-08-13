// create node class
class Node {
  constructor(value) {
    this.value = value
    this.left = null
    this.right = null
  }
}

// create BST class
class BST {
  constructor(value) {
    this.root = new Node(value)
    this.count = 1 // track how many nodes there are
  }

  size() {
    return this.count;
  }

  insert(value) {
    // increase count for each node inserted
    this.count++;

    let newNode = new Node(value);

    const searchTree = (node) => {
      // compare value being inserted to node value
      // if value < node.value, move left
      if (value < node.value) {
        // if there is no left child node, assign node here
        if (!node.left) {
          node.left = newNode;
        } else {
          // if there is a left child node, call function again and move left
          searchTree(node.left);
        }
      }
      // if value > node.value, move right
      else if (value > node.value) {
        if (!node.right) {
          // if no right child node, add node here
          node.right = newNode;
        } else {
          // if right child node exists, call search function again and move right
          searchTree(node.right);
        }
      }
    }
    // call search function again on root node
    searchTree(this.root);
  }

  min() {
    // assign root to current before moving left
    let current = this.root;

    // keep moving left repeatedly
    while (current.left) {
      // if node exists to left, assign to current
      current = current.left;
    }
    // return value of current found
    return current.value;
  }

  max() {
    // start current at root before moving right
    let current = this.root;

    // repeatedly move right
    while (current.right) {
      // if node exists to right, assign to current
      current = current.right;
    }
    // return value of current node found
    return current.value;
  }

  contains(value) {
    let current = this.root

    while (current) {
      // if value = current then value was found
      if (value === current.value) {
        return true
      }
      // value < current value, assign moving left to current
      if (value < current.value) {
        current = current.left
      } else {
        // value > current value, assign moving right to current
        current = current.right
      }
    }
    // if node doesn't exist, return false
    return false
  }

  // depth first search - branch by branch

  // 1. in-order: left, root, right
  dfsInOrder() {
    let result = []

    const transverse = (node) => {
      // if node is left, move left
      if(node.left) transverse(node.left)

      // push root node value
      result.push(node.value)

      // if node is right, move right
      if(node.right) transverse(node.right)
    }
    transverse(this.root)
    // return resulting array
    return result
  }

  // 2. pre-order: root, left, right
  dfsPreOrder() {
    let result = []

    const transverse = (node) => {
      // push root node value
      result.push(node.value)

      // if left child exists, move left
      if(node.left) transverse(node.left)

      // if right child exists, move right
      if(node.right) transverse(node.right)
    }
    transverse(this.root)
    // return resulting array
    return result
  }

  // 3. post-order: left, right, root
  dfsPostOrder() {
    let result = []

    const transverse = (node) => {

      // if left child exists, move left
      if(node.left) transverse(node.left)

      // if right child exists, move right
      if(node.right) transverse(node.right)

      // push root node value
      result.push(node.value)
    }
    transverse(this.root)
    // return resulting array
    return result
  }

  // breadth first search - level by level
  // use a queue!
  bfs() {
    let result = []
    let queue = []

    queue.push(this.root)

    while(queue.length) {
      let current = queue.shift()
      result.push(current.value)

      if(current.left) {
        queue.push(current.left)
      }
      if(current.right) {
        queue.push(current.right)
      }
    }
    return result
  }
}

const bst = new BST(30) // data here will be root node value, num of nodes = 1
bst.insert(11) // 2 nodes
bst.insert(36) // 3 nodes
bst.insert(2) // 4 nodes
bst.insert(31) // 5 nodes
bst.insert(28)
bst.insert(39)

console.log(bst)

const size = bst.size()
const min = bst.min()
const max = bst.max()
const exists = bst.contains(11)
const doesNotExist = bst.contains(9)

console.log(`There are ${size} nodes, 
the smallest value is ${min}, 
the largest value is ${max}.`)

if(exists) {
  console.log(`The value was found.`)
}

if(doesNotExist)
  console.log(`The value does not exist.`)

const inOrder = bst.dfsInOrder()
const preOrder = bst.dfsPreOrder()
const postOrder = bst.dfsPostOrder()

console.log("\n")
console.log(`InOrder breadth first search: `, inOrder) //if you use string interpolation the array brackets [] won't show up
console.log(`PreOrder breadth first search: `, preOrder)
console.log(`PostOrder breadth first search: `, postOrder)

const breathFirst = bst.bfs()
console.log(`Breadth first search: `, breathFirst)

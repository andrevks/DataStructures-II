//Singly LinkedList

class ListNode{
  constructor(data){
    this.data = data
    this.next = null
  }
}

class LinkedList {
  constructor(head = null){
    this.head = head
  }
}

size(){
  let size = 0 
  
}

//That's my plan
//[10] -> [25]-> null
let node = new ListNode(10)
let node1 = new ListNode(25)
//Pointer from node to node1 
node.next = node1

//Head points to node[10]
let list = new LinkedList(node)


console.log(list.head.data)//10
console.log(list.head.next.data)//25

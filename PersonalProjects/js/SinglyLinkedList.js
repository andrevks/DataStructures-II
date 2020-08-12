//Singly LinkedList

class Node{
  constructor(data){
    this.data = data
    this.next = null
  }
}
class LinkedList {
  constructor(func){
    this.head = undefined;
    this.size = 0;
    //this.equalFunc = func || defaultEq;

  }
  push(data){
    //head -> undefined
    //head -> [18] -> null
    const newNode = new Node(data);
    if(this.head == undefined){
      //[data]->null
      //Head -> [data]->null
      this.head = newNode;
    
    }else{
      //Head ->[data]->[data]->null
      let latestNode = this.head;
      
      while(latestNode.next){
        latestNode = latestNode.next;
      }

      latestNode.next = newNode;
      
    }
    this.size++;
    return 1;
  }
  getElementAt(index){
    
    if(index < 0 && index > this.size)return;

    let node = this.head;
    //Head ->[data]->[data]->null
    let count = 0;
    while(node && count < index){
      node = node.next;
      count++;  
    }
    return node;

  }
 
}




//That's my plan
//[10] -> [25]-> [77] -> null
let list = new LinkedList();
console.log(list.push(10))
console.log(list.push(15))
// console.log(list.head)
console.log("getElementAt:",list.getElementAt(1))


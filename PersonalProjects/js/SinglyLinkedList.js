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

  insert(data, pos){
    if( pos < 0 && pos > this.size)return;
    
    let newNode = new Node(data);
    if(pos == 0){
      if(this.head != undefined)newNode.next = this.head;
      this.head = newNode;
      this.size++;
      return 0;
    }

    let aux = this.getElementAt(pos -1);
    newNode.next = aux.next;
    aux.next = newNode;
    this.size++;
    return 1;
  }
  show(){
    let current = this.head;
    console.log("------- ---------");
    while( current != null){
      console.log("[",current.data,"]->");
      current = current.next;
    }
    console.log("------- ---------");
  }
 
}




//That's my plan
//[10] -> [25]-> [77] -> null
//[10] -> [25]->[100]->[77] -> null
//[100]->[10] -> [25]-> [77] -> null
let list = new LinkedList();
console.log(list.push(10))
console.log(list.push(25))
console.log(list.push(77))
// console.log(list.head)
console.log("getElementAt:",list.getElementAt(0))
console.log("inserted:",list.insert(100,0))
console.log("getElementAt:",list.getElementAt(0).data)
console.log("Size:",list.size)
list.show()

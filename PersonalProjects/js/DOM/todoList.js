var campo = document.querySelector("#app");
var inputElement = document.getElementById("addNew");
var listOfItems = document.getElementById("items");
var clearButton = document.querySelector("#clear");

var todoLists = [
    "Study Calculus",
    "Meditate",
    "Read a book"
];

function renderItems(){

   if(listOfItems.hasChildNodes())listOfItems.innerHTML = '';
   
   var listsParsed = JSON.parse(localStorage.todolists);
   console.log(typeof(listsParsed));
   
    for(const element of listsParsed){
        
        const text = document.createTextNode(element);
        const li = document.createElement('li');
        li.appendChild(text);
        const a = document.createElement('a');
        a.href = "#";
        a.innerHTML = " X";
        li.appendChild(a);

        let position = todoLists.indexOf(element);
        a.setAttribute('onclick',"removeItem("+position+")"); 
        listOfItems.appendChild(li);
    }
    
}
renderItems();

//function createItem(){

    //const item = document.createElement("li");
    //item.className = "todo";

    ////Adding input value to the item 
    //const text = document.createTextNode(inputValue);
    //item.appendChild(text);
    
    //const link = document.createElement("a");
    //link.href = 'javascript:removeItem(event)';

    ////Creating a Icon to delete
    //const deleteItemIcon = document.createTextNode(" X");
    //link.appendChild(deleteItemIcon);
    //item.appendChild(link);
    //listOfItems.appendChild(item);
//}

function createItem(){
    
    if(inputElement.value != ''){
        const inputValue = inputElement.value;
        todoLists.push(inputValue);
        saveLocalStorage();        
        renderItems(); 
        inputElement.value = '';
    }

}
document.getElementById("send").addEventListener("click",createItem);

function removeItem(pos){

    todoLists.splice(pos,1);  
    renderItems();
}

function clearLocalStorage(){
   localStorage.clear();
  
}
clearButton.addEventListener('click',clearLocalStorage);

function saveLocalStorage(){
    lists = JSON.stringify(todoLists);
    localStorage.todolists = lists;
}
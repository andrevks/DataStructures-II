var campo = document.querySelector("#app");
var inputElement = document.getElementById("addNew");
var listOfItems = document.getElementById("items");

var todoLists = [
    "Study Calculus",
    "Meditate",
    "Read a book"
];

function renderItems(){

   if(listOfItems.hasChildNodes())listOfItems.innerHTML = '';
   

    for(const element of todoLists){
        
        const text = document.createTextNode(element);
        const li = document.createElement('li');
        li.appendChild(text);
        const a = document.createElement('a');
        a.href = "javascript:removeItem()";
        a.innerHTML = " X";
        li.appendChild(a);

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
        renderItems(); 
        inputElement.value = '';
    }
 
}
document.getElementById("send").addEventListener("click",createItem);

function removeItem(){

    

}
//document.getElementById("eachItem").addEventListener('click',removeItem);
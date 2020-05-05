const campo = document.querySelector("#app");

function createItem(){
    
    const item = document.createElement("li");
    item.className = "todo";


    //Adding input value to the item 
    const inputValue = document.getElementById("addNew").value;
    const text = document.createTextNode(inputValue);
    item.appendChild(text);

    
    const link = document.createElement("a");
    link.href = 'javascript:removeItem(event)';

    //Creating a Icon to delete
    const deleteItemIcon = document.createTextNode(" X");
    link.appendChild(deleteItemIcon);
    item.appendChild(link);


    const listOfItems = document.getElementById("items");
    listOfItems.appendChild(item);

}


document.getElementById("send").addEventListener("click",createItem);

function removeItem(event){
   


}
//document.getElementById("eachItem").addEventListener('click',removeItem);
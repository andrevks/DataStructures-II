
// function mostraAlert(){
//     alert("Button was cliked");
// }

//document = variável global que referência a árvore de elementos

// const inputElement = document.getElementById('nome');
// const inputElement = document.getElementsByTagName('input');
// const inputElement = document.getElementsByClassName('nome');
const inputElement = document.querySelector('input[name=nome]');

const btnElement = document.querySelector('button.botao');

btnElement.onclick =() => {
    let text = inputElement.value;
    alert(text);

}

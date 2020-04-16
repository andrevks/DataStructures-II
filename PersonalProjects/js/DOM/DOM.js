
// // function mostraAlert(){
// //     alert("Button was cliked");
// // }

// //document = variável global que referência a árvore de elementos

// // const inputElement = document.getElementById('nome');
// // const inputElement = document.getElementsByTagName('input');
// // const inputElement = document.getElementsByClassName('nome');
// // const inputElement = document.querySelector('input[name=nome]');

// // const btnElement = document.querySelector('button.botao');

// // btnElement.onclick =() => {
// //     let text = inputElement.value;
// //     alert(text);

// // }



// const linkElement = document.createElement('a');

// linkElement.setAttribute('href','https://codebebo.com/javascript-is-awesome');
// linkElement.setAttribute('title','Blog sobre javascript');
// //para incluir texto:

// const textElement = document.createTextNode('Acessar site do javascript');

// //para posicionar o texto dentro do elemento com o link:

// linkElement.appendChild(textElement);

// const containerElement = document.querySelector("#app");


// //adicionar o link dentro da div
// // containerElement.appendChild(linkElement);

// // const inputElement = document.querySelector("#nome");

// // containerElement.removeChild(inputElement);

// // ------------------------------

// let boxElement = document.querySelector('#app');

// boxElement.style.width = 100;
// boxElement.style.height = 100;
// boxElement.style.title = "wow";
// boxElement.style.backgroundcolor = "#f00";

// -----------------------------

//exercício1

function createB(){
    
    const boxElement = document.createElement("div");
    boxElement.style.width = "100px";
    boxElement.style.height = "100px";
    boxElement.style.backgroundColor = "#f00";

    const APP = document.querySelector('#app');

    APP.appendChild(boxElement);
}

//exercício2

function getRandomColor(){

    const letters = "0123456789ABCDEF";
    let color = "#";

    for(let i = 0; i<6;i++){
        color += letters[Math.floor(Math.random()*16)];
    }

    return color;
}





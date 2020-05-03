
//Intervals and Timeouts

//função e tempo de atualização em milisegundos
// setInterval(() => {
//     console.log('Hello World');
// },1000);

//Executa apenas uma vez
// setTimeout(() => {
//     console.log('Hello World');
// },5000)

//Exercício 1

const endereço = {
    rua: "Rua dos pinheiros",
    número: 1293,
    bairro: "Centro",
    cidade: "São Paulo",
    uf:"SP"
};

//Declusturing
const {rua,número,bairro,cidade,uf} = endereço;

document.writeln(`<h4>Ex1</h4>`);

document.writeln(`<p>O usuário mora em ${cidade} / ${uf}, no bairro
${bairro}, na rua ${rua} com número ${número}</p>`);

//Exercício 2


document.writeln(`<h4>Ex2</h4>`);

function pares(x,y){
    
    for(let i = x; i <= y;i++){

        if( i%2 == 0){
            document.writeln(i);
        }
    }
}

pares(32,321);

//Exercício 3

document.writeln(`<h4>Ex3</h4>`);

function temHabilidade(skills){
    
    // for(let x = (skills.length - 1); x >= 0 ; x--){

    //     if(skills[x] == "Javascript"){
    //         return true;
    //     }
    // }

    // return false;

    //Outra maneira:
    //indexOf retorna a posicão ou -1 caso não encontre 
        return skills.indexOf("Javascript",[PontoInicial = 0]) > -1;

}

const skills = ["Javascript","ReactJS","React Native"];
document.writeln(`<p>Tem Habilidade Javascript? ${temHabilidade(skills)}</p>`);


//Exercício 4

document.writeln(`<h4>Ex4</h4>`);

function experiencia(anos){

        if(anos <= 1)return document.writeln("Iniciante");
          
        if(anos >1 && anos<=3) return document.writeln("Intermediário");
          
        if(anos>3 && anos <=6) return document.writeln("Avançado");
          
        if(anos >=7)  return document.writeln("Jedi Master");
    
        if(anos<0)  return document.writeln("Tem que estudar DEV");
        
}

let anosEstudo = 7;
experiencia(anosEstudo);



//Exercício 5

document.writeln(`<h4>Ex5</h4>`);





const usuarios = [
    {
        nome:"Diego",
        habilidades:["Javascript","ReactJS","Redux"]
    },
    {
        nome: "Gabriel",
        habilidades: ["VueJS","Ruby on Rails","Elixir"]
    }
    
]

function printUsuarios(users){

    for(let value of users){
        document.writeln(`<p>O ${value.nome} possui as habilidades: ${value.habilidades.join([separador = ", "])}</p>`);
    }

}

printUsuarios(usuarios);

//Exercises from the Program Structure Chapter(2)

let pyramid = "";
// console.log(typeof(pyramid));
// for(let i = 0; i<7;i++){
//     pyramid +="#";
//     console.log(pyramid);
// }

console.log("-------------\n");

// for(let i =0; i<100;i++){
//     if( i % 3 == 0) console.log("Fizz");
//     else if( i % 5 == 0) console.log("Buzz");
//     else if( i % 3==0 && i%5==0)console.log("FizzBuzz");
//     else console.log(i);
// }


function chessBoard(size){
    let grid = "";
    let PrintC = false;

    for(let i = 0; i<size;i++){

        (i % 2 ==0)?PrintC = true:PrintC= false;

        for(let j = 0; j<size;j++){

            if(PrintC){
                
                grid+=" "; 
                PrintC = false;

            }    
            else {
                
                grid+="#";
                PrintC = true;
            }
        }

        grid+="\n";
    }
    return grid;
}

console.log(chessBoard(10));
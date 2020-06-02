const EventEmitter = require('events');
class MeuEmissor extends EventEmitter {

}
const meuEmissor = new MeuEmissor();
//manipulador de eventos
const nomeEvento = 'usuario:click'; 
meuEmissor.on(nomeEvento,(click)=>{
    console.log("Um usuário clicou",click);
});


//meuEmissor.emit(nomeEvento,'na barra de rolagem');
//meuEmissor.emit(nomeEvento,'no Ok');

//let count = 0;
//setInterval(()=>{
    //meuEmissor.emit(nomeEvento,'no Ok ' + (count++));
//},1000)

const stdin = process.openStdin();
stdin.addListener('data',function(value){
    console.log(`You typed: ${value.toString().trim()}`)
})
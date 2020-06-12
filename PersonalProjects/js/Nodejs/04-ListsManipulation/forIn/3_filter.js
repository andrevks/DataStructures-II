//Do objeto json que foi requisitado, somente quero extrair o getpeople
const { getPeople } = require('./service');

/*

const item = {
    nome: 'João',
    idade: 15
}

const { nome,idade } = item;

*/
Array.prototype.myFilter = function(callback){
    const myNewFilteredArray = [];
    for(let index = 0; index<this.length; index++){
        const result = callback(this[index]);
        if(!result) continue;
        myNewFilteredArray.push(this[index]);
        //if(result)myNewFilteredArray.push(this[index]);
    }
    return myNewFilteredArray;
}
async function main (){
    try {
       const { results } = await getPeople('a');
       //const larsFamily = results.filter(function(item){
            //// por padrão precisa retorar um booleano 
            ////para informar se deve manter ou remover da lista
            ////false > "remove" da lista
            ////true >   mantem
            //const result = item.name.toLowerCase().indexOf('lars') !== -1;
            //return result; 
       //});
       const larsFamily = results.myFilter((item)=>{
           const result = item.name.toLowerCase().indexOf("lars") !== -1;
           return result;
       })
       const names = larsFamily.map( pessoa => pessoa.name);
       console.log(`names:`,names);
    } catch (error) {
       console.log("Something went wrong:",error); 
    }
}
main();
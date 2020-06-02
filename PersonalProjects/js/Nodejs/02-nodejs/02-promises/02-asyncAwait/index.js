/*
0 - Obter um usuario
1 - Obter o número de um telefone de um usuário a partir de seu ID
2 - Obter o endereço do usuário pelo ID
*/

//Foi importado um módulo interno do node.js
const util = require('util');
//const getAsyncAddress = util.promisify(getAddress);


function getUser(){ 
    //Quando der algum problema -> usa função reject(ERROR)  
    //Quando der tudo certo (SUCCESS) -> usa a função resolve
   return new Promise(function solvePromise(resolve, reject){
        
        setTimeout( ()=>{
            //Quando a função terminar de executar
            //o estado getUser vai mudar para fullfilled 
            //e quem chamá-lo conseguirá executar e resolver
            //essas informações
            //return reject(new Error("A real error happend!!!"));
            return resolve({
                    id:1,
                    nome:'Medina',
                    birth:new Date()
                });
        }, 1000);
   });
}
function getPhone(idUser){
    return new Promise(function solvePromise(resolve,reject){
        setTimeout(() =>{
            return resolve({
                phone:'999396734',
                ddd: 11 
            });
        }, 2000); 
    });
          
} 

function getAddress(idUser){
    return new Promise(function solverAddress(resolve,reject){
        setTimeout(()=>{
            return resolve({
                road:'alves',
                number: 09
            });
        }, 2000);
    });
}

//1 - adicionar a palavra async -> automaticamente
//ela retonará uma   Promise
main()
async function main(){
    try {
        console.time('medida-promise');
        const user = await getUser();
        //const phone = await getPhone(user.id);
        //const address = await getAddress(user.id);
        const result = await Promise.all([
            getPhone(user.id),
            getAddress(user.id)
        ])
        const phone = result[0];
        const address = result[1];

        console.log(`
            Name: ${user.nome},
            Phone: (${phone.ddd}) ${phone.phone},
            Address: ${address.road}, ${address.number}
        
        `)
        console.timeEnd('medida-promise');

    } catch (error) {
        console.error("SOMETHING WENT WRONG",error);
    }
}

//const userPromise = getUser();
////Para manipular o sucesso usa-se a função .then
////Para manipular erros usa-se o .catch
//// user -> phone -> phone(última)
//userPromise
    //.then(function (user){
        ////captura o user e devolve o phone
        //return getPhone(user.id)
            //.then(function solvePhone(result){
               //return {
                   //user:{
                       //nome: user.nome,
                       //id: user.id
                   //},
                   //phone:result
               //} 
            //})
    //})
    //.then(function (previousResult){
        //const address = getAsyncAddress(previousResult.user.id)
        //return address.then(function solverAddress(result){
            //return {
                //user:previousResult.user,
                //phone:previousResult.phone,
                //address:result
            //}
        //})
    //})
    //.then(function(result){
        ////Nesse caso o resultado é o user
        //console.log(`
            //Name: ${result.user.nome},
            //Address: ${result.address.road},${result.address.number},
            //Phone: (${result.phone.ddd})${result.phone.phone}
        //`)
    //})
    //.catch(function(error){
        //console.log("A error happend:",error);
    //})


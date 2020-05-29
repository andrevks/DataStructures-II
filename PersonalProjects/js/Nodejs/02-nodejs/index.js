/*
0 - Obter um usuario
1 - Obter o número de um telefone de um usuário a partir de seu ID
2 - Obter o endereço do usuário pelo ID
*/
function getUser(callback){ 
    //Executa uma função após 1 segundo
    setTimeout(() => {
        return callback(null,{
            id:1,
            nome:'Medina',
            birth:new Date()
        })
    }, 1000);
}
function getPhone(idUser,callback){
    setTimeout(() =>{
        return callback(null,{
            phone:'999396734',
            ddd: 11
        })
    }, 2000);
}
function getAddress(idUser, callback){
    setTimeout(()=>{
        return callback(null,{
           road:'alves',
           number: 09
        })
    })
}

function userSolver(erro,user){
    console.log(`User: ${user}`);
}

getUser(function userSolver(error,usuario){
    //null || "" || 0 === false
    if(error){
        console.error("Error in USER...", error);
        return;
    } 
    getPhone(user.id, function phoneSolver(error1,phone){
        
        if(error1){
            console.error("Error in USER...", error);
            return;
        } 
        getAddress(user.id,function solverAddress(error2, address){
            if(error2){
                console.error("Error in USER...", error);
                return;
            } 

            console.log(`
                Name: ${user.nome},
                Address: ${address.road},${address.number},
                Phone: (${phone.ddd})${phone.phone}
            `)
        })
                
    })
});

//const phone = getPhone(user.id);
//const address = getAddress(user.id);

//console.log(`Phone: ${phone}`);

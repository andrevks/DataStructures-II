const Commander = require('commander')
const Database = require('./database')
const  Hero  = require('./heros')
async function main(){
    Commander
        .version('v1')
        //tudo que passar de argumento para o projeto
        //será convertido
        .option('-n , --name [value]', "Hero's name")
        .option('-p , --power [value]', "Hero's power")
        .option('-i , --id [value]',"Hero's id")


        .option('-r, --register', "Register a hero")
        .option('-l, --list ', "To list the hero by id or all the heros")
        .option('-rem, --remove ',"To remove the hero from the id")
        .option('-u, --update [value]',"To update the hero")
        .parse(process.argv)
    const hero = new Hero(Commander)
    try {
        if(Commander.register) {
            delete hero.id
            const result = await Database.register(hero)
            if(!result){
                console.error("Hero couldn't be registered")
                return;
            } 
            console.log("Hero registered sucessfully")
        }
        
        if(Commander.list){
            const result = await Database.listData(hero.id)
            console.log(`Heros`,result)
            return;
        }

        if(Commander.remove){
            const result = await Database.remove(hero.id)
            if(!result){
                console.error("Hero couldn't be removed")
                return;
            } 
            console.log(`Hero removed successfully`)
            
        }

        if(Commander.update){
            const idUpdate = parseInt(Commander.update);
            //remover todas as chaves com undefined ou null
            const data = JSON.stringify(hero)
            const heroUpdate = JSON.parse(data)
            const result = await Database.update(idUpdate,heroUpdate)
            if(!result){
                console.error("The hero wasn't updated")
                return;
            }
            console.log("Hero updated sucessfully")
        }
    } catch (error) {

        console.error("Something went wrong:",error)
    }
}

main()
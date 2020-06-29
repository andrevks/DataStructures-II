const Commander = require('commander')
const Database = require('./database')
async function main(){
    Commander
        .version('v1')
        //tudo que passar de argumento para o projeto
        //será convertido
        .option('-n , --name [value]', "Hero's name")
        .option('-p , -power [value]', "Hero's power")

        .option('-r, --register', "Register a hero")
        .parse(process.argv)
    try {
        
    } catch (error) {

        console.log("Something went wrong:",error)
    }
}

main()
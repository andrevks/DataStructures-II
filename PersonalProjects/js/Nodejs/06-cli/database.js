const {
    readFile,
    writeFile
} = require('fs');

const {
    promisify
} = require('util');

const readFileAsync = promisify(readFile);
const writeFileAsync = promisify(writeFile);
//Outra forma de obter dados do json
//const dados = require('./heros.json')

class Database{
    constructor(){
        this.NOME_ARQUIVO = 'heros.json';
    }
    async getDadosArquivo(){
        const arquivo = await readFileAsync(this.NOME_ARQUIVO, "utf8")
        return JSON.parse(arquivo.toString())
    }
    async escreverArquivo(dados){
        await writeFileAsync(this.NOME_ARQUIVO,JSON.stringify(dados))
        return true;
    }
    async cadastrar(hero){
        const dados = await this.getDadosArquivo()
        const id = hero.id <= 2 ? hero.id : Date.now();

        const heroWithId ={
            id,
            ...hero
        }
        const finalData = [
            ...dados,
            heroWithId
        ]
        const result = await this.escreverArquivo(finalData);
        return result;
    }
    async listar(id){
        const dados = await this.getDadosArquivo()
        const dadosFiltrados = dados.filter(item => id ? item.id === id: true) 
        return dadosFiltrados 
    }
}

module.exports =  new Database();
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
        this.NAME_FILE = 'heros.json'; 
    }
    async getFileData(){
        const file = await readFileAsync(this.NAME_FILE, "utf8")
        return JSON.parse(file.toString())
    }
    async writeInFile(data){
        await writeFileAsync(this.NAME_FILE,JSON.stringify(data))
        return true;
    }
    async register(hero){
        const data = await this.getFileData();
        const id = hero.id <= 2 ? hero.id : Date.now();

        const heroWithId ={
            id,
            ...hero
        }
        const finalData = [
            ...data,
            heroWithId
        ]
        const result = await this.writeInFile(finalData);
        return result;
    }
    async listData(id){
        const data = await this.getFileData()
        const filteredData = data.filter(item => id ? item.id === id: true) 
        return filteredData; 
    }
    async remove(id){
        if(!id){
            return await this.writeInFile([]);
        }
        const data = await this.getFileData()
        const index = data.findIndex(hero => hero.id === parseInt(id))

        if(index === -1) throw Error("Usuário informado não existe")

        data.splice(index,1)
        return await this.writeInFile(data)
    }
    async update(id,newHero){
        const data = await this.getFileData()
        const index = data.findIndex(hero => hero.id === parseInt(id))
        if(index === -1) throw Error("Usuário informado não existe")

        const currentHero = data[index]
        currentHero.name = newHero.name;
        currentHero.power = newHero.power;

        return await this.writeInFile(data)
    }
}

module.exports =  new Database();
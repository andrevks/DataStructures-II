const {
    deepEqual,
    ok
} = require('assert');

const database = require('./database');

const DEFAULT_ITEM_CADASTRAR = { 
    nome:'Flash',
    poder:'Speed',
    id: 1
}

describe('Suite de manipulação de heróis',() => {
    it("Deve pesquisar um herói utilizando arquivos", async()=>{
        const expected = DEFAULT_ITEM_CADASTRAR;
        //descruture 
        const [ result ]= await database.listar(expected.id)
        deepEqual(result, expected)
        //ok(resultado,expected);
    })
    it("Deve cadastrar um herói, utilizando arquivos",async ()=>{
        const expected = DEFAULT_ITEM_CADASTRAR;
        const result = await database.cadastrar(DEFAULT_ITEM_CADASTRAR);
        const [ current ] = await database.listar(DEFAULT_ITEM_CADASTRAR.id); 
        deepEqual(current, expected)
    })    
})

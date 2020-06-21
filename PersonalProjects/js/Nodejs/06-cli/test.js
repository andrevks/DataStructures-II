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
    before(async () => {
        await database.register(DEFAULT_ITEM_CADASTRAR);
    })
    it("Deve pesquisar um herói utilizando arquivos", async()=>{
        const expected = DEFAULT_ITEM_CADASTRAR;
        //descruture 
        const [ result ]= await database.listData(expected.id)
        deepEqual(result, expected)
        //ok(resultado,expected);
    })
    it("Deve cadastrar um herói, utilizando arquivos",async ()=>{
        const expected = DEFAULT_ITEM_CADASTRAR;
        const result = await database.register(DEFAULT_ITEM_CADASTRAR);
        const [ current ] = await database.listData(DEFAULT_ITEM_CADASTRAR.id); 
        deepEqual(current, expected)
    })    
    it("Deve remover um herói por id", async () =>{
        const expected = true;
        const result = await database.remove(DEFAULT_ITEM_CADASTRAR.id)
        deepEqual(result,expected)
    })
})

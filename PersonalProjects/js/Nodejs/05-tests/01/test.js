const assert = require('assert');
const { getPeople } = require('./service');

describe('Start Wars Tests',()=>{
    it('Buscar o r2d2 com o formato correto', async ()=>{
        const expected = [{
            name:'R2-D2',
            weight:'96'
        }];
        const baseName = 'r2-d2';
        const result = await getPeople(baseName);
        //resultadoAtual,resultado esperado
        assert.deepEqual(result,expected);
    });
});



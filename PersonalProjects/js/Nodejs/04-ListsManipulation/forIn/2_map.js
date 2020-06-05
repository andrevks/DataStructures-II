const service = require('./service');

Array.prototype.myMap = function(callback) {
    const newMappedArray = [];
    for(let index = 0; index < this.length; index++){
        const result = callback(this[index], index);
        newMappedArray.push(result);
    }
    return newMappedArray;
}

async function main (){

    try {
        const results = await service.getPeople('a');
        //const names= [];
        //para cada item da lista a função é chamada a função
        //console.time('forEach');
        //results.results.forEach((item)=>{
            //names.push(item.name);
        //});
        //console.timeEnd('forEach');
        //console.time('map');
        //const names = results.results.map(person => person.name);
        //console.timeEnd('map');
        const names = results.results.myMap(function(person,index){
            return `[${index}]- ${person.name}`;
        });
        
        console.log(`names`, names);

    } catch (error) {
       console.log("Something went wrong", error); 
    }
}
main();
const { getPeople } = require('./service');

Array.prototype.myReduce = function (callback,initialValue) {
    let finalValue = typeof initialValue !== "undefined"?initialValue:this[0];
    for(index = 1; index<this.length;index++){
        finalValue = callback(finalValue,this[index],this);
    }
    return finalValue;
}

async function main(){
    try {
        //Trazer o peso das pessoas
        //somar e verificar quanto é peso de cada uma 
        const { results } = await getPeople('a');
        const weight = results.map((person)=>{
            return(!isNaN(person.mass))?parseInt(person.mass): 0;
        });
        console.log(`weight:`,weight);
        //const weightTotal = weight.reduce((previous,next)=>{
                //console.log("previous:",previous,"next:",next);
                //return previous + next; 
        //});
        const weightTotal = weight.myReduce((previous,next)=>{
            console.log("previous:",previous,"next:",next);
            return previous + next;
        })
        console.log(typeof weightTotal);
        console.log(`weightTotal:`,weightTotal);
    } catch (error) {
       console.log("Something went wrong:",error); 
    }
}
main();
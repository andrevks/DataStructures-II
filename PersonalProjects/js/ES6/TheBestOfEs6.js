//destructuring
var foo = {
    bar:1,
    baz:2
}

//instead of:
// var bar = foo.bar; var baz = foo.baz;

//Just do:
var {bar, baz} = foo;
console(bar);


var tenses = ["me","you","he"];
//destructuring a array
var [ firstPerson , secondPerson] = tenses;

//It's really helpful with promises
Promise.all([promise1,promise2]).then( function([results1, results2]){

});

//destructuring objects

var foo2 = 2;

var obj = {
    bar:1,
    foo2 //foo2 exist
}

const chewieQuote="Let him have it. It's not wise to upset a Wookiee." 
// Only change code below this line
let chewieRegex = /Aa*/g;// Change this line
// Only change code above this line

let result = chewieQuote.match(chewieRegex);

console.log(result);
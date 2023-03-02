function gen(amount) {
    let string = "";
    for(let i = 0; i < amount; i++) {
        const value = Math.floor(Math.random() * amount);
        string += ` ${value}`
    }
    return string;
}

console.log(gen(50));
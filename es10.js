
"use strict";

var Prime = function(){

};

Prime.prototype.getPrime = function(base){
    var prime;
    for (var i = base+1; i < base*3; i++){
        prime = true;
        for (var j = 2; j < i && prime === true; j++){
            if ((i % j) === 0){
                prime = false;
            }
        }
        if (prime === true){
            return i;
        }
    }
    return -1;
};

Prime.prototype.slowAlgorithm = function(floor){
    var lastPrime = 1;
    var sum = 0;
    for (var i = 1; lastPrime < floor; i++){
        lastPrime = this.getPrime(lastPrime);
        sum += lastPrime;
    }
    sum = sum-lastPrime;
    return sum;
};

Prime.prototype.algorithm = function(floor){
    return this.slowAlgorithm(floor);
};

var main = function(){
    for (var i = 10; i < 2010; i = i+10){
        var sum = new Prime().algorithm(i);
        console.log('index: ' + i + ' ' + sum);
    }
};

main();
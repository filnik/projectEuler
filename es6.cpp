#include<iostream>
using namespace std;

/*
The sum of the squares of the first ten natural numbers is,
1^(2) + 2^(2) + ... + 10^(2) = 385

The square of the sum of the first ten natural numbers is,
(1 + 2 + ... + 10)^(2) = 55^(2) = 3025

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/

int sumOfSquares(int limMax){
    int cont = 1;
    int somma = 0;
    while(cont <= limMax){
        somma += cont*cont;
        cont++;
    }
    return somma;
}

int squareOfSum(int limMax){
    int cont = 1;
    int somma = 0;
    while(cont <= limMax){
        somma += cont;
        cont++;
    }
    return somma*somma;
}
int F(int limMax){
    int firstSum = sumOfSquares(limMax);
    int secondSum = squareOfSum(limMax);
    return secondSum-firstSum;
}

int main(){
    cout << F(100);
}

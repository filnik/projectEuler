#include<iostream>
#include<fstream>
using namespace std;

/*
Find the greatest product of five consecutive digits in the 1000-digit number. (il numero e' in input_es8.txt)
*/

int F(){
    ifstream input("input_es8.txt");
    int x = 0;
    int cont = 0;
    int A[1000];
    int max = 0;
    while(x != -49){
        x = input.get() - 48;
        if (x != -38 && x != -49){
            A[cont] = x;
            if (cont > 3){
                int prod = A[cont]*A[cont-1]*A[cont-2]*A[cont-3]*A[cont-4];
                if (prod > max){
                    max = prod;
                }
            }
            cont++;
        }
    }
    cout << max;
}

int main(){
    F();
}

#include<iostream>
using namespace std;

int lung(int num){
    if (!num){
        return 0;
    }
    if (num/10 == 0){
        return 1;
    }
    int lunghezza = lung(num/10);
    return 1+lunghezza;
}

/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.

*/

void numeri(int num, int * A){
    int lunghezza = lung(num) - 1;
    int const lung = lunghezza;
    int num1 = num;
    int num2 = 0;
    while(lunghezza >= 0){
        num2 = num1/10;
        num2 = num2*10;
        num2 = num1-num2;
        num1 = num1/10;
        A[lunghezza] = num2;
        lunghezza--;
    }
}

int reverse(int * A, int dim){
    if (dim%2 != 0){
        return -1;
    }
    int newNum = 0;
    for (int i = 0; i < dim; i++){
        int addNum = A[dim-i-1];
        int cont = dim-i-1;
        while(cont){
            addNum = addNum*10;
            cont--;
        }
        newNum += addNum;
    }
    return newNum;
}

int pal(int num){
    if (lung(num)%2==0){
        int const lung_num = lung(num);
        int A[lung_num];
        numeri(num, A);
        int reverse_num = reverse(A, lung_num);
        if (num == reverse_num){
            return true;
        }
    }
    return false;
}

int F(int n_digit){
    n_digit = n_digit - 1;
    int cont = n_digit;
    int num1 = 9;
    while (cont){
        int cont2 = cont;
        int addNum = 9;
        while(cont2){
            addNum = addNum*10;
            cont2--;
        }
        num1 += addNum;
        cont--;
    }
    //cout << num1;
    int num2 = num1, iniziale = num1, result = 0;
    bool found = false;
    int max = -1;
    while(lung(num1) > lung(iniziale/10)){
        result = num1*num2;
        //cout << result << endl;
        found = pal(result);
        if (found && result > max){
            max = result;
        }
        if (lung(iniziale/10) > lung(num2)){
            cout << num1 <<endl;
            num1--;
            num2 = iniziale;
        }
        num2--;
    }
    return max;
}

int main(){
    cout << endl << F(3) << endl;
    system("pause");
}

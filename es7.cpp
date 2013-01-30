#include<iostream>
using namespace std;

/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6^(th) prime is 13.

What is the 10001^(st) prime number?

*/

unsigned long long F(unsigned long long indice){
	unsigned long long num = 3;
	unsigned long long A[900000];
	A[0] = (unsigned long long) 2;
	A[1] = (unsigned long long) 3;
	A[2] = (unsigned long long) 5;
	A[3] = (unsigned long long) 7;
	A[4] = (unsigned long long) 11;
	A[5] = (unsigned long long) 13;
	A[6] = (unsigned long long) 17;
	A[7] = (unsigned long long) 23;
	unsigned long long cont = (unsigned long long) 8;
	unsigned long long result = (unsigned long long) 0;

	while(true){
		if (num%2 && num%3 && num%5 && num%7 && num%11 && num%13 && num%17 && num%23){
			cout << num << endl;
			bool prime = true;
			unsigned long long i = 7;
			while(i < cont && prime){
				if (num%A[i] == 0){
					prime = false;
				}
				i++;
			}
			if (prime){
			    if (indice == cont+1){
			        return num;
			    }
				A[cont] = num;
				cont++;
			}
		}
		num++;
	}
}

unsigned long long prime(unsigned long long numero){
    unsigned long long cont = 2;
    while (cont < numero){
        if (numero%cont == 0){
            return false;
        }
        cont++;
    }
    return true;
}

unsigned long long F2(int indiceMX){
    int indice = 1;
    int num = 2;
    int result = 0;
    while(indice <= indiceMX){
        if (prime(num)){
            //cout << "INDICE: " << indice << " NUM: " << num << endl;
            indice++;
        }
        num++;
    }
    return num-1;
}

int main(){
    int x;
    while(x != 1){
        cin >> x;
        cout << F2(x);
    }
}

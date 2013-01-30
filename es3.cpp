#include<iostream>
using namespace std;

/*
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
-----------
I fattori primi di 13195 sono 5, 7, 13 e 29.

Qual'è il piu' grande numero primo che divide il numero 600851475143 ?
*/

struct nodo {unsigned long long info; nodo* next; nodo(unsigned long long, nodo*);};
nodo::nodo (unsigned long long a=0, nodo* b=0) {info=a; next=b;}

// PRE = (limMax int > 0)
unsigned long long F(unsigned long long limMax){
	if (limMax == 1){
		return 1;
	}else if(limMax == 2){
		return 2;
	}
	unsigned long long num = 3;
	unsigned long long meta = (limMax/2)+1; // il numero primo che cerco dev'essere minore della meta' aumentata di uno
	nodo * primeNumbers = 0;
	primeNumbers = new nodo(2, primeNumbers);
	unsigned long long cont = 1;

	while(num < meta){
		if (num%2){
			bool prime = true;
			unsigned long long i = 0;
			nodo * temp = primeNumbers;
			while(i < cont && prime && temp){
				i--;
				if (temp->info == num){
					prime = false;
				}else{
					temp = temp->next;
				}
			}
			if (prime){
				primeNumbers = new nodo(num, primeNumbers);
				cont++;
			}
		}
		num++;
	}
	if (primeNumbers){
		return primeNumbers->info;
	}else{
		return 0; // error
	}
}

unsigned long long F2(unsigned long long limMax){
	if (limMax == 1){
		return 1;
	}else if(limMax == 2){
		return 2;
	}
	unsigned long long num = 3;
	unsigned long long const meta = (limMax/2)+1; // il numero primo che cerco dev'essere minore della meta' aumentata di uno
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

	while(num < meta){
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
				A[cont] = num;
				cont++;
				if (limMax%num == 0){
					result = num;
				}
			}
		}
		num++;
	}
	return result;
}

unsigned long long F3(unsigned long long limMax){
	if (limMax == 1){
		return 1;
	}else if(limMax == 2){
		return 2;
	}
	unsigned long long const meta = (limMax/2)+1; // il numero primo che cerco dev'essere minore della meta' aumentata di uno
	unsigned long long num = meta;
	unsigned long long result = 0;

	while(num > 0){
		if (num%2 && num%3 && num%5 && num%7 && num%11 && num%13 && num%17 && num%23){
			cout << num << endl;
			if (limMax%num == 0){
				return num;
			}
		}
		num--;
	}
	return num;
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

unsigned long long F4(unsigned long long limMax, unsigned long long cont = 2){
    if (limMax%cont == 0 && prime(limMax/cont)){
            return limMax/cont;
    }else if (limMax%cont == 0){
            return F4(limMax/cont, cont);
    }else{
        do{
            cont++;
        }while (cont < limMax && !prime(cont));
        return F4(limMax , cont);
    }
}

// POST = (F ritorna il numero primo piu' grande che divide limMax)

int main(){
    unsigned long long n = 600851475143L;
    //cin >> n;
	cout << F4(n) <<endl; //
	//system("pause");
}

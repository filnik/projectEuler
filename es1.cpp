#include<iostream>
using namespace std;

/*
CONSEGNA:

If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
-------------------------
Se abbiamo tutta la lista dei numeri naturali inferiori a 10, se prendiamo solo quelli che sono multipli di 3 o 5, troviamo 3, 5, 6, 9. La somma
di questi multipli e' 23.

Trova la somma di tutti i multipli di 3 o 5 sotto 1000.
*/

// PRE = (limMax valore int definito >= 0,
//		  start valore int >= 0, puo' essere definito dall'utente o lasciato di default. Indica da che numero naturale si parte a contare
//		  MCD valore int > 0
//		  altroNum valore int > 0 )
int F(int MCD, int altroNum, int limMax, int start = 0){
	int somma = 0;
	if (start >= limMax){
		return 0;
	}
	somma = F(MCD, altroNum, limMax, start + MCD);	
	if (altroNum == 0 || start % altroNum != 0){
		somma += start;
	}
	return somma;
}
// POST = (La funzione restituisce la somma: r1+r2+...rn dove r1..rn sono tutti i numeri naturali >= start 
//			divisibili per MCD, non divisibili per altroNum e n = limMax)

/*
DIMOSTRAZIONE INDUTTIVA:

Caso Base:
	start >= limMax:
		se start = limMax, non abbiamo nessun numero da controllare, quindi la somma richiesta e' zero. Vale la POST, ok.
Invocazione induttiva:
	MCD, altroNum e limMax sono i valori dati alla funzione, quindi corretti rispetto alla PRE, start e' start + 3 e la sua unica
	limitazione e' che sia >= 0, quindi ok. Invocazione corretta rispetto alla PRE, suppongo corretta la POST.
Caso induttivo:
	altroNum == 0 || start % altroNum != 0:
		Se altroNum e' zero, vuol dire che non dobbiamo controllare nulla, sommiamo semplicemente il valore processato con la somma parziale
		Se il resto di start/altroNum e' diverso da zero, vuol dire che possiamo sommarlo alla somma parziale, altrimenti lo saltiamo
Alla fine avremo la somma di tutti i numeri divisibili per MCD e non per altroNum (se questo e' diverso da zero), quindi la funzione e' corretta rispetto
alla POST.
*/

int main(){
	int somma;
	somma = F(3, 5, 1000);
	somma = somma + F(5, 0, 1000);
	cout << somma<<endl;
	system("pause");
}

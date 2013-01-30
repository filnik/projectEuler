#include<iostream>
using namespace std;

/*

A Pythagorean triplet is a set of three natural numbers, a  < b  < c, for which,
a^(2) + b^(2) = c^(2)

For example, 3^(2) + 4^(2) = 9 + 16 = 25 = 5^(2).

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.

*/

int F(int sumTriplet){
    int a = 0, b = 0, c = 0, sum = 0;
    bool found = false;
    while(c < sumTriplet && !found){
        sum = a + b + c;
        if (sum == 1000 && (a*a + b*b == c*c)){
            cout << a << endl << b << endl << c << endl << endl;
            found = true;
        }else{
            if (a == sumTriplet){
                a = 0;
                b++;
            }
            if (b == sumTriplet){
                b = 0;
                c++;
            }
            a++;
        }
    }
    return a*b*c;
}

int main(){
    cout << F(1000);
}

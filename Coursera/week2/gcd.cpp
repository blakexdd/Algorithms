#include <iostream>

long int gcd(long int a, long int b);

int main(){
    long int a, b;

    std::cin >> a >> b;
    std::cout << gcd(a, b);
}

long int gcd(long int a, long int b){

    while (b != 0){
        long int tmp; 

        if (a > b){
            tmp = b;
            b = a % b;
            a = tmp;
        }else{
            b = b % a;
        }
    }

    return a;
}
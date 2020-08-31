#include <iostream>
#include <vector>

long int fib(int n);
long int lastDigitFib(int n);

int main(){
    int n;

    std::cin >> n;
    //std::cout << fib(n) << "\n";
    std::cout << lastDigitFib(n);
}

long int fib(int n){
    std::vector<long int> fibv(n + 1);

    fibv[0] = 0;
    fibv[1] = 1;

    for (int i = 2; i <= n; i++)
        fibv[i] = fibv[i - 1] + fibv[i - 2];

    return fibv.back();
}

long int lastDigitFib(int n){
    std::vector<long int> fibv(n + 1);

    fibv[0] = 0;
    fibv[1] = 1;

    for (int i = 2; i <= n; i++)
        fibv[i] = (fibv[i - 1] + fibv[i - 2]) % 10;

    return fibv.back();
}
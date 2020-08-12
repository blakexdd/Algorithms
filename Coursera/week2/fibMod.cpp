#include <iostream>
#include <vector>

int fibMod(long int n, long int mod);

int main(){
    long int a, b;

    std::cin >> a >> b;
    std::cout << fibMod(a, b);
}

int fibMod(long int n, long int mod){
    std::vector<int> fibv(mod * mod + 1);

    fibv[0] = 0;
    fibv[1] = 1;
    int period;

    for (int i = 2; i <= mod * mod; i++)
        fibv[i] = (fibv[i - 1] + fibv[i - 2]) % mod;

    for (int i = 3; i <= mod * mod; i++)
        if (fibv[i - 1] == 0 && fibv[i] == 1){
            period = i - 1;
            break;
        }

    int pos = n % period;

    return fibv[pos];
}
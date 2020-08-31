#include <iostream>
#include <vector>

int sumSquares(long int n);

int main(){
    long int n;

    std::cin >> n;

    std::cout << sumSquares(n);
}

int sumSquares(long int n){
    std::vector<long long> vec(101);

    vec[0] = 0;
    vec[1] = 1;

    for (int i = 2; i <= 100; i++){
        vec[i] = (vec[i - 1] + vec[i - 2]) % 10;
    }

    int period;

    for (int i = 3; i <= 100; i++)
        if (vec[i - 1] == 0 && vec[i] == 1){
            period = i - 1;
            break;
        }

    int pos1 = n % period;
    int pos2 = (n + 1) % period;

    return vec[pos1] * vec[pos2] % 10;
}
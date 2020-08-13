#include <iostream>
#include <vector>

int sum(long int n);

int main(){
    long int n;

    std::cin >> n;

    std::cout << sum(n);
}

int sum(long int n){
    std::vector<long long> vec(102);
    std::vector<long long> sum(102);

    vec[0] = 0;
    vec[1] = 1;
    sum[0] = 0;
    sum[1] = 1;

    int per1 = 1, per2 = 2;

    for (int i = 2; i <= 100; i++){
        vec[i] = vec[i - 1] + vec[i - 2];
        sum[i] = vec[i] + sum[i - 1];
        sum[i] %= 10;
    }

    int period = 0;

    for (int i = 4; i <= 100; i++)
        if(sum[i - 1] == per1 && sum[i] == per2)
        {
            period = i - 2;
            break;
        }
        
    int perRes = n % period;

    return sum[perRes];
}
#include <iostream>
#include <vector>

int sum(long int m, long int n);

int main(){
    long int n, m;

    std::cin >> m >> n;

    std::cout << sum(m, n);
}

int sum(long int m, long int n){
    std::vector<long long> vec(60);
    std::vector<long long> sum(60);

    vec[0] = 0;
    vec[1] = 1;
    sum[0] = 0;
    sum[1] = 1;

    for (int i = 2; i <= 60; i++){
        vec[i] = vec[i - 1] + vec[i - 2];
        sum[i] = vec[i] + sum[i - 1];
        sum[i] %= 10;
    }

    int period = 60;
    long int lowerRange;

    if (m - 1 < 0)
        lowerRange = 0;
    else{
        lowerRange = m - 1;
    }
    
    return ((sum[n % period] + 10) - sum[lowerRange % period]) % 10;
}
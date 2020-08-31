#include <iostream>
#include <vector>
#include <algorithm>

long long int findRevenue(std::vector<long long int> a, std::vector<long long int> b);

int main(){
    long long int n;

    std::cin >> n;
    
    std::vector<long long int> a(n);
    std::vector<long long int> b(n);

    for (long long int i = 0; i < n; i++)
    {
        long long int elem;
        std::cin >> elem;
        a[i] = elem;
    }

    for (long long int i = 0; i < n; i++)
    {
        long long int elem;
        std::cin >> elem;
        b[i] = elem;
    }

    std::cout << findRevenue(a, b);
}

bool sortingFunc(const long long int a, const long long int b){
    return a < b;
}

long long int findRevenue(std::vector<long long int> a, std::vector<long long int> b){
    std::sort(a.begin(), a.end(), sortingFunc);
    std::sort(b.begin(), b.end(), sortingFunc);

    long long int sum = 0;

    for (long long int i = 0; i < a.size(); i++){
        sum += a[i] * b[i];
    }

    return sum;
}
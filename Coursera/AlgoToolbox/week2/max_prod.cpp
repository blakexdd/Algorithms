#include <iostream>
#include <vector>

long int maxPairwiseProduct(std::vector<long int> v);

int main( void ){
    int n;
    std::vector<long int> v;

    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        long int elem;
        std::cin >> elem;
        v.push_back(elem);
    }

    std::cout << maxPairwiseProduct(v);

    return 0;
}

long int maxPairwiseProduct(std::vector<long int> v){
    long int firstMax = 0;
    long int secondMax = 0;

    for (int i = 0; i < v.size(); i++)
        if (v[i] > firstMax)
            secondMax = firstMax, firstMax = v[i];
        else if (v[i] > secondMax)
            secondMax = v[i];

    return firstMax * secondMax;
}
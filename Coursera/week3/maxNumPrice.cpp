#include <iostream>
#include <vector>

void findMaxPrice(long int n);

int main(){
    long int n;

    std::cin >> n;

    findMaxPrice(n);
}

void findMaxPrice(long int n){
    std::vector<long int> prices;
    long int currSum = n;

    for (int i = 1; i <= n; i++){
        if (currSum - i >= 0 && currSum - 2 * i - 1 >= 0)
            prices.push_back(i), currSum -= i;
        else{
            prices.push_back(currSum);
            break;
        }
    }

    std::cout << prices.size() << std::endl;
    
    for (int i = 0; i < prices.size(); i++)
        std::cout << prices[i] << " ";
}
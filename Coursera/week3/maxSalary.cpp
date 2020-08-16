#include <iostream>
#include <algorithm>
#include <vector>

int main(){
    long long int n;

    std::cin >> n;

    std::vector<long long int> nums(n);

    for (long long int i = 0; i < n; i++){
        long long int elem;
        std::cin >> elem;
        nums[i] = elem;
    }

    std::sort(nums.begin(), nums.end(), [](const long long int &a, const long long int &b){
        std::vector<long long int> firstNums;
        std::vector<long long int> secondNums;
        long long int newA = a;
        long long int newB = b;

        do{
            firstNums.push_back(newA % 10);
            newA /= 10;
        }while (newA % 10 > 0);

        do{
            secondNums.push_back(newB % 10);
            newB /= 10;
        }while (newB % 10 > 0);

        std::reverse(secondNums.begin(), secondNums.end());

        std::reverse(firstNums.begin(), firstNums.end());

        for (long long int i = 0; i < std::min(firstNums.size(), secondNums.size()); i++){
            if (firstNums[i] > secondNums[i])
                return true;
            else if (secondNums[i] > firstNums[i])
                return false;
            else if (firstNums[i] == secondNums[i] && i == std::min(firstNums.size(), secondNums.size()) - 1){
                int arrLonger = 1;

                if (firstNums.size() < secondNums.size())
                    arrLonger = 2;
                
                if (arrLonger == 1)
                    if (firstNums[i + 1] > secondNums[i])
                        return true;
                    else
                        return false;
                else
                    if (secondNums[i + 1] > firstNums[i])
                        return false;
                    else
                        return true;    
            }
        }

        return false;
    });

    for (long long int i = 0; i < nums.size(); i++)
        std::cout << nums[i];
        
}
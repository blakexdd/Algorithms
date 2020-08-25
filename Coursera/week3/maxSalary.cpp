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
        std::string s1 = std::to_string(a);
        std::string s2 = std::to_string(b);

        return s1 + s2 > s2 + s1;
    });

    for (long long int i = 0; i < nums.size(); i++)
        std::cout << nums[i];
        
}
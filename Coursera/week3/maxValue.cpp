#include <iostream>
#include <algorithm>
#include <vector>

float findMaxValue(int capacity, std::vector<std::vector<int> > items);

int main(){
    int n, cap;
    int v, w;
    std::vector<std::vector<int> > items(n);

    std::cin >> n >> cap;

    for (int i = 0; i < n; i++)
    {
        std::cin >> v >> w;

        std::vector<int> values(2);
        values[0] = v;
        values[1] = w;
        items.push_back(values);
    }

    std::cout << findMaxValue(cap, items);
}

float findMaxValue(int capacity, std::vector<std::vector<int> > items){
    return 1.0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

void dispayVec(std::vector<std::vector<double>> vec);
double findMaxValue(double capacity, std::vector<std::vector<double>> items);

int main(){
    double n, cap;
    double v, w;

    std::cin >> n >> cap;

    std::vector<std::vector<double>> items(n);

    for (double i = 0; i < n; i++)
    {
        std::cin >> v >> w;

        std::vector<double> values = {v, w};
        items[i] = values;
    }

    std::cout.precision(10);

    std::cout << findMaxValue(cap, items);
}


double findMaxValue(double capacity, std::vector<std::vector<double>> items){
    std::sort(items.begin(), items.end(), []( const std::vector<double>& a,
           const std::vector<double>& b ) {
        return a[0] / a[1] < b[0] / b[1];
    });

    double total = 0.0;

    while (capacity != 0){

        if (items.empty())
            return total;
            
        double v = items[items.size() - 1][0];
        double w = items[items.size() -1][1];

        items.pop_back();

        double curr_w = std::min(w, capacity);
        capacity -= curr_w;
        
        total += (double(v) / w) * curr_w;
    }

    return total;
}

void dispayVec(std::vector<std::vector<double>> vec){
    for (double i = 0; i < vec.size(); i++) { 
        for (double j = 0; j < vec[i].size(); j++) 
            std::cout << vec[i][j] << " "; 
        std::cout << std::endl; 
    } 
}
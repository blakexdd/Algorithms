#include <iostream>
#include <vector>
#include <algorithm>

void dispayVec(std::vector<std::vector<long int>> vec);
void collectSignatures(std::vector<std::vector<long int>> v);

int main(){
    int n;

    std::cin >> n;

    std::vector<std::vector<long int>> timeRanges(n);

    for (int i = 0; i < n; i++){
        long int from, to;

        std::cin >> from >> to;

        std::vector<long int> range = {from, to};

        timeRanges[i] = range;
    }

    collectSignatures(timeRanges);

}

void collectSignatures(std::vector<std::vector<long int>> v){
    std::sort(v.begin(), v.end(), [](const std::vector<long int> &a,
        const std::vector<long int> &b){
            return a[1] < b[1];
        });

    int entries = 0;
    std::vector<long int> dates;

    int i = 0;

    while (i < v.size()){
        long int max = v[i][1];
        long int min = v[i][0];
        i++;

        while(i < v.size() && v[i][0] <= max){
            if (v[i][1] < max)
                max = v[i][1];
            i++;
        }
        dates.push_back(max);
    }

    std::cout << dates.size() << "\n";

    for (int i = 0; i < dates.size(); i++)
        std::cout << dates[i] << " ";
}
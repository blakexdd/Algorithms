#include <iostream>
#include <vector>

int countStops(int m, std::vector<int> stops);

int main(){
    int d, m, n;

    std::cin >> d;
    std::cin >> m;
    std::cin >> n;

    std::vector<int> stops(n + 2);

    stops[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        int stop;
        std::cin >> stop;
        stops[i] = stop;
    }

    stops[n + 2 -1] = d;

    std::cout << countStops(m, stops);
}

int countStops(int m, std::vector<int> stops){
    int stopsNum = 0;
    int i = 0;

    while (i <= stops.size() - 1){
        int j = i;

        while(j <= stops.size() - 1 && stops[j] - stops[i] <= m){
            j++;
        }

        if (i != j - 1){
            stopsNum++;

            i = j - 1;
        }else if (i == stops.size() -1 )
            return stopsNum - 1;
        else
            return -1;
    }

    return 0;
}
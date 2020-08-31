#include <iostream>

int findChange(int m);

int main(){
    int m;

    std::cin >> m;
    std::cout << findChange(m);

}

int findChange(int m){
    int tenTimes = m / 10;
    m %= 10;

    int fiveTimes = m / 5;
    m %= 5;

    return tenTimes + fiveTimes + m;
}
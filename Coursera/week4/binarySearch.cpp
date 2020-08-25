#include <iostream>
#include <vector>

using namespace std;

void res(vector<long int> in, vector<long int> wanted);
long int binarySearch(vector<long int> v, long int num, long int l, long int r);

int main(){
    int n;
    int k;

    cin >> n;

    vector<long int> in(n);

    for (int i = 0; i < n; i++)
        cin >> in[i];

    cin >> k;

    vector<long int> wanted(k);

    for (int i = 0; i < k; i++)
        cin >> wanted[i];

    res(in, wanted);

    return 0;
}

void res(vector<long int> in, vector<long int> wanted){
    for (int i = 0; i < wanted.size(); i++)
        cout << binarySearch(in, wanted[i], 0, in.size() - 1) << " ";
}

long int binarySearch(vector<long int> v, long int num, long int l, long int r){
    long int result = -1;

    while (l <= r && result == -1){
        long int mid = (l + r) / 2;

        if (v[mid] == num)
            result = mid;
        else if (v[mid] > num)
            r = mid - 1;
        else
            l = mid + 1;    
    }

    return result;
}
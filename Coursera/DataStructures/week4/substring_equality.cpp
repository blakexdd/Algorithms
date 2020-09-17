#include <iostream>
#include <vector>
#include <random>
using namespace std;

long long power(int a, int b){
    long long res = a;
    for (int i = 1; i < b; i++)
        res *= a;

    return res;
}

class Solver {
	string s;
    vector<long long> h1;
    vector<long long> h2;
    vector<long long> pows;
    long long m1 = 1000000007;
    long long m2 = 1000000009;
    long long x = 4;
public:	
	Solver(string s) : s(s) {	
		// initialization, precalculation

        this->pows = vector<long long>(s.size() + 1);
        this->h1 = vector<long long>(s.size() + 1);
        this->h2 = vector<long long>(s.size() + 1);
        this->pows[0] = 1;

        this->h1[0] = 0;
        this->h2[0] = 0;

        for (int i = 1; i <= s.size(); i++){
            this->pows[i] = this->pows[i - 1] * this->x;
            this->h1[i] = (((this->x * this->h1[i - 1] + s[i - 1]) % this->m1) + this->m1) % this->m1;
            this->h2[i] = (((this->x * this->h2[i - 1] + s[i - 1]) % this->m2) + this->m2) % this->m2;
        }
	}

	bool ask(int a, int b, int l) {

        long long lH1 = (((this->h1[a + l] - this->h1[a] * this->pows[l]) % this->m1) + this->m1) % this->m1;
        long long rH1 = (((this->h1[b + l] - this->h1[b] * this->pows[l]) % this->m1) + this->m1) % this->m1;
        long long lH2 = (((this->h2[a + l] - this->h2[a] * this->pows[l]) % this->m2) + this->m2) % this->m2;
        long long rH2 = (((this->h2[b + l] - this->h2[b] * this->pows[l]) % this->m2) + this->m2) % this->m2;

		return lH1 == rH1 &&
		    lH2 == rH2;
	}
};

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	string s;
	int q;
	cin >> s >> q;
	Solver solver(s);
	for (int i = 0; i < q; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		cout << (solver.ask(a, b, l) ? "Yes\n" : "No\n");
	}
}

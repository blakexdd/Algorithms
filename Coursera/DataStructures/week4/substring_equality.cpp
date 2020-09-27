#include <iostream>
#include <vector>
#include <random>
using namespace std;

class Solver {
	string s;
    vector<unsigned long long> h1;
    vector<unsigned long long> h2;
    vector<unsigned long long> powsM1;
    vector<unsigned long long> powsM2;
     unsigned long long m1 = 1000000007;
     unsigned long long m2 = 1000000009;
     unsigned long long x = 4;
public:
	Solver(string s) : s(s) {
		// initialization, precalculation

        this->powsM1 = vector<unsigned long long>(s.size() + 1);
        this->powsM2 = vector<unsigned long long>(s.size() + 1);
        this->h1 = vector< unsigned long long>(s.size() + 1);
        this->h2 = vector< unsigned long long>(s.size() + 1);
        this->powsM1[0] = 1;
        this->powsM2[0] = 1;
        this->h1[0] = 0;
        this->h2[0] = 0;

        for (int i = 1; i <= s.size(); i++){
            this->powsM1[i] = (this->powsM1[i - 1] * this->x) % this->m1;
            this->powsM2[i] = (this->powsM2[i - 1] * this->x) % this->m2;
            this->h1[i] = (this->h1[i - 1] + (s[i - 1] - 'a' + 1) * this->powsM1[i - 1]) % this->m1;
            this->h2[i] = (this->h2[i - 1] + (s[i - 1] - 'a' + 1) * this->powsM2[i - 1]) % this->m2;
        }
	}

	bool ask(int a, int b, int l) {
         long long lH1 = ((this->h1[a + l] - this->h1[a]) * this->powsM1[b - a]) % this->m1;
         long long rH1 = ((this->h1[b + l] - this->h1[b])) % this->m1;
         long long lH2 = ((this->h2[a + l] - this->h2[a]) * this->powsM2[b - a]) % this->m2;
         long long rH2 = ((this->h2[b + l] - this->h2[b])) % this->m2;

         //cout << lH1 << " " << rH1 << " " << lH2 << " " << rH2 << " ";

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

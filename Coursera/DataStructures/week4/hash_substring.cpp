#include <iostream>
#include <string>
#include <vector>

using std::string;
typedef unsigned long long ull;

struct Data {
    string pattern, text;
};

Data read_input() {
    Data data;
    std::cin >> data.pattern >> data.text;
    return data;
}

void print_occurrences(const std::vector<int>& output) {
    for (size_t i = 0; i < output.size(); ++i)
        std::cout << output[i] << " ";
    std::cout << "\n";
}

int hash_func(const string& s, int multiplier, int prime){
    unsigned long long hash = 0;
    for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
        hash = (hash * multiplier + s[i]) % prime;

    return hash;
}

std::vector<int> get_occurrences(const Data& input) {
    const string& s = input.pattern, t = input.text;
    std::vector<long long> hashes(t.size() - s.size() + 1);
    std::vector<int> ans;
    int multiplier = 263;
    int prime = 1000000007;
    long long pattern_hash = hash_func(s, multiplier, prime);
    hashes[t.size() - s.size()] = hash_func(t.substr(t.size() - s.size(), s.size()), multiplier, prime);
    int y = 1;

    for (int i = 1; i <= s.size(); i++){
        y = (y * multiplier) % prime;
    }

    for (int i = t.size() - s.size() - 1; i >= 0; i--){
        hashes[i] = (multiplier * hashes[i + 1] + t[i] - y * t[i + s.size()]) % prime;
    }

    for (int i = 0; i < t.size() - s.size() + 1; i++){
        if (hashes[i] == pattern_hash){
            if (t.substr(i, s.size()) == s)
                ans.push_back(i);
        }
    }

    return ans;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrences(read_input()));
    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

using std::string;
using std::vector;
using std::cin;
using std::list;

struct Query {
    string type, s;
    size_t ind;
};

class QueryProcessor {
    int bucket_count;
    vector<list<string>> elems;

    size_t hash_func(const string& s) const {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
            hash = (hash * multiplier + s[i]) % prime;
        return hash % bucket_count;
    }

public:
    explicit QueryProcessor(int bucket_count): bucket_count(bucket_count) {
        this->elems.resize(bucket_count);
    }

    Query readQuery() const {
        Query query;
        cin >> query.type;
        if (query.type != "check")
            cin >> query.s;
        else
            cin >> query.ind;
        return query;
    }

    void writeSearchResult(bool was_found) const {
        std::cout << (was_found ? "yes\n" : "no\n");
    }

    void processQuery(const Query& query) {
        size_t hash = hash_func(query.s);
        if (query.type == "check") {
            // use reverse order, because we append strings to the end
//            std::cout << "check: " << elems[query.ind].size() << " str: " << query.s << "\n";
//            std::cout << "q index: " << query.ind << "\n";
            list<string>::iterator it;
            for (it = elems[query.ind].end(); it != elems[query.ind].begin();){
                std::cout << *(--it) << " ";
            }
            std::cout << "\n";
        } else {
            list<string>::iterator it = std::find(elems[hash].begin(), elems[hash].end(), query.s);
            if (query.type == "find")
                writeSearchResult(it != elems[hash].end());
            else if (query.type == "add") {
                if (it == elems[hash].end())
                    elems[hash].push_back(query.s);
            } else if (query.type == "del") {
                if (it != elems[hash].end())
                    elems[hash].erase(it);
            }
        }
    }

    void processQueries() {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            processQuery(readQuery());
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;
}

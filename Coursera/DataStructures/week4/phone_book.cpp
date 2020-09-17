#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <list>

using std::string;
using std::vector;
using std::cin;
using std::list;

struct Query {
    string type, name;
    int number;

    bool operator == (const Query query) const {
        return this->number == query.number;
    }
};

vector<Query> read_queries() {
    int n;
    cin >> n;
    vector<Query> queries(n);
    for (int i = 0; i < n; ++i) {
        cin >> queries[i].type;
        if (queries[i].type == "add")
            cin >> queries[i].number >> queries[i].name;
        else
            cin >> queries[i].number;
    }
    return queries;
}

void write_responses(const vector<string>& result) {
    for (size_t i = 0; i < result.size(); ++i)
        std::cout << result[i] << "\n";
}

int computeHash(int number, int m, int a, int b){
    int p = 15485863;
    return (a * number + b) % p % m;
}

string find(int number, vector<list<Query>> contacts, int m, int a, int b){
    int hash = computeHash(number, m, a, b);

    for (auto &elem: contacts[hash])
        if (elem.number == number) {
            return elem.name;
        }

    return "not found";
}

vector<string> process_queries(const vector<Query>& queries) {
    vector<string> result;
    // Keep list of all existing (i.e. not deleted yet) contacts.
    srand(1232);
    int a = rand() % 800;
    int b = rand() % 800;

    int averageNumbers = 0;
    for (size_t i = 0; i < queries.size(); ++i){
        if (queries[i].type == "add")
            averageNumbers++;
    }

    int m = averageNumbers * 0.8;

    if (m == 0)
        m = 1;

    vector<list<Query>> contacts(m);
    for (size_t i = 0; i < queries.size(); ++i)
        if (queries[i].type == "add") {
            int hash = computeHash(queries[i].number, m, a, b);
            int found = false;

            for (auto &elem: contacts[hash])
                if (elem.number == queries[i].number) {
                    elem = queries[i];
                    found = true;
                    break;
                }

            if (!found)
                contacts[hash].push_back(queries[i]);
        } else if (queries[i].type == "del") {
            int hash = computeHash(queries[i].number, m, a, b);

            list<Query>::iterator it;
            for (it = contacts[hash].begin(); it != contacts[hash].end(); it++)
                if (*it == queries[i]){
                    break;
                }

            if (it != contacts[hash].end())
                 contacts[hash].erase(it);
        } else {
            result.push_back(find(queries[i].number, contacts, m, a, b));
        }

    return result;
}

int main() {
    write_responses(process_queries(read_queries()));
    return 0;
}

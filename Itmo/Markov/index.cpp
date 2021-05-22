#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
struct MarkovRule
{
    string pattern;
    string replacement;
    bool terminal;
    MarkovRule(string pat, string rep, bool term) : pattern(pat),
                                                    replacement(rep),
                                                    terminal(term)
    {
    }
};

string const whitespace = " \t";

class MarkovHelper
{
public:
    static bool
    whiteSpace(char c)
    {
        return whitespace.find(c) != string::npos;
    }

    static vector<MarkovRule>
    readRules(ifstream &MarkovRulefile)
    {
        vector<MarkovRule> MarkovRules;
        string line;

        while (getline(MarkovRulefile, line))
        {
            string::size_type pos = 0;
            if (line.find_first_not_of(" \t") == string::npos)
            {
                continue;
            }

            while (pos != string::npos && (pos == 0 || !whiteSpace(line[pos - 1])))
                pos = line.find("->", pos + 1);

            if (pos == string::npos || line.length() < pos + 3 || !whiteSpace(line[pos + 2]))
            {
                cout << "Rule is in wrong format";
                exit(1);
            }

            string pattern = line.substr(0, pos - 1);
            string replacement = line.substr(pos + 3);
            pattern.erase(pattern.find_last_not_of(whitespace) + 1);
            replacement.erase(0, replacement.find_first_not_of(whitespace));
            bool terminal = replacement.empty();

            MarkovRules.push_back(MarkovRule(pattern, replacement, terminal));
        }

        return MarkovRules;
    }

    static string solve(vector<MarkovRule> MarkovRules, string input)
    {
        string &output = input;
        vector<MarkovRule>::iterator iter = MarkovRules.begin();

        while (iter != MarkovRules.end())
        {
            string::size_type pos = output.find(iter->pattern);
            if (pos != string::npos)
            {
                output.replace(pos, iter->pattern.length(), iter->replacement);
                if (iter->terminal)
                    break;
                iter = MarkovRules.begin();
            }
            else
                ++iter;
        }

        return output;
    }
};

int main(int _, char *argv[])
{
    string filename = argv[1];
    string input = argv[2];

    ifstream MarkovRulefile(filename);
    vector<MarkovRule> MarkovRules = MarkovHelper::readRules(MarkovRulefile);
    string resultedString = MarkovHelper::solve(MarkovRules, input);

    cout << resultedString << endl;
}
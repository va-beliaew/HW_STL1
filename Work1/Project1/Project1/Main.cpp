#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

int main() {
    std::string st;
    getline(std::cin, st);
    std::multiset<char> s;
    std::map<char, int> m;
    std::vector<std::pair<char, int>> v;
    for (char n : st) {
        s.insert(n);
    }
    for (std::multiset<char>::iterator it = s.begin(); it != s.end(); ++it) {
        m.insert({ *it, s.count(*it) });
    }
    for (std::pair<char, int> pa : m) {
        v.push_back(pa);
    }
    std::sort(v.begin(), v.end(), [](const std::pair<char, int>& a, const std::pair<char, int>& b) {return a.second > b.second; });
    for (std::pair<char, int> pa : v) {
        std::cout << pa.first << ':' << '\t' << pa.second << '\n';
    }
    return 0;
}
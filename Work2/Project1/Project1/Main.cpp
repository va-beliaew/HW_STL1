#include <iostream>
#include <set>
#include <vector>

int main() {
    int N = 0;
    std::cin >> N;
    int n;
    std::set<int, std::greater<int>> s;
    for (int i = 0; i < N; ++i) {
        std::cin >> n;
        s.insert(n);
    }
    std::cout << std::endl;
    for (int i : s) {
        std::cout << i << std::endl;
    }
    return 0;
}
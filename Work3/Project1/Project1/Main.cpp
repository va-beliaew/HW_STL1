#include <iostream>
#include <algorithm>
#include <initializer_list>

namespace std {
    template<typename T>
    class vector {
        int iterator = 0;
        int count = 8;
        T* arr = new T[count]{};
        void arr_size() {
            T* arr2;
            arr2 = new T[count * 2];
            for (int i = 0; i < count; ++i) {
                arr2[i] = arr[i];
            }
            delete[] arr;
            arr = new T[count * 2];
            arr = std::move(arr2);
            count *= 2;
        }
    public:
        vector() {};
        vector(const std::initializer_list<T>&& mas) {
            if (count <= mas.size()) {
                count = mas.size() * 2;
                delete[] arr;
                arr = new T[count];
            }
            for (auto i = mas.begin(); i < mas.end(); ++i) {
                arr[iterator] = *i;
                ++iterator;
            }
        }
        vector(int n) {
            if (n > count) {
                count = n * 2;
                delete[] arr;
                arr = new T[count];
            }
        }
        vector(const T& mas) {
            iterator = 0;
            if (mas.size() >= sizeof(arr)) {
                arr_size(mas.size());
            }
            for (auto n : mas) {
                arr[iterator] = n;
                ++iterator;
            }
        }
        T at(int i) {
            if (i < count && i >= 0) {
                return arr[i];
            }
            else {
                throw std::out_of_range("Out of range!");
            }
        }
        void push_back(T n) {
            if (iterator > (count - static_cast<int>(count / 3))) {
                arr_size();
            }
            arr[iterator] = n;
            ++iterator;
        }
        int size() {
            return iterator;
        }
        int capacity() {
            return count;
        }
        ~vector() {
            delete[] arr;
        }
        auto begin() {
            return &arr[0];
        }
        auto end() {
            return &arr[iterator];
        }

    };
}

int main() {
    std::vector<char> v;
    std::string s;
    std::cin >> s;
    for (char n : s) {
        v.push_back(n);
    }
    v.push_back('D');
    for (char n : v) {
        std::cout << n << ' ';
    }
    std::cout << std::endl;
    std::cout << v.size() << '\t' << v.capacity();
    return 0;
}
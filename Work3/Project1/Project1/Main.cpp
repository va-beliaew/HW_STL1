#include <iostream>
#include <algorithm>
#include <initializer_list>
#include <array>

namespace std {
    template<typename T>
    class vector {
        int iterator = 0;
        int count = 8;
        T* arr = new T[count]{};
        void arr_size() {
            T* temp_arr = new T[count * 2];
            for (int i = 0; i < count; ++i) {
                temp_arr[i] = arr[i];
            }
            delete[] arr;
            arr = temp_arr;
            temp_arr = nullptr;
            count *= 2;
        }
        int bit(int size) {
            while ((size / 8) != 1) {
                ++size;
            }
            return size * 2;
        }
    public:
        vector() {};
        vector(const vector<T>& copy) {
            iterator = 0;
            if (copy.size() > count) {
                delete[] arr;
                count = bit(copy.size());
                arr = new T[count];
            }
            for (auto n : copy) {
                arr[iterator] = n;
                ++iterator;
            }
        }
        vector(const T& n) {
            arr[iterator] = n;
            ++iterator;
        }
        vector(const std::initializer_list<T>& mas) {
            if (count <= mas.size()) {
                count = bit(mas.size());
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
                count = bit(n);
                delete[] arr;
                arr = new T[count];
            }
        }
        vector(const std::array<T, 10>& mas) {
            iterator = 0;
            if (mas.size() >= sizeof(arr)) {
                arr_size(mas.size());
            }
            for (auto n : mas) {
                arr[iterator] = n;
                ++iterator;
            }
        }
        vector<T> operator= (const vector<T>& vec) {
            iterator = 0;
            if (count < vec.size()) {
                delete[] arr;
                count = bit(vec.size());
                arr = new T[count];
            }
            for (auto n : vec) {
                arr[iterator] = n;
                ++iterator;
            }
        }
            T at(int i) {
                if (i < iterator && i >= 0) {
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
        std::vector<char> ch('f');
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
        for (auto d : ch) {
            std::cout << d << ' ';
        }
        std::cout << v.size() << '\t' << v.capacity();
        try{
        std::cout << v.at(50);
    }
    catch (const std::out_of_range& out) {
        std::cerr << out.what();
    }
    return 0;
}
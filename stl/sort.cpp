#include <algorithm>
#include <iostream>
#include <vector>

template <typename Iter>
void print(Iter begin, Iter end) {
    while (begin != end) {
        std::cout << *begin << " ";
        begin++;
    }
    std::cout << std::endl;
}

template <typename T>
struct greater_comp {
    bool operator()(const T& a, const T& b) const { return a > b; }
};

int main() {
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(6);
    vec.push_back(4);
    vec.push_back(7);
    vec.push_back(2);

    std::cout << "Before sort ----" << std::endl;
    print(vec.begin(), vec.end());
    std::sort(vec.begin(), vec.end(), greater_comp<int>());

    std::cout << "After sort -----" << std::endl;
    print(vec.begin(), vec.end());
}

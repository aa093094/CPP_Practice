#include <iostream>

template <int N>
struct Fibo {
    static const int result = Fibo<N-1>::result + Fibo<N-2>::result;
};

template <>
struct Fibo<2> {
    static const int result = 1;
};

template <>
struct Fibo<1> {
    static const int result = 1;
};

int main() {
    std::cout << "Tenth fibonacci num :: " << Fibo<10>::result << std::endl;
}

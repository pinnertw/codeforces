#include <iostream>
#include <time.h>
#include <cinttypes>
using namespace std;

int fibonacci(int n) {
    return n == 1 || n == 2 ? 1 : fibonacci(n-1) + fibonacci(n-2);
}

constexpr int fibonacci_constexpr(const int n) {
    return n == 1 || n == 2 ? 1 : fibonacci_constexpr(n-1) + fibonacci_constexpr(n-2);
}

// Dynamic programming
int dp_table[10000];
int fibonacci_dp(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    else if (dp_table[n] != 0) {
        return dp_table[n];
    }
    else {
        dp_table[n] =  fibonacci_dp(n-1) + fibonacci_dp(n-2);
        return dp_table[n];
    }
}

// Template
template<int n>
struct fibonacci_template
{
  static constexpr int value = fibonacci_template<n-1>::value + fibonacci_template<n-2>::value;
};
template<>
struct fibonacci_template<0>
{
  static constexpr int value = 0;
};
template<>
struct fibonacci_template<1>
{
  static constexpr int value = 1;
};

int main() {
    const int n = 45;
    double start, end;

    cout << "Fibonacci" << endl;
    start = clock();
    cout << fibonacci(n) << endl;
    end = clock();
    cout << (end - start) / CLOCKS_PER_SEC << endl;

    cout << "Fibonacci using constexpr" << endl;
    start = clock();
    cout << fibonacci_constexpr(n) << endl;
    end = clock();
    cout << (end - start) / CLOCKS_PER_SEC << endl;

    cout << "Fibonacci using dynamic programming" << endl;
    start = clock();
    cout << fibonacci_dp(n) << endl;
    end = clock();
    cout << (end - start) / CLOCKS_PER_SEC << endl;

    cout << "Fibonacci using template" << endl;
    start = clock();
    cout << fibonacci_template<n>::value << endl;
    end = clock();
    cout << (end - start) / CLOCKS_PER_SEC << endl;
}

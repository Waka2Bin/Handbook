#include <iostream>

using namespace std;

int main() {
    long long n,answ;
    answ = 0;
    cin >> n;

    if (n % 2) {
        answ = ((n + 1) / 2) * n;
    }
    else answ = n / 2 * (n + 1);
    
    std::cout << answ << "\n";
}
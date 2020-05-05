#include <iostream>
#include <random>
#include <chrono>
#include "SingleHash.h"
#include "FourLevelHash.h"


int main() {
    SingleHash H(7);

    vector<int> primes = {5, 7, 11, 13};
    FourLevelHash H4(primes);

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(1.0, 1000000000.0);

    std::cout << "Hashing With Chaining!!" << std::endl;

    int size = 100000000;

    for (auto i = 0; i < size; i++) {
        cout << "Hello" << '\n';
        auto temp = (long long) (dist(mt));
        H.insertItem(temp);
        H4.insertItem(temp);
    }
    H.displaySizes();

    auto start = std::chrono::high_resolution_clock::now();
    H.findNumber(H.getNumber(1000000, 3));
    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << duration.count() << endl;

    return 0;
}

#include <iostream>
#include <random>
#include <chrono>
#include "SingleHash.h"
#include "FourLevelHash.h"


int main() {
    SingleHash H(37);

    vector<int> primes = {23, 29, 31, 37};
    FourLevelHash H4(primes);

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(1.0, 1000000000.0);

    std::cout << "Hashing With Chaining!!" << std::endl;

    int size = 100000000;

    auto start1 = std::chrono::high_resolution_clock::now();

    cout << "Allocating Items" << endl;
    for (auto i = 0; i < size; i++) {
        auto temp = (long long) (dist(mt));
        H.insertItem(temp);
        H4.insertItem(temp);
    }
    cout << "Items Allocated" << endl;
    auto stop1 = std::chrono::high_resolution_clock::now();

    auto duration1 = std::chrono::duration_cast<std::chrono::seconds>(stop1 - start1);
    cout << "Item Allocation Duration: " << duration1.count() << " seconds" << endl;

//    H.displaySizes();
//    H4.displaySizes();

    auto start2 = std::chrono::high_resolution_clock::now();
    H.findNumber(H.getNumber(10000000, 3));
    auto stop2 = std::chrono::high_resolution_clock::now();

    auto duration2 = std::chrono::duration_cast<std::chrono::milliseconds>(stop2 - start2);
    cout << "Single Hash Function completed searching in " << duration2.count() << " milliseconds" << endl;

    auto start3 = std::chrono::high_resolution_clock::now();
    H4.findNumber(H.getNumber(10000000, 3));
    auto stop3 = std::chrono::high_resolution_clock::now();

    auto duration3 = std::chrono::duration_cast<std::chrono::milliseconds>(stop3 - start3);
    cout << "Four Level Hash Function completed searching in " << duration3.count() << " milliseconds" << endl;

    return 0;
}

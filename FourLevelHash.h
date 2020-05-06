//
// Created by shrey on 05/05/20.
//

#ifndef HASHIMPLEMENTATION_FOURLEVELHASH_H
#define HASHIMPLEMENTATION_FOURLEVELHASH_H

#include <iostream>
#include <utility>
#include <vector>
#include <list>

using namespace std;

class FourLevelHash {
//    list < list < list < list <long long>* >* >* > *table;
    vector<int> hashLevel;
    vector<vector<vector<vector<vector<long long> > > > > table;
public:
    explicit FourLevelHash(vector<int> v) {
        hashLevel = std::move(v);

//        vector < vector<vector<vector<vector<long long>>>>> table(hashLevel[0],
//                vector< vector<vector<vector<long long>>>> (hashLevel[1],
//                        vector<vector<vector<long long>>> (hashLevel[2],
//                                vector<vector<long long>> (hashLevel[3]))));

        table = vector<vector<vector<vector<vector<long long> > > > >(hashLevel[0]);
        for (int i = 0; i < hashLevel[0]; i++) {
            table[i] = vector<vector<vector<vector<long long> > > >(hashLevel[1]);
            for (int j = 0; j < hashLevel[1]; j++) {
                table[i][j] = vector<vector<vector<long long> > >(hashLevel[2]);
                for (int k = 0; k < hashLevel[2]; k++) {
                    table[i][j][k] = vector<vector<long long> >(hashLevel[3]);
                }
            }
        }
    }

    static int hashFunction(long long x, int hashNumber) {
        return x % (long long) hashNumber;
    }

    void insertItem(long long key) {
        int id1 = hashFunction(key, hashLevel[0]);
        int id2 = hashFunction(key, hashLevel[1]);
        int id3 = hashFunction(key, hashLevel[2]);
        int id4 = hashFunction(key, hashLevel[3]);
        table[id1][id2][id3][id4].push_back(key);
    }
};

#endif //HASHIMPLEMENTATION_FOURLEVELHASH_H

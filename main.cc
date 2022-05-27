/**
* Aidan Gooding
* HW8 - comparison of search time for data structures
* 3/23/22
**/
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <fstream>
#include <iostream>

using std::vector;
using std::set;
using std::unordered_set;

 int main() {

    std::fstream f;
    f.open("data.csv", std::ios::out);

    for (int nMax = 1; nMax <= 1000; nMax++) {
        int A[nMax];
        srand (time(NULL));
        for (int i = 0; i < nMax; i++) {
            A[i] = rand() % nMax + 1;
        }

        vector<int>* V = new vector<int>;
        set<int>* S = new set<int>;
        unordered_set<int>* US = new unordered_set<int>;


        for (int j = 0; j < nMax; j++) {
            int k = A[j];
            (*V).push_back(k);
            (*S).insert(k);
            (*US).insert(k);
        }


        clock_t start = std::clock();
        for (int l = 0; l < nMax; l++) {
            int val = A[l];
            std::find((*V).begin(), (*V).end(), val);
        }
        clock_t vEnd = std::clock();
        long double vEndt = (long double)(vEnd - start) / nMax;
        vEndt = vEndt / CLOCKS_PER_SEC;

        start = std::clock();
        for (int l = 0; l < nMax; l++) {
            int val = A[l];
            (*S).find(val);
        }
        clock_t sEnd = clock();
        long double sEndt = (long double)(sEnd - start) / nMax;
        sEndt = sEndt / CLOCKS_PER_SEC;

        start = std::clock();
        for (int l = 0; l < nMax; l++) {
            int val = A[l];
            (*US).find(val);
        }
        clock_t usEnd = std::clock();
        long double usEndt = (long double)(usEnd - start) / nMax;
        usEndt = usEndt / CLOCKS_PER_SEC;

        f <<  nMax << "," << vEndt << "," << sEndt << "," << usEndt << "\n";

        delete V;
        delete S;
        delete US;
    }

    f.close();

    return 0;
 }
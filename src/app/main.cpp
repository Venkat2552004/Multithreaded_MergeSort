#include <iostream>
#include <vector>
#include <chrono>

#include "sorting/mergeSort.hpp"
#include "sorting/parallelMergeSort.hpp"

using namespace std;

int SIZE;


int main(int argc, char *argv[]) {
    cout << "Enter the size you want to test with : ";
    cin >> SIZE;

    cout << endl <<  "--Building a vector with " << SIZE << " random elements--" << endl << endl;

    vector<int> A(SIZE);
    vector<int> B(SIZE);

    for(int i = 0; i < SIZE; i++)
        A[i] = B[i] = rand() % SIZE;

    MergeSort *mergeSort = new MergeSort(&A);

    cout << "Recursive Merge Sort started" << endl;
    auto start = std::chrono::high_resolution_clock::now();
    mergeSort->sort();
    auto end = std::chrono::high_resolution_clock::now();
    cout << "Recursive Merge Sort ended" << endl;
    std::chrono::duration<double> duration = end - start;
    cout << "Time taken = " << duration.count() << " seconds" << endl << endl;


    ParallelMergeSort *parallelmergeSort = new ParallelMergeSort(&B);

    cout << "Parallel Merge Sort started" << endl;
    start = std::chrono::high_resolution_clock::now();
    mergeSort->sort();
    end = std::chrono::high_resolution_clock::now();
    cout << "Parallel Merge Sort ended" << endl;
    duration = end - start;
    cout << "Time taken = " << duration.count() << " seconds" << endl << endl;

    return 0;
}
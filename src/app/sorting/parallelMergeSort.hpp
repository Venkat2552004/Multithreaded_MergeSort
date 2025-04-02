#ifndef PMERGESORT_H
#define PMERGESORT_H

#include <vector>
#include<mutex>
#include<thread>
#include <iostream>
#include<algorithm>

class ParallelMergeSort {
    private:
        std::vector<int> *nums;

    public:
        ParallelMergeSort(std::vector<int> *nums);
        ~ParallelMergeSort();
        void sort();
        void recSort(int left, int right);
};

#endif
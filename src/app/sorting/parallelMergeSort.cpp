#include "parallelMergeSort.hpp"

ParallelMergeSort::ParallelMergeSort(std::vector<int> *nums){
    this->nums = nums;
}

ParallelMergeSort::~ParallelMergeSort() {}

void ParallelMergeSort::recSort(int left, int right) {
    if (left >= right) return;
    
    const int THRESHOLD = 5000;

    if (right - left < THRESHOLD){
        std::sort(nums->begin() + left, nums->begin() + right + 1);
        return;
    }


    int mid = left + (right - left) / 2;

    std::thread thread_1([this, left, mid] { 
        this->recSort(left, mid); 
    });
    std::thread thread_2([this, mid, right] {
        this->recSort(mid + 1, right); 
    });

    thread_1.join();
    thread_2.join();

    std::vector<int> arr;
    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right){
        if ((*nums)[i] <= (*nums)[j])
            arr.push_back((*nums)[i++]);
        else
            arr.push_back((*nums)[j++]);
    }

    while (i <= mid)
        arr.push_back((*nums)[i++]);

    while (j <= right)
        arr.push_back((*nums)[j++]);

    for (int k = 0; k < arr.size(); k++)
        (*nums)[left + k] = arr[k];
}

void ParallelMergeSort::sort(){
    if ((*nums).size() == 0) return;

    std::thread thread_1([this]{
        this->recSort(0, (*nums).size() - 1); 
    });

    thread_1.join();
}
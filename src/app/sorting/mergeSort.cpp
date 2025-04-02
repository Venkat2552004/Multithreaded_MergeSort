#include "mergeSort.hpp"

MergeSort::MergeSort(std::vector<int> *nums) {
   this->nums = nums;
}

MergeSort::~MergeSort(){}

void MergeSort::recSort(int left, int right) {
    if(left >= right) return;

    int mid = left + (right - left) / 2;
    recSort(left, mid);
    recSort(mid + 1, right);

    std::vector<int> arr;
    int i = left, j = mid + 1;

    while(i <= mid && j <= right){
        if((*nums)[i] <= (*nums)[j])
            arr.push_back((*nums)[i++]);
        else
            arr.push_back((*nums)[j++]);
    }

    while(i <= mid)
        arr.push_back((*nums)[i++]);

    while(j <= right)
        arr.push_back((*nums)[j++]);

    for(int k = 0; k < arr.size(); k++)
        (*nums)[k + left] = arr[k];

}

void MergeSort::sort(){
    if((*nums).size() == 0) return;
    recSort(0, (*nums).size() - 1);
}


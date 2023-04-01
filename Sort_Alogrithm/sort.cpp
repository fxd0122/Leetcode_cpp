#include <iostream>
#include <vector>
using namespace std;

void InsertionSort(vector<int>& nums){
    for(int i=1; i<nums.size(); i++){
        int j = i-1;
        int key = nums[i];
        while(nums[j] > key && j >= 0){
            nums[j+1] = nums[j];
            j--;
        }
        nums[j+1] = key;
    }
}

void Merge(vector<int>& nums, int left, int right, int mid){
    vector<int> L;
    for(int i=0; i<mid-left+1; i++){
        L.push_back(nums[left+i]);
    }
    vector<int> R;
    for(int i=0; i<right-mid; i++){
        R.push_back(nums[mid+1+i]);
    }
    int i=0, j=0;
    for(int k=left; k<=right; k++){ // 需要考虑边界条件！！！！
        if(i==L.size()){
            nums[k] = R[j++];
        }
        else if(j==R.size() || L[i] < R[j]){
            nums[k] = L[i++];
        }
        else{
            nums[k] = R[j++];
        }
    }
}

void MergeSort(vector<int>& nums, int left, int right){
    if (left >= right) return;
    int mid = (left+right)/2;
    MergeSort(nums, left, mid);
    MergeSort(nums, mid+1, right);
    Merge(nums, left, right, mid);
}

int main(){
    vector<int> nums = {4, 2, 7, 9, 1, 5, 4};
    // InsertionSort(nums);
    MergeSort(nums, 0, nums.size()-1);
    for(int i=0; i<nums.size(); i++){
        cout << nums[i] << "\n";
    }
    cin.get();
}
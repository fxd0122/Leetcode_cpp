#include <iostream>
#include <vector>
using namespace std;

/* InsertionSort */
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

/* MergeSort */
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

/* HeapSort */
int LeftChild(int idx) { // heap下标从1开始
	return 2 * (idx + 1) - 1;
}

int RightChild(int idx) {
	return 2 * (idx + 1);
}

void MaxHeapify(vector<int> &array, int idx, int heap_size) {
	int left = LeftChild(idx);
	int right = RightChild(idx);
	int largest = idx;
	if (left < heap_size && array[left] > array[idx]) {
		largest = left;
	}
	if (right < heap_size && array[right] > array[largest]) {
		largest = right;
	}
	if (largest != idx) {
		swap(array[idx], array[largest]);
		MaxHeapify(array, largest, heap_size);
	}
	else return;
}

void MaxHeapifyV1(vector<int>& array, int idx, int heap_size) {
	int cur_idx = idx;
	int largest = cur_idx;
	while (LeftChild(cur_idx) < heap_size) {
		int left = LeftChild(cur_idx);
		int right = RightChild(cur_idx);
		if (array[left] > array[cur_idx]) {
			largest = left;
		}
		if (right<heap_size && array[right]>array[largest]) {
			largest = right;
		}
		if (largest != cur_idx) {
			swap(array[largest], array[cur_idx]);
			cur_idx = largest;
		}
		else break;
	}
}

void BuildMaxHeap(vector<int>& array) {
	int heap_size = array.size();
	for (int i = array.size() / 2 - 1; i >= 0; i--) {
		MaxHeapify(array, i, heap_size);
	}
}

void HeapSort(vector<int>& array) {
	BuildMaxHeap(array);
	int heap_size = array.size();
	for (int i = array.size() - 1; i >= 1; i--) {
		swap(array[0], array[i]);
		heap_size = heap_size - 1;
		//MaxHeapify(array, 0, heap_size);
		MaxHeapifyV1(array, 0, heap_size);
	}
}

/* QuickSort */
int Partition(vector<int> &array, int begin, int end) {
	int key = (rand() % (end - begin + 1)) + begin; // 随机选择一个key
	swap(array[key], array[end]);
	int value = array[end];
	int i = begin - 1;
	for (int j = begin; j < end; j++) {
		if (array[j] <= value) {
			i++;
			swap(array[i], array[j]);
		}
	}
	swap(array[i + 1], array[end]);
	return i + 1;
}

void QuickSort(vector<int>& array, int begin, int end) {
	if (begin < end) {
		int p = Partition(array, begin, end);
		QuickSort(array, begin, p - 1);
		QuickSort(array, p + 1, end);
	}
}

void TailRecurQuickSort(vector<int>& array, int begin, int end) {
	while (begin < end) {
		int p = Partition(array, begin, end);
		TailRecurQuickSort(array, begin, p - 1);
		begin++;
	}
}

void TailRecurQuickSortV1(vector<int>& array, int begin, int end) {
	while (begin < end) {
		int p = Partition(array, begin, end);
		if (p - begin <= end - p) {
			TailRecurQuickSortV1(array, begin, p - 1);
			begin = p + 1;
		}
		else {
			TailRecurQuickSortV1(array, p + 1, end);
			end = p - 1;
		}
	}
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
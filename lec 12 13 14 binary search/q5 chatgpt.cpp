#include<iostream>
using namespace std;

int getPivot(int arr[], int n) {
    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;
    while (s < e) {
        if (arr[mid] >= arr[0]) {
            s = mid + 1;
        }
        else {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return s;
}

int binarysearch(int arr[], int s, int e, int key) {
    int start = s;
    int end = e;
    int mid;
    while (start <= end) {
        mid = start + (end - start) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] < key) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return -1;
}

int findposition(int arr[], int n, int k) {
    int pivot = getPivot(arr, n);
    if (k >= arr[pivot] && k <= arr[n - 1]) {
        return binarysearch(arr, pivot, n - 1, k);
    }
    else {
        return binarysearch(arr, 0, pivot - 1, k);
    }
}

int main() {
    int arr[5] = {13, 14, 15, 1, 2};
    int n = 5;
    int key = 15;
    int result = findposition(arr, n, key);
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    }
    else {
        cout << "Element not found" << endl;
    }
    return 0;
}


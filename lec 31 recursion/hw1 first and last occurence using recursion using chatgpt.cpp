#include<iostream>
using namespace std;

int firstoccurrence(int *arr, int s, int e, int k) {
    if (s <= e) {
        int mid = (s + e) / 2;
        if (arr[mid] == k && (mid == 0 || arr[mid - 1] < k)) {
            return mid;
        } else if (arr[mid] < k) {
            return firstoccurrence(arr, mid + 1, e, k);
        } else {
            return firstoccurrence(arr, s, mid - 1, k);
        }
    }
    return -1;
}

int lastoccurrence(int *arr, int s, int e, int k) {
    if (s <= e) {
        int mid = (s + e) / 2;
        if (arr[mid] == k && (mid == e || arr[mid + 1] > k)) {
            return mid;
        } else if (arr[mid] <= k) {
            return lastoccurrence(arr, mid + 1, e, k);
        } else {
            return lastoccurrence(arr, s, mid - 1, k);
        }
    }
    return -1;
}

int main() {
    int arr[6] = {1, 3, 3, 4, 5, 6};
    int k = 3;
    cout << "first occurrence is: " << firstoccurrence(arr, 0, 5, k) << endl;
    cout << "last occurrence is: " << lastoccurrence(arr, 0, 5, k);
}

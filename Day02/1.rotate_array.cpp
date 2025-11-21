/*
Question:
Given an integer array nums, rotate the array to the right by k steps,
where k is non-negative.

Example 1:
Input:
nums = [1 2 3 4 5 6 7], k = 3
Output:
[5 6 7 1 2 3 4]

Example 2:
Input:
nums = [-1 -100 3 99], k = 2
Output:
[3 99 -1 -100]

The rotation must be done in-place with O(1) extra space.
*/

#include <iostream>
using namespace std;

int main() {
    int nums[100000];
    int n, k;

    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter k: ";
    cin >> k;

    if (n == 0) return 0;

    k = k % n;  // adjust if k > n

    // reverse whole array
    int i = 0, j = n - 1;
    while (i < j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
        i++;
        j--;
    }

    // reverse first k part
    i = 0;
    j = k - 1;
    while (i < j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
        i++;
        j--;
    }

    // reverse remaining part
    i = k;
    j = n - 1;
    while (i < j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
        i++;
        j--;
    }

    cout << "Rotated array: ";
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}

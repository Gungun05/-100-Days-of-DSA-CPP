/*
Question:
You are given two integer arrays nums1 and nums2, both sorted in non-decreasing order.
You are also given integers m and n, representing how many actual elements are in nums1 and nums2.

nums1 has a total size of m + n. The first m elements contain real values,
and the last n elements are 0 placeholders to fit nums2.

Your task is to merge nums2 into nums1 so that nums1 becomes one sorted array.

Example 1:
Input:
nums1 = [1 2 3 0 0 0], m = 3
nums2 = [2 5 6], n = 3
Output:
[1 2 2 3 5 6]

Example 2:
Input:
nums1 = [1], m = 1
nums2 = [], n = 0
Output:
[1]

Example 3:
Input:
nums1 = [0], m = 0
nums2 = [1], n = 1
Output:
[1]

Constraints:
0 <= m, n <= 200
nums1.length = m + n
nums2.length = n
*/

#include <iostream>
using namespace std;

int main() {
    int nums1[400], nums2[200];
    int m, n;

    cout << "Enter value of m (elements in nums1): ";
    cin >> m;

    cout << "Enter value of n (elements in nums2): ";
    cin >> n;

    cout << "Enter nums1 elements (include only the first " << m << " real elements): ";
    for (int i = 0; i < m; i++) {
        cin >> nums1[i];
    }

    // fill rest with zeros to match size m+n
    for (int i = m; i < m + n; i++) {
        nums1[i] = 0;
    }

    cout << "Enter nums2 elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums2[i];
    }

    int i = m - 1;          // pointer for nums1 actual values
    int j = n - 1;          // pointer for nums2
    int k = m + n - 1;      // pointer for placing values in nums1

    // Merge from the back
    while (j >= 0 && i >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    // If nums2 still has remaining elements
    while (j >= 0) {
        nums1[k] = nums2[j];
        k--;
        j--;
    }

    cout << "Merged array: ";
    for (int x = 0; x < m + n; x++) {
        cout << nums1[x] << " ";
    }
    cout << endl;

    return 0;
}

/*
Question:
Given an integer array nums, move all 0's to the end of the array while
maintaining the relative order of non-zero elements.

Note:
This must be done in-place without using extra space to copy the array.

Example 1:
Input:
nums = [0 1 0 3 12]
Output:
[1 3 12 0 0]

Example 2:
Input:
nums = [0]
Output:
[0]

Constraints:
1 <= nums.length <= 10000
-2^31 <= nums[i] <= 2^31 - 1
*/

#include <iostream>
using namespace std;

int main() {
    int nums[10000];
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int pos = 0;

    // move non-zero values to the front
    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            nums[pos] = nums[i];
            pos++;
        }
    }

    // fill remaining positions with zero
    while (pos < n) {
        nums[pos] = 0;
        pos++;
    }

    cout << "Array after moving zeroes: ";
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}

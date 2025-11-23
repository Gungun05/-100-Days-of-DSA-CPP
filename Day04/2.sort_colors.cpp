/*
    75. Sort Colors

    You are given an array containing only 0, 1, and 2.
    0 -> red
    1 -> white
    2 -> blue

    Sort the array in-place so that 0s come first, then 1s, then 2s.

    You cannot use any built-in sort function.

    Example:
    Input: [2,0,2,1,1,0]
    Output: [0,0,1,1,2,2]

    One-pass + constant space solution (Dutch National Flag Algorithm).
*/

#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int> &nums) {
    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1) {
            mid++;
        }
        else {  // nums[mid] == 2
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main() {
    vector<int> v1 = {2,0,2,1,1,0};
    sortColors(v1);
    for(int x : v1) cout << x << " ";
    cout << endl;

    vector<int> v2 = {2,0,1};
    sortColors(v2);
    for(int x : v2) cout << x << " ";
    cout << endl;

    return 0;
}

/*
    53. Maximum Subarray

    Given an integer array nums, return the sum of the subarray
    that has the largest total.

    Example:
    nums = [-2,1,-3,4,-1,2,1,-5,4] -> 6   (subarray [4,-1,2,1])
    nums = [1] -> 1
    nums = [5,4,-1,7,8] -> 23

    We use Kadane's Algorithm:
    Keep a running sum (curr). At each step, decide whether to
    extend the old subarray or start a new one. Track the best sum.
*/

#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int> &nums) {
    int curr = nums[0];    // running sum
    int best = nums[0];    // best sum so far

    for (int i = 1; i < nums.size(); i++) {

        // choose to extend or restart
        if (curr + nums[i] < nums[i]) {
            curr = nums[i];
        } else {
            curr = curr + nums[i];
        }

        // update best if needed
        if (curr > best) {
            best = curr;
        }
    }

    return best;
}

int main() {
    vector<int> v1 = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(v1) << endl;  // 6

    vector<int> v2 = {1};
    cout << maxSubArray(v2) << endl;  // 1

    vector<int> v3 = {5,4,-1,7,8};
    cout << maxSubArray(v3) << endl;  // 23

    return 0;
}

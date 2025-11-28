/*
    Rearrange array in alternating positive and negative items (preserve order variant)

    Given an array of integers, rearrange it so that positive and negative numbers
    alternate. This implementation preserves the relative order of positive numbers
    and negative numbers (stable). If one side has more elements, the remaining items
    are appended at the end.

    Example:
    Input: [1,2,3,-4,-1,4]
    Output: [1,-4,2,-1,3,4]  (one possible stable arrangement)

    Idea:
    Collect positives and negatives separately (keeping order), then merge them by
    taking one from pos and one from neg alternately. Start with the larger group
    (or positives if equal) for better distribution.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> rearrangeArray(vector<int> &nums) {
    vector<int> pos, neg;
    for (int x : nums) {
        if (x >= 0) pos.push_back(x);
        else neg.push_back(x);
    }

    vector<int> res;
    res.reserve(nums.size());
    int i = 0, j = 0;
    bool startWithPos = (pos.size() >= neg.size());

    while (i < (int)pos.size() || j < (int)neg.size()) {
        if (startWithPos) {
            if (i < (int)pos.size()) res.push_back(pos[i++]);
            if (j < (int)neg.size()) res.push_back(neg[j++]);
        } else {
            if (j < (int)neg.size()) res.push_back(neg[j++]);
            if (i < (int)pos.size()) res.push_back(pos[i++]);
        }
    }

    return res;
}

int main() {
    vector<int> a = {1, 2, 3, -4, -1, 4};
    auto r1 = rearrangeArray(a);
    for (int x : r1) cout << x << " ";
    cout << endl; // e.g. 1 -4 2 -1 3 4

    vector<int> b = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    auto r2 = rearrangeArray(b);
    for (int x : r2) cout << x << " ";
    cout << endl;

    return 0;
}

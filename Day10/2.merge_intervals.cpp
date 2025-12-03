/*
Question:
Given a list of intervals, merge all overlapping intervals and return the resulting non-overlapping intervals.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(2));
    for (int i = 0; i < n; i++) cin >> arr[i][0] >> arr[i][1];

    sort(arr.begin(), arr.end());
    vector<vector<int>> merged;

    for (auto &interval : arr) {
        if (merged.empty() || merged.back()[1] < interval[0]) {
            merged.push_back(interval);
        } else {
            merged.back()[1] = max(merged.back()[1], interval[1]);
        }
    }

    for (auto &it : merged) {
        cout << it[0] << " " << it[1] << endl;
    }
}

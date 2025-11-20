/*
Question:
Given a sorted array, remove duplicate elements in-place such that each element appears only once.
Print the count of unique elements after removal.
*/

#include <iostream>
using namespace std;

int main() {
    int n, a[100];

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the sorted array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    int index = 1;

    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            a[index] = a[i];
            index++;
        }
    }

    cout << "Number of unique elements: " << index << endl;
}

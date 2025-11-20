/*
Question:
Given an array of integers, check whether the array is sorted in non-decreasing order.
Print "Sorted" if it is sorted, otherwise print "Not Sorted".
*/

#include <iostream>
using namespace std;

int main() {
    int n, a[100];
  
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bool sorted = true;

    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            sorted = false;
            break;
        }
    }

    if (sorted) {
        cout << "Sorted" << endl;
    } else {
        cout << "Not Sorted" << endl;
    }
}

/*
Question:
Given an array of integers, find and print the largest element present in the array.
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

    int largest = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] > largest) {
            largest = a[i];
        }
    }

    cout << "Largest element: " << largest << endl;
}

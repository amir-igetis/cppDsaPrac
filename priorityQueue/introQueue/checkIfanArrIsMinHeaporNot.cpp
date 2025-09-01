#include <bits/stdc++.h>
using namespace std;

bool isMaxHeap(int arr[], int n)
{
    for (int i = 0; i <= (n - 2) / 2; i++)
    {
        if (arr[2 * i + 1] > arr[i])
            return false;

        if (2 * i + 2 < n && arr[2 * i + 2] > arr[i])
            return false;
    }
    return true;
}

bool isHeapI(int arr[], int i, int n)
{
    if (i >= (n - 1) / 2)
        return true;

    if (arr[i] >= arr[2 * i + 1] &&
        arr[i] >= arr[2 * i + 2] && isHeapI(arr, 2 * i + 1, n) && isHeapI(arr, 2 * i + 2, n))
        return true;

    return false;
}

int main()
{
    int arr[] = {90, 15, 10, 7, 12, 2};
    int n = 6;
    cout << isMaxHeap(arr, n) << endl;

    // int arr[] = { 90, 15, 10, 7, 12, 2, 7, 3 };
    // int n = sizeof(arr) / sizeof(int) - 1;

    // isHeap(arr, 0, n) ? printf("Yes") : printf("No");
    return 0;
}
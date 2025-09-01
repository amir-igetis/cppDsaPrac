#include <bits/stdc++.h>
using namespace std;

void maxHeapify(vector<int> &arr, int i, int N)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    if (left < N && arr[left] > arr[i])
        largest = left;
    if (right < N && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, largest, N);
    }
}

void convertMinToMaxHeap(vector<int> &arr, int N)
{
    for (int i = (N - 2) / 2; i >= 0; i--)
    {
        maxHeapify(arr, i, N);
    }
}

void printArray(vector<int> &arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

int main()
{

    vector<int> arr = {1, 2, 3, 4};
    int N = 4;
    convertMinToMaxHeap(arr, N);

    printArray(arr, N);
    return 0;
}
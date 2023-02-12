//implementing insertion sort

#include <iostream>
using namespace std;
int count = 0;

void insertionSort(int arr[], int n)
{
    int key, j;
    count++; //declaration
    for(int i=1; i<n; i++)
    {
        count++; //for loop condition comparison
        key = arr[i];
        count++; //assignment
        j = i-1;
        count++; //assignment
        while(j >= 0 && arr[j] > key)
        {
            count++; //while condition comparison, when true
            arr[j+1] = arr[j];
            count++; //assignment
            j = j-1;
            count++; //assignment
        }
        arr[j+1] = key;
        count++; //assignment
    }
}

int main()
{
    int n;
    cout << "Enter number of elements in the array: " << endl;
    cin >> n;
    cout << "Enter elements: " << endl;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    insertionSort(arr, n);
    cout << "Sorted array: " << endl;
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
    cout << "Number of steps: " << count;
    return 0;
}

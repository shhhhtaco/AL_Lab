//implementing bubble sort

#include <iostream>
using namespace std;
int count=0;

void bubbleSort(int arr[], int n)
{
    int i, j;
    count++; //declaration

    for(i=0; i<n-1; i++) //traversing through the array
    {
        count++; //for loop condition comparison
        for(j=0; j<n-i-1; j++) //last i elements are already in place
        {
            count++; //for loop condition comparison
            count++; //if condition comparison
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                count++; //declaration and assignment
                arr[j] = arr[j+1];
                count++; //assignment
                arr[j+1] = temp;
                count++; //assignment
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements of the array: ";

    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    bubbleSort(arr, n);

    cout << "Sorted array: " << endl;

    for(int i=0; i<n; i++)
    {
        cout << arr[i] << "\t";
    }

    cout << endl;

    cout << "Number of steps: " << count;

    return 0;
}

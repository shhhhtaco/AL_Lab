//binary search iterative method

#include <iostream>
using namespace std;
int count = 0;

int binarySearch(int arr[], int n, int target)
{
    int low = 0, high = n-1;
    count++; //declaration and assignment


    while(low <= high)
    {
        count++; //while loop comparison, true condition
        int mid = (low+high)/2;
        count++; //declaration and assignment

        //if target is found in the middle position
        //return index of middle
        count++; //if condition comparison
        if (target == arr[mid])
        {
            count++; //return
            return mid;
        }


        //if target is less than the number in the middle position
        //forget about the right side of the array and search the left
        //forget middle as well

        else if(target < arr[mid])
        {
            count++; //else if condition comparison
            count++; //assignment
            high = mid - 1;
        }

        //if target is greater than the number in the middle position
        //forget about the left side of the array and search the right
        //forget middle as well

        else
        {
            count++; //else condition comparison
            count++; //assignment
            low = mid + 1;
        }
    }

    //if target is not found in the array
    count++; //return
    return -1;
}

int main() {
    int n;
    cout << "Enter number of elements in the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements of the array: ";
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter number to search for: ";
    int target;
    cin >> target;


    int index = binarySearch(arr, n, target);

    if(index != -1)
    {
        cout << "Element " << target << " found at position: " << index;
    }
    else
    {
        cout << "Element " << target << " not found." << endl;
    }
    cout << endl;
    cout << "Number of steps for each search function: " << count;
    return 0;
}



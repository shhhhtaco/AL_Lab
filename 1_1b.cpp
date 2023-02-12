//recursive method
#include <iostream>
using namespace std;
int count = 0;

int binarySearch(int arr[], int low, int high, int target) {

    //if the entire array has been searched and element is not found
    count++; //if condition comparison
    if (low > high) {
        count++; //return statement
        return -1;
    }

    int mid = (high + low)/2;
    count++; //assignment and declaration

    //if the element in the middle position is the target
    count++; //if condition comparison
    if(target == arr[mid])
    {
        count++; //return statement
        return mid;
    }

    //if target is less than the value in the middle
    //forget about the right side of the array and search the left
    //forget middle as well
    else if(target < arr[mid])
    {
        count++; //else if condition comparison
        count++; //assignment
        high = mid - 1;
        count++; //return statement
        return binarySearch(arr, low, high, target);
    }

    //if target is more than the value in the middle
    //forget about the left side of the array and search the right
    //forget middle as well
    else
    {
        count++; //else condition comparison
        count++; //assignment
        low = mid + 1;
        count++; //return statement
        return binarySearch(arr, low, high, target);
    }
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

    int target;
    cout << "Enter element to search for: ";
    cin >> target;

    int low = 0, high = n-1;
    int index = binarySearch(arr, low, high, target);
    if(index != -1) {
        cout << "Element " << target << " found at position: " << index;
    }
    else {
        cout << "Element " << target << " not found." << endl;
    }
    cout << endl;
    cout << "Number of steps for each search function: " << count;
    return 0;
}

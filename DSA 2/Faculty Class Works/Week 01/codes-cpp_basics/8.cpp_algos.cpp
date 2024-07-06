/** https://www.geeksforgeeks.org/c-magicians-stl-algorithms/ */
#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric> //For accumulate operation
using namespace std;

int main()
{
    // Initializing vector with array values
    int arr[] = {10, 20, 5, 20, 42, 20, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> vect(arr, arr + n);

    cout << "Vector is: ";
    for (int i = 0; i < vect.size(); i++)
        cout << vect[i] << " ";

    // Sorting the Vector in Ascending order
    sort(vect.begin(), vect.end());

    cout << "\nVector after sorting is: ";
    for (int i = 0; i < n; i++)
        cout << vect[i] << " ";

    // Reversing the Vector
    reverse(vect.begin(), vect.end());

    cout << "\nVector after reversing is: ";
    for (int i = 0; i < 6; i++)
        cout << vect[i] << " ";

    cout << "\nMaximum element of vector is: ";
    cout << *max_element(vect.begin(), vect.end());

    cout << "\nMinimum element of vector is: ";
    cout << *min_element(vect.begin(), vect.end());

    // Starting the summation from 0
    cout << "\nThe summation of vector elements is: ";
    cout << accumulate(vect.begin(), vect.end(), 0) << endl;

    cout << "Occurrences of 20 in vector : ";

    // Counts the occurrences of 20 from 1st to
    // last element
    cout << count(vect.begin(), vect.end(), 20) << endl;

    // find() returns iterator to last address if
    // element not present
    find(vect.begin(), vect.end(), 5) != vect.end() ? cout << "\nElement found" : cout << "\nElement not found";

    // Returns the first occurrence of 20
    auto q = lower_bound(vect.begin(), vect.end(), 20);
 
    // Returns the last occurrence of 20
    auto p = upper_bound(vect.begin(), vect.end(), 20);
 
    cout << "The lower bound is at position: ";
    cout << q-vect.begin() << endl;
 
    cout << "The upper bound is at position: ";
    cout << p-vect.begin() << endl;

    return 0;
}
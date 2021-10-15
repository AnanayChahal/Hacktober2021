/*
Given an array Arr (distinct elements) of size N. Rearrange the elements of array in zig-zag fashion. The converted array should be in form a < b > c < d > e < f. The relative order of elements is same in the output i.e you have to iterate on the original array only.

Example 1:

Input:
N = 7
Arr[] = {4, 3, 7, 8, 6, 2, 1}
Output: 3 7 4 8 2 6 1
Explanation: 3 < 7 > 4 < 8 > 2 < 6 > 1
Example 2:

Input:
N = 4
Arr[] = {1, 4, 3, 2}
Output: 1 4 2 3
Explanation: 1 < 4 > 2 < 3
Your Task:
You don't need to read input or print anything. Your task is to complete the function zigZag() which takes the array of integers arr and n as parameters and returns void. You need to modify the array itself.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 105
0 <= Arri <= 106
*/

// C++ program to sort an array in Zig-Zag form
#include <iostream>
using namespace std;

// Program for zig-zag conversion of array
void zigZag(int arr[], int n)
{
	// Flag true indicates relation "<" is expected,
	// else ">" is expected. The first expected relation
	// is "<"
	bool flag = true;

	for (int i=0; i<=n-2; i++)
	{
		if (flag) /* "<" relation expected */
		{
			/* If we have a situation like A > B > C,
			we get A > B < C by swapping B and C */
			if (arr[i] > arr[i+1])
				swap(arr[i], arr[i+1]);
		}
		else /* ">" relation expected */
		{
			/* If we have a situation like A < B < C,
			we get A < C > B by swapping B and C */
			if (arr[i] < arr[i+1])
				swap(arr[i], arr[i+1]);
		}
		flag = !flag; /* flip flag */
	}
}

// Driver program
int main()
{
	int arr[] = {4, 3, 7, 8, 6, 2, 1};
	int n = sizeof(arr)/sizeof(arr[0]);
	zigZag(arr, n);
	for (int i=0; i<n; i++)
		cout << arr[i] << " ";
	return 0;
}

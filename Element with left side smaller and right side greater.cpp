/*
Given an unsorted array of size N. Find the first element in array such that all of its left elements are smaller and all right elements to it are greater than it.

Note: Left and right side elements can be equal to required element. And extreme elements cannot be required element.

 

Example 1:

Input:
N = 4
A[] = {4, 2, 5, 7}
Output:
5
Explanation:
Elements on left of 5 are smaller than 5
and on right of it are greater than 5.
 

Example 2:

Input:
N = 3
A[] = {11, 9, 12}
Output:
-1
 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function findElement() which takes the array A[] and its size N as inputs and returns the required element. If no such element present in array then return -1.

 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

 

Constraints:
3 <= N <= 106
1 <= A[i] <= 106
*/

// C++ program to find the element which is greater than
// all left elements and smaller than all right elements.
#include <bits/stdc++.h>
using namespace std;

// Function to return the index of the element which is greater than
// all left elements and smaller than all right elements.
int findElement(int arr[], int n)
{
	// leftMax[i] stores maximum of arr[0..i-1]
	int leftMax[n];
	leftMax[0] = INT_MIN;

	// Fill leftMax[]1..n-1]
	for (int i = 1; i < n; i++)
		leftMax[i] = max(leftMax[i-1], arr[i-1]);

	// Initialize minimum from right
	int rightMin = INT_MAX;

	// Traverse array from right
	for (int i=n-1; i>=0; i--)
	{
		// Check if we found a required element
		if (leftMax[i] < arr[i] && rightMin > arr[i])
			return i;

		// Update right minimum
		rightMin = min(rightMin, arr[i]);
	}

	// If there was no element matching criteria
	return -1;
}

// Driver program
int main()
{
	int arr[] = {5, 1, 4, 3, 6, 8, 10, 7, 9};
	int n = sizeof arr / sizeof arr[0];
	cout << "Index of the element is " << findElement(arr, n);
	return 0;
}

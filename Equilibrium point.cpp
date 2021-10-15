/*Given an array A of n positive numbers. The task is to find the first Equilibium Point in the array. 
Equilibrium Point in an array is a position such that the sum of elements before it is equal to the sum of elements after it.

Example 1:

Input: 
n = 5 
A[] = {1,3,5,2,2} 
Output: 3 
Explanation: For second test case 
equilibrium point is at position 3 
as elements before it (1+3) = 
elements after it (2+2). 
 

Example 2:

Input:
n = 1
A[] = {1}
Output: 1
Explanation:
Since its the only element hence
its the only equilibrium point.
 

Your Task:
The task is to complete the function equilibriumPoint() which takes the array and n as input parameters and returns the point of equilibrium. Return -1 if no such point exists.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= n <= 106
1 <= A[i] <= 108
*/

// C++ program to find equilibrium
// index of an array
#include <bits/stdc++.h>
using namespace std;

int equilibrium(int arr[], int n)
{
	int i, j;
	int leftsum, rightsum;

	/* Check for indexes one by one until
	an equilibrium index is found */
	for (i = 0; i < n; ++i)
	{	

		/* get left sum */
		leftsum = 0;
		for (j = 0; j < i; j++)
			leftsum += arr[j];

		/* get right sum */
		rightsum = 0;
		for (j = i + 1; j < n; j++)
			rightsum += arr[j];

		/* if leftsum and rightsum
		are same, then we are done */
		if (leftsum == rightsum)
			return i;
	}

	/* return -1 if no equilibrium
	index is found */
	return -1;
}

// Driver code
int main()
{
	int arr[] = { -7, 1, 5, 2, -4, 3, 0 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	cout << equilibrium(arr, arr_size);
	return 0;
}



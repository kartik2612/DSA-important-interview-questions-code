//Initial Template for C

#include <stdio.h>
#include <stdlib.h>


 // } Driver Code Ends
//User function Template for C

// arr[]: input array
// N: size of array
// x: element to find index
//Function to find index of element x in the array if it is present.
int closer(int arr[], int n, int x) {
    
    //Your code here
    int i=0;
    int j=n-1;
    while(i<=j)
    {
        int mid=i+(j-i)/2;
        if(arr[mid]==x)
        {
            return mid; 
        }
        else if((mid-1)>=0 && arr[mid-1]==x)
        {
            return mid-1;
        }
        else if((mid+1)<n && arr[mid+1]==x)
        {
            return mid+1;
        }
        else if(arr[mid]<x)
        {
            i=mid+1;
        }
        else
        {
            j=mid-1;
        }
    }
    return -1;
}

// { Driver Code Starts.


int main() {

    int t;
	scanf("%d", &t);

	while (t--) {
		int n;
		scanf("%d", &n);
		int *arr;
		arr = (int*)malloc(n * sizeof(int));
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		int x;
		scanf("%d", &x);
		printf("%d\n", closer(arr, n, x) );
	}
	return 0;

}  // } Driver Code Ends

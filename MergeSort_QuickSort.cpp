#include<iostream>

using namespace std;

/*
Write a program in C/C++ to implement merge sort and quick sort.

Submission instuction: Name your file with the last four digits of your roll number, nothing else.
*/



//MergeSort Definition

void merge(int A[], int p, int q, int r)
{
	int n1 = q-p+1;
	int n2 = r-q;
	int L[n1];
	int R[n2];
	for( int i = 0; i < n1; i++)
	{
		L[i]=A[p+i];
	}
	for(int j = 0; j< n2; j++)
	{
		R[j]=A[j+q+1];
	}
	cout<<endl;
	int x = 0;
	int y = 0;
	int index = p;
	while(x<n1 && y<n2)
	{
		if(L[x]<=R[y])
		{
			A[index]=L[x];
			x++;
		}
		else //(L[x]>R[y])
		{
			A[index]=R[y];
			y++;
		}

		index++;
	}
	while(x<n1)
	{
		A[index]=L[x];
		x++;
		index++;
	}
	while(y<n2)
	{
		A[index]=R[y];
		y++;
		index++;
	}
}
void mergesort(int A[], int p, int r) // 
{
	/*if(p>=r)
		return;*/
	if(p<r)
	{
	int q = p+ ((r-p)/2);	// compute middle index
	mergesort(A,p,q);	// merge sort left subarray 
	mergesort(A,q+1,r);	// merge sort right subarray 
	merge(A,p,q,r);		// merge both sorted subarrays

		// returns when initial index exceeds final index
	}

}


//Quicksort Definition
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
int partition(int A[], int low, int high)
{

	int pivot = A[high];
	int i = low-1;
	for(int j = low; j<high; j++)
	{
		if(A[j]<pivot)
		{
			i++;//low=0
			swap(&A[i],&A[j]);
		}
	}
	swap(&A[i+1],&A[high]);

	return i+1;

	// do{i++;}
	// while(A[i]<pivot);
	// do{j++;}
	// while(A[j]>pivot);
	// if(i<j)
	// 	swap(A[i],A[j]);
	// swap(A[j+1],A[high]);
	// return i+1;


}
void quicksort(int A[],int low, int high)
{
	if(low<high)
	{
		int idx = partition(A, low, high); //A,0,1
		quicksort(A,low,idx-1);
		quicksort(A, idx, high);
	}

}
int main()
{
	int n;
	cin>>n;
	int A[n];
	for(int i = 0; i<n; i++)
		cin>>A[i];
	int flag;
	cout<<"Enter 0 for mergesort and 1 for quicksort:";
	cin>>flag;
	if(flag == 0)
	{
		mergesort(A,0,n-1);
		cout<<"Sorting with MergeSort:";
		for(int i = 0; i<n; i++)
			cout<<A[i]<<" ";
	}

	else if(flag == 1)
	{
		quicksort(A,0,n-1);
		cout<<"Sorting with QuickSort:";
		for(int i = 0; i<n; i++)
			cout<<A[i]<<" ";
	}
	else
		cout<<"Please try running again with proper input.";


}
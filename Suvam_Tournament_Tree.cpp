#include<iostream>
using namespace std;

/*

Write a C/C++ code to find the maximum, second maximum and the minimum of N integers, while ensuring minimum number of comparisons. Your code should display the number of comparisons as the output for any input set of N integers.
0 1 2|3 4 5 6
4 3 4|3 1 4 2


0 1 2 3 4 5 6|7 8 9 10 11 12 13 14
9 9 6|9 7 5 6|9 8 3  7  2  5  1  6

Error corrected for:
11 8 2 12 4

*/
int count = 0;
void tree_pop(int a[], int n, int index)
{
	if(index==0)
	{
		a[index]=max(a[index+1],a[index+2]);
		count++;
		return;
	}
	else
	{
		a[index]=max(a[2*index+2],a[2*index+1]);
		count++;
		return tree_pop(a,n,index-1);
	}
}

int main(){
	int n;
	cin>>n;
	int tree[2*n-1];
	for(int i = n-1; i<2*n-1;i++)
		{cin>>tree[i];}
	if(n==1) {count++; cout<<tree[0]<<endl<<tree[0]; return 0;}
	tree_pop(tree,n,n-2);
	cout<<"Max:"<<tree[0]<<endl;
 	int temp=-1, idx=0;
	while(idx<2*n-2){
		if(tree[idx]==tree[0])
			{count++; idx++;}
		else
			{count++; temp = max(tree[idx],temp);idx=(idx)*2-1;}
	}
	cout<<"Second Max:"<<temp<<endl;
// Min
	int i = n-2,min=tree[0];
	for(i=n-2; i>n-2-(n/2);i--)
	{
		if(tree[i]==tree[2*i+1] && tree[2*i+2]<min)
			{ count++;
				min=tree[2*i+2];}
		else if(tree[i]==tree[2*i+2] && tree[2*i+1]<min)
			{count++;
				min=tree[2*i+1];}

	}
	cout<<"Min:"<<min<<endl;
	cout<<"Count:"<<count;

}
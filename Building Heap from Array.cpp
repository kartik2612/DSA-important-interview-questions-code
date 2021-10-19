#include<bits/stdc++.h>
using namespace std;

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void heapify(int a[],int n,int i)
{
    int largest=i;//make current index as root
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && a[l]>a[largest])
    {
        largest=l;
    }
    if(r<n && a[r]>a[largest])
    {
        largest=r;
    }
    if(largest!=i)
    {
        swap(&a[i],&a[largest]);
        heapify(a,n,largest);
    }
}

void buildHeap(int a[],int n)
{
    int startidx=(n/2)-1;//starting of non leaf node
    for(int i=startidx;i>=0;i--)
    {
        heapify(a,n,i);
    }
}

void printHeap(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    buildHeap(a,n);
    printHeap(a,n);
    return 0;
}

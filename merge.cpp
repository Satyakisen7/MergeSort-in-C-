#include<bits/stdc++.h>
using namespace std;
void merge(int arr[],int l,int m,int r)
{
    int n1=m-l+1;
    int n2=r-m;
    int L[n1],R[n2];
    for(int i=0;i<n1;++i)
    {
        L[i]=arr[l+i];
    }
    for(int j=0;j<n2;++j)
    {
        R[j]=arr[m+1+j];
    }
    int i=0;
    int j=0;
    int k=l;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])//ascending and descending change the sign
        {
            arr[k]=L[i];
            i++;
        }
        else
        {
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=R[j];
        j++;
        k++;
    }
}

void mergesort(int arr[],int l,int r)
{
    if(l<r)
    {
        int m=l+(r-l)/2;

        mergesort(arr,l,m);
        mergesort(arr,m+1,r);

        merge(arr,l,m,r);
    }
}
void display(int arr[],int n)
{
    for(int i=0;i<n;++i)
    {
        cout<<" "<<arr[i];
    }
    cout<<"\n";
}
int main()
{
    int size;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;++i)
    {
        cin>>arr[i];
    }
    mergesort(arr,0,size-1);
    display(arr,size);
}

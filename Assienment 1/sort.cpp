#include<iostream>
using namespace std;
int a[9] = {3,5,2,1,4,9,8,7,6};

int Partition(int A[], int left, int right)
{
    int p = A[left];
    while (left < right)
    {
        while (left < right && A[right] >= p)
        {
            right--;
        }
        A[left] = A[right];
        while (left < right && A[left] <= p)
        {
            left++;
        }
        A[right] = A[left];
    }
    A[left] = p;
    return left;
}

void QuickSort(int A[], int left, int right){
    if(left < right){
        int p = Partition(A, left, right);
        QuickSort(A, left, p - 1);
        QuickSort(A, p+1 , right);
    }
}

int main(){
    QuickSort(a,0,8);
    for(int i=0;i<9;i++){
        cout<<a[i]<<endl;
    }
}
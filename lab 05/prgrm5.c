#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void quick_sort(int a[],int low,int high){
    int j;
    if(low<high){
            j=partition(a,low,high);
            quick_sort(a,low,j-1);
            quick_sort(a,j+1,high);

    }
}

int partition(int a[],int low,int high){
    int i,j,pivot,temp1,temp2;

    i=low;
    j=high+1;
    pivot=a[low];

    while(i<=j){
        do{
            i++;
        }
        while(pivot>=a[i]);
        do{
            j--;
        }
        while(pivot<a[j]);

        if(i<j){
                temp1=a[i];
                a[i]=a[j];
                a[j]=temp1;

        }
    }
    temp2=a[low];
    a[low]=a[j];
    a[j]=temp2;

    return j;

}

int main(){

    int n;
    clock_t start,end;
    printf("enter the no of elements ");
    scanf("%d",&n);
    int a[n],low,high;
    low=0;
    high=n-1;
    printf("enter the elements");
    for(int i=0;i<n;i++){
        //scanf("%d",&a[i]);
        a[i]=rand();
    }
    start=clock();

    quick_sort(a,low,high);
    end=clock();

    printf("the sorted array is:");

    for(int i=0;i<n;i++){
        printf("%d \t",a[i]);
    }
    printf("\n");
    double t = (double)(end-start)/CLOCKS_PER_SEC;
    printf("%f",t);
return 0;

}

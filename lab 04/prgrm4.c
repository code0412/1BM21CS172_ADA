#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge_sort(int a[],int low, int high, int size){
     int mid;

     if(low<high){
            mid=(low+high)/(2);
            merge_sort(a,low,mid,size);
            merge_sort(a, mid+1,high,size);
            merge(a,low,mid,high,size);
             }



 }

 void merge(int a[], int low, int mid, int high , int size){

     int i,j,k;
     int b[size];
     i=low;
     k=low;
     j= mid+1;
     while(i<=mid && j<=high){
        if(a[i]<a[j]){
            b[k]=a[i];
            i++;
            k++;
        }
        else{

            b[k]=a[j];
            j++;
            k++;
        }


        }
    while(i<=mid){
        b[k]=a[i];
        i++;
        k++;

    }
    while(j<=high){
        b[k]=a[j];
        j++;
        k++;
    }
    for(i=low;i<=high;i++){
        a[i]=b[i];

    }


     }



 int main(){
     int n, low, high;
     clock_t start,end;
     printf("ENTER THE ARRAY SIZE");
     scanf("%d",&n);
     int arr[n];
     printf("ENTER THE ARRAY ELEMENTS");

     int i;
     for(i=0;i<n;i++){
            arr[i]=rand()%10000;

     }
     low = 0;
     high = n-1;
     start = clock();

     merge_sort(arr,low,high,n);

     end = clock();
     printf("Sorted Array");
     for(i=0;i<n;i++){
        printf("%d\t",arr[i]);
     }
     printf("\n");

     double t = (double)(end-start)/(CLOCKS_PER_SEC);
     printf("%f",t);
        return 0;
     }








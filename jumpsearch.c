#include "stdio.h"
#include "math.h"
int min (int first, int second){
    if (second > first){
        return first;
    }
    else{
        return second;
    }
}
int jumpSearch(int arr[], int size, int key){
    int step = sqrt(size);
    int previous =0;
    while(arr[min(step,size)-1]<key){
        previous = step;
        step = step + sqrt(size);
        if(previous >= size){
            return -1;
        }

    }
    if (key = arr[step-1]){
        return step-1;
    }
     for (int j=previous; j< step ; j++){
         if (arr[j]== key){
             return j;
         }
     }
     return -1;

}
int main()
{
    int arr[] = { 10,15,18,30,42,50,57,60,63,70,75,80};
    int size = sizeof(arr)/sizeof(arr[0]);
    int toFind =15;
    int indexNumber =  jumpSearch(arr, size, toFind);
    if (indexNumber!= -1){
        printf (" We found\n");
        printf("found at index:%d  data:%d ",indexNumber,arr[indexNumber]);
    }
    else {
        printf (" Not found\n");
    }


    return 0;
}
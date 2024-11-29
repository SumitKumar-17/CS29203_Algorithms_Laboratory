#include<stdio.h>

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1; // Element not found
}


int result(int n,int k,int *prizes){
      int i;
      int sum=0;
      for(i=0;i<k;i++){
        sum+=prizes[i];
      }

      return (sum/n);
}

int main(){
    int n;
    scanf("%d",&n);

    int k;
    scanf("%d",&k);

    int i;
    int prizes[k];

    for(i=0;i<k;i++){
        scanf("%d",&prizes[i]);
    }

    int ans=result(n,k,prizes);
    printf("the answer is %d",ans);                                                                                                                      
}
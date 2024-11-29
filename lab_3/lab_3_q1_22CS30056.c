#include <stdio.h>

// Function to compare two intervals based on their end times
int compare(const void* a, const void* b) {
    return *((int*)a + 1) - *((int*)b + 1);
}

int find(int p[],int arr[],int index){
    int counter=0;
    int n=index;
   // printf("%d--",index);
   int i,j;
    for (i=p[0];i<p[1]+1;i++){
        for(j=0;j<n;j++){
            if(arr[j]==i) counter++;
            //printf("-%d %d-\n",arr[j],i);
        }
    }
 
    return counter;
}

int minPowerOnTime(int programs[][3], int n) {
    
    qsort(programs, n, sizeof(programs[0]), compare);

    int currentTime = 0;
    int powerOnTime = 0;
  int i,j;
    for (i = 0; i < n; i++) {
        if (programs[i][0] > currentTime) {
          
            currentTime = programs[i][0];
        }
        
       
        powerOnTime += programs[i][2];
        currentTime += programs[i][2];
    }
    
    
    for(i=0;i<n;i++){
         for(j=i+1;j<n;j++){
             int index=programs[i][1]-programs[i][0]+1;
             int num1=programs[i][0];
             int arr[index];
             int q;
             for(q=0;q<index;q++){
                 arr[q]=num1;
                 num1++;
             }
            
             
             int check=find(programs[j],arr,index);
             powerOnTime-=check;
         }
     }

    return powerOnTime;
}

int main() {
    int n;
    printf("Enter the number of programs");
    scanf("%d",&n);
   
   printf("enter the data\n");
    int programs[n][3] ;
    int i;
    for(i=0;i<n;i++){
            scanf("%d %d %d",&programs[i][0],&programs[i][1],&programs[i][2]);

    }
    n = sizeof(programs) / sizeof(programs[0]);
   printf("Minimum time workstation should be on:");

    int result = minPowerOnTime(programs, n);
    printf(" %d\n", result);

    return 0;
}
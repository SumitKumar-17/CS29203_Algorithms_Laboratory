#include<stdio.h>
#include<math.h>
int n;
int city1;
int city2;
int path[100000];


void merge(float arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    float L[n1], R[n2];
    int i ,j;
    for (i= 0; i < n1; i++)
        L[i] = arr[l + i];
    for ( j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
     j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// MergeSort function
void mergeSort(float arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}


float distance(int *a1,int *a2){
    return sqrt(pow(a1[0]-a2[0],2)+pow(a1[1]-a2[1],2));
}

void findindex(float dist[n][n],float k){
    int i,j;
      for( i=0;i<n;i++){
        for(j=0;j<n;j++){
              if(k==dist[i][j]) {
                city1=i;
                city2=j;
              }
        }
    }

}

float greedy(int n,float dist[n][n],int path[n+1]){

    int checkvisit[n]; 
    int i,j;
    for(i=0;i<n;i++){
        checkvisit[i]=0;
    }

    float distcopy[n][n];
    for( i=0;i<n;i++){
        for(j=0;j<n;j++){
              distcopy[i][j]=dist[i][j];
        }
    }

     
    for(i=0;i<n;i++){
        mergeSort(distcopy[i],0,n-1);
    }

    int z=0;
     checkvisit[0]=1;
     path[z++]=0;
     path[n]=0;

    float cost=0;
    
    for(j=1;j<n;j++){
    for( i=0;i<n;i++){
            float k=distcopy[j][i];

            findindex(distcopy,k);
            if(checkvisit[city1]==1 && checkvisit[city2]==0){
                cost+=k;
                path[z++]=city2;
                checkvisit[city2]=1;
                break;

            }
            else if(checkvisit[city2]==1 && checkvisit[city1]==0){
                cost+=k;
                path[z++]=city1;
                checkvisit[city1]=1;
                break;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
            }
            else if(checkvisit[city2]==1 && checkvisit[city1]==1) continue;
        
    }
    }

    for(i=0;i<n+1;i++){ printf("%d->",path[i]);}


    return cost;

     


}

int main(){
    
    scanf("%d",&n);

    int coord[n][2];
    int i,j;
    for(i=0;i<n;i++){
        scanf("%d %d",&coord[i][0],&coord[i][1]);
    }

    float dist[n][n];
    
     for(i=0;i<n;i++){
        for(j=0;j<n;j++){
              dist[i][j]=distance(coord[i],coord[j]);
        }
    }

   
    float cost=greedy(n,dist,path)+distance(coord[0],coord[path[1]])+distance(coord[0],coord[path[n-1]]);

    int c=cost;
    
    printf("\nthe path cost  is %d",c);

}
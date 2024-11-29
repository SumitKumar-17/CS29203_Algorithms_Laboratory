#include <stdio.h>
//-12 18 47 -12 -12 85 -12 73 10 -12 -12
//0  -3 5 -4 -2 3 1 0
int main(){
    int n;
    printf("enter the number of people in the value:");
    //takes the input value n how many people are there in the country
    scanf("%d",&n);

    //this is the array in which the FI will be stored
    int arr[n];
    int counter[n][2];
    int i,j;
    printf("Enter the FI list for a country:");
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
       
    }

    //an array k is initialized which will store the indexes of our required numbers
    int k[n];
    int x=0;
    
    //this is o(n*n) algorithm
    //it iterates through the loop and for each element it 
    //calcualte the sum of previous values and after value
    for ( i = 0; i < n; i++)
    {   
        int p=i;
        int sumprev=0;
        int sumafter=0;
        for (j = 0; j<n; j++)
        {
            if(j<i) sumprev+=arr[j];
            else if(j>i) sumafter+=arr[j];
        }
        
        //the index gets stored in k array if it matches the conditions
        if(sumprev==sumafter) k[x++]=p;
        
        
    }
    int l=0;

    printf("Stable indices in the list are:");
    for(l;l<x;l++){
        printf("%d ",k[l]);
    }
    return 0;


    
   
}

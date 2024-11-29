#include <stdio.h>

int main(){
    int n;
    //takes the input value n how many people are there in the country
    printf("enter the number of people in the value:");
    scanf("%d",&n);

    
    int arr[n];
    int i,j;
    //i have used a sumaaray which will store the values before its index number
    int sumarr[n+1];
    for ( i = 0; i < n; i++)
    {
        sumarr[i]=0;
    }

    //this is the array in which the FI will be stored
    printf("Enter the FI list for a country:");
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);

    }

    //storing the values in sumarr
    sumarr[0]=0;
    for ( i = 0; i < n; i++)
    {
        sumarr[i+1]=(sumarr[i]+arr[i]);

    }
    
    //an array k is initialized which will store the indexes of our required numbers
    int k[n];
    int x=0;
    int sumprev;
    int sumafter;

   //this is O(n) algorithm getting used
    for ( i = 0; i < n; i++)
    {   int p=i;
        int sumprev=sumarr[i];
        int sumafter=sumarr[n]-sumarr[i]-arr[i];
        
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

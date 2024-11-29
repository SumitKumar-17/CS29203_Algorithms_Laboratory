#include<stdio.h>
//Enter the FI list for a country: -12, 18, 47, -12, -12, 85, -12, 73, 10, -12, -12
//(Output) The FI value present in most of the people: -1

int main(){
    int n;
    //takes the input value n how many people are there in the country
    printf("enter the number of people in the value");
    scanf("%d",&n);

    //this is the array in which the FI will be stored
    int arr[n];
    int i,j;
    printf("Enter the FI list for a country:");
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
       
    }
   
    printf("The FI value present in most of the people:");

    //this is a frequency array which stores the count of each element as per its index
    //all values of counter array are first initialized to zero
    int counter[n];
    for ( i = 0; i < n; i++){
        counter[i]=0;
    }
    //this is o(n*n) algorithm used to count the frequency of each element
    for ( i = 0; i < n; i++)
    {
        for (j = 0; j< n; j++)
        {
            if(arr[i]==arr[j])  counter[i]++;
        }
        
    }
    
    //now I have found the index number of the maximum FI
    int max=0;
    int maxindex=0;
    for ( i = 0; i < n; i++)
    {
        if(counter[i]>max) {
            max=counter[i];
            maxindex=i;
        }
    }

    //If the value of FI is for more than half of people then it is printed
    if(counter[maxindex]>n/2){
          printf("%d",arr[maxindex]);
    }
    
    
}
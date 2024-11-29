#include <stdio.h>

//time complexity of the function is o(n)
int maxFreq(int *arr, int n) {

	int res = 0;
	int count = 1;
    int i;
    //the time complexity of the algorithm is o(n)
	for(i = 1; i < n; i++) {
		if(arr[i] == arr[res]) {
			count++;
		} else {
			count--;
		}
		
		if(count == 0) {
			res = i;
			count = 1;
		}
		
	}
	
	return arr[res];
}


int main(){
    int n;
    printf("enter the number of people in the value");
    //takes the input value n how many people are there in the country
    scanf("%d",&n);

    //this is the array in which the FI will be stored
    int arr[n];
    int i,j;
    printf("Enter the FI list for a country:");
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
       
    }
    
    //this is a function created which finally returns the max freq element
	int freq = maxFreq(arr , n);

    //If the value of FI is for more than half of people then it is printed
    
    printf("The FI value present in most of the people: %d",  maxFreq(arr , n)) ;
    
	
	
	return 0;
}


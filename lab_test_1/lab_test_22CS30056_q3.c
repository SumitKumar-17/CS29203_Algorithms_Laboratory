#include<stdio.h>

float operation(float a ,float b,char ch){
    if(ch=='*') return a*b;

    else return a+b;
}

float max(float a,float b){
         return a>b?a:b;
}

float calculate(float *arr, char *ch,int n){
     float dp[n][n];
     
     int i,j;


     for( i=0;i<n;i++){
        for(j=0;j<n-1;j++){
            if(i==0||j==0) dp[i][j]=0;
             
             else{
            float val1=operation(arr[i-1],arr[i],ch[i-1]);
            float val2=operation(arr[i],arr[i+1],ch[i]);
            dp[i][j]=max(dp[i-1][j-1],max(dp[i-1][j],dp[i][j-1]))+max(val1,val2);
             }

        }
     }


     return dp[n-1][n-2];
}

int main(){
    int i,n;
    printf("Number of positive numbers");
    scanf("%d",&n);
    

    float arr[n];
    for(i=0;i<n;i++){
        scanf("%f",&arr[i]);
    }

    printf("\n Enter %d characters from left to right",n-1);

    char ch[n-1];

    char asd;
    for(i=0;i<n;i++){
        scanf("%c",&ch[i]);
        scanf("%c",&asd);
        
    }
    float result=calculate(arr,ch,n);
    printf("max value of expression is :%f" ,result);




}
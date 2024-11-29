#include<stdio.h>
//this is a function which returns the final left 
//treasure in the game 
int box(int n,int m){
    if(n==1) return 1;
    int r=(m-1)%n;
    int f=box(n-1,m);
    return (f+r)%n +1;
}

int main(){
    int n,m;
    printf("n=");
    scanf("%d",&n);
    printf("m=");
    scanf("%d",&m);
    int k=box(n,m);
    printf("\n output:%d\n",k);

}
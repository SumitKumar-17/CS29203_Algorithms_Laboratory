#include <stdio.h>

int maxPoints(int machines[][2], int n) {
    int dp[n];
    int i;
    for (i = n - 1; i >= 0; i--) {
        int play_points = machines[i][0];
        int skip = machines[i][1];
        
        if (i + skip >= n) {
            dp[i] = play_points;
        } else {
            dp[i] = play_points + dp[i + skip];
            if (dp[i] < dp[i + 1]) {
                dp[i] = dp[i + 1];
            }
        }
    }
    
    return dp[0];
}

int main() {
    int m;
    scanf("%d ",&m);
    int machine[m][2] ;
    int i;
    for (i = 0; i <m; i++) {
      
         scanf("%d %d",&machine[i][0],&machine[i][1]);
    
    }
    
    printf("%d", maxPoints(machine, m)); 
   
    
    return 0;
}
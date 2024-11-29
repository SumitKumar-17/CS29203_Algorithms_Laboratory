#include <stdio.h>
#include <string.h>

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}


void findDifference(char X[], char Y[]) {
    int m = strlen(X);
    int n = strlen(Y);
    int i,j;

    // Create a 2D array to store LCS lengths
    int dp[m + 1][n + 1];

    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Initialize indices for tracing LCS
    i = m, j = n;

    char diff[2 * (m + n)]; 

    int k = 0; 
    // Trace the LCS to find differences
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            diff[k++] = X[i - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            diff[k++] = X[i - 1];
            diff[k++] = '-';
            
            i--;
        } else {
            diff[k++] = Y[j - 1];
            diff[k++] = '+';
            
            j--;
        }
    }

    // If there are remaining characters in X or Y
    while (i > 0) {
        diff[k++] = X[i - 1];
        diff[k++] = '-';
        
        i--;
    }
    while (j > 0) {
        diff[k++] = Y[j - 1];
        diff[k++] = '+';
        
        j--;
    }

    // Print the reversed difference string
    int l;
    for (l= k - 1; l >= 0; l--) {
        printf("%c ", diff[l]);
    }
}

int main() {
    char X[1000] ;
    char Y[1000] ;
    scanf("%s",&X);
    scanf("%s",&Y);

    
    printf("Output: ");
    findDifference(X, Y);
    
    return 0;
}
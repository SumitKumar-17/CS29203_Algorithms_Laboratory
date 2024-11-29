

#include <stdio.h>
#include <string.h>

void solveAlphabetGame(char *initiator) {
    int len = strlen(initiator);
    char receiver[len];
    char paper[len];
    int receiverIdx = 0;
    int paperIdx = 0;
    
    int i;
    for (i = 0; i < len; i++) {
        while (receiverIdx > 0 && receiver[receiverIdx - 1] <= initiator[i]) {
            paper[paperIdx++] = receiver[receiverIdx - 1];
            receiverIdx--;
        }
        receiver[receiverIdx++] = initiator[i];
    }

    while (receiverIdx > 0) {
        paper[paperIdx++] = receiver[receiverIdx - 1];
        receiverIdx--;
    }

    paper[paperIdx] = '\0';
    printf("%s\n", paper);
}

int main() {
    char initiator[100];
    scanf("%s", initiator);
    solveAlphabetGame(initiator);
    return 0;
}
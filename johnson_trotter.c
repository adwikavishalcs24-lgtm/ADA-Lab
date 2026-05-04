#include <stdio.h>

int perm[10], dir[10];

void printPerm(int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", perm[i]);
    printf("\n");
}

int getMobile(int n) {
    int mobile = 0, pos = -1;

    for(int i = 0; i < n; i++) {
        int next = i + dir[i];

        if(next >= 0 && next < n && perm[i] > perm[next]) {
            if(perm[i] > mobile) {
                mobile = perm[i];
                pos = i;
            }
        }
    }
    return pos;
}

void johnsonTrotter(int n) {
    for(int i = 0; i < n; i++) {
        perm[i] = i + 1;
        dir[i] = -1;
    }

    printPerm(n);

    while(1) {
        int mobilePos = getMobile(n);

        if(mobilePos == -1)
            break;

        int swapPos = mobilePos + dir[mobilePos];

        int temp = perm[mobilePos];
        perm[mobilePos] = perm[swapPos];
        perm[swapPos] = temp;

        temp = dir[mobilePos];
        dir[mobilePos] = dir[swapPos];
        dir[swapPos] = temp;

        mobilePos = swapPos;

        for(int i = 0; i < n; i++) {
            if(perm[i] > perm[mobilePos])
                dir[i] *= -1;
        }

        printPerm(n);
    }
}

int main() {
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    johnsonTrotter(n);

    return 0;
}

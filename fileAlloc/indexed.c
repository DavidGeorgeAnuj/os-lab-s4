#include <stdio.h>

int main() {
    int files[50][50]; // file index table
    int indexBlock, n, blocks[50], i, j;

    printf("Enter the index block: ");
    scanf("%d", &indexBlock);

    printf("Enter number of blocks needed for the file: ");
    scanf("%d", &n);

    printf("Enter the block numbers:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &blocks[i]);
    }

    // store block numbers in index table
    for (i = 0; i < n; i++) {
        files[indexBlock][i] = blocks[i];
    }

    // display allocation
    printf("\nFile Indexed Allocation Table:\n");
    printf("Index Block: %d\n", indexBlock);
    printf("Blocks Allocated: ");
    for (i = 0; i < n; i++) {
        printf("%d ", files[indexBlock][i]);
    }
    printf("\n");

    return 0;
}

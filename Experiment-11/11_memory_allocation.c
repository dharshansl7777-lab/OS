#include <stdio.h>

void firstFit(int blocks[], int nb, int processes[], int np)
{
    int allocation[20], i, j;

    for(i = 0; i < np; i++)
        allocation[i] = -1;

    for(i = 0; i < np; i++)
        for(j = 0; j < nb; j++)
            if(blocks[j] >= processes[i])
            {
                allocation[i] = j;
                blocks[j] -= processes[i];
                break;
            }

    printf("\nFirst Fit\n");
    printf("Process No\tProcess Size\tBlock No\n");

    for(i = 0; i < np; i++)
    {
        printf("%d\t\t%d\t\t", i + 1, processes[i]);
        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

void bestFit(int blocks[], int nb, int processes[], int np)
{
    int allocation[20], i, j, bestIdx;

    for(i = 0; i < np; i++)
        allocation[i] = -1;

    for(i = 0; i < np; i++)
    {
        bestIdx = -1;

        for(j = 0; j < nb; j++)
            if(blocks[j] >= processes[i])
                if(bestIdx == -1 || blocks[j] < blocks[bestIdx])
                    bestIdx = j;

        if(bestIdx != -1)
        {
            allocation[i] = bestIdx;
            blocks[bestIdx] -= processes[i];
        }
    }

    printf("\nBest Fit\n");
    printf("Process No\tProcess Size\tBlock No\n");

    for(i = 0; i < np; i++)
    {
        printf("%d\t\t%d\t\t", i + 1, processes[i]);
        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

void worstFit(int blocks[], int nb, int processes[], int np)
{
    int allocation[20], i, j, worstIdx;

    for(i = 0; i < np; i++)
        allocation[i] = -1;

    for(i = 0; i < np; i++)
    {
        worstIdx = -1;

        for(j = 0; j < nb; j++)
            if(blocks[j] >= processes[i])
                if(worstIdx == -1 || blocks[j] > blocks[worstIdx])
                    worstIdx = j;

        if(worstIdx != -1)
        {
            allocation[i] = worstIdx;
            blocks[worstIdx] -= processes[i];
        }
    }

    printf("\nWorst Fit\n");
    printf("Process No\tProcess Size\tBlock No\n");

    for(i = 0; i < np; i++)
    {
        printf("%d\t\t%d\t\t", i + 1, processes[i]);
        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

int main()
{
    int blocks[20], processes[20], nb, np, i;
    int b1[20], b2[20], b3[20];

    printf("Enter Number of Blocks: ");
    scanf("%d", &nb);

    printf("Enter Number of Processes: ");
    scanf("%d", &np);

    printf("Enter Block Sizes:\n");
    for(i = 0; i < nb; i++)
        scanf("%d", &blocks[i]);

    printf("Enter Process Sizes:\n");
    for(i = 0; i < np; i++)
        scanf("%d", &processes[i]);

    for(i = 0; i < nb; i++)
    {
        b1[i] = blocks[i];
        b2[i] = blocks[i];
        b3[i] = blocks[i];
    }

    firstFit(b1, nb, processes, np);
    bestFit(b2, nb, processes, np);
    worstFit(b3, nb, processes, np);

    return 0;
}

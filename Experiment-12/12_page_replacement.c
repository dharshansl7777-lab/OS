#include <stdio.h>

void fifo(int pages[], int n, int f)
{
    int frames[10], i, j, k = 0, fault = 0, found;

    for(i = 0; i < f; i++)
        frames[i] = -1;

    for(i = 0; i < n; i++)
    {
        found = 0;

        for(j = 0; j < f; j++)
            if(frames[j] == pages[i])
            {
                found = 1;
                break;
            }

        if(!found)
        {
            frames[k] = pages[i];
            k = (k + 1) % f;
            fault++;
        }
    }

    printf("FIFO Page Faults = %d\n", fault);
}

void lru(int pages[], int n, int f)
{
    int frames[10], time[10];
    int i, j, fault = 0, count = 0;
    int found, pos, min;

    for(i = 0; i < f; i++)
        frames[i] = -1;

    for(i = 0; i < n; i++)
    {
        found = 0;

        for(j = 0; j < f; j++)
            if(frames[j] == pages[i])
            {
                count++;
                time[j] = count;
                found = 1;
                break;
            }

        if(!found)
        {
            min = time[0];
            pos = 0;

            for(j = 0; j < f; j++)
            {
                if(frames[j] == -1)
                {
                    pos = j;
                    break;
                }

                if(time[j] < min)
                {
                    min = time[j];
                    pos = j;
                }
            }

            frames[pos] = pages[i];
            count++;
            time[pos] = count;
            fault++;
        }
    }

    printf("LRU Page Faults = %d\n", fault);
}

void optimal(int pages[], int n, int f)
{
    int frames[10];
    int i, j, k, pos = 0, fault = 0, found;

    for(i = 0; i < f; i++)
        frames[i] = -1;

    for(i = 0; i < n; i++)
    {
        found = 0;

        for(j = 0; j < f; j++)
            if(frames[j] == pages[i])
            {
                found = 1;
                break;
            }

        if(!found)
        {
            int farthest = -1;

            for(j = 0; j < f; j++)
            {
                int future = 999;

                for(k = i + 1; k < n; k++)
                    if(frames[j] == pages[k])
                    {
                        future = k;
                        break;
                    }

                if(frames[j] == -1)
                {
                    pos = j;
                    farthest = 9999;
                    break;
                }

                if(future > farthest)
                {
                    farthest = future;
                    pos = j;
                }
            }

            frames[pos] = pages[i];
            fault++;
        }
    }

    printf("Optimal Page Faults = %d\n", fault);
}

int main()
{
    int pages[50], n, f, i;

    printf("Enter Number of Pages: ");
    scanf("%d", &n);

    printf("Enter Reference String:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter Number of Frames: ");
    scanf("%d", &f);

    fifo(pages, n, f);
    lru(pages, n, f);
    optimal(pages, n, f);

    return 0;
}

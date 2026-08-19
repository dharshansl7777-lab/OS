#include <stdio.h>

int main()
{
    int n, i, j, temp, choice, tq;
    int bt[20], pr[20], wt[20], tat[20], rem_bt[20];
    float avg_wt = 0, avg_tat = 0;

    printf("1. FCFS\n2. SJF\n3. Priority\n4. Round Robin\n");
    printf("Enter Choice: ");
    scanf("%d", &choice);

    printf("Enter Number of Processes: ");
    scanf("%d", &n);

    if(choice == 3)
    {
        for(i = 0; i < n; i++)
        {
            printf("Enter Burst Time for P%d: ", i + 1);
            scanf("%d", &bt[i]);
            printf("Enter Priority for P%d: ", i + 1);
            scanf("%d", &pr[i]);
        }

        for(i = 0; i < n - 1; i++)
            for(j = i + 1; j < n; j++)
                if(pr[i] > pr[j])
                {
                    temp = pr[i]; pr[i] = pr[j]; pr[j] = temp;
                    temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                }
    }
    else
    {
        for(i = 0; i < n; i++)
        {
            printf("Enter Burst Time for P%d: ", i + 1);
            scanf("%d", &bt[i]);
            rem_bt[i] = bt[i];
        }

        if(choice == 2)
            for(i = 0; i < n - 1; i++)
                for(j = i + 1; j < n; j++)
                    if(bt[i] > bt[j])
                    {
                        temp = bt[i];
                        bt[i] = bt[j];
                        bt[j] = temp;
                    }
    }

    if(choice == 4)
    {
        printf("Enter Time Quantum: ");
        scanf("%d", &tq);

        int time = 0, done;
        do
        {
            done = 1;
            for(i = 0; i < n; i++)
                if(rem_bt[i] > 0)
                {
                    done = 0;
                    if(rem_bt[i] > tq)
                    {
                        time += tq;
                        rem_bt[i] -= tq;
                    }
                    else
                    {
                        time += rem_bt[i];
                        wt[i] = time - bt[i];
                        rem_bt[i] = 0;
                    }
                }
        } while(!done);
    }
    else
    {
        wt[0] = 0;
        for(i = 1; i < n; i++)
            wt[i] = wt[i - 1] + bt[i - 1];
    }

    printf("\nProcess\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++)
    {
        tat[i] = wt[i] + bt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
        printf("P%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat / n);

    return 0;
}

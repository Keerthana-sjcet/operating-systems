#include<stdio.h>

int main(){
    int n;
    printf("Enter number of processes: ");
    scanf("%d",&n);

    int AT[n], BT[n], WT[n], TAT[n], CT[n];

    for(int i=0;i<n;i++){
        printf("\nProcess %d\n",i+1);
        printf("Arrival Time: ");
        scanf("%d",&AT[i]);
        printf("Burst Time: ");
        scanf("%d",&BT[i]);
    }

    int time=0, totalWT=0, totalTAT=0;

    for(int i=0;i<n;i++){
        if(time < AT[i])
            time = AT[i];

        WT[i] = time - AT[i];
        time += BT[i];
        CT[i] = time;
        TAT[i] = CT[i] - AT[i];

        totalWT += WT[i];
        totalTAT += TAT[i];
    }

    printf("\nProcess AT BT WT TAT\n");
    for(int i=0;i<n;i++)
        printf("%d      %d  %d  %d  %d\n",i+1,AT[i],BT[i],WT[i],TAT[i]);

    printf("\nAverage WT = %.2f", (float)totalWT/n);
    printf("\nAverage TAT = %.2f", (float)totalTAT/n);

    return 0;
}

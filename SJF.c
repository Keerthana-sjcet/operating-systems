#include<stdio.h>
#include<limits.h>

int main(){
    int n;
    printf("Enter number of processes: ");
    scanf("%d",&n);

    int AT[n], BT[n], WT[n], TAT[n], CT[n], done[n];

    for(int i=0;i<n;i++){
        printf("\nProcess %d\n",i+1);
        scanf("%d%d",&AT[i],&BT[i]);
        done[i]=0;
    }

    int completed=0, time=0, totalWT=0, totalTAT=0;

    while(completed<n){
        int minBT=INT_MAX, index=-1;

        for(int i=0;i<n;i++){
            if(AT[i]<=time && !done[i] && BT[i]<minBT){
                minBT=BT[i];
                index=i;
            }
        }

        if(index==-1){
            time++;
        } else {
            WT[index]=time-AT[index];
            time+=BT[index];
            CT[index]=time;
            TAT[index]=CT[index]-AT[index];

            totalWT+=WT[index];
            totalTAT+=TAT[index];

            done[index]=1;
            completed++;
        }
    }

    printf("\nProcess AT BT WT TAT\n");
    for(int i=0;i<n;i++)
        printf("%d      %d  %d  %d  %d\n",i+1,AT[i],BT[i],WT[i],TAT[i]);

    printf("\nAverage WT = %.2f",(float)totalWT/n);
    printf("\nAverage TAT = %.2f",(float)totalTAT/n);

    return 0;
}

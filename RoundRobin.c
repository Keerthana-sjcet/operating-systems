#include<stdio.h>

int main(){
    int n, tq;
    printf("Enter number of processes: ");
    scanf("%d",&n);

    int AT[n], BT[n], RT[n], WT[n], TAT[n], CT[n];

    for(int i=0;i<n;i++){
        printf("\nProcess %d\n",i+1);
        scanf("%d%d",&AT[i],&BT[i]);
        RT[i]=BT[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d",&tq);

    int time=0, completed=0, totalWT=0, totalTAT=0;

    while(completed<n){
        int flag=0;

        for(int i=0;i<n;i++){
            if(RT[i]>0 && AT[i]<=time){
                flag=1;

                if(RT[i]>tq){
                    time+=tq;
                    RT[i]-=tq;
                } else {
                    time+=RT[i];
                    CT[i]=time;
                    TAT[i]=CT[i]-AT[i];
                    WT[i]=TAT[i]-BT[i];

                    totalWT+=WT[i];
                    totalTAT+=TAT[i];

                    RT[i]=0;
                    completed++;
                }
            }
        }

        if(flag==0)
            time++;
    }

    printf("\nProcess AT BT WT TAT\n");
    for(int i=0;i<n;i++)
        printf("%d      %d  %d  %d  %d\n",i+1,AT[i],BT[i],WT[i],TAT[i]);

    printf("\nAverage WT = %.2f",(float)totalWT/n);
    printf("\nAverage TAT = %.2f",(float)totalTAT/n);

    return 0;
}

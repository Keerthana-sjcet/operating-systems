#include<stdio.h>
int main(){
    int np, nr;
    printf("Enter Number of Processes: ");
    scanf("%d",&np);
    printf("Enter Number of Resources: ");
    scanf("%d",&nr);
    int alloc[10][10], max[10][10], need[10][10];
    int avail[10];
    printf("Enter Allocation Matrix:\n");
    for(int i=0;i<np;i++){
        for(int j=0;j<nr;j++){
            scanf("%d",&alloc[i][j]);
        }
    }
    printf("Enter Maximum Matrix:\n");
    for(int i=0;i<np;i++){
        for(int j=0;j<nr;j++){
            scanf("%d",&max[i][j]);
        }
    }
    printf("Enter Available Resources:\n");
    for(int j=0;j<nr;j++){
        scanf("%d",&avail[j]);
    }
    for(int i=0;i<np;i++){
        for(int j=0;j<nr;j++){
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    printf("\nNeed Matrix:\n");
    for(int i=0;i<np;i++){
        for(int j=0;j<nr;j++){
            printf("%d ",need[i][j]);
        }
        printf("\n");
    }
    int finish[10] = {0};
    int safe[10];
    int count = 0;
    while(count < np){                 // while no of processes completed <no of processes 
        int found = 0;                //  becomes  1 is appropiriaet process is found
        for(int i=0;i<np;i++){
            if(finish[i]==0){
                int ok = 1;            //ok to be executed
                for(int j=0;j<nr;j++){   //
                    if(need[i][j] > avail[j]){
                        ok = 0;
                        break;
                    }
                }
                if(ok==1){
                    for(int j=0;j<nr;j++){
                        avail[j] += alloc[i][j];         //
                    }
                    safe[count] = i;
                    count++;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if(found==0){
            printf("\nSystem is NOT Safe\n");
            return 0;
        }
    }
    printf("\nSystem is Safe\nSequence: ");
    for(int i=0;i<np;i++){
        printf("P%d ",safe[i]);
    }
    return 0;
}

#include<stdio.h>

int main(){

    int size;
    int front = 0, rear = 0, count = 0;
    int buffer[100], item;
    int choice;

    printf("Enter Buffer Size: ");
    scanf("%d",&size);

    while(1){

        printf("\n1. Producer\n2. Consumer\n3. Exit\n");
        printf("Enter Choice: ");
        scanf("%d",&choice);

        switch(choice){

            // 🔹 PRODUCER
            case 1:
                if(count == size){
                    printf("Buffer is Full\n");
                }
                else{
                    printf("Enter Item: ");
                    scanf("%d",&item);

                    buffer[rear] = item;
                    rear = (rear + 1) % size;
                    count++;

                    printf("Item %d inserted\n",item);

                    // Display
                    if(count == 0){
                        printf("Queue: Empty\n");
                    }
                    else{
                        printf("Queue: ");
                        int i = front;
                        for(int j=0; j<count; j++){
                            printf("%d ", buffer[i]);
                            i = (i + 1) % size;
                        }
                        printf("\n");
                    }
                }
                break;

            // 🔹 CONSUMER
            case 2:
                if(count == 0){
                    printf("Buffer is Empty\n");
                }
                else{
                    item = buffer[front];
                    front = (front + 1) % size;
                    count--;

                    printf("Item %d consumed\n",item);

                    // Display
                    if(count == 0){
                        printf("Queue: Empty\n");
                    }
                    else{
                        printf("Queue: ");
                        int i = front;
                        for(int j=0; j<count; j++){
                            printf("%d ", buffer[i]);
                            i = (i + 1) % size;
                        }
                        printf("\n");
                    }
                }
                break;

            // 🔹 EXIT
            case 3:
                return 0;

            // 🔹 INVALID
            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}

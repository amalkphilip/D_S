#include<stdio.h>
#define max 6
int queue[max];
int front=-1,rear=-1;

void enqueue(int item) {
    if((rear+1)%max==front) {
        printf("Overflow...");
    }
    else if(front==-1 && rear ==-1){
        front=rear=0;
        queue[rear]=item;
    }
    else {
        rear=(rear+1)%max;
        queue[rear] = item;
        printf("Item is added.\n\n");
    }
}

void dequeue(){
    if (front==-1&& rear==-1){
        printf("Underflow...");
    }
    else if(front==rear){
        printf("Deleted element :",queue[front]);
        front=rear-1;
    }
    else{
        int element = queue[front];
        
        printf("Deleted element :%d",element);
        front=(front+1)%max;
    }
    printf("\n");
}

void display(){
    if (front==-1&&rear==-1){
        printf("The Queue is Empty.\n");
        
    }
    else{
        
        for(int i=front;i<=rear;i++){
            printf("%d\t",queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int i=1,value,item;
    while(i>0){
        printf("Enter the choice....\n");
        printf("1.enqueue.\n2.dequeue.\n3.display.\n");
        scanf("%d",&value);
        switch(value){
            case 1:{
                printf("Enter the value..");
                scanf("%d",&item);
                enqueue(item);
                break;
            }
            case 2:{
                dequeue();
                break;
            }
            case 3:{
                display();
                break;
            }
        }
        
    }
    return 0;
}

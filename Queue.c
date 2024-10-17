#include <stdio.h>
# define SIZE 10

int my_queue[SIZE];
int Rear = - 1;
int Front = - 1;
main()
{
    int choice;
    while (1)
    {
        printf("1.Enqueue \n");
        printf("2.Dequeue \n");
        printf("3.Display elements\n");
        printf("4.Exit\n");
        printf("Enter your choice of operations : ");
        scanf("%d", &choice);

        if (choice==1){
            enqueue();
        }
        else if (choice==2){

           dequeue();
        }
        else if (choice==3){
            display();
        }
        else if (choice>=4){
                break;
        }
        else{
              printf("Invalid choice \n");
        }
    }
}

void enqueue()
{
    int insert_item;
    if (Rear == SIZE - 1)
       printf("Overflow \n");
    else
    {
        if (Front == - 1)

        Front = 0;
        printf("Element to be inserted in the Queue\n : ");
        scanf("%d", &insert_item);
        Rear = Rear + 1;
        my_queue[Rear] = insert_item;
    }
}

void dequeue()
{
    if (Front == - 1 || Front > Rear)
    {
        printf("Nothing in the queue \n");
        return ;
    }
    else
    {
        printf("Element deleted from the queue is: %d\n", my_queue[Front]);
        Front = Front + 1;
    }
}
void display()
{
    if (Front == - 1)
        printf("The queue is empty \n");
    else
    {
        printf("Queue: \n");
        for (int i = Front; i <= Rear; i++)
            printf("%d ", my_queue[i]);
        printf("\n");
    }
}

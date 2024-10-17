#include <stdio.h>
#include <stdlib.h>


//creating a node
struct node{
int value;
struct node *next;

};

void displayList(struct node *p){
while (p!=NULL){
    printf("%d ", p->value);
    p=p->next;
}

}
int main(){
//initialise our nodes
struct node *head;
struct node *one=NULL;
struct node *two=NULL;
struct node *three=NULL;
struct node *four=NULL;

//allocating memmory using malloc
one=malloc(sizeof(struct node));
two=malloc(sizeof(struct node));
three=malloc(sizeof(struct node));
four=malloc(sizeof(struct node));

//assign values to our nodes
one->value=29;
two->value=56;
three -> value=83;
four->value =97;

one->next=two;
two->next=three;
three->next=four;
four->next = NULL;
head= one;
displayList(head);

return 0;
}

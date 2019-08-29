#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define QSIZE 10
void enqueue(int q[],int*r,int item);
void dequeue(int q[],int *f,int*r);
void display(int q[],int*f,int *r);
void main()
{
int ch;
int f=0;
int r=-1;
int item;
int q[QSIZE];
clrscr();
while(ch!=4)
{
printf("\n Queue Menu");
printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
printf("Enter Choice");
scanf("%d",&ch)      ;
switch(ch)
{
case 1:enqueue(q,&r,item);
		 break;
case 2:dequeue(q,&f,&r);
		 break;
case 3:display(q,&f,&r);
		 break;
case 4:printf("Exiting Queue Program");
		 break;
}
}
getch();
}


void enqueue(int q[],int *r,int item)
{
if(*r==QSIZE-1)
printf("Queue is fyll");
else
printf("Enter item");
scanf("%d",&item);
(*r)++;
q[*r]=item;
}
void dequeue(int q[],int *f,int *r)
{
if(*f>*r)
printf("queue is empty");
else
printf("element deleted=%d\n",q[*f]);
(*f)++;
}
void display(int q[],int *f,int *r)
{
int i;
if(*f>*r)
printf("Nothing to display\n");
else
for(i=*f;i<=*r;i++)
printf("%d",q[i]);
}

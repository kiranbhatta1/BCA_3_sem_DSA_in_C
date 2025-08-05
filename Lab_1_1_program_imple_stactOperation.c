#include<stdio.h>
int stack [100],j,choice=0,n,top=-1;
void push();
void pop();
void display();
void main();
{
print("enter the number of element in the stack");
Scanf("%d",&n);
printf("Stack operation using array\n");
printf("\n....\n):
  while(choice!=4)
  {
  printf("Chose one from the below\n");
  printf("\n1 for push \n 2 for pop \n 3 for display\n 4 for exist");
printf("\nEnter the choice");
Switch(choice){
case 1:
push();
break;
case 4 :
pop();
break;
case 3:
  display();
break;
case 4:
printf("Exiting..");
 break;
default :
printf("Please enter vaild choice");
}
}
}
void push(){
int val
if(top==n)
  printf("enter the value");
 scanf("%d" ,&val);
top +=top;
stack[top]=val;
}
}
void pop()
{
if(top==-1)
  printf("Underflow..");
else
  top=top-1;
}
void display()
{
  for(i=top ;i>=0;i--)
{
printf("%d",stack[i]);
}
if(top==-1)
{
printf("stack is empty");
}
}

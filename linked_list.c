//Provided an input string, store each character in a singly linked list node and print in reverse.
//If the string is multi word, words needs to reversed not the whole string.
//Storing is forward Linked list data are not affected but printing the elements in reverse direction.
//By Mruthyunjeyan S for Linumiz assessment submittted on 03/06/22
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct newNode
{
 char data;
 struct newNode* next;
}; // structure for new node in linked list

void revPrint(struct newNode* start)
{
 if (start == NULL)
  return;
 revPrint(start->next);
 printf("%c" , start->data);
} // function for printing in reverse


void createList(char* str)
{
struct newNode *start; //start node
struct newNode *temp;  //node used for traversing
struct newNode *currNode; //node for every char
start =  malloc(sizeof(struct newNode));
start->data = str[0];
start->next = NULL;
temp = start;

for(int i = 1; i < strlen(str) ; i++)
{
 currNode = malloc(sizeof(struct newNode));  //called to give new mem addr for each char
 currNode->data= str[i];
 currNode->next = NULL;
 temp->next = currNode;
 temp = temp->next;
} // push data , Move temp 

revPrint(start);

/* code for printing the elements as it is
temp = start;
while(temp->next != NULL)
{
 printf("%c" , temp->data);
 printf(" ");
 temp = temp->next;
}
printf("%c\n",temp->data);
*/
}


int main(int argc , char* argv[])
{
 printf("Linked List in Reverse: "); 
 for (int i =  1 ; i < argc ; i++)
  {
    createList(argv[i]);
    printf(" ");
  }
}//passing the string from arguments and passing to createList

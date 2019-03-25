#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{

  int choice;
  struct node* headPtr = NULL;


  printf("1) Add a patient.\n");
  scanf("%d",&choice);

  while (choice!=-1) {
    if(choice==1)
    {
      printf("Adding Patient....\n");
      AddElementAtStart(&headPtr);
    }
  }

  return 0;
}

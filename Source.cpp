#include "header.h"

void AddElementAtStart(struct node** top);

int main()
{

  int choice;
  int pos;
  struct node* headPtr = NULL;
  struct node* tailPtr = NULL;

  displayMenu();
  printf("Enter option : ");
  scanf("%d",&choice );

  while (choice!=-1) {
    if(choice==1)
    {
      system("clear");
      printf("Adding Patient....\n");
      printf("------------------\n");
      AddElementAtStart(&headPtr);
    }

    else if(choice==2)
    {
      if(headPtr==NULL)
      {
        system("clear");
        printf("There are no registered patients.\n");
      }
      else
      {
        DisplayList(headPtr);
      }
    }

    else if(choice == 3)
    {
      //PATIENTS DETAILS
      //SEARCH PATIENT
      displayPatientDetails();
    }

    else if(choice == 4)
    {
      //DELETE A PATIENT
      printf("Please enter a postion to delete at :");
      scanf("%d",&pos );

      //Call delete at pos function
      DeleteElementAtPos(headPtr, pos);

    }
    displayMenu();
    printf("Enter option : ");
    scanf("%d",&choice );
  }

  return 0;
}

//
//
//
// ADDING AND DELETING PATIENTS

void AddElementAtStart(struct node** top)
{
  struct node* newNode;

  newNode = (struct node*)malloc(sizeof(struct node));

  printf("Please enter Patient first name\n");
  scanf("%s", newNode->fname);

  printf("Please enter Patient surname\n");
  scanf("%s", newNode->lname);

  printf("Please enter Patient DOB (DD/MM/YY)\n");
  scanf("%d", &newNode->DOB);

  printf("Please enter Patient email\n");
  scanf("%s", newNode->email);

  printf("Please enter Patient mobile\n");
  scanf("%s", newNode->mobileNum);

  printf("Please enter Patient next of kin\n");
  scanf("%s", newNode->nextOfkin);

  printf("Please enter Patient weight\n");
  scanf("%f", &newNode->weight);

  printf("Please enter Patient height\n");
  scanf("%f", &newNode->height);

  newNode->NEXT = *top;
  *top = newNode;
}

void DeleteElementAtPos(struct node* top, int position)
{
	int i;
	struct node* temp;
	struct node* prev_temp;
	struct node* newNode;

	temp = top;

  system("clear");
  printf("Deleting Patient details...\n");
  printf("---------------------------\n");
	for (i = 0;i < position - 1;i++)
	{
		prev_temp = temp;
		temp = temp->NEXT;
	}


	prev_temp->NEXT = temp->NEXT;
	free(temp);

}

//
//
//
// MENU'S

void displayMenu()
{
  printf("==============================\n");
  printf("Welcome to ABC Dental Practice\n");
  printf("==============================\n\n");

  printf("1) Add a new Patient.\n");
  printf("2) Display Patients.\n");

}

//
//
//
// DISPLAY LIST OF PATIENTS

void DisplayList(struct node* top)
{
	struct node* temp = top;

  system("clear");

	while (temp != NULL)
	{
		printf("Patients name : %s %s\n", temp->fname, temp->lname);
		temp = temp->NEXT;
	}
}


void displayPatientDetails(struct node* top)
{
  struct node* temp = top;

  //SEARCH PPS NUMBER FOR USER DETAILS TO Display
  // if/else
  system("clear");
  printf("Displaying patient %s %s Details.\n", temp->fname, temp->lname);
  printf("DEBUG\n");
}

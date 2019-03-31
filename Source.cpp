#include "Header.h"

int main()
{
	struct node* headPtr = NULL;
  struct node* tailPtr = NULL;

	int choice;
	int position;

  printf("1) Please enter 1 to add a Patient\n2) Patient at end\n3) Display the list\n");
  printf("4) Please enter 4 to delete a Patient from start\n5) Please enter 5 to delete a Patient from the end\n");
  printf("6) Please enter 6 to add Patient at a position\n7) Please enter 7 to delete Patient at a position\n - 1 to exit\n");
  scanf("%d", &choice);

	while (choice != -1)
	{
		if (choice == 1)
		{
			printf("Adding Patient at the start . . .\n");

			AddElementAtStart(&headPtr);
		}
		else if (choice == 2)
		{
			printf("Adding element at the end\n");
			if (headPtr == NULL)
				AddElementAtStart(&headPtr);
			else
			{
				AddElementAtEnd(headPtr);
			}
		}
		else if (choice == 3)
		{
			printf("Display the list\n");
			DisplayList(headPtr);
		}

		else if (choice == 4)
		{
			DeleteElementAtStart(&headPtr);
		}

		else if (choice == 5)
		{
			if (Listlength(headPtr) == 1)
				DeleteElementAtStart(&headPtr);
			else
			{
				DeleteElementAtEnd(headPtr);
			}
		}

		else if (choice == 6)
		{
			printf("Please enter the position\n");
			scanf("%d", &position);

			if (position < 1 || position>Listlength(headPtr))
				printf("You need to enter a number between 1 and %d\n", Listlength(headPtr));
			else if (position == 1)
				AddElementAtStart(&headPtr);
			else
				AddElementAtPos(headPtr, position);

		}

		else if (choice == 7)
		{
			printf("Please enter the position\n");
			scanf("%d", &position);

			if (position < 1 || position>Listlength(headPtr))
				printf("You need to enter a number between 1 and %d\n", Listlength(headPtr));
			else if (position == 1)
				DeleteElementAtStart(&headPtr);
			else
				DeleteElementAtPos(headPtr, position);

		}

    	printf("1) Please enter 1 to add a Patient\n2) Patient at end\n3) Display the list\n");
    	printf("4) Please enter 4 to delete a Patient from start\n5) Please enter 5 to delete a Patient from the end\n");
    	printf("6) Please enter 6 to add Patient at a position\n7) Please enter 7 to delete Patient at a position\n - 1 to exit\n");
    	scanf("%d", &choice);
	}

	return 0;
}


void AddElementAtStart(struct node** top)
{
	struct node* newNode;
	char PPS[20];

	printf("Please enter the PPS number of the new Patient\n");
	scanf("%s", PPS);

	if (searchList(*top, PPS) == 1)
	{
		printf("Sorry the PPS number already exists in the datatbase.\n");
		return;
	}

	newNode = (struct node*)malloc(sizeof(struct node));


  	printf("Please enter Patient name\n");
  	scanf("%s", newNode->name);

  	strcpy(newNode->ID, PPS);

  	printf("Please enter Patient age\n");
  	scanf("%d", &newNode->age);

  	printf("Please enter Patient grade\n");
  	scanf("%f", &newNode->average);

  	printf("Please enter Patient email\n");
  	scanf("%s", newNode->email);

  	printf("Please enter Patient mobile\n");
  	scanf("%s", newNode->mobile);

    printf("Please enter Patient weight\n");
  	scanf("%f", &newNode->weight);

    printf("Please enter Patient height\n");
  	scanf("%f", &newNode->height);

    printf("Do you smoke? (Y/N) :\n");
    scanf("%s", &newNode->smoke);

	newNode->NEXT = *top;
	*top = newNode;
}


void DisplayList(struct node* top)
{
	struct node* temp = top;
	while (temp != NULL)
	{
		printf("Student %s ID: %s Age: %d Average %f Email %s Mobile %s Weight %f Height %f\n Smoking status : %s\n", temp->name, temp->ID, temp->age, temp->average,
     temp->email, temp->mobile, temp->weight, temp->height, temp->smoke);
		temp = temp->NEXT;
	}
}

void AddElementAtEnd(struct node* top)
{
	struct node* temp = top;
	struct node* newNode;
	char ID[10];

	printf("Please enter the ID of the new student\n");
	scanf("%s", ID);

	if (searchList(top, ID) == 1)
	{
		printf("Sorry the ID already exists\n");
		return;
	}

	while (temp->NEXT != NULL)
	{
		temp = temp->NEXT;
	}

	newNode = (struct node*)malloc(sizeof(struct node));

	printf("Please enter student name\n");
	scanf("%s", newNode->name);

	strcpy(newNode->ID, ID);

	printf("Please enter student age\n");
	scanf("%d", &newNode->age);

	printf("Please enter average grade\n");
	scanf("%f", &newNode->average);

	printf("Please enter student email\n");
	scanf("%s", newNode->email);

	printf("Please enter student mobile\n");
	scanf("%s", newNode->mobile);

	newNode->NEXT = NULL;
	temp->NEXT = newNode;
}

void DeleteElementAtStart(struct node** top)
{
	struct node* temp;

	temp = *top;

	*top = temp->NEXT;

	free(temp);
}
void DeleteElementAtEnd(struct node* top)
{
	struct node* temp;
	struct node* prev_temp;

	temp = top;

	while (temp->NEXT != NULL)
	{
		prev_temp = temp;
		temp = temp->NEXT;
	}

	prev_temp->NEXT = NULL;
	free(temp);
}

int Listlength(struct node* top)
{
	struct node* temp;
	int count = 0;
	temp = top;

	while (temp != NULL)
	{
		count++;
		temp = temp->NEXT;
	}

	return count;
}

void AddElementAtPos(struct node* top, int position)
{
	int i;
	struct node* temp;
	struct node* prev_temp;
	struct node* newNode;
	char ID[10];

	printf("Please enter the ID of the new student\n");
	scanf("%s", ID);

	if (searchList(top, ID) == 1)
	{
		printf("Sorry the ID already exists\n");
		return;
	}

	temp = top;

	for (i = 0;i < position - 1;i++)
	{
		prev_temp = temp;
		temp = temp->NEXT;
	}

	newNode = (struct node*)malloc(sizeof(struct node));

	printf("Please enter Patient name\n");
	scanf("%s", newNode->name);

	strcpy(newNode->ID, ID);

	printf("Please enter Patient age\n");
	scanf("%d", &newNode->age);

	printf("Please enter Patient grade\n");
	scanf("%f", &newNode->average);

	printf("Please enter Patient email\n");
	scanf("%s", newNode->email);

	printf("Please enter Patient mobile\n");
	scanf("%s", newNode->mobile);

  printf("Please enter Patient weight\n");
	scanf("%f", &newNode->mobile);

  printf("Please enter Patient height\n");
	scanf("%f", &newNode->mobile);


	newNode->NEXT = temp;
	prev_temp->NEXT = newNode;
}


void DeleteElementAtPos(struct node* top, int position)
{
	int i;
	struct node* temp;
	struct node* prev_temp;
//	struct node* newNode;

	temp = top;

	for (i = 0;i < position - 1;i++)
	{
		prev_temp = temp;
		temp = temp->NEXT;
	}


	prev_temp->NEXT = temp->NEXT;
	free(temp);

}

int searchList(struct node* top, char searchID[10])
{
	int found = 0;
	struct node* temp = top;

	while (temp != NULL)
	{
		if (strcmp(temp->ID,searchID)==0)
		{
			found = 1;
			return found;
		}

		temp = temp->NEXT;
	}

	return found;
}

#include "Header.h"


int main()
{
	struct node* headPtr = NULL;
	struct node* tailPtr = NULL;

	int choice;
	int position;
	char password[20];
	char username[20];
	char ch;
	int i=0;

	printf("WELCOME TO ABC DENTAL PRACTICE LTD.\n");
	printf("-----------------------------------\n\n");

	//LOGIN PHASE
	//
	//
	//
	printf("Enter your username : ");
	scanf("%s", username);
	printf("Enter your password : ");

	//SETTING PASSWORD INPUTS AS ASTERISK (********)
	while (1)
	{
		ch = getch();
		if (ch == 13)
		{
			password[i] = '\0';
			break;
		}

		password[i] = ch;
		i++;
		printf("*");
	}

	//printf("\nDEBUG : %s\n\n", password);

	//LOGIN GREETING
	printf("\n\nWelcome %s", username);
	printf("\n-----------------\n\n");


	//MENU
	printf("1) Add a Patient.\n2) Display all Patients details.\n3) Display a Patients details.\n");
	printf("4) Update Patients details.\n5) Delete a Patient from the datatbase.\n");
	printf("6) Generate Statistics.\n7) Print Patient details to report file.\nX) -1 to exit\n");
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
	int emailConfirm=0;
	char emailInput[30];

	//clear screen
	system("@cls||clear");

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

	printf("Please enter Patient surname\n");
	scanf("%s", newNode->surname);

	strcpy(newNode->ID, PPS);

	printf("Please enter Patient age\n");
	scanf("%d", &newNode->age);

	printf("Please enter Patient grade\n");
	scanf("%f", &newNode->average);

	printf("Please enter Patient email\n");
	scanf("%s", newNode->email);
	/*VALIDATION OF EMAIL ADDRESS
		Sending the input email from the struct node*
		to the function validEmail which will return 1 if the
		email address contains a '@'
	*/
	emailConfirm = validEmail(newNode->email);

	while (emailConfirm != 5)
	{
		printf("Invalid email address has been entered. Must contain a VALID email address.\n");
		printf("Please enter Patient email\n");
		scanf("%s", emailInput);
		emailConfirm = validEmail(emailInput);
	}


	printf("Please enter Patient mobile\n");
	scanf("%s", newNode->mobile);

	printf("Please enter Patient weight\n");
	scanf("%f", &newNode->weight);

	printf("Please enter Patient height\n");
	scanf("%f", &newNode->height);

	printf("Do you smoke? (Y/N) :\n");
	scanf("%s", &newNode->smoke);
	//IF FOR SMOKING ANS == Y
	if (newNode->smoke == 'y' || newNode->smoke == 'Y')
	{
		int smokeChoice = 0;

		printf("1) Do you smoke :\nLess than 10 a day?\n2)More than 10 a day?\n ");
		scanf("%d", &smokeChoice);
	}

	printf("Do you Exercise? (Y/N) :\n");
	scanf("%s", &newNode->exercise);
	//IF FOR EXERCISE ANS == Y
	if (newNode->exercise== 'y' || newNode->exercise == 'Y')
	{
		int exerciseChoice = 0;

		printf("1) Do you exercise :\nLess than twice a week?\n2)More than twice a week?\n ");
		scanf("%d", &exerciseChoice);
	}

	newNode->NEXT = *top;
	*top = newNode;

	printf("\n\nPatient has been added to the database.");
	printf("\n---------------------------------------\n\n");
}


void DisplayList(struct node* top)
{
	struct node* temp = top;

	//clear screen
	system("@cls||clear");

	while (temp != NULL)
	{
		printf("Patient %s %s\n---------------------\n PPS: %s\n Age: %d\n Average %f\n Email %s\n Mobile %s\n Weight %f\n Height %f\n", temp->name, temp->surname, temp->ID, temp->age, temp->average, temp->email, temp->mobile, temp->weight, temp->height);
		printf(" Smoking status : %s\n ", &temp->smoke);
		printf("Exercise status : %s \n\n", &temp->exercise);

		temp = temp->NEXT;
	}

	printf("----------------------------------------------------------\n\n");
}

void AddElementAtEnd(struct node* top)
{
	struct node* temp = top;
	struct node* newNode;
	char PPS[10];

	printf("Please enter the ID of the new student\n");
	scanf("%s", PPS);


	if (searchList(top, PPS) == 1)
	{
		printf("Sorry the ID already exists\n");
		return;
	}

	while (temp->NEXT != NULL)
	{
		temp = temp->NEXT;
	}

	newNode = (struct node*)malloc(sizeof(struct node));

	printf("Please enter Patient name\n");
	scanf("%s", newNode->name);

	printf("Please enter Patient surname\n");
	scanf("%s", newNode->surname);

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

	printf("Do you Exercise? (Y/N) :\n");
	scanf("%s", &newNode->exercise);


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
	char PPS[10];

	printf("Please enter the ID of the new student\n");
	scanf("%s", PPS);

	if (searchList(top, PPS) == 1)
	{
		printf("Sorry the ID already exists\n");
		return;
	}

	temp = top;

	for (i = 0; i < position - 1; i++)
	{
		prev_temp = temp;
		temp = temp->NEXT;
	}

	newNode = (struct node*)malloc(sizeof(struct node));

	printf("Please enter Patient name\n");
	scanf("%s", newNode->name);

	printf("Please enter Patient surname\n");
	scanf("%s", newNode->surname);

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

	printf("Do you Exercise? (Y/N) :\n");
	scanf("%s", &newNode->exercise);


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

	for (i = 0; i < position - 1; i++)
	{
		prev_temp = temp;
		temp = temp->NEXT;
	}


	prev_temp->NEXT = temp->NEXT;
	free(temp);

}


//VALIDATIONS
//
//
//

int searchList(struct node* top, char searchID[10])
{
	int found = 0;
	struct node* temp = top;

	while (temp != NULL)
	{
		if (strcmp(temp->ID, searchID) == 0)
		{
			found = 1;
			return found;
		}

		temp = temp->NEXT;
	}

	return found;
}

int validEmail(char email[40])
{
	int confirmation=0;
	int length = strlen(email);

	for (int i = 0; i < length; i++)
	{
		//searching for @ at pos [i]
		if (email[i] == '@')
		{
			confirmation++;
			break;
		}

		//searching for '.com' at pos [length-1,2,3,4]
		if (email[length - 4] == '.')
		{
			confirmation++;
		}

		if (email[length - 3] == 'c')
		{
			confirmation++;
		}

		if (email[length - 2] == 'o')
		{
			confirmation++;
		}

		if (email[length - 1] == 'm')
		{
			confirmation++;
		}

		return confirmation;
	}
}

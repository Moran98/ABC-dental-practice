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
	int i = 0;

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
		printf("6) Please enter 6 to Generate Statistics\n7) Please enter 7 to delete Patient at a position\n - 1 to exit\n");
		scanf("%d", &choice);
	}

	return 0;
}


void AddElementAtStart(struct node** top)
{
	struct node* newNode;
	char PPS[20];
	int emailConfirm = 0;
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

	printf("Please enter Patient Year Born\n");
	scanf("%d", &newNode->yearOfBirth);

	printf("Please enter Patient gender\n");
	scanf("%s", &newNode->gender);

	switch (newNode->gender)
	{

	case 'm':
	case 'M':
			newNode->gender = 'Male';
			printf("Male.");
			break;

	case 'f':
	case 'F':
			printf("Female.");
			break;

	default:
		printf("Gender not specified.\n");
		break;
	}

	printf("Please enter Patient email\n");
	scanf("%s", newNode->email);
	/*VALIDATION OF EMAIL ADDRESS
		Sending the input email from the struct node*
		to the function validEmail which will return 1 if the
		email address contains a '@' and 5 if the email contains
		an '@' and '.com'
	*/
	emailConfirm = validEmail(newNode->email);

	while (emailConfirm != 5)
	{
		printf("Invalid email address has been entered. Must contain a VALID email address.\n");
		printf("Please enter Patient email\n");
		scanf("%s", emailInput);
		emailConfirm = validEmail(emailInput);
	}


	printf("Please enter Patient Next of Kin Name\n");
	scanf("%s", newNode->nextOfkin);

	printf("Please enter Patient Last Appointment(Month)\n");
	scanf("%s", newNode->lastApp);


	printf("Please enter Patient weight(LBS)\n");
	scanf("%f", &newNode->weight);

	printf("Please enter Patient height(CM)\n");
	scanf("%f", &newNode->height);

	//SENDING VARIABLES HEIGHT + WEIGHT TO BMI FUNCTION
	BMI(newNode , newNode->weight, newNode->height);


	printf("Does the Patient have any allergies (Y/N)\n");
	scanf("%s", allergyStat);
/*
	while ((allergyStat == 'y') || (allergyStat == 'Y') || (allergyStat == 'n') || (allergyStat == 'N'))
	{
		printf("Invalid entry \n");
		printf("Does the Patient have any allergies (Y/N)\n");
		scanf("%s", allergyStat);
	}*/

	if ((allergyStat == 'y' )|| (allergyStat == 'Y')) {
		//COUNT WITH ALLERGIES
		printf("Yes");
	}

	else if (allergyStat == 'n' || allergyStat == 'N') {
		//COUNT ALL WITHOUT ALLERGY
		printf("No");
	}
	else
	{
		printf("Invalid entry.");
	}


	printf("Do you smoke? (Y/N) :\n");
	scanf("%s", &newNode->smoke);
	//IF FOR SMOKING ANS == Y
	if (newNode->smoke == 'y' || newNode->smoke == 'Y')
	{
		int smokeChoice = 0;

		printf("1) Do you smoke :\n1)Less than 10 a day.\n2)More than 10 a day.\n ");
		scanf("%d", &smokeChoice);
	}

	printf("Do you drink Alcohol? (Y/N) :\n");
	scanf("%s", &newNode->alcohol);
	//IF FOR ALCOHOL ANS == Y
	if (newNode->alcohol == 'y' || newNode->alcohol == 'Y')
	{
		int alcoholChoice = 0;

		printf("1) Do you Drink :\n1)None\n2)More than 10 units.\n3)Less than 10 units.\n ");
		scanf("%d", &alcoholChoice);
	}

	printf("Do you Exercise? (Y/N) :\n");
	scanf("%s", &newNode->exercise);
	//IF FOR EXERCISE ANS == Y
	if (newNode->exercise == 'y' || newNode->exercise == 'Y')
	{
		int exerciseChoice = 0;

		printf("1) Do you exercise :\n1)Less than twice a week?\n2)More than twice a week?\n ");
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
		printf("Patient %s %s\n---------------------\n", temp->name, temp->surname);
		printf("Year of Birth : %d\n", temp->yearOfBirth);
		printf("Email : %s\n", temp->email);
		//printf("Gender : %s\n", temp->gender);
		printf("Next of Kin : %s\n", temp->nextOfkin);
		printf("Last Appointment : %s\n", temp->lastApp);
		printf("Weight : %f`\n", temp->weight);
		printf("Height : %f\n", temp->height);
		printf("Smoking status : %s\n ", temp->smoke);
		printf("Exercise status : %s\n", temp->exercise);
		//printf("Drinking status : %s\n\n", temp->alcohol);


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

	printf("Please enter Patient Year Born\n");
	scanf("%d", &newNode->yearOfBirth);

	printf("Please enter Patient gender\n");
	scanf("%s", &newNode->gender);

	printf("Please enter Patient email\n");
	scanf("%s", newNode->email);

	printf("Please enter Patient Next of Kin Name\n");
	scanf("%s", newNode->nextOfkin);

	printf("Please enter Patient Last Appointment(Month)\n");
	scanf("%s", newNode->lastApp);

	printf("Please enter Patient weight\n");
	scanf("%f", &newNode->weight);

	printf("Please enter Patient height\n");
	scanf("%f", &newNode->height);

	printf("Do you smoke? (Y/N) :\n");
	scanf("%s", &newNode->smoke);

	printf("Do you drink Alcohol? (Y/N) :\n");
	scanf("%s", &newNode->alcohol);

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

	printf("Please enter Patient Year Born\n");
	scanf("%d", &newNode->yearOfBirth);

	printf("Please enter Patient gender\n");
	scanf("%s", &newNode->gender);

	printf("Please enter Patient email\n");
	scanf("%s", newNode->email);


	printf("Please enter Patient Next of Kin Name\n");
	scanf("%s", newNode->nextOfkin);

	printf("Please enter Patient Last Appointment(Month)\n");
	scanf("%s", newNode->lastApp);

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
	int confirmation = 0;
	int length = strlen(email);

	for (int i = 0; i < length; i++)
	{
		//searching for @ at pos [i]
		if (email[i] == '@')
		{
			confirmation++;
			break;
		}
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

//BMI CALCULATIONS
/*
	BMI = Weight/height*height
*/
float BMI(struct node* top,float w, float h)
{
	int i;
	float bmi=0;
	int c1, c2, c3, c4;
	struct node* temp = top;

	temp->BMI = (w*703) / (h * h);

	printf("DEBUG - BMI is %f", temp->BMI);

	if (bmi <= 18.5){
		//bmi18(temp->BMI);
	}
	else if (bmi <= 25) {
		c2++;
	}
	else if (bmi <= 30) {
		c3++;
	}
	else if (bmi >= 30) {
		c4++;
	}

	return temp->BMI;
}


//GENERATING STATISTICS
/*
	By using the totals from BMI's
	this function will produce the statistics of
	% patients with specific BMI's

*/

void GenerateStatistics(struct node* top,float w, float h)
{

	struct node* temp = top;

	//clear screen
	system("@cls||clear");

	printf("1) % Patients with less than 18.5 BMI.\n");
	printf("2) % Patients with less than 25 BMI.\n");
	printf("3) % Patients with less than 30 BMI.\n");
	printf("4) % Patients with greater tahn 30 BMI.\n");
	printf("5) % Patients with less than 18.5 BMI.\n\n");

	printf("i) How many cigarettes you smoke a day.\n");
	printf("ii) How often do you exercise.\n");

	printf("\nPlease enter an option : ");
	scanf("%d", &statsChoice);

	switch (statsChoice)
	{

	case 1:
	default:
		break;
	}
}
// STATISTICS FUNCTIONS FOR BMI
/*
void bmi18(float bmi)
{
	printf("%f", bmi);
}
*/

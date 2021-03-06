#include "Header.h"


int main()
{
	struct node* headPtr = NULL;

	int choice=0;
	int pos=0;
	int pps=0;
	char fname[20];
	char sname[20];
	int dob=0;
	char gender[10];
	char email[20];
	char NoK[20];
	char app[20];
	char allergy[10];
	int exercise;
	int smoke;
	int alcohol;
	float weight=0;
	float height=0;
	float bmi=0;
	int ppsSearch = 0;

	printf("WELCOME TO ABC DENTAL PRACTICE LTD.\n");
	printf("-----------------------------------\n\n");

	// USER'S ACCESS
	//
	// USERNAME | PASSWORD
	//
	// admin admin
	// aaron moran
	// martin hynes

	login = fopen("login.txt", "r");
	report = fopen("report.txt", "r");


	printf("Enter your Username :");
	scanf("%s", uname);
	printf("Enter your password : ");

	//SETTING PASSWORD INPUTS AS ASTERISK (********)
	while (1)
	{
		ch = getch();
		if (ch == 13)
		{
			pword[i] = '\0';
			break;
		}

		pword[i] = ch;
		i++;
		printf("*");
	}


	while (!feof(login))
	{
		numInputs = fscanf(login, "%s %s", username, password);

		if (numInputs == 2) {
			if ((strcmp(username, uname) == 0) && (strcmp(password, pword) == 0)) {
				accept = true;
				printf("\n\nWelcome to the Patient database\n\n");

				time(&currTime);
				printf("---------------------------------\n");
				printf("Today is %s", ctime(&currTime));
				printf("---------------------------------\n\n");

				fclose(login);
				fclose(report);
				break;
			}

		}
	}


	//CONFIRMATION OF ACCESS
	if (accept == false)
	{
		printf("\n\nNot allowed access to the database.");
		exit(0);
	}

	if (accept == true) {

		while (!feof(report))
		{
			reportInputs = fscanf(report, "%d %s %s %d %s %s %s %s %s %d %d %d %f %f %f", &pps, fname, sname, &dob, gender, email, NoK, app, allergy, &exercise, &smoke, &alcohol, &height, &weight, &bmi);

			if (reportInputs == 15) {

				printf("Patient %d\n", pps);
				printf("Patient %s %s\n", fname, sname);
				printf("Patient Year of Birth %d\n", dob);
				printf("Patient Gender : %s\n", gender);
				printf("Patient Email %s\n", email);
				printf("Patient Next Of Kin : %s\n", NoK);
				printf("Patient last Appointment : %s\n", app);
				printf("Patient Allergies : %s\n", allergy);
				printf("Patient Exercise : %d\n", exercise);
				printf("Patient Smoke : %d\n", smoke);
				printf("Patient Alcohol : %d\n", alcohol);
				printf("Patient Height %f\n", height);
				printf("Patient Weight %f\n", weight);
				printf("Patient BMI %f\n", bmi);
			}
			break;
		}
	}


	fclose(login);
	fclose(report);


	printf("Enter a choice\n");
	printf("1)ADD A PATIENT\n2)DISPLAY ALL PATIENTS\n3)DISPLAY PATIENT\n4)UPDATE DETAILS\n5)DELETE A PATIENT\n6)GENERATE STATISTICS\n7)PRINT DETAILS TO REPORT FILE\n8)LIST PATIENTS IN ORDER OF LAST APPOINTMENT\n");
	scanf("%d", &choice);

	while (choice != -1)
	{
		//Added function validation before each MENU OPTION.

		if (choice < 1 || choice >8) {
			printf("\n-----------------------------------------------");
			printf("\nPlease enter a value within the Menu options.\n");
			printf("-----------------------------------------------\n");

		}

		else if (choice == 1)
		{
			printf("Adding Patient at the start . . .\n");

			AddElementAtStart(&headPtr);
		}

		else if (choice == 2)
		{
			//Bug when displaying the list displays the Patient but console freezes?
			if (headPtr == NULL) {
				printf("\n----------------------------------------------------------");
				printf("\nThe database is empty, Please add a patient before displaying.\n");
				printf("----------------------------------------------------------\n");
			}
			else
			{
				DisplayList(headPtr);
			}
		}

		else if (choice == 3)
		{
			//Bug when searching the list displays the Patient but console freezes?
			if (headPtr == NULL)
			{
				printf("\n--------------------------------------");
				printf("\nPlease add a Patient before searching.");
				printf("\n--------------------------------------\n");
			}
			else
			{
				searchList(headPtr);
			}
		}

		else if (choice == 4)
		{
			if (headPtr == NULL)
			{
				printf("\n----------------------------------------");
				printf("\n\nPlease add a Patient before updating.\n\n");
				printf("----------------------------------------\n");
			}
			else
			{
				UpdateDetails(headPtr);
			}
		}

		else if (choice == 5)
		{
			printf("Please enter the PPS\n");
			scanf("%d", &pos);
			if (headPtr == NULL)
			{
				printf("\n----------------------------------------------------------");
				printf("\n\nYou must add a patient before you can delete a patient.");
				printf("\n----------------------------------------------------------\n");

			}
			else if (pos < 1 || pos>Listlength(headPtr))
				printf("You need to enter a number between 1 and %d\n", Listlength(headPtr));
			else if (pos == 1)
				DeleteElementAtStart(&headPtr);
			else
				DeleteElementAtPos(headPtr, pos);
		}

		else if (choice == 6)
		{
			if (headPtr == NULL) {
				printf("\n----------------------------------------------------------------------");
				printf("\n\nPlease add a patient to the database before Generating statistics.\n");
				printf("------------------------------------------------------------------------\n");
			}
			else
			{
				GenerateStatistics(headPtr);
			}
		}

		else if (choice == 7) {

			if (headPtr == NULL) {
				printf("\n----------------------------------------------------------------------");
				printf("\nPlease add a patient to the database before saving to the report file.\n");
				printf("------------------------------------------------------------------------\n");

			}
			else
			{
				ReportFile(headPtr);
			}


		}

		else if (choice == 8) {
			//AppointmentList(headPtr, headPtr->year, headPtr->year);
		}

		printf("WELCOME TO ABC DENTAL PRACTICE LTD.\n");
		printf("-----------------------------------\n\n");


		printf("Enter a choice\n");
		printf("1)ADD A PATIENT\n2)DISPLAY ALL PATIENTS\n3)DISPLAY PATIENT\n4)UPDATE DETAILS\n5)DELETE A PATIENT\n6)GENERATE STATISTICS\n7)PRINT DETAILS TO REPORT FILE\n8)LIST PATIENTS IN ORDER OF LAST APPOINTMENT\n");
		scanf("%d", &choice);

	}


	return 0;

}

//ADD A PATIENT
//
//
//
void AddElementAtStart(struct node** top)
{
	struct node* newNode;
	int allergy = 0;
	int noAllergy = 0;
	int emailConfirm = 0;
	char emailInput[30];
	time_t appointment[20];

	report = fopen("report.txt", "r");


	//clear screen
	system("@cls||clear");

	newNode = (struct node*)malloc(sizeof(struct node));

	printf("Please enter PPS\n");
	scanf("%d", &newNode->PPS);
	if (UniqueID(*top, newNode->PPS) == 1)
	{
		printf("Sorry the PPS number already exists in the datatbase.\n");
		return;
	}

	printf("Please enter first name\n");
	scanf("%s", newNode->name);
	printf("Please enter second name\n");
	scanf("%s", newNode->surname);
	printf("Please enter Year Born\n");
	scanf("%d", &newNode->yearOfBirth);
	printf("Please enter Gender\n");
	scanf("%s", newNode->gender);
	printf("Please enter Email\n");
	scanf("%s", newNode->email);
	//
	//

	/*  VALIDATION OF EMAIL ADDRESS
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
	//
	//
	printf("Next of Kin\n");
	scanf("%s", newNode->nextOfkin);

	//printf("Please enter Last Appointment\n");
	//scanf("%s", newNode->lastApp);

	// %i specifies integer
	printf("Please enter Last Appointment (DD/MM/YY) - Number Format\n");
	scanf("%i %i %i", &newNode->day, &newNode->month, &newNode->year );
	printf("Date of last App was %i / %i / %i\n", newNode->day, newNode->month, newNode->year);

	//newNode->year = yearList[0]+i;

	//printf("DEBUG : Year list %d", yearList[i]);

	// MM/DD/YY

	/*
		This block of code was an attempt at getting the
		CurrTime() diff to The last appointment.
		//
		//
		diff = difftime(currTime, newNode->app);
		printf("Time difference %lf\n", diff);

		printf("Please enter Last Appointment\n");
		scanf("%lf", newNode->app);

		diff = difftime(currTime, newNode->app);
		printf("Time difference %lf\n", diff);
	*/

	printf("Does Patient have allergies? (Y/N)\n");
	scanf(" %c", &newNode->allergies);

	// ALLERGIES -  Y/N only works with " %c"
	if (newNode->allergies == 'y' || newNode->allergies == 'Y') {
		printf("Enter the medication they're allegic to\n");
		scanf("%s", newNode->allergy);
	}
	else if (newNode->allergies == 'n' || newNode->allergies == 'N') {
		newNode->allergy == NULL;
	}

	printf("How much do you smoke?\n");
	printf("1) None\n");
	printf("2) Less than 10 cigarettes\n");
	printf("3) More than 10 cigarettes\n");
	scanf("%d", &newNode->smoke);

	//3 invalid entry errors for statistics
	if (newNode->smoke < 1 || newNode->smoke >3) {
		printf("Invalid entry.\n\n");
	}

	printf("How much do you drink Alcohol?\n");
	printf("1) None\n");
	printf("2) Less than 10 units\n");
	printf("3) More than 10 units\n");
	scanf("%d", &newNode->alcohol);

	if (newNode->alcohol < 1 || newNode->alcohol >3) {
		printf("Invalid entry.\n\n");
	}

	printf("How much do you do exercise?\n");
	printf("1) None\n");
	printf("2) Less than 2 times a week\n");
	printf("3) More than 2 times a week\n");
	scanf("%d", &newNode->exercise);

	if (newNode->exercise < 1 || newNode->exercise >3) {
		printf("Invalid entry.\n\n");
	}

	//Calculating the BMI by passing it to a function
	printf("Please enter weight (KG)\n");
	scanf("%f", &newNode->weight);
	printf("Please enter height (Mtrs)\n");
	scanf("%f", &newNode->height);
	BMI(newNode, newNode->weight, newNode->height);

	fclose(report);
	newNode->NEXT = *top;
	*top = newNode;
}

//SEARCH
//
//
//
void searchList(struct node* top) {

	struct node* newNode = top;
	int found = 0;
	char nameSearch[30];
	char snameSearch[30];
	int ppsSearch = 0;
	int choice = 0;

	printf("Do you want to : \n");
	printf("1)Search by PPS\n");
	printf("2)Search by Name\n");
	scanf("%d", &choice);

	if (choice == 1)
	{
		printf("Enter the PPS to search\n");
		scanf("%d", &ppsSearch);
	}
	else if (choice == 2) {
		printf("Enter the Name to search\n");
		scanf("%s %", nameSearch, snameSearch);
	}

	while (newNode != NULL)
	{
		//Name BUG - Endless loop?
		if (newNode->PPS == ppsSearch || strcmp(newNode->name, nameSearch) == 0 && strcmp(newNode->surname, snameSearch) == 0) {

			printf("\nFound patient.\n");

			printf("Patient %d\n", newNode->PPS);
			printf("Patient %s %s\n", newNode->name, newNode->surname);
			printf("Patient Year of Birth %d\n", newNode->yearOfBirth);
			printf("Patient Gender : %s\n", newNode->gender);
			printf("Patient Email %s\n", newNode->email);
			printf("Patient Next Of Kin : %s\n", newNode->nextOfkin);
			printf("Patient last Appointment : %i / %i / %i\n", newNode->day, newNode->month, newNode->year);
			printf("Patient Allergies : %c\n", newNode->allergies);
			printf("Patient Exercise : %d\n", newNode->exercise);
			printf("Patient Smoke : %d\n", newNode->smoke);
			printf("Patient Alcohol : %d\n", newNode->alcohol);
			printf("Patient Height %f\n", newNode->height);
			printf("Patient Weight %f\n", newNode->weight);
			printf("Patient BMI %f\n", newNode->BMI);

			printf("\n\n--------------\n\n");
			break;
		}

		else
		{
			printf("\n\nPatient does not exist\n");
			break;
		}
	}

	newNode = newNode->NEXT;
}

//DISPLAY
//
//
//
void DisplayList(struct node* top)
{
	struct node* temp = top;

	//clear screen
	system("@cls||clear");


	while (temp != NULL)
	{
		printf("Patient PPS %d\n", temp->PPS);
		printf("Patient %s %s\n", temp->name, temp->surname);
		printf("Patient Year of Birth %d\n", temp->yearOfBirth);
		printf("Patient Gender : %s\n", temp->gender);
		printf("Patient Email %s\n", temp->email);
		printf("Patient Next of Kin : %s\n", temp->nextOfkin);
		printf("Patient last Appointment : %i / %i / %i\n", temp->day, temp->month, temp->year);
		printf("Patient Allergies : %c\n", temp->allergies);
		printf("Patient Smoke : %d\n", temp->smoke);
		printf("Patient Exercise : %d\n", temp->exercise);
		printf("Patient Alcohol : %d\n", temp->alcohol);
		printf("Patient Height %f\n", temp->height);
		printf("Patient Weight %f\n", temp->weight);
		printf("Patient BMI %f\n", temp->BMI);


		printf("\n\n----------------------------------\n\n");

		temp = temp->NEXT;
	}

}

//UPDATE
//
//
//
void UpdateDetails(struct node* top)
{
	struct node* newNode = top;
	int found = 0;
	int ppsSearch = 0;
	int choice = 0;
	char yesNo;

	//clear screen
	system("@cls||clear");



	printf("Enter the PPS to search\n");
	scanf("%d", &ppsSearch);

	while (newNode != NULL)
	{
		/*
			Comparing the node PPS to the ppsSearch to find the patient and update their details.
			Each user detail has an option of Y/N to update that specific detail
		*/
		if (newNode->PPS == ppsSearch) {
			printf("\nFound patient.\n\n");

			printf("Updating Details.\n");
			printf("----------------\n");

			printf("Do you want to update PPS?(Y/N)\n");
			scanf(" %c", &yesNo);
			if (yesNo == 'y' || yesNo == 'Y') {
				printf("New PPS\n");
				scanf("%d", &newNode->PPS);
			}

			printf("Do you want to update Name?(Y/N)\n");
			scanf(" %c", &yesNo);
			if (yesNo == 'y' || yesNo == 'Y') {
				printf("New Name\n");
				scanf("%s %s", newNode->name, newNode->surname);
			}

			printf("Do you want to update Year of Birth?(Y/N)\n");
			scanf(" %c", &yesNo);
			if (yesNo == 'y' || yesNo == 'Y') {
				printf("New Year of Birth\n");
				scanf("%d", newNode->yearOfBirth);
			}

			printf("Do you want to update Email?(Y/N)\n");
			scanf(" %c", &yesNo);
			if (yesNo == 'y' || yesNo == 'Y') {
				printf("New Email Address\n");
				scanf("%s", newNode->email);
			}

			printf("Do you want to update Next of Kin?(Y/N)\n");
			scanf(" %c", &yesNo);
			if (yesNo == 'y' || yesNo == 'Y') {
				printf("New Next of Kin\n");
				scanf("%s", newNode->nextOfkin);
			}

			printf("Do you want to update Last App?(Y/N)\n");
			scanf(" %c", &yesNo);
			if (yesNo == 'y' || yesNo == 'Y') {
				printf("Patient last Appointment?");
				scanf("%i / %i / %i\n", newNode->day, newNode->month, newNode->year);
			}

			printf("Do you want to update Medication Allergy?(Y/N)\n");
			scanf(" %c", &yesNo);
			if (yesNo == 'y' || yesNo == 'Y') {
				printf("New Medication Allergy\n");
				scanf("%s", newNode->allergy);
			}

			printf("Do you want to update Smoking Details?(Y/N)\n");
			scanf(" %c", &yesNo);
			if (yesNo == 'y' || yesNo == 'Y') {
				printf("How much do you smoke?\n");
				printf("1) None\n");
				printf("2) Less than 10 cigarettes\n");
				printf("3) More than 10 cigarettes\n");
				scanf("%d", &newNode->smoke);

				//3 invalid entry errors for statistics
				if (newNode->smoke < 1 || newNode->smoke >3) {
					printf("Invalid entry.\n\n");
				}
			}

			printf("Do you want to update Exercise Details?(Y/N)\n");
			scanf(" %c", &yesNo);
			if (yesNo == 'y' || yesNo == 'Y') {
				printf("How much do you do Exercise?\n");
				printf("1) None\n");
				printf("2) Less than 2 days a week\n");
				printf("3) More than 2 days a week\n");
				scanf("%d", &newNode->exercise);

				//3 invalid entry errors for statistics
				if (newNode->exercise < 1 || newNode->exercise >3) {
					printf("Invalid entry.\n\n");
				}
			}

			printf("Do you want to update Alcohol Details?(Y/N)\n");
			scanf(" %c", &yesNo);
			if (yesNo == 'y' || yesNo == 'Y') {
				printf("How much do you Drink Alcohol?\n");
				printf("1) None\n");
				printf("2) Less than 10 units a week\n");
				printf("3) More than 10 units a week\n");
				scanf("%d", &newNode->alcohol);

				//3 invalid entry errors for statistics
				if (newNode->alcohol < 1 || newNode->alcohol >3) {
					printf("Invalid entry.\n\n");
				}
			}

			printf("Do you want to update Height?(Y/N)\n");
			scanf(" %c", &yesNo);
			if (yesNo == 'y' || yesNo == 'Y') {
				printf("New Height\n");
				scanf("%d", newNode->height);
			}

			printf("Do you want to update Weight?(Y/N)\n");
			scanf(" %c", &yesNo);
			if (yesNo == 'y' || yesNo == 'Y') {
				printf("New Weight\n");
				scanf("%d", newNode->weight);
			}

		}
		break;
	}

	newNode = newNode->NEXT;
}

//DELETE A PATIENT
//
//
//
void DeleteElementAtPos(struct node* top, int pos)
{
	struct node* newNode = top;
	struct node* prev_temp;

	for (int i = 0; i < pos -1 ; i++)
	{
		prev_temp = newNode;
		newNode = newNode->NEXT;
	}

	prev_temp->NEXT = newNode->NEXT;
	free(newNode);

}

//
//

void DeleteElementAtStart(struct node** top)
{
	struct node* temp;

	temp = *top;

	*top = temp->NEXT;

	free(temp);
}

//LIST LENGTH
//
//
//
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

//GENERATE STATISTICS
//
//
//
void GenerateStatistics(struct node* top)
{

	struct node* temp = top;
	int patient = 0;
	int smokeChoice = 0;
	int exerciseChoice = 0;
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	int count4 = 0;
	int percent1 = 0;
	int percent2 = 0;
	int percent3 = 0;
	int percent4 = 0;
	int choice;

	//clear screen
	system("@cls||clear");

	report = fopen("report.txt", "a");

	//clear screen
	system("@cls||clear");

	printf("1) % Patients with less than 18.5 BMI.\n");
	printf("2) % Patients with less than 25 BMI.\n");
	printf("3) % Patients with less than 30 BMI.\n");
	printf("4) % Patients with greater than 30 BMI.\n");

	printf("i) How many cigarettes you smoke a day.\n");
	printf("ii) How often do you exercise.\n");


	printf("Enter an option\n");
	scanf("%d", &choice);

	/*
		For the generating statistics i allowed the user to select an option of 1) or 2)
		this will then generate the stats for either people who chose,
		1) Smoke stats or 2) Exercise stats
	*/


		if (choice == 1) {

			printf("1)None\n");
			printf("2)More than 10\n");
			printf("3)Less than 10\n");
			scanf("%d", &smokeChoice);


			if (smokeChoice == 1) {

				while (temp != NULL)
				{
					if (temp->smoke = 1 && temp->BMI <= 18.5) {
						count1++;
					}
					else if (temp->smoke = 1 && temp->BMI <= 25) {
						count2++;
					}
					else if (temp->smoke = 1 && temp->BMI <= 30) {
						count3++;
					}
					else if (temp->smoke = 1 && temp->BMI <= 30) {
						count4++;
					}

					patient++;
					temp = temp->NEXT;


				}
			}

			else if(smokeChoice == 2)
			{
				while (temp != NULL)
				{
					if (temp->smoke = 2 && temp->BMI <= 18.5) {
						count1++;
					}
					else if (temp->smoke = 2 && temp->BMI <= 25) {
						count2++;
					}
					else if (temp->smoke = 2 && temp->BMI <= 30) {
						count3++;
					}
					else if (temp->smoke = 2 && temp->BMI <= 30) {
						count4++;
					}

					patient++;
					temp = temp->NEXT;


				}

			}
			else if (smokeChoice == 3)
			{
				while (temp != NULL)
				{
					if (temp->smoke = 3 && temp->BMI <= 18.5) {
						count1++;
					}
					else if (temp->smoke = 3 && temp->BMI <= 25) {
						count2++;
					}
					else if (temp->smoke = 3 && temp->BMI <= 30) {
						count3++;
					}
					else if (temp->smoke = 3 && temp->BMI <= 30) {
						count4++;
					}

					patient++;
					temp = temp->NEXT;


				}

			}

		else if (choice == 2) {

				printf("1)None\n");
				printf("2)More than twice a week\n");
				printf("3)Less than twice a week\n");
				scanf("%d", &smokeChoice);

				if (exerciseChoice == 1) {

					while (temp != NULL)
					{
						if (temp->exercise = 1 && temp->BMI <= 18.5) {
							count1++;
						}
						else if (temp->exercise = 1 && temp->BMI <= 25) {
							count2++;
						}
						else if (temp->exercise = 1 && temp->BMI <= 30) {
							count3++;
						}
						else if (temp->smoke = 1 && temp->BMI <= 30) {
							count4++;
						}

						patient++;
						temp = temp->NEXT;


					}
				}

				else if (exerciseChoice == 2)
				{
					while (temp != NULL)
					{
						if (temp->exercise = 2 && temp->BMI <= 18.5) {
							count1++;
						}
						else if (temp->exercise = 2 && temp->BMI <= 25) {
							count2++;
						}
						else if (temp->exercise = 2 && temp->BMI <= 30) {
							count3++;
						}
						else if (temp->exercise = 2 && temp->BMI <= 30) {
							count4++;
						}

						patient++;
						temp = temp->NEXT;


					}

				}
				else if (exerciseChoice == 3)
				{
					while (temp != NULL)
					{
						if (temp->exercise = 3 && temp->BMI <= 18.5) {
							count1++;
						}
						else if (temp->exercise = 3 && temp->BMI <= 25) {
							count2++;
						}
						else if (temp->exercise = 3 && temp->BMI <= 30) {
							count3++;
						}
						else if (temp->exercise = 3 && temp->BMI <= 30) {
							count4++;
						}

						patient++;
						temp = temp->NEXT;

					}
				}
		}

	}

	//Calculating precentages
	//
	// less 18
	percent1 = ((count1 * 100) / patient);
	printf("\n\n1)Patients Less than 18 BMI : %d %\n", percent1);
	fprintf(report, "\n1)Patients Less than 18 BMI : %d %\n", percent1);

	// less 25
	percent2 = ((count2 * 100) / patient);
	printf("1)Patients Less than 25 BMI : %d %\n", percent2);
	fprintf(report, "\n2)Patients Less than 25 BMI : %d %\n", percent2);

	// less 30
	percent3 = ((count3 * 100) / patient);
	printf("1)Patients Less than 30 BMI : %d %\n", percent3);
	fprintf(report, "\n3)Patients Less than 30 BMI : %d %\n", percent3);

	// greater 30
	percent4 = ((count4 * 100) / patient);
	printf("1)Patients Greater than 30 BMI : %d %\n", percent4);
	fprintf(report, "\n4)Patients Less than 30 BMI : %d %\n", percent4);

	fclose(report);
}

//BMI CALCULATION
//
//
//
float BMI(struct node* top, float w, float h)
{
	int i;
	float bmi = 0;
	struct node* temp = top;

	bmi = w / (h * h);

	printf("BMI is %f\n", bmi);

	temp->BMI = bmi;

	return temp->BMI;
}

//EMAIL VALIDATION
//
//
//
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

//UNIQUE ID
//
//
//
int UniqueID(struct node* top, int searchID) {

	int found = 0;
	struct node* temp = top;

	while (temp != NULL)
	{
		if (temp->PPS == searchID)
		{
			found = 1;
			return found;
		}

		temp = temp->NEXT;
	}

	return found;
}

//REPORT FILE
//
//
//
void ReportFile(struct node* top)

{
	struct node* temp = top;

	report = fopen("report.txt", "a");

	while (temp != NULL)
	{
		//DISPLAYING THE CONTENTS BEING SAVED
		printf("Patient %d\n", temp->PPS);
		printf("Patient %s %s\n", temp->name, temp->surname);
		printf("Patient Year of Birth %d\n", temp->yearOfBirth);
		printf("Patient Gender : %s\n", temp->gender);
		printf("Patient Email %s\n", temp->email);
		printf("Patient Next Of Kin : %s\n", temp->nextOfkin);
		printf("Patient last Appointment : %i / %i / %i\n", temp->day, temp->month, temp->year);
		printf("Patient Allergies : %c\n", temp->allergies);
		printf("Patient Alergic to : %s\n", temp->allergy);
		printf("Patient Exercise : %d\n", temp->exercise);
		printf("Patient Smoke : %d\n", temp->smoke);
		printf("Patient Alcohol : %d\n", temp->alcohol);
		printf("Patient Height %f\n", temp->height);
		printf("Patient Weight %f\n", temp->weight);
		printf("Patient BMI %f\n", temp->BMI);

		printf("\n\n--------------------------\n");
		printf("Details have been saved.");
		printf("\n\n--------------------------\n");

		//SAVING THEM TO THE FILE
		fprintf(report, "--------------------------------------------\n");
		fprintf(report, "Patient %d\n", temp->PPS);
		fprintf(report, "Patient %s %s\n", temp->name, temp->surname);
		fprintf(report, "Patient Year of Birth %d\n", temp->yearOfBirth);
		fprintf(report, "Patient Gender : %s\n", temp->gender);
		fprintf(report, "Patient Email %s\n", temp->email);
		fprintf(report, "Patient Next Of Kin : %s\n", temp->nextOfkin);
		fprintf(report, "Patient last Appointment : %i / %i / %i \n", temp->day, temp->month, temp->year);
		fprintf(report, "Patient Allergies : %c\n", temp->allergies);
		fprintf(report, "Patient Alergic to : %s\n", temp->allergy);
		fprintf(report, "Patient Exercise : %d\n", temp->exercise);
		fprintf(report, "Patient Smoke : %d\n", temp->smoke);
		fprintf(report, "Patient Alcohol : %d\n", temp->alcohol);
		fprintf(report, "Patient Height %f\n", temp->height);
		fprintf(report, "Patient Weight %f\n", temp->weight);
		fprintf(report, "Patient BMI %f\n", temp->BMI);
		fprintf(report,"--------------------------------------------\n");

		temp = temp->NEXT;
	}
	fclose(report);
}

//APPOINTMENT LIST
//
//
//
void AppointmentList(struct node* top, int left, int right) {

	struct node* temp = top;

	//clear screen
	system("@cls||clear");


	while (temp != NULL)
	{


		printf("Patient PPS %d\n", temp->PPS);
		printf("Patient %s %s\n", temp->name, temp->surname);
		printf("Patient Year of Birth %d\n", temp->yearOfBirth);
		printf("Patient Gender : %s\n", temp->gender);
		printf("Patient Email %s\n", temp->email);
		printf("Patient Next of Kin : %s\n", temp->nextOfkin);
		printf("Patient last Appointment : %i / %i / %i\n", temp->day, temp->month, temp->year);
		printf("Patient Allergies : %c\n", temp->allergies);
		printf("Patient Smoke : %d\n", temp->smoke);
		printf("Patient Exercise : %d\n", temp->exercise);
		printf("Patient Alcohol : %d\n", temp->alcohol);
		printf("Patient Height %f\n", temp->height);
		printf("Patient Weight %f\n", temp->weight);
		printf("Patient BMI %f\n", temp->BMI);


		printf("\n\n----------------------------------\n\n");

		temp = temp->NEXT;
	}

}

void swap(int year, int year2, int years[]) {

	//Swapping and sorting the years from low to high
	// eg. 1999, 2001, 2007, 2010
	int temp = years[year];
	years[year] = years[year2];
	years[year] = temp;
}

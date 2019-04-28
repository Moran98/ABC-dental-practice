#ifndef HEADER

#define HEADER



#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#include<conio.h>

#include<iostream>



//GLOBAL VARIABLES

char allergyStat;

char smokeStat;

char exerciseStat;

char alcoholStat;

float BMItotal;

int statsChoice = 0;

char password[20];

char pword[20];

char username[20];

char uname[20];

char ch;

int i = 0;

FILE* login;

FILE* report;

bool accept = false;

int numInputs = 0;

int reportInputs = 0;





//STRUCT



struct node {

	char name[30];

	char surname[30];

	int PPS;

	char gender[10];

	char nextOfkin[30];

	float weight;

	float height;

	float BMI;

	int smoke;

	char allergies;

	char allergy[50];

	int exercise;

	int alcohol;

	int yearOfBirth;

	char ID[10];

	char lastApp[15];

	float average;

	char email[30];

	char mobile[30];



	struct node* NEXT;

};



//FUNCTIONS

void AddElementAtStart(struct node** top);

void DeleteElementAtStart(struct node** top);

void DeleteElementAtPos(struct node* top, int pos);

void ReportFile(struct node* top);



int Listlength(struct node* top);

void DisplayList(struct node* top);



//VALIDATIONS

void searchList(struct node* top);

int UniqueID(struct node* top, int searchID);

int validEmail(char email[40]);



//BMI

float BMI(struct node* top, float w, float h);



//STATISTICS

void GenerateStatistics(struct node* top);

//void bmi18(float bmi);



//UPDATING DETAILS

void UpdateDetails(struct node* top);



#endif

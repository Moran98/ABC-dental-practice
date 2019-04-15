#ifndef HEADER
#define HEADER

#include "Patient.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

//GLOBAL VARIABLES
char allergyStat;
char smokeStat;
char exerciseStat;
char alcoholStat;
float BMItotal;
int statsChoice = 0;

//STRUCT

struct node {
	char name[30];
	char surname[30];
	int PPS;
	char gender;
	char nextOfkin[30];
	float weight;
	float height;
	float BMI;
	char smoke;
	char allergies;
	char exercise;
	char alcohol;
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
void AddElementAtEnd(struct node* top);
void AddElementAtPos(struct node* top, int position);


void DeleteElementAtStart(struct node** top);
void DeleteElementAtEnd(struct node* top);
void DeleteElementAtPos(struct node* top, int position);

int Listlength(struct node* top);
void DisplayList(struct node* top);

//VALIDATIONS
int searchList(struct node* top, int searchID);
int validEmail(char email[40]);

//BMI
float BMI(struct node* top,float w, float h);

//STATISTICS
void GenerateStatistics(struct node* top);
//void bmi18(float bmi);

//UPDATING DETAILS
void UpdateDetails(struct node* top);

#endif

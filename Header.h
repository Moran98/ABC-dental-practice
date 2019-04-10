#ifndef HEADER
#define HEADER

#include "Patient.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

//STRUCT

struct node {
	char name[30];
	char surname[30];
	int PPS;
	char gender;
	char nextOfkin;
	float weight;
	float height;
	char smoke;
	char exercise;
	char alcohol;
	int age;
	char ID[10];
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
int searchList(struct node* top, char searchID[10]);
int validEmail(char email[40]);


#endif

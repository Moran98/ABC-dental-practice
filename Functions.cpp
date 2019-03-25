#include "header.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//
//
//
// ADDING  A PATIENT
void AddElementAtStart(struct node** top)
{
  struct node* newNode;

  printf("Please enter Patient PPS Number\n");
  scanf("%d", &newNode->PPS);

  newNode = (struct node*)malloc(sizeof(struct node));

  printf("Please enter Patient first name\n");
  scanf("%s", newNode->fname);

  printf("Please enter Patient surname\n");
  scanf("%s", newNode->lname);

  printf("Please enter Patient DOB\n");
  scanf("%d", &newNode->DOB);

//	strcpy(newNode->PPS, PPS);

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

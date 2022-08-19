//Jakub Szkup - Autumn Repeat Project
//Student ID - G00395191
// 
//#define_CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
	//declaring variables
	char firstName[25];
	char surname[25];
	char email[30];
	char nextOfKinName[25];

	int PPS;
	int yearOfBirth;
	int gender;
	int lastAppointmet;
	int allergicReactions;
	int cigarrettes;
	int weight;
	int height;

	struct node* NEXT;

}nodeT;

struct node* createNode();

//Declaring functions
void displayList(nodeT* top);
int search(nodeT* top, int searchVal);
void addAtTheEndList(struct node* top);
void addAtTheStartList(struct node** top);
void addAtTheLocation(struct node* top, int location);
void displayListUpdated(nodeT* top);
//int listLength(nodeT* top);
void deleteAtLocation(struct node* top, int location);
void outputToFile(struct node* top);
void deleteAtStart(struct node** top);
void deleteAtEnd(struct node* top);
//Main
void main()
{
	nodeT* headPtr = NULL;
	nodeT* newNode;
	nodeT* temp;

	//variables
	int choice;
	int searchVal;
	int length = 0;
	int result;
	int location;
	int location1;

	//Print menu to console
	printf("--------------------------------------------------------------------------------------------------------\n");
	printf("Press 1 to add patient by unique PPS number.\n");
	printf("Press 2 to display all patient details. \n");
	printf("Press 3 to display patient details. \n");
	printf("Press 4 to update patient details. \n");
	printf("Press 5 to delate a patient. \n");
	printf("Press 6 to  generate statistics. \n");
	printf("Press 7 to print patient details to a report file. \n");
	printf("Press 8 to list all patient of the follwing countries in order of their last apointment. \n ");
	printf("--------------------------------------------------------------------------------------------------------\n");

	scanf_s("%d", &choice);

	//while loop for functions
	while (choice == -1)
	{
		if (choice == 1)
		{
			addAtTheStartList(&headPtr);
		}
		else if (choice == 2)
		{
			displayList(headPtr);
		}
		else if (choice == 3)
		{
			result = search(headPtr, &searchVal);
		}
		else if (choice == 4) //using addAtThelocation to update patient's details
		{
			displayListUpdated(headPtr);
			printf("Enter the number you wish to update\n");
			scanf_s("%d", &location1);

			//addAtTheLocation(headPtr, &location);

			
		}
		else if (choice == 5)
		{
			displayListUpdated(headPtr);
			printf("Enter the number you wish to delete\n");
			scanf_s("%d", &location1);

			/*if (location1<0 || location1>(listLength(headPtr) - 1)) //programme wont run at this point ( file cannot be specified error:/ )
			{
				printf("This location is out of range\n");
			}
			else if (location1 == 0)
			{
				deleteAtStart(&headPtr);
			}
			else if (location1 == (listlength(headPtr) - 1))
			{
				deleteAtEnd(headPtr);
			}
			else
			{
				deleteAtLocation(headPtr, location1);
			}*/
		}
		else if (choice == 6)
		{

		}
		else if (choice == 7)
		{
			//outputToFile(headPtr);
		}
		else if (choice == 8)
		{

		}
	}
	printf("--------------------------------------------------------------------------------------------------------\n");
	printf("Press 1 to add patient by unique PPS number.\n");
	printf("Press 2 to display all patient details. \n");
	printf("Press 3 to display patient details. \n");
	printf("Press 4 to update patient details. \n");
	printf("Press 5 to delate a patient. \n");
	printf("Press 6 to  generate statistics. \n");
	printf("Press 7 to print patient details to a report file. \n");
	printf("Press 8 to list all patient of the follwing countries in order of their last apointment. \n ");
	scanf_s("%d", &choice);
	printf("--------------------------------------------------------------------------------------------------------\n");

	
}





//Functions ////////////////////////////////////////////////////

//This function allows user to add any detail about the client
void addAtTheStartList(struct node** top)
{
	struct node* newNode;

	newNode = (struct node*)malloc(sizeof(struct node));

	printf("------------------------------------------------------------\n");

	printf("Please enter patient's PPS number: \n");
	scanf_s("%d", &newNode->PPS);

	printf("Please enter the patient's name: \n");
	scanf_s("%s", newNode->firstName);

	printf("Please enter the patient's surname: \n");
	scanf_s("%s", newNode->surname);

	printf("Please enter the year of birth: \n");
	scanf_s("%d", &newNode->yearOfBirth);

	printf("Gender of the patient? (0=male , 1=female)\n");
	scanf_s("%d", &newNode->gender);

	printf("Please enter email adress: \n");
	scanf_s("s", newNode->email);

	printf("Name Next of kin of the patient: \n");
	scanf_s("%s", newNode->nextOfKinName);

	printf("Patients last appointment (DD/MM/YY): \n");
	scanf_s("s", newNode->lastAppointmet);

	printf("Please enter patient's weight: \n");
	scanf_s("%d", &newNode->weight);

	printf("Please enter the patient's height: \n");
	scanf_s("%d", &newNode->height);

	printf("Does the patient have any allergies? (1=Yes, 2=No");
	scanf_s("%d", &newNode->allergicReactions);

	printf("Cigarretes smoked by patient per day?(0=None, 1=less than 5, 2= more than 10: \n");
	scanf_s("%d", &newNode->cigarrettes);

	printf("----------------------------------------------------------------------------------------\n");

	newNode->NEXT = *top;
	*top = newNode;



}

 //This function displays all client info that the user is searching for
void displayList(nodeT* top)
{
	struct node* temp;
	temp = top;
	while (temp != NULL)
	{
		printf("PPS Number : %d \nFirst Name: %s\nSurname: %s\nYear Born: %d\nGender: %d\nEmail Address: %s\nNext of Kin: %s\nLast appointment: %d\nWeight: %d\nHeight: %d\nDoes the patient have allergies: %d\nHow many cigarrettess does the patient smoke per day?: %d",
			temp->PPS, temp->firstName, temp->surname, temp->yearOfBirth, temp->gender, temp->email, temp->nextOfKinName, temp->lastAppointmet, temp->weight, temp->height, temp->allergicReactions, temp->cigarrettes);
	 }
}

//This function searches fot he pps number the user is looking for
int search(nodeT* top, int searchVal)
{
	printf("Enter the PPS number of client you are searching for: \n");
	scanf_s("%d", &searchVal);
	printf("PPS number you are searching for is(make sure this is the right number you are searching for!): %d \n", searchVal);

	struct node* temp = top;
	int found = -1;
	int count = 0;

	while (temp!= NULL)
	{
		if (temp->PPS == searchVal)
		{
			found = count;

			printf("Patients PPS number is: %d\n", temp->PPS);
		}

		if (temp->gender == 0)
		{
			printf("The patients gender is MALE\n");
		}
		else
		{
			printf("The patients gender is FEMALE\n");
		}
	}
	temp = temp->NEXT;
	count++;
}

//This function allows user to pick a number which will allow them to to update/delete a patients details
void displayListUpdated(nodeT* top)
{
	struct node* temp;
	temp = top;

	int i = 0; //i initiliazed to 0

	while (temp != NULL)
	{
		printf("%d  PPS number: %d \t FullName: %s %s\n", i, temp->PPS, temp->firstName, temp->surname);

		temp = temp->NEXT;
		i++;
	}

}

//This function outputs the linked list to a text file
/*void outputToFile(struct node* top)
{
	struct node* temp;
	FILE* fp;
	temp = top;

	fp = fopen("Patient.txt", "w");

	while (temp != NULL)
	{
		if (fp != NULL)
		{
			fprint(fp, "%d %s %s %d %d %s %s %d %d %d %d %d\n", temp->PPS, temp->firstName, temp->surname, temp->yearOfBirth, temp->gender,
				temp->email, temp->nextOfKinName, temp->lastAppointmet, temp->weight, temp->height, temp->allergicReactions, temp->cigarrettes);
		}
		temp = temp->NEXT;
	}
	if (fp != NULL)
	{
		fclose(fp);
		printf("Filve has been saved\n");
		exit;
	}
}*/

//This function finds the length of the linked list
//int listLength(nodeT* top)





//End of functions/////////////////////////////////////////////////


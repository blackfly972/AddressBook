/*
 ============================================================================
 Name        : COrvilleAddressBook.c
 Author      : Christophe Orville
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "address_book.h"

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);

	char input[BUFSIZ];

	int done = 0;
	printf("Ready\n");
	while(!done) {

		char command = fgetc(stdin);
		fgetc(stdin);//consume trailing newline
		switch(command) {
		case 'a' : {
			int desiredIndex = atoi(fgets(input, BUFSIZ,stdin));
//			printf("%d\n", desiredIndex); //Test to see if you get the right index that was entered
//			fgetc(stdin);//consume trailing newline
			char* properties = fgets(input, BUFSIZ, stdin);
			properties[strlen(properties) - 1] = '\0';
			addContact(desiredIndex, properties);
			break;
		}
		case 'g' : {
			int desiredIndex = atoi(fgets(input, BUFSIZ,stdin));
		//	fgetc(stdin);//consume trailing newline
			printContact(desiredIndex);
			break;
		}
		case 'd' :{
			int desiredIndex = atoi(fgets(input, BUFSIZ,stdin));
			//fgetc(stdin);//consume trailing newline
			deleteContact(desiredIndex);
			break;
		}
		case 'f' : {
			int desiredIndex = fgetc(stdin) - '0';
			fgetc(stdin);//consume trailing newline
			char* fieldName = fgets(input, BUFSIZ, stdin);
			fieldName[strlen(fieldName) - 1] = '\0';
			printField(desiredIndex, fieldName);
			break;
		}
		case 'l' : {
			char* filename = fgets(input, BUFSIZ, stdin);
			filename[strlen(filename) - 1] = '\0';
			loadContactsFromFile(filename);
			break;
		}
		case 's' : {
			char* filename = fgets(input, BUFSIZ, stdin);
			filename[strlen(filename) - 1] = '\0';
			writeContactsToFile(filename);
			break;
		}
		case 'n' :{
			numberOfContacts();
			break;
		}
		case 'e' :{
			int desiredIndex = fgetc(stdin) - '0';
			fgetc(stdin);//consume trailing newline
			char* fieldName = fgets(input, BUFSIZ, stdin);
			fieldName[strlen(fieldName) - 1] = '\0';
			editContacts(desiredIndex, fieldName);
			break;
		}
		case 'o' :{
			void sortContacts();
			break;
		}
		case 'q' : {
			done = 1;
			break;
		}
		default: {
			break;
		}
		}

	}

	printf("Complete\n");
	return 0;
//
//	char properties[] = "WILLIAMS,SACHIKO,swilliams@about.com,8001110003";
//	initAddressBook();
//	addContact(0, properties);
//
//	printContact(0);
//
//	return 0;
}


//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef struct {
//	char lastName[255];
//	char firstName[255];
//	char email[255];
//	char phoneNumber[255];
//} Contact;
//
//void addNewContact(int index, char* properties);
//void deleteContact(addressBook book[]);
//void getContact(addressBook book[]);
//void getField(addressBook book[]);
//void getNumberofContactsInTheList(addressBook book[]);
//void loadaFile(addressBook book[]);
//void saveContactsToaFile(addressBook book[]);
//void editaContact(addressBook book[]);
//void sortContacts(addressBook book[]);
//
//int counter = 0;
//
//int main(void) {
//	setvbuf(stdout, NULL, _IONBF, 0); // Turn off output buffering. Required for automated testing.
//
//	const int MAX_CONTACTS = 100;
//	Contact contacts[MAX_CONTACTS];
//
//
//
//
//
//	char buffer[BUFSIZ];
//
//	char information[1000] = { '\0' };
//
//	addressBook book[100];
//	char choice;
//
//	char* line;
//
//	while (choice != 'q') {
//		printf("Ready\n");
//		scanf("%s", &choice);  //Stores menu choice into variable choice
//		fgetc(stdin);
//		//Add Contact
//		if (choice == 'a')
//			addNewContact(book);
//		//Delete Contact
//		if (choice == 'd')
//			deleteContact(book);
//		//Get Contact
//		if (choice == 'g')
//			getContact(book);
//		//Get field
//		if (choice == 'f')
//
//			//Get number of contacts in the list
//			if (choice == 'n')
//
//				//Load a file
//				if (choice == 'l')
//
//					//Save contacts to a file
//					if (choice == 's')
//
//						//Edit a contact
//						if (choice == 'e')
//
//							//Sort contacts
//							if (choice == 'o')
//								sortContacts(book);
//		//Quit
//		if (choice == 'q') {
//			printf("Complete\n");
//			return 0;
//		}
//	}
//}
//void addNewContact(int index, char* properties) {
//	counter = counter + 1;
//	char* find = ",";
//	int findLength = strlen(find);
//	char string1[BUFSIZ];
//	char buffer[BUFSIZ];
//
//    void *temp = book;
//    int i;
//	int s = 0;
//
//	int index = atoi(fgets(buffer, BUFSIZ, stdin));
//	printf("%d", index);
//
//	scanf("%s", string1);
//
//	printf("%s", string1);
//
//
//
//
//
//
//	}
//void deleteContact(addressBook book[]) {
//	int x = 0;
//	char deleteName[20]; // Temp string to compare to existing addressBook
//	char deleteSurname[20]; //temp string
//	char nullStr[20] = { "\0" }; // empty string to remove phoneNumber
//	printf("\nEnter name: ");
//	scanf("%s", deleteName); //place into temp string
//	printf("Enter Surname: ");
//	scanf("%s", deleteSurname); //place into temp string
//	for (x = 0; x < counter; x++) {
//		if (strcmp(deleteName, book[x].firstName) == 0) //compare deleteName to book.firstName
//				{
//			for (x = 0; x < counter; x++) {
//				if (strcmp(deleteSurname, book[x].lastName) == 0) //If deleteSurname matches book.lastName
//						{
//					strcpy(book[x].firstName, nullStr); //Put null into firstName
//					strcpy(book[x].lastName, nullStr); //Null into lastName
//					strcpy(book[x].phoneNumber, nullStr); //Null into phoneNumber
//					counter--;
//					break;
//				}
//			}
//		} else
//			printf("Invalid entry--try again.\n");
//	}
//}
//
//void getContact(addressBook book[]) {
//	int x = 0;
//	for (x = 0; x < counter; x++) {
//		printf("\n(%d)\n", x + 1); //Show contact number
//		printf("%s %s\n", book[x].firstName, book[x].lastName); //Name
//		printf("%s\n", book[x].phoneNumber); //Number
//	}
//}
//
//void sortContacts(addressBook book[]) {
//	addressBook temp;
//	int i;
//	int j;
//	for (i = 0; i < 19; i++) {
//		for (j = i + 1; j < 19; j++) {
//			if (strcmp(book[i].lastName, book[j].lastName) > 0) {
//				temp = book[i];
//				book[i] = book[j];
//				book[j] = temp;
//			}
//		}
//	}
//}
//

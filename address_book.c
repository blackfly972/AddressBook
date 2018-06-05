/*
 * address_book.c
 *
 *  Created on: Apr 16, 2018
 *      Author: corville
 */

#include "address_book.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void initAddressBook() {
	addressBook.contactCount = 0;
	addressBook.top = NULL;
}

void freeAddressBook() {
	int numberOfContacts = addressBook.contactCount;
	int i;
	for(i = 0; i < numberOfContacts; ++i) {
		deleteContact(i);
	}
}

void addContact(int desiredIndex, char properties[]) {

	if((addressBook.contactCount == 0 && desiredIndex != 0) || (addressBook.contactCount > 0 && desiredIndex > addressBook.contactCount)) {
		return;
	}

	struct Contact* newContact = (struct Contact*) malloc(
			sizeof(struct Contact));
	newContact->next = NULL;
	newContact->prev = NULL;

	if (addressBook.top == NULL) {
		addressBook.top = newContact;
	} else {

		struct Contact* contact = getContact(desiredIndex);

		if (contact == addressBook.top) {
			//adding to the front
			newContact->next = addressBook.top;
			newContact->prev = NULL;
			addressBook.top->prev = newContact;
			addressBook.top = newContact;
		} else if(contact == NULL) {
			//adding to the end
			struct Contact* last = getContact(desiredIndex - 1);
			last->next = newContact;
			newContact->prev = last;
		} else {
			//adding in the middle
			newContact->next = contact;
			newContact->prev = contact->prev;
			contact->prev->next = newContact;
			contact->prev = newContact;
		}
	}

	char delimiter = ',';

	int lengths[4] = { 0, 0, 0, 0 };
	int lengthIndex = 0;
	int previousDelimiterIndex = 0;

	char copy[BUFSIZ];
	strncpy(copy, properties, BUFSIZ);
	copy[strlen(copy)] = delimiter;

	int i;
	for (i = 0; i < strlen(copy); ++i) {

		char currentChar = copy[i];

		if (currentChar == delimiter) {
			lengths[lengthIndex] = (i
					- (previousDelimiterIndex
							+ (previousDelimiterIndex == 0 ? 0 : 1)));
			lengthIndex++;
			previousDelimiterIndex = i;

		}

	}

	strncpy(newContact->lastName, copy + 0, lengths[0]);
	strncpy(newContact->firstName, copy + lengths[0] + 1, lengths[1]);
	strncpy(newContact->email, copy + lengths[0] + lengths[1] + 2, lengths[2]);
	strncpy(newContact->phoneNumber,
			copy + lengths[0] + lengths[1] + lengths[2] + 3, lengths[3]);

	addressBook.contactCount++;

}

int isValidIndex(int index) {
	//printf("%d\n", addressBook.contactCount);
	return (index >= 0 && index < addressBook.contactCount);

}

void printContact(int index) {

	if (!isValidIndex(index)) {
		return;
	}

	struct Contact* contact = getContact(index);

	printf("%s,%s,%s,%s\n", contact->lastName, contact->firstName, contact->email,
			contact->phoneNumber);

}

void deleteContact(int desiredIndex) {

	if(!isValidIndex(desiredIndex)) {
		return;
	}

	Contact* contact = getContact(desiredIndex);
	if(contact == addressBook.top) {
		//removing from the front
		addressBook.top = addressBook.top->next;
		if (addressBook.top != NULL)
			addressBook.top->prev = NULL;
		//addressBook.top->prev->next = NULL;
		//addressBook.top->prev = NULL;
	}else if(desiredIndex == addressBook.contactCount - 1) {//(getContact(desiredIndex + 1) == NULL) {
		//removing from the back
		contact->prev->next = NULL;
		//contact->prev->prev = NULL;
	}else {
		//removing from the middle
		contact->prev->next = contact->next;
		contact->next->prev = contact->prev;
		contact->next = contact->prev = NULL;
	}
	free(contact);
	addressBook.contactCount--;

}

struct Contact* getContact(int index) {

	int currentIndex = 0;

	struct Contact* cursor = addressBook.top;
	while(cursor != NULL) {
		if(currentIndex == index) {
			return cursor;
		}
		currentIndex++;
		cursor = cursor->next;
	}

	return NULL;
}

void printField(int contactIndex, char* fieldName) {

	if(!isValidIndex(contactIndex)) {
		return;
	}

	struct Contact* contact = getContact(contactIndex);

	if(strcmp(fieldName, "lastName") == 0) {
		printf("%s\n", contact->lastName);
	}
	else if(strcmp(fieldName, "firstName") == 0) {
		printf("%s\n", contact->firstName);
	}
	else if(strcmp(fieldName, "email") == 0) {
		printf("%s\n", contact->email);
	}
	else if(strcmp(fieldName, "phoneNumber") == 0) {
		printf("%s\n", contact->phoneNumber);
	}

}

void numberOfContacts() {
	printf("%d\n", addressBook.contactCount);
}

void loadContactsFromFile(char* filename) {

	FILE* file = fopen(filename, "r");
	if(!file) {
		return;
	}

	char buffer[BUFSIZ];

	char* line;
	int firstLine = 1;
	while((line = fgets(buffer, BUFSIZ, file)) != NULL) {
		if(firstLine) {
			firstLine = 0;
			continue;
		}

		line[strlen(line) - 1] = '\0';

		addContact(addressBook.contactCount, line);

	}

	fclose(file);


}

void writeContactsToFile(char* filename) {

	FILE* file = fopen(filename, "w");

	int i;
	fprintf(file, "lastName,firstName,email,phoneNumber\n");
	for(i = 0; i < addressBook.contactCount; ++i) {
		struct Contact* contact = getContact(i);
		fprintf(file, "%s,%s,%s,%s\n", contact->lastName, contact->firstName, contact->email, contact->phoneNumber);
	}

	fflush(file);
	fclose(file);

}

void editContacts(int contactIndex, char* fieldName){
	char buffer[BUFSIZ];
	if(!isValidIndex(contactIndex)){
		return;
	}
	struct Contact* contact = getContact(contactIndex);
	fgets(buffer, BUFSIZ, stdin);
	buffer[strlen(buffer)-1] = '\0';

	if(strcmp(fieldName, "lastName") == 0) {
		strcpy(contact->lastName, buffer);
	}
	else if(strcmp(fieldName, "firstName") == 0) {
		strcpy(contact->firstName, buffer);
	}
	else if(strcmp(fieldName, "email") == 0) {
		strcpy(contact->email, buffer);
	}
	else if(strcmp(fieldName, "phoneNumber") == 0) {
		strcpy(contact->phoneNumber, buffer);
	}
}

void sortContacts(){

}
















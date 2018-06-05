/*
 * address_book.h
 *
 *  Created on: Apr 16, 2018
 *      Author: corville
 */

#ifndef ADDRESS_BOOK_H_
#define ADDRESS_BOOK_H_

typedef struct Contact {
	char lastName[255];
	char firstName[255];
	char email[255];
	char phoneNumber[255];
	struct Contact* next;
	struct Contact* prev;
}Contact;

struct AddressBook {
	Contact* top;
	int contactCount;
};
#define max_contacts  100
struct AddressBook addressBook;

void initAddressBook();

void freeAddressBook();

void addContact(int, char properties[]);

int isValidIndex(int);

void printContact(int);

void deleteContact(int);

struct Contact* getContact(int);

void printField(int, char*);

void numberOfContacts();

void loadContactsFromFile(char*);

void writeContactsToFile(char*);

void editContacts(int, char*);

void sortContacts();

#endif /* ADDRESS_BOOK_H_ */

#include <stdio.h>
#include <string.h>

//Phone record structure definition
struct phoneRecord {
	char lastName[20];
	char firstName[20];
	char phoneNum[15];
} phoneRecord;

struct phoneRecord phoneBook[69];
int curr = 0;

void askFor(char * asked, char * value) {

	printf("%s (do not use spaces) ? ", asked);
	fflush(stdout);
	scanf("%s", value);
}

void printContact(struct phoneRecord record, FILE * file) {

	// Reaches the end of the stream
	//fseek(file, 0, SEEK_END);

	// Writes the contact at the end of the stream.
	fprintf(file, "%s ",  record.firstName);
	fprintf(file, "%s\n", record.lastName);
	fprintf(file, "%s\n", record.phoneNum);
}

void printContacts(FILE * file) {

	int i;
	for (i=0; i < curr; i++) {
		printContact(phoneBook[i], file);
	}
}

void printAllToFile(FILE *fPtr) {

	FILE * phones = fopen("phones.txt", "wb+");

	if (phones != NULL) {
		printContacts(phones);
		fclose(phones);
		return;
	}

	printf("Error: Error creating the phones.txt file.\n");
}

void updateDB(FILE * fPtr) {
	printContacts(fPtr);
}

void addRecord(FILE *fPtr) {

	printf("Contact:\n");

	if (fPtr != NULL) {

		askFor("Last Name", phoneBook[curr].lastName);
		askFor("First Name", phoneBook[curr].firstName);
		askFor("Phone Number", phoneBook[curr].phoneNum);

		printContact(phoneBook[curr], stdout);
		curr++;
		updateDB(fPtr);
		return;
	}

	printf("Error: Getting the contact info did not work.\n");
}

int findPhoneNum(FILE *fPtr) {

	char searched[20];

	printf("I will return the FIRST MATCH:\n");
	askFor("First Name OR Last Name", searched);

	int i;
	// Reads the file looking for the name given.
	for (i=0; i < curr; i++) {
		
		if (strcmp(phoneBook[i].firstName, searched)) {
			printf("Matched by First Name (%i):\n", i);
			printContact(phoneBook[i], stdout);
			return i;
		}

		if (strcmp(phoneBook[i].lastName, searched)) {
			printf("Matched by Last Name (%i):\n", i);
			printContact(phoneBook[i], stdout);
			return i;
		}
	}
	
	printf("Error: Contact could not be found.\n");
	return -1;
}

void deleteRecord(FILE *fPtr) {

	int toDelete = findPhoneNum(fPtr);

	if (toDelete < 0) {

	} else {
		curr--;
		strcpy(phoneBook[toDelete].lastName,
			phoneBook[curr].lastName);
		strcpy(phoneBook[toDelete].firstName,
			phoneBook[curr].firstName);
		strcpy(phoneBook[toDelete].phoneNum,
			phoneBook[curr].phoneNum);

		updateDB(fPtr);
		return;
	}

	printf("Error: Contact could not be deleted.\n");
}

void updateRecord(FILE *fPtr){

	deleteRecord(fPtr);
	addRecord(fPtr);
}
#include <stdio.h>
#include <string.h>

//Phone record structure definition
struct phoneRecord {
	char lastName[20];
	char firstName[20];
	char phoneNum[15];
};


int askFor(char * asked, char * value) {

	printf("%s?\n", asked);
	scanf("%s", value);
	return 0;
}

void reachString() {

}

void writeContact(struct phoneRecord record, FILE * file) {

	// Reaches the end of the file
	fseek(file, 0, SEEK_END);

	// Writes the contact at the end of the file.
	fprintf(file,"%s ", record.lastName);
	fprintf(file,"%s\n", record.firstName);
	fprintf(file,"%s\n", record.phoneNum);

	// Releases the file.
	fflush(file);
}

void addRecord(FILE *fPtr) {
	struct phoneRecord newContact;

	char buffer[20];
	printf("Contact:\n");

	if (fPtr != NULL) {

		if(!askFor("Last Name", buffer)) {
			strncpy(newContact.lastName, buffer, 20);

			if(!askFor("First Name", buffer)) {
				strncpy(newContact.firstName, buffer, 20);

				if(!askFor("Phone Number", buffer)) {
					strncpy(newContact.phoneNum, buffer, 15);

					//writeContact(newContact, stdout);
					writeContact(newContact, fPtr);
					return;
				}
			}
		}
	}

	printf("Error: Getting the contact info did not work.\n");
}

void findPhoneNum(FILE *fPtr) {

	char buffer[41];
	char searched[41];

	if (fPtr != NULL) {

		if(!askFor("Phone Number", buffer)) {

			// Reads the file looking for the name given.
			while(fgets(buffer, sizeof(buffer), fPtr) != NULL) {

				if (strcmp(searched, buffer)) {
					
					printf("Number found: ");
					fgets(buffer, sizeof(buffer), fPtr);
					printf("%s\n", buffer);
					return;

				}
			}
		}
	}

	printf("Error: Contact could not be found.\n");
}

void deleteRecord(FILE *fPtr) {

	char buffer[41];
	char toDelete[41];
	FILE * reWriter = fopen("myPhoneBookDB", "rb+");

	if (fPtr != NULL) {

		if(!askFor("Contact Name", buffer)) {

			// Reads the file looking for the name given.
			while(fgets(buffer, sizeof(buffer), fPtr) != NULL) {

				if (!strcmp(toDelete, buffer)) {
					
					printf("Deleting: ");
					fgets(buffer, sizeof(buffer), fPtr);
					printf("%s", buffer);
					return;

				} else {
					fprintf(reWriter,"%s", buffer);
					fflush(reWriter);
				}
			}
			return;
		}
	}

	printf("Error: Contact could not be deleted.\n");
}

void updateRecord(FILE *fPtr){

	deleteRecord(fPtr);
	addRecord(fPtr);

}

void printAllToFile(FILE *fPtr) {

	char buffer[41];
	FILE * phone = fopen("phones.txt", "wb+");

	if (fPtr != NULL && phone != NULL) {

		while(fgets(buffer, sizeof(buffer), fPtr) != NULL) {

			fprintf(phone,"%s", buffer);	
		}

		fflush(phone);
		return;
	}

	printf("Error: Error creating the phones.txt file.\n");

}
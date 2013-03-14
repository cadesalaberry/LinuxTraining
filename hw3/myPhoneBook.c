//Phone book processing program reads a random-access file sequentially, updates records already
//written to the file, creates new record to be placed in the file, deletes records in the file, and prints
//records in the file.

#include <stdio.h>
#include "myPhoneBook.h"

unsigned int enterChoice(void);

int main(void)
{
	FILE * fPtr; //myPhoneBook file pointer
	unsigned int choice; // user’s choice

	//fopen opens the file; exists if file cannot be opened
	if( (fPtr = fopen("myPhoneBookDB", "rb+") ) == NULL ) {

		puts("File cannot be opened.\n");
	}
	else{
		//let user to specify action
		while( (choice = enterChoice() ) !=6 ) {
			switch(choice) {
				case 1: addRecord(fPtr);break;
				case 2: findPhoneNum(fPtr);break;
				case 3: updateRecord(fPtr);break;
				case 4: deleteRecord(fPtr);break;
				case 5: printAllToFile(fPtr);break;

				default:puts("Incorrect choice.");
				break;
			} //end switch
		} //end while

		fclose(fPtr);
	} //end else

	return 0;
} //end main


unsigned int enterChoice(void)
{
	unsigned int menuChoice; //variable to store user’s choice

	// display available options
	printf("Enter your choice:\n");
	printf("1 --- add a new phone record\n");
	printf("2 --- find a phone number of a given user \n");
	printf("3 --- update the phone record \n");
	printf("4 --- delete a phone record\n");
	printf("5 --- list all phone records in a text file \"phones.txt\" for printing \n");
	printf("6 --- end program\n");

	scanf(" %u", &menuChoice); //receive choice from user

	return menuChoice;
} //end function enterChoice
#COMP 206


## Homework 3


**Due on Wednesday, March 13th, 2012 at 11:59pm**

##Instructions for Submission


Students should email their submissions to sandeepwadhwani09.gmail@com
Below is the format that should be followed:
**SUBJECT:** COMP-206 Homework-3 of *STUDENT NAME* (*McGill ID*)
**FILES:** *STUDENT NAME* (*McGill ID*).zip


Emails would be filtered according to the subject, so students must follow the subject guidelines.


### *__/2* 1. File viewer


Write a program called **printFile.c** that takes the name of a text file and outputs the entire text of it onto the screen. Make the executable named printFile, so if I type

	“./printFile myFile.txt”

I can view the file on screen.


### *__/3* 2. Basic Contact Manager

Write a program processing your phone book using random access files. The program is able to update existing records, adding new records, deleting records, retrieving records, and storing all the records in a text file for printing. Let us assume that the address book is named as myPhoneBook, which is empty initially. When you update, add or delete records, the myPhoneBook will be updated accordingly. The main program is given, and it has 5 options. Option 1 calls the function addRecord to add a new phone record to the file myPhoneBook. Option 2 calls the function findPhoneNum to print the phone number of a given user. Option 3 calls the function updateRecord to update a phone number that already exists. Option 4 calls the function deleteRecord to delete a record from the file. Option 5 calls the function printAllToFile to list all the phone records in a text file named phones.txt that may be printed later.

You are asked to write the 5 functions which are declared in the given code. Inside the functions, you may want to get user’s first name and last name from the STDIN, and use the information to locate the record of a given user in the file myPhoneBook. You may consider using fread and fwrite functions in your implementation. Note that the function deleteRecord doesn’t need to remove the record from the file, you only need to mark the phoneNum field invalid for the given record.

Below is the code in phonebook.c:

	//Phone book processing program reads a random-access file sequentially, updates records already
	//written to the file, creates new record to be placed in the file, deletes records in the file, and prints
	//records in the file.
	
	#include<stdio.h>
	//Phone record structure definition

	struct phoneRecord{
		char lastName[20];
		char firstName[20];
		char phoneNum[15];
	};

	unsigned int enterChoice(void);
	void addRecord(FILE *fPtr);
	void findPhoneNum(FILE *fPtr);
	void updateRecord(FILE *fPtr);
	void deleteRecord(FILE *fPtr);
	void printAllToFile(File *fPtr);
	int main(void)
	{
		FILE * fPtr; //myPhoneBook file pointer
		unsigned int choice; // user’s choice

		//fopen opens the file; exists if file cannot be opened
		if( (fPtr = fopen(“myPhoneBook”, “rb+”) ) == NULL ) {

			puts(“File cannot be opened.\n”);
		}
		else{
			//let user to specify action
			while( (choice = enterChoice() ) !=6 ) {
				switch(choice) {
					case 1:addRecord(fPtr);
					break;
					case 2:findPhoneNum(fPtr);
					break;
					case 3:updateRecord(fPtr);
					break;
					case 4:deleteRecord(fPtr);
					break;
					case 5:printAllToFile(fPtr);
					break;
					default:puts(“Incorrect choice.”);
					break;
				} //end switch
			} //end while

			fclose(fPtr);
		} //end else
	} //end main


	unsigned int enterChoice(void)
	{

		unsigned int menuChoice; //variable to store user’s choice

		// display available options
		printf(“Enter your choice:\n”);
		printf(“1 --- add a new phone record\n”);
		printf(“2 --- find a phone number of a given user \n”);
		printf(“3 --- update the phone record \n”);
		printf(“4 --- delete a phone record\n”);
		printf(“5 --- list all phone records in a text file \”phones.txt\” for printing \n”);
		printf(“6 --- end program\n”);

		scanf(“ %u”, &menuChoice); //receive choice from user

		return menuChoice;
	} //end function enterChoice


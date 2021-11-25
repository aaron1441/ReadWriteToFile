#include <stdio.h>

void main()
{
	FILE* fp;
	int numPeople;
	int numInputs;
	int i;
	int age;
	float interestRate;
	char firstName[30];
	char lastName[30];

	// creating file pointer and opening file
	fp = fopen("People.txt", "w");
	if (fp == NULL)
	{
		printf("Sorry the file could not be opened");
	}
	else
	{
		printf("Please enter the number of people you wish to read and output to file\n");
		scanf("%d", &numPeople);

		for (i = 0; i < numPeople; i++)
		{
			printf("Please enter your first name, last name, age and interest rate\n");
			scanf("%s %s %d %f", firstName, lastName, &age, &interestRate);

			// output to the file
			fprintf(fp, "% s % s % d % f\n", firstName, lastName, age, interestRate);
		}

		fclose(fp);
	} // end of if statement

	// read in the file contents
	fp = fopen("People.txt", "r");

	if (fp == NULL)
	{
		printf("File could not be opened\n");
	}
	else
	{

		// c provides a function called feof which received the file pointer as parameter  and return true if atthe end of the file
		while (!feof(fp))
		{
			numInputs = fscanf(fp, "%s %s %d %f", firstName, lastName, &age, &interestRate);
			// output then to screen
			if (numInputs == 4)
			{
				printf("Echoing the contents of the file, %s %s %d %f\n", firstName, lastName, age, interestRate);
			}

		}
		fclose(fp);
	}
}
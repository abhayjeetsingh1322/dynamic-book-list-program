/*
BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF THE WORK TO CREATE
THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN THIS FILE MYSELF WITH NO ASSISTANCE
FROM ANY PERSON (OTHER THAN THE INSTRUCTOR OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY
ADHERED TO THE TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.
*/

/* Author: Abhayjeet Singh */

#include <stdio.h>
#include <stdlib.h>
#include "lab3.h"

int main()
{
	//Prompt
	int size = 0;
	printf("How many library book titles do you plan to enter? ");
	scanf("%d", &size);
    
	if(size >= 1)
	{
    	//Pointer to char pointers
    	char **titles = calloc(size, sizeof(char *));
   	 
    	//Allocation check
    	if (titles == NULL)
    	{
    	    //Free memory 
    	    free(titles);
    	    titles = NULL;
    	    
        	//Report error and exit
        	fputs("Memory Allocation Failed.", stderr);
        	exit(EXIT_FAILURE);
    	}
   	 
    	int i = 0;
    	for (i = 0; i < size; i++)
    	{
        	//Char pointer to 'string'
        	*(titles+i) = calloc (61, sizeof(char));
       	 
        	//Allocation check
        	if (*(titles+i) == NULL)
        	{
        	    //Freeing memory
                freeBookTitles(titles, i);
            	free(titles);
            	titles = NULL;
        	    
            	//Report error and exit
            	fputs("Memory Allocation Failed.", stderr);
            	exit(EXIT_FAILURE);
        	}
    	}
       	 
    	//Filling book titles
    	fillTitles (titles, size);
   	 
    	//Printing book titles
    	printf("\nYou've entered: \n");
    	printList (titles, size);
   	 
    	//Prompt
    	printf("\nOf those %d books, how many do you plan to put on your favorites list? ", size);
    	int numFavs = 0;
    	scanf("%d", &numFavs);
   	 
    	//Pointer to char pointers
    	char **favorites = calloc(numFavs, sizeof(char *));
   	 
    	//Allocation check
    	if (favorites == NULL)
    	{
    	    //Freeing memory
        	freeBookTitles(titles, size);
        	free(titles);
        	titles = NULL;
        	free(favorites);
        	favorites = NULL;
        	
        	//Report error and exit
        	fputs("Memory Allocation Failed.", stderr);
        	exit(EXIT_FAILURE);
    	}
   	 
    	//Referencing book titles
    	fillFavorites (favorites, numFavs, titles);
   	 
    	//Printing favorite books
    	printf("\nThe books on your favorites list are: \n");
    	printList(favorites, numFavs);
   	 
    	//Prompt
    	printf("\nDo you want to save them (1=yes, 2=no): ");
    	int save = 0;
    	scanf("%d", &save);
   	 
    	if (save == 1)
    	{   
        	//Printing to file
        	printToFile (titles, size, favorites, numFavs);
    	}
   	 
    	//Freeing memory
        freeBookTitles(titles, size);
        free(titles);
        titles = NULL;
        free(favorites);
        favorites = NULL;
	}
	else
	{
    	printf("Program Terminated: Number of books must be greater than or equal to 1.");
	}
    
	return 0;
}

void fillTitles (char **titles, int size)
{
	//Prompt
	printf("Enter the %d book titles one to a line: ", size);
	getchar(); //Consume \n
    
	//Filling in titles
	for (int i = 0; i < size; i++) {
    	scanf("%60[^\n]", *(titles+i));
    	getchar(); //Consume \n
	}
}

void printList (char **titles, int size)
{
	//Printing in list format
	for (int i = 0; i < size; i++)
	{
    	printf("%d. %s\n", i+1, *(titles+i));
	}
}

void fillFavorites (char **favorites, int numFavs, char **titles)
{
	//Prompt
	printf("Enter the number next to each book title you want on your favorites list: ");
    
	//Referencing book titles
	for (int i = 0; i < numFavs; i++)
	{
    	int bookNum = 0;
    	scanf("%d", &bookNum);
    	*(favorites + i) = *(titles + bookNum - 1);
	}
}

void printToFile (char **titles, int size, char **favorites, int numFavs)
{
	//Prompt
	printf("What file name do you want to use? ");
    
	//Assuming 50 char max limit
	char * fileName = calloc(55, sizeof(char));
    
    //Allocation check
    if (fileName == NULL)
    {
        //Freeing memory
        freeBookTitles(titles, size);
        free(titles);
        titles = NULL;
        free(favorites);
        favorites = NULL;
        free(fileName);
        fileName = NULL;
        
        //Report error and exit
    	fputs("Memory Allocation Failed.", stderr);
    	exit(EXIT_FAILURE);
    }
    
	scanf("%50s", fileName); //Since name must not contain whitespace
    
	//Finding end of filename
	int end = 0;
	while (*(fileName + end) != '\0')
	{
    	end++;
	}
    
	//Appending .txt
	*(fileName + end++) = '.';
	*(fileName + end++) = 't';
	*(fileName + end++) = 'x';
	*(fileName + end) = 't';
    
	//Create and write to file
	FILE *out = fopen(fileName, "w");
	int i = 0;
    
	//Writing all book titles
	fputs("Books I've Read:\n", out);
	for (i = 0; i < size; i++)
	{
    	fputs(*(titles + i), out);
    	fputs("\n", out);
	}
    
	//Writing all favorites
	fputs("\nMy Favorites are:\n", out);
	for (i = 0; i < numFavs; i++)
	{
    	fputs(*(favorites + i), out);
    	fputs("\n", out);
	}
    
	//Closing file
	fclose(out);
	
	//Free memory
	free(fileName);
	fileName = NULL;
}

void freeBookTitles(char **titles, int size)
{
    //Freeing memory
	for (int i = 0; i < size; i++)
	{
    	free(*(titles + i));
	}
}

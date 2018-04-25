// -n: Number of lines
// -e: Add a dollar sign to each of the output

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int flag1 = 0;
	int flag2 = 0;
	int ch;
	while((ch = getopt(argc, argv, "ne")) != -1) {
		switch(ch) {
			case 'n':
				flag1 = 1;
				break;
			case 'e':
				flag2 = 1;
				break;
		}		
	}
	argc -= optind;
	argv += optind;

	FILE *fptr;
	if(argc) {
		if (flag1 == 0 && flag2 == 0)
		{
			// No flag is passed
			fptr = fopen(argv[0], "r");
			if (fptr == NULL)
				{
					printf("ERROR: File does not exist\n");
				}
			char c;
			fseek(fptr,0,SEEK_SET);
			if (fptr) 
			{
		    while ((c = getc(fptr)) != EOF)
		    {
		        putchar(c);
		    }
		    fclose(fptr);
			}
		
		}
		else if(flag1 == 1 && flag2 == 0) {
			// Number of lines
			int numLines = 1;
			fptr = fopen(argv[0], "r");
			if (fptr == NULL)
				{
					printf("ERROR: File does not exist\n");
				}
			char c;
			fseek(fptr,0,SEEK_SET);
			if (fptr) 
			{
				printf("%d ", numLines);
			    while ((c = getc(fptr)) != EOF)
			    {
			    	if(c == '\n') {
			    		numLines++;
			    		printf("%c", c);
			    		printf("%d ", numLines);
			    	}
			    	else {
			    		printf("%c", c);
			    	}
			    }
			    fclose(fptr);
			}
		}
		else if (flag1 == 0 && flag2 == 1) {
			// Add a dollar sign
			fptr = fopen(argv[0], "r");
			if (fptr == NULL)
				{
					printf("ERROR: File does not exist\n");
				}
			char c;
			fseek(fptr,0,SEEK_SET);
			if (fptr) 
			{
		    while ((c = getc(fptr)) != EOF)
		    {
		    	if(c == '\n') {
		    		printf("$");
		    	}
		        printf("%c", c);
		    }
		    fclose(fptr);
			}
		}
		else {
			// Add both the flags
			int numLines = 1;
			fptr = fopen(argv[0], "r");
			if (fptr == NULL)
				{
					printf("ERROR: File does not exist\n");
				}
			char c;
			fseek(fptr,0,SEEK_SET);
			if (fptr) 
			{
				printf("%d ", numLines);
			    while ((c = getc(fptr)) != EOF)
			    {
			    	if(c == '\n') {
			    		numLines++;
			    		printf("$");
			    		printf("%c", c);
			    		printf("%d ", numLines);
			    	}
			    	else {
			    		printf("%c", c);
			    	}
			    }
			    fclose(fptr);
			}
		}
	}
	else {
		printf("Print Error. No file mentioned\n");
	}
	return 0;
}
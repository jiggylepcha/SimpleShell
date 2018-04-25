#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define DELIMITER " "

int main (void)
{
	char PATH[500];
	getcwd(PATH,500);
	strcat(PATH,"/");
	//printf("%s\n", PATH);
	while (1)
	{
		int historyCounter = 0;
		char pwd [1024];

		getcwd(pwd, sizeof(pwd));
		printf("ush: %s$ ", pwd);

		char command[1000];

		fgets(command,1000,stdin);
		command[strlen(command) - 1] = '\0';
		//printf("%s\n", line [1]);

		// for(int i = 0; i < 5; i++)
		// {
		// 	printf("%s\n", line[i]);
		// }

		//printf("%s\n", line [1]);

		FILE *fptr;
		fptr = fopen("/Users/jiggylepcha/Desktop/IIITD/Sem 4/OS/Assignment/Assignment 0/history.txt", "a+");
		if (fptr == NULL)
		{
			printf("ERROR: Null value\n");
			break;
		}
		
		if (strncmp(command, "exit", 4) == 0)
		{
			char tcmd [10];
			//puts (line[0]);
			strncpy(tcmd, command, 4);
			fprintf(fptr, "%s\n", tcmd);
			fclose(fptr);
			break;
		}
		else if (strncmp(command, "pwd", 3) == 0)
		{
			//printf("%s\n", line[0]);
			//puts (line[0]);
			char tcmd [10];
			strncpy(tcmd, command, 3);
			//printf("%s\n", tcmd);
			fprintf(fptr, "%s\n", tcmd);
			fclose(fptr);
			if(getcwd(pwd, sizeof(pwd)) != NULL)
			{
				printf("%s\n", pwd);
			}
			else
			{
				printf("Error\n");
			}
			continue;
			
		}
		else if (strncmp(command, "history", 7) == 0)
		{
			char tcmd [10];
			strncpy(tcmd, command, 7);
			fprintf(fptr, "%s\n", tcmd);
			// char c = fgetc(fptr);
			// while(c != EOF)
			// {
			// 	printf("%c", c);
			// 	c = fgetc(fptr);
			// }
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
			continue;

		}
		else if (strncmp(command, "echo", 4) == 0)
		{
			char tcmd [10];
			strncpy(tcmd, command, 4);
			fprintf(fptr, "%s\n", tcmd);
			fclose(fptr);
			//printf("jihfiehihe  %s\n", line[1]);
			int flag1 = 0; //-n
			int flag2 = 0; //-e
			char word[1000];
			
			if ((strncmp(command, "echo -nE ",8) == 0) || (strncmp(command,"echo -En ",8) == 0) || (strncmp(command, "echo -n -E",10) == 0) || (strncmp(command, "echo -e -n",10) == 0))
			{
				flag1 = 1;
				flag2 = 1;
				strcpy(word,&command[9]);
			}
			else if (strncmp(command,"echo -n ",7) == 0){
				flag1 = 1;
				strcpy(word,&command[8]);
				printf("%s", word);
			}
			else if (strncmp(command,"echo -E ",7) == 0){
				flag2 = 1;
				strcpy(word,&command[8]);
				printf("%s\n",word );
			}
			else{
				strcpy(word,&command[5]);
				printf("%s\n",word );
			}
			continue;
		}
		else if (strncmp(command, "cd", 2) == 0)
		{
			//printf("_____\n");
			char tcmd [10];
			strncpy(tcmd, command, 2);
			fprintf(fptr, "%s\n", tcmd);
			fclose(fptr);
			char word[1000];
			strcpy(word,&command[3]);
			//printf("%s\n", word);
			int status = chdir(word);
			if(status != 0)
			{
				printf("No such directory exists\n");
			}
			continue;
		}
		else if (strncmp(command, "cat", 3) == 0 )
		{
			char tcmd [10];
			strncpy(tcmd, command, 3);
			//printf("%s\n", tcmd);
			// pid_t pid = fork();
			// if (pid == -1)
			// {
			// 	printf("Error. Cannot fork\n");
			// }
			// else if (pid == 0)
			// {
			// 	char execpath[500];
			// 	strcpy(execpath,PATH);
			// 	strcat(execpath,line[0]);
			// 	execv(execpath,line);
			// }
			continue;
		}
		//printf("%s\n", line[0]);
		else {
			printf("No such command exists.\n");
		}
	}
	return 0;
}
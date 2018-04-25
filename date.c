#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[])
{
	int flag1 = 0;
	int flag2 = 0;
	int ch;
	while ((ch = getopt(argc, argv, "uR")) != -1) {
		switch(ch){
			case 'u':
				flag1 = 1;
				break;
			case 'R':
				flag2 = 1;
				break;
		}
	}
	if (flag1 == 0 && flag2 == 0) {
		time_t t = time(NULL);
		struct tm *formatTime = localtime(&t);
		char temp [50];
		strftime(temp, 50, "%c", formatTime);
		printf("%s IST\n",temp);
		//printf("now: %d-%d-%d %d:%d:%d\n", lt.tm_year + 1900, lt.tm_mon + 1, lt.tm_mday, lt.tm_hour, lt.tm_min, lt.tm_sec);
	}
	else if (flag1 == 0 && flag2 == 1) {
		// R is passed
		time_t t = time(NULL);
		struct tm *formatTime = localtime(&t);
		char temp [50];
		strftime(temp, 50, "%c", formatTime);
		printf("%s +0530\n",temp);

	}
	else if (flag1 == 1 && flag2 == 0) {
		// u is a added
		time_t t = time(NULL);
		struct tm *formatTime = gmtime(&t);
		char temp [50];
		strftime(temp, 50, "%c", formatTime);
		printf("%s GMT\n",temp);
	}
	else {
		// Both the flags are passed
		time_t t = time(NULL);
		struct tm *formatTime = gmtime(&t);
		char temp [50];
		strftime(temp, 50, "%c", formatTime);
		printf("%s +0000\n",temp);
	}
	return 0;
}
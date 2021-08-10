#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ARGS_LEN 256
//#define PROG_LEN 64
#define PROG_NUM 3

int echo(int countIn, char *argsIn[]) {
}

int helloworld(int countIn, char *argsIn[]) {
	printf("HelloWorld!!!\n");
	return 0;
}

int lazybox(int countIn, char *argsIn[]) {
	printf("LazyBox\n");
	printf("Usage: lazybox [command] [args]\n");
}

int wip() {
	printf("WIP\n");
	return 1;
}

int resolver(int countIn, char *argsIn[]) {
	
	char progs[PROG_NUM][PROG_LEN] = {
		"lazybox",
		"helloworld",
		"echo",
		};

	int progid = 0;		
	for(int i=0; i<PROG_NUM; i++) {
		if (strcmp(progs[i], argsIn[0])) {
			progid = i;
		}
	}

	switch(progid) {
		case 2:
			return echo(countIn, argsIn);
		case 1:
			return helloworld(countIn, argsIn);
		case 0:
		default:
			return lazybox(countIn, argsIn);
	}
	return wip();
}

int main(int countIn, char *argsIn[]) {
	//wip
	char *binary;
	char *token = strtok(argsIn[0],'\');
	while(token != NULL) {
		strcpy(binary, token)
		token = strtok(NULL,'\');
	}
	//wip

	if((strcmp(binary,"lazybox") == 0)) {
		printf("%s",argsIn[0]);
		int count=countIn-1;
		char *args[count];
		for(int i=0; i<count; i++) {
			strcpy(args[i],argsIn[i+1]);
		}
		return resolver(count, args);
	}

	return resolver(countIn, argsIn);
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ARGS_LEN 256
#define PROG_LEN 64
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
		if (strcmp(progs[i], argsIn[0]) == 0) {
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

	//find size of binary string
	int size=0;
	while(argsIn[0][size] != '\0') {
		size=size+1;
	}
	size=size+1;

	//removes leading garbage from binary name
	char binary[size];
	char *token = strtok(argsIn[0], "/");
	while(token != NULL) {
		strcpy(binary, token);
		token = strtok(NULL, "/");
	}

	//clears the trailing characters after null terminator 
	//hi0llo becomes hi0000 etc
	int i = 0;
	while(argsIn[0][i] != '\0') {
		argsIn[0][i] = '\0';
		i=i+1;
	}
	
	//moves new string into args
	strcpy(argsIn[0], binary);

	printf("wub");
	printf("Running %s\n", argsIn[0]);

	//lazybox mode
	if((strcmp(argsIn[0], "lazybox") == 0)) {
		printf("%s", argsIn[0]);
		int count=countIn-1;
		char *args[count];
		for(int i=0; i<count; i++) {
			strcpy(args[i], argsIn[i+1]);
		}
		return resolver(count, args);
	}
	
	//link mode
	return resolver(countIn, argsIn);
}

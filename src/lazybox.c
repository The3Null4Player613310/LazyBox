#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PROG_LEN 64
#define PROG_NUM 2

int helloworld() {
	printf("HelloWorld!!!\n");
	return 0;
}

int lazybox() {
	printf("LazyBox\n");
	printf("Usage: lazybox [command] [args]\n");
}

int wip() {
	printf("WIP");
	return 1;
}

int resolver(int count, char *args[]) {
	
	char progs[PROG_NUM][PROG_LEN] = {
		"lazybox",
		"helloworld",
		};

	int progid = 0;		
	for(int i=0; i<PROG_NUM; i++) {
		if (strcmp(progs[i], args[0])) {
			progid = i;
		}
	}

	switch(progid) {
		case 1:
			return helloworld();
		case 0:
		default:
			return lazybox();
	}
	return wip();
}

int main(int countIn, char *argsIn[]) {
	if(strcmp(argsIn[0],"lazybox")) {
		//wip
		return wip();
		int count=countIn-1;
		return resolver(count, argsIn);
		//wip
	}
	return resolver(countIn, argsIn);
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int helloworld() {
	printf("HelloWorld!!!\n");
	return 0;
}

int resolver(int count, char *args[]) {
	//wip
	return helloworld();
	//wip
	return 0;
}

int main(int countIn, char *argsIn[]) {
	if(strcmp(argsIn[0],"lazybox")) {
		//wip
		return helloworld();
		int count=countIn-1;
		return resolver(count, argsIn);
		//wip
	}
	return resolver(countIn, argsIn);
}

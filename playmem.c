#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
	int i, loops = 1000, sz = 128*1024;
	char * ptr = NULL;
	char * options = "";

	if(argc > 1){
		loops = atoi(argv[1]);
	}
	if(argc>2) {
		options = argv[2];
	}
	
	printf("Loop %d times of malloc %s\n", loops, options);

	for(i = 0; i<loops; i++) {
		ptr = (char*)malloc(sz);
		if(ptr == NULL) {
			printf("oom error");
			return -1;
		}
		if(strstr(options, "noset") == 0)
			memset(ptr, 0, sz);

		// use the buffer
		//
		if(strstr(options, "nofree") == 0)
			free(ptr);
	}

	return *ptr;
}


// filebug.c 
#include <stdio.h>
#include <stdlib.h>

// program entry point
int main(int argc, char **argv) {
	int i, n, use_flush = 1;
	const char *usage = "usage: filebug f[ast]|s[low] flie n\n";
	char *filename;
	FILE *fp;
	char c;

	if(argc != 4) {
		fprintf(stderr, usage);
		return 1;
	}

	if(argv[1][0] == 'f')
		use_flush = 0;
	
	filename = argv[2];

	n = atoi(argv[3]);
	if(n<0) {
		fprintf(stderr, usage);
		return 2;
	}

	if(!(fp = fopen(filename, "w"))) {
		fprintf(stderr, "can not open file '%s' for writer\n", filename);
		return 3;
	}

	// write n characters to file, to observe effect of fflush()
	for(i=0; i<n; i++) {
		c = 'a' + (i % 256);
		fputc(c, fp);
		if(use_flush)
			fflush(fp);
	}
	fclose(fp);
	return 0;
}

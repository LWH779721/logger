#include <stdio.h>
#include <stdint.h>

//#include "mtimeStamp.h"

char *output_file_generate_filename(char *logdir, char *prefix)
{
}

FILE * output_file_new(char *fname, uint32_t fsize)
{
	FILE *fp = NULL;
	char end = 0;
	
	if (NULL == (fp = fopen(fname, "wb+")))
	{
		printf("failed when fopen\n");
		return -1;
	}
	
	setbuf(fp, NULL);
	
	fseek(fp, fsize, SEEK_SET);
	fwrite(&end, 1, sizeof(end), fp);
	fdatasync(fileno(fp));
	fseek(fp, 0L, SEEK_SET);
	
	return fp;
}

int output_file_append(FILE *fp, const char *log)
{
	int ret = 0;
	
	ret = fprintf(fp, "%s", log);
	fdatasync(fileno(fp));
	
	return ret;
}

int output_file_end(FILE *fp)
{
	fclose(fp);
	return 0;
}
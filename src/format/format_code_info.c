#include <stdio.h>
#include <string.h>

char *format_code_info_file_basename(const char *fname)
{ 
	char *ret = NULL;

	ret = strrchr(fname, '/');
	if (ret)
	{
		return ret + 1;
	}
	
	return fname;
}

char *format_code_info_file_rootname(const char *fname, const char *root)
{
	
	return 0;			
}
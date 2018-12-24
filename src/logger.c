#include <stdio.h>
#include <time.h>
#include <sys/timeb.h>
#include <stdarg.h>

long mlog_set_logfile(char *file)
{
    FILE *fp;
    
    if (NULL == (fp = freopen(file, "w", stdout)))
    {
        printf ("failed when reopen stdout");
        return -1;
    }
    
    return 0;
}
#if 0
int logger_err(char *sparam, ...)
{
	char buf[200];
	va_list list;
	
	va_start(list, sparam);
     
	strcpy(buf, "err:");
	strcat(buf, sparam);
	strcat(buf, "\n");
	vfprintf(stderr, buf, list); 
	va_end(list);
	
	return 0;
}
#endif
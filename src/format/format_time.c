#include <stdio.h>
#include <time.h>
#include <sys/timeb.h> 

char *format_time_local_time(char *buf)
{
	struct tm *ptm;  
    struct timeb stTimeb;  
	int ret = 0;
    
    ftime(&stTimeb);  
    ptm = localtime(&stTimeb.time);  
    ret = sprintf(buf, "%04d-%02d-%02d %02d:%02d:%02d.%03d",  
                ptm->tm_year+1900, ptm->tm_mon+1, ptm->tm_mday, ptm->tm_hour, ptm->tm_min, ptm->tm_sec, stTimeb.millitm);
    
	return buf + ret + 1; 	
}
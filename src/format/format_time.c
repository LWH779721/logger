#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <sys/time.h>
#include <sys/timeb.h> 
#include <inttypes.h>

char *format_time_local_time(void)  
{  
    struct tm *ptm;  
    struct timeb stTimeb;  
    static char szTime[24];
    
    ftime(&stTimeb);  
    ptm = localtime(&stTimeb.time);  
    sprintf(szTime, "%04d-%02d-%02d %02d:%02d:%02d.%03d",  
                ptm->tm_year+1900, ptm->tm_mon+1, ptm->tm_mday, ptm->tm_hour, ptm->tm_min, ptm->tm_sec, stTimeb.millitm);
    
	return szTime;  
} 

char *format_time_timeStamp(void)  
{   
	uint64_t timestamp;
    struct timeval current;
	static char szTime[24];
    
    gettimeofday(&current, NULL);
    timestamp = (uint64_t)current.tv_sec * 1000 * 1000 + (uint64_t)current.tv_usec; 
    sprintf(szTime, "%"PRIu64"",  
                timestamp);
    
	return szTime;  
} 
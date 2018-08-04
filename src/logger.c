#include <stdio.h>
#include <time.h>
#include <sys/timeb.h>

/* -------------- private header-------------------------*/
#include "logger.h"

char *mlog_time(void)  
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

long mlog_set_logfile(char *file)
{
    FILE *fp;
    
    if (NULL == (fp = freopen(file, "w", stdout)))
    {
        mlog_err ("failed when reopen stdout");
        return -1;
    }
    
    return 0;
}
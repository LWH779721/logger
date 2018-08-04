#ifndef __MLOG_H__
#define __MLOG_H__

#ifdef __Cplusplus
extern "C"{
#endif

#define DEBUG_LEVEL 3

#ifdef DEBUG_LEVEL

#if DEBUG_LEVEL == 1

#define mlog_err(sparam,arg...) \
do {\
    printf("[%s %s:%d %s] err:"sparam"\n", mlog_time(), __FILE__, __LINE__, __FUNCTION__, ##arg);\
}while(0);
#define mlog_warm(sparam,arg...)
#define mlog_info(sparam,arg...)

#elif DEBUG_LEVEL == 2

#define mlog_err(sparam,arg...) \
do {\
    printf("[%s %s:%d %s] err:"sparam"\n", mlog_time(), __FILE__, __LINE__, __FUNCTION__, ##arg);\
}while(0);
#define mlog_warm(sparam,arg...)\
do {\
    printf("[%s %s:%d %s] warm:"sparam"\n", mlog_time(), __FILE__, __LINE__, __FUNCTION__, ##arg);\
}while(0);

#define mlog_info(sparam,arg...)

#elif DEBUG_LEVEL == 3

#define mlog_err(sparam,arg...) \
do {\
    printf("[%s %s:%d %s] err:"sparam"\n", mlog_time(), __FILE__, __LINE__, __FUNCTION__, ##arg);\
}while(0);
#define mlog_warm(sparam,arg...)\
do {\
    printf("[%s %s:%d %s] warm:"sparam"\n", mlog_time(), __FILE__, __LINE__, __FUNCTION__, ##arg);\
}while(0);
#define mlog_info(sparam,arg...)\
do {\
    printf("[%s %s:%d %s] info:"sparam"\n", mlog_time(), __FILE__, __LINE__, __FUNCTION__, ##arg);\
}while(0);
#endif
#endif

extern long mlog_set_logfile(char *file);

#ifdef __Cplusplus
}
#endif
#endif
#ifndef __LOGGER_H__
#define __LOGGER_H__

#ifdef __cplusplus
extern "C"{
#endif

#include "logger_level.h"
#include "format/format_time.h"
#include "format/format_code_info.h"

#ifndef LOGGER_COMPILE_LEVEL
#define LOGGER_COMPILE_LEVEL ALL
#pragma message("使用默认打印等级 ALL")
#endif

#define logger(LEVEL, sparam, arg...)\
do{\
	logger_##LEVEL(sparam, ##arg);\
} while(0);

#if LOGGER_COMPILE_LEVEL >= ERROR
	#define logger_err(sparam, arg...) \
		do {\
			fprintf(stderr, "[E %s %s:%s.%d]"sparam"\n", format_time_timeStamp(), format_code_info_file_basename(__FILE__), __FUNCTION__, __LINE__, ##arg);\
		}while(0);
#else
	#define logger_err(sparam,arg...)	
#endif

#if LOGGER_COMPILE_LEVEL >= WARM
	#define logger_warm(sparam,arg...) \
		do {\
			printf("[W %s %s:%s.%d] warm:"sparam"\n", format_time_timeStamp(), format_code_info_file_basename(__FILE__), __FUNCTION__, __LINE__, ##arg);\
		}while(0);
#else
	#define logger_warm(sparam,arg...)	
#endif

#if LOGGER_COMPILE_LEVEL >= DEBUG
	#define logger_debug(sparam,arg...) \
		do {\
			printf("[D %s %s:%s.%d] debug:"sparam"\n", format_time_timeStamp(), format_code_info_file_basename(__FILE__), __FUNCTION__, __LINE__, ##arg);\
		}while(0);
#else
	#define logger_debug(sparam,arg...)	
#endif

#if LOGGER_COMPILE_LEVEL >= INFO
	#define logger_info(sparam,arg...) \
		do {\
			printf("[I %s %s:%s.%d]"sparam"\n", format_time_timeStamp(), format_code_info_file_basename(__FILE__), __FUNCTION__, __LINE__, ##arg);\
		}while(0);
#else
	#define logger_info(sparam,arg...)	
#endif

#ifdef __cplusplus
}
#endif
#endif
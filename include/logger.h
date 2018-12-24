#ifndef __LOGGER_H__
#define __LOGGER_H__

#ifdef __cplusplus
extern "C"{
#endif

#include "format/format_time.h"
#include "format/format_code_info.h"
//#include "output/output_file.h"

#define logger(LEVEL, sparam, arg...)\
do{\
	logger_##LEVEL(sparam, ##arg);\
} while(0);

#ifdef LOGGER_COMPILE_LEVEL
	#if LOGGER_COMPILE_LEVEL >= ERR
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
#endif

#ifdef __cplusplus
}
#endif
#endif
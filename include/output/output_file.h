#ifndef __OUTPUT_FILE_H__
#define __OUTPUT_FILE_H__

#ifdef __Cplusplus
extern "C"{
#endif

#include <stdint.h>

extern FILE * output_file_new(char *fname, uint32_t fsize);

#ifdef __Cplusplus
}
#endif
#endif
source = mlog.c mlog.h
test_source = mlog_test.c

LDFLAGS = -fPIC -shared
output_lib = libmlog.so

output = mlog
cflag_debug = -g -Ddebug
output_debug = mlog.debug
lib_flags = -lmlog
cflag_release = -o2
output_release = mlog
cc = gcc 

SRCS = $(wildcard *.c)
OBJS = $(patsubst %c, %o, $(SRCS))
CCFLAGS = -g -Wall -O2

ALL:$(output_lib) $(output_debug) $(output_release)
	@echo $(SRCS) 
	@echo $(OBJS)
        
$(output_debug):$(output_lib)
	$(cc) $(test_source) $(cflag_debug) $(lib_flags) -o $(output_debug)
    
$(output_release):$(output_lib) 
	$(cc) $(test_source) $(cflag_release) $(lib_flags) -o $(output_release) 
    
$(output_lib):$(OBJS)
	$(cc) $(OBJS) $(LDFLAGS) -o $(output_lib)
#	-mkdir /usr/local/include/$(output)
#	-cp *.h /usr/local/include/$(output)/
#	-mv $(output_lib) /usr/local/lib/ 

libmlog.a:$(OBJS)
    ar cr libmlog.a mlog.o

%.o:%.c
	$(cc) $(CCFLAGS) -c $<
   
.PHONY: clean
clean:
	@rm -rf *.o $(output_debug) $(output_release) $(output_lib)   

###########################################################################
## Makefile generated for component 'Fmask'. 
## 
## Makefile     : Fmask_rtw.mk
## Generated on : Tue Nov 07 17:08:40 2023
## Final product: ./Fmask.a
## Product type : static-library
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# MODELLIB                Static library target

PRODUCT_NAME              = Fmask
MAKEFILE                  = Fmask_rtw.mk
MATLAB_ROOT               = /home/sergio/Programs/MATLAB/R2023b
MATLAB_BIN                = /home/sergio/Programs/MATLAB/R2023b/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/glnxa64
START_DIR                 = /home/sergio/Desktop/Estudios/TFG/FMaskInC/Fmask
TGT_FCN_LIB               = ISO_C
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 
RELATIVE_PATH_TO_ANCHOR   = ../../..
C_STANDARD_OPTS           = -fwrapv
CPP_STANDARD_OPTS         = -fwrapv
MODELLIB                  = Fmask.a

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          GNU gcc/g++ | gmake (64-bit Linux)
# Supported Version(s):    
# ToolchainInfo Version:   2023b
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# C_STANDARD_OPTS
# CPP_STANDARD_OPTS

#-----------
# MACROS
#-----------

WARN_FLAGS         = -Wall -W -Wwrite-strings -Winline -Wstrict-prototypes -Wnested-externs -Wpointer-arith -Wcast-align
WARN_FLAGS_MAX     = $(WARN_FLAGS) -Wcast-qual -Wshadow
CPP_WARN_FLAGS     = -Wall -W -Wwrite-strings -Winline -Wpointer-arith -Wcast-align
CPP_WARN_FLAGS_MAX = $(CPP_WARN_FLAGS) -Wcast-qual -Wshadow

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = 

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: GNU C Compiler
CC = gcc

# Linker: GNU Linker
LD = g++

# C++ Compiler: GNU C++ Compiler
CPP = g++

# C++ Linker: GNU C++ Linker
CPP_LD = g++

# Archiver: GNU Archiver
AR = ar

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%/bin/glnxa64
MAKE = "$(MAKE_PATH)/gmake"


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @rm -f
ECHO                = @echo
MV                  = @mv
RUN                 =

#--------------------------------------
# "Faster Runs" Build Configuration
#--------------------------------------

ARFLAGS              = ruvs
CFLAGS               = -c $(C_STANDARD_OPTS) -fPIC \
                       -O3 -fno-loop-optimize -fno-aggressive-loop-optimizations
CPPFLAGS             = -c $(CPP_STANDARD_OPTS) -fPIC \
                       -O3 -fno-loop-optimize -fno-aggressive-loop-optimizations
CPP_LDFLAGS          =
CPP_SHAREDLIB_LDFLAGS  = -shared -Wl,--no-undefined
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              =
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = -shared -Wl,--no-undefined



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = ./Fmask.a
PRODUCT_TYPE = "static-library"
BUILD_TYPE = "Static Library"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR)/codegen/lib/Fmask -I$(START_DIR) -I$(MATLAB_ROOT)/extern/include

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_CUSTOM = 
DEFINES_STANDARD = -DMODEL=Fmask

DEFINES = $(DEFINES_CUSTOM) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/coder_posix_time.c $(START_DIR)/Fmask_data.c $(START_DIR)/Fmask_initialize.c $(START_DIR)/Fmask_terminate.c $(START_DIR)/Fmask.c $(START_DIR)/tic.c $(START_DIR)/timeKeeper.c $(START_DIR)/nd2toarbt.c $(START_DIR)/pixel2pixv.c $(START_DIR)/prctile.c $(START_DIR)/sortIdx.c $(START_DIR)/ixfun.c $(START_DIR)/padarray.c $(START_DIR)/fcssm.c $(START_DIR)/sum.c $(START_DIR)/find.c $(START_DIR)/minOrMax.c $(START_DIR)/bwlabel.c $(START_DIR)/regionprops.c $(START_DIR)/horzcatStructList.c $(START_DIR)/ismember.c $(START_DIR)/strel.c $(START_DIR)/imdilate.c $(START_DIR)/morphop.c $(START_DIR)/toc.c $(START_DIR)/CoderTimeAPI.c $(START_DIR)/imfill.c $(START_DIR)/sort.c $(START_DIR)/flip.c $(START_DIR)/plcloud.c $(START_DIR)/div.c $(START_DIR)/Fmask_emxutil.c $(START_DIR)/Fmask_emxAPI.c $(START_DIR)/Fmask_rtwutil.c

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = coder_posix_time.o Fmask_data.o Fmask_initialize.o Fmask_terminate.o Fmask.o tic.o timeKeeper.o nd2toarbt.o pixel2pixv.o prctile.o sortIdx.o ixfun.o padarray.o fcssm.o sum.o find.o minOrMax.o bwlabel.o regionprops.o horzcatStructList.o ismember.o strel.o imdilate.o morphop.o toc.o CoderTimeAPI.o imfill.o sort.o flip.o plcloud.o div.o Fmask_emxutil.o Fmask_emxAPI.o Fmask_rtwutil.o

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = 

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS =  -L"$(MATLAB_ROOT)/bin/glnxa64" -L"$(MATLAB_ROOT)/sys/os/glnxa64" -lmwippreconstruct -lmwipp -lmwbwpackctbb -lmwmorphop_packed -lmwnhood -lmwmorphop_ipp -lmwmorphop_nonflat_tbb -lmwmorphop_nonflat -lmwmorphop_flat_tbb -lmwmorphop_flat -lm -liomp5

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_OPTS = -fopenmp
CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_OPTS) $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_OPTS = -fopenmp
CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CPPFLAGS += $(CPPFLAGS_OPTS) $(CPPFLAGS_BASIC)

###########################################################################
## INLINED COMMANDS
###########################################################################

###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build clean info prebuild download execute


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


prebuild : 


download : $(PRODUCT)


execute : download


###########################################################################
## FINAL TARGET
###########################################################################

#---------------------------------
# Create a static library         
#---------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS)
	@echo "### Creating static library "$(PRODUCT)" ..."
	$(AR) $(ARFLAGS)  $(PRODUCT) $(OBJS)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.o : %.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : %.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/codegen/lib/Fmask/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/codegen/lib/Fmask/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/codegen/lib/Fmask/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/codegen/lib/Fmask/%.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/codegen/lib/Fmask/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/codegen/lib/Fmask/%.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/codegen/lib/Fmask/%.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


coder_posix_time.o : $(START_DIR)/coder_posix_time.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Fmask_data.o : $(START_DIR)/Fmask_data.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Fmask_initialize.o : $(START_DIR)/Fmask_initialize.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Fmask_terminate.o : $(START_DIR)/Fmask_terminate.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Fmask.o : $(START_DIR)/Fmask.c
	$(CC) $(CFLAGS) -o "$@" "$<"


tic.o : $(START_DIR)/tic.c
	$(CC) $(CFLAGS) -o "$@" "$<"


timeKeeper.o : $(START_DIR)/timeKeeper.c
	$(CC) $(CFLAGS) -o "$@" "$<"


nd2toarbt.o : $(START_DIR)/nd2toarbt.c
	$(CC) $(CFLAGS) -o "$@" "$<"


pixel2pixv.o : $(START_DIR)/pixel2pixv.c
	$(CC) $(CFLAGS) -o "$@" "$<"


prctile.o : $(START_DIR)/prctile.c
	$(CC) $(CFLAGS) -o "$@" "$<"


sortIdx.o : $(START_DIR)/sortIdx.c
	$(CC) $(CFLAGS) -o "$@" "$<"


ixfun.o : $(START_DIR)/ixfun.c
	$(CC) $(CFLAGS) -o "$@" "$<"


padarray.o : $(START_DIR)/padarray.c
	$(CC) $(CFLAGS) -o "$@" "$<"


fcssm.o : $(START_DIR)/fcssm.c
	$(CC) $(CFLAGS) -o "$@" "$<"


sum.o : $(START_DIR)/sum.c
	$(CC) $(CFLAGS) -o "$@" "$<"


find.o : $(START_DIR)/find.c
	$(CC) $(CFLAGS) -o "$@" "$<"


minOrMax.o : $(START_DIR)/minOrMax.c
	$(CC) $(CFLAGS) -o "$@" "$<"


bwlabel.o : $(START_DIR)/bwlabel.c
	$(CC) $(CFLAGS) -o "$@" "$<"


regionprops.o : $(START_DIR)/regionprops.c
	$(CC) $(CFLAGS) -o "$@" "$<"


horzcatStructList.o : $(START_DIR)/horzcatStructList.c
	$(CC) $(CFLAGS) -o "$@" "$<"


ismember.o : $(START_DIR)/ismember.c
	$(CC) $(CFLAGS) -o "$@" "$<"


strel.o : $(START_DIR)/strel.c
	$(CC) $(CFLAGS) -o "$@" "$<"


imdilate.o : $(START_DIR)/imdilate.c
	$(CC) $(CFLAGS) -o "$@" "$<"


morphop.o : $(START_DIR)/morphop.c
	$(CC) $(CFLAGS) -o "$@" "$<"


toc.o : $(START_DIR)/toc.c
	$(CC) $(CFLAGS) -o "$@" "$<"


CoderTimeAPI.o : $(START_DIR)/CoderTimeAPI.c
	$(CC) $(CFLAGS) -o "$@" "$<"


imfill.o : $(START_DIR)/imfill.c
	$(CC) $(CFLAGS) -o "$@" "$<"


sort.o : $(START_DIR)/sort.c
	$(CC) $(CFLAGS) -o "$@" "$<"


flip.o : $(START_DIR)/flip.c
	$(CC) $(CFLAGS) -o "$@" "$<"


plcloud.o : $(START_DIR)/plcloud.c
	$(CC) $(CFLAGS) -o "$@" "$<"


div.o : $(START_DIR)/div.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Fmask_emxutil.o : $(START_DIR)/Fmask_emxutil.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Fmask_emxAPI.o : $(START_DIR)/Fmask_emxAPI.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Fmask_rtwutil.o : $(START_DIR)/Fmask_rtwutil.c
	$(CC) $(CFLAGS) -o "$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files ..."
	$(RM) $(PRODUCT)
	$(RM) $(ALL_OBJS)
	$(ECHO) "### Deleted all derived files."
	
main :
	gcc -c main.c $(SRCS)



# Makefile for jam

CC = cc
TARGET = -o jam0
CFLAGS = 

# Special flavors - uncomment appropriate lines

# Solaris 2.0 seem not to have any identifying cpp symbol
#CFLAGS = -Dsolaris

# AIX needs -lbsd, and has no identifying cpp symbol
# Use _AIX41 if you're not on 3.2 anymore.
#LINKLIBS = -lbsd
#CFLAGS = -D_AIX
#CFLAGS = -D_AIX41

# NT (with Microsoft compiler)
# Use FATFS if building on a DOS FAT file system
#Lib = $(MSVCNT)/lib
#Include = $(MSVCNT)/include
#CC = cl /nologo
#CFLAGS = -I $(Include) -DNT 
#TARGET = /Fejam0
#LINKLIBS = $(Lib)/kernel32.lib $(Lib)/libc.lib

SOURCES = \
	command.c compile.c execnt.c execunix.c execvms.c expand.c \
	filent.c fileos2.c fileunix.c filevms.c glob.c hash.c \
	headers.c jam.c jambase.c jamgram.c lists.c make.c make1.c \
	newstr.c option.c parse.c pathunix.c pathvms.c regexp.c \
	rules.c scan.c search.c timestamp.c variable.c

all: jam0
	jam0

jam0:
	$(CC) $(TARGET) $(CFLAGS) $(SOURCES) $(LINKLIBS)

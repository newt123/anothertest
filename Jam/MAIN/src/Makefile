# Makefile for jam

# Special flavors - uncomment appropriate lines

# Solaris 2.0 seem not to have any identifying cpp symbol
#CFLAGS = -Dsolaris

# AIX needs -lbsd, and has no identifying cpp symbol
#LINKLIBS = -lbsd
#CFLAGS = -DAIX

install: jam0
	jam0 -f Jambase install

jam0:
	cc $(CFLAGS) *.c -o jam0 $(LINKLIBS)

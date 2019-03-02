
###-------------------------------------------------------------###
###  Program Name :  Makefile					###
###								###
###  Copyrights 						###
###  reserved by Bo-kyun Na (bkna@ecs.syr.edu)			###
###  ----  IntellActive Research Lab. ----			###
###-------------------------------------------------------------###
###  This file contains the information necessary for           ###
###  the compiler and linker to create the object file  	###
###  for library archive in the UNIX.                   	###
###                                                     	###
###-------------------------------------------------------------###
###  USAGE:							###
###  To run a makefile: make -f libvdo.mk 			###
###  To clean:          make -f libvdo.mk clean			###
###-------------------------------------------------------------###

TARGET = dll
TLIB  = libsessman.a

CC = gcc
WDIR = .

CFLAGS = -Wall -I${WDIR}/include 
LDLIBS = -L/usr/X11R6/lib -L${WDIR}/lib 

CFLAGS += -DTEST
LDLIBS += -lm 

#CFLAGS += `gtk-config --cflags gthread`
#LDLIBS += `gtk-config --libs gthread`

SRCS = dll.c 
OBJS = ${SRCS:.c=.o}


### ************************************************************************
all :  ${TARGET} # ${TLIB}
### ************************************************************************
${TLIB} : ${OBJS}
	ar -rv $@ $?
	mv $@ ${WDIR}/lib/

${TARGET} : ${OBJS}
	${CC} ${CFLAGS} -o $@ $? ${LDLIBS}
### ------------------------------------------------------------------------
clean:
	rm -f a.out core *.o $(OBJS)
### ************************************************************************

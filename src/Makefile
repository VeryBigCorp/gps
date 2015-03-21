CC=/usr/bin/g++
AR=/usr/bin/ar
CP=/bin/cp
MKDIR=/bin/mkdir
RM=/bin/rm
CFLAGS=-g3 -Wall -lm
BUILD_DIR=../build
all: init
${CC} ${CFLAGS} -I. -c -o ${BUILD_DIR}/GPS.o gps.cpp
${CC} ${CFLAGS} -I. -c -o ${BUILD_DIR}/Serial.o Serial.cpp
${AR} -rsc ${BUILD_DIR}/libgps_cpp.a ${BUILD_DIR}/GPS.o ${BUILD_DIR}/Serial.o
${CP} *.h ${BUILD_DIR}
@echo
@echo
@echo RUN TESTS SHOULD BE A GOOD IDEA...
@echo
@echo make tests
@echo
@echo
init:
${MKDIR} -p ${BUILD_DIR}
install:
ln -s `pwd`/${BUILD_DIR}/libgps.a /usr/lib/libgps_cpp.a
ln -s `pwd`/${BUILD_DIR}/GPS.h /usr/include/gps_cpp.h
clean:
${RM} ${BUILD_DIR}/*
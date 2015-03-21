// Serial.h

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <inttypes.h>
#include <string.h>

#ifndef __SERIAL_H__
#define __SERIAL_H__

class Serial {

public:
	Serial();
	~Serial();

	bool begin( char * dev = "/dev/ttyAMA0", int nBaud = 9600 );
	bool close( void );

	int readln( void *, int );
	int println( const char *, int );

	bool is_open( void ){ return( m_bOpened ); }

protected:
	bool m_bOpened;

};

#endif

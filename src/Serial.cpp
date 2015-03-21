#include "Serial.h"

int stream = -1;
Serial::Serial(){
	
}

Serial::~Serial(){
	close();
}

// Use constants in termios.h
// 9600  = 0x0000000d
// 57600 = 0x00010001
bool Serial::begin(char *dev, int baud){
	
	stream = open(dev, O_RDWR | O_NOCTTY | O_NDELAY);
	
	if(stream == -1){
		printf("Unable to open serial connection to device %s", dev);
	}
	
	struct termios options;
	tcgetattr(uart0_filestream, &options);
	options.c_cflag = baud | CS8 | CLOCAL | CREAD;
	options.c_iflag = IGNPAR;
	options.c_oflag = 0;
	options.c_lflag = 0;
	tcflush(uart0_filestream, TCIFLUSH);
	tcsetattr(uart0_filestream, TCSANOW, &options);
}

bool Serial::close(){
	close(stream);
}

bool Serial::println(const char *line, int len){
	if(stream != -1){
		char *cp = (char *)malloc((len+1)*sizeof(char));
		strcpy(cp, line);
		cp[len-1] = '\r';
		cp[len] = '\n';
		
		int count = write(stream, cp, len+1);
		free(cp);
		
		return count >= 0;
	} else {
		printf("Stream invalid.");
	}
	return false;
}

bool Serial::readln(char *buf, int len){
	char c;
	char *b = buffer;
	int rx_len = -1;
	while(1) {
		rx_len = read(stream, (void*)(&c), 1);
		
		if(rx_len <= 0){
			sleep(1); // Wait for rx
		} else {
			if(c == '\n'){ // End of line
				*b++ = '\0';
				break;
			}
			*b++ = c;
		}
	}
}
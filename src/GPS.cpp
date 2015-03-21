#include <Serial.h>

int main(){
	Serial s();
	s.begin("/dev/ttyAMA0", 0x00010001);
	
	while(1){
		printf("%s", s.readln());
	}
}

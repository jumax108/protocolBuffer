#include "../headers/protocolBuffer.h"
#pragma comment(lib, "protocolBuffer")

int main(){

	CProtocolBuffer buffer(10);
	buffer << 123;

	int a;
	buffer >> a;

	printf("%d",a);

	return 0;

}
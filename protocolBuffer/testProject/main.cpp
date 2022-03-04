#include <stdio.h>

#include "../headers/protocolbuffer.h"
#pragma comment(lib, "../release/protocolBuffer")

int main(){

	CProtocolBuffer buffer(30);

	buffer << 123;
	buffer << 456;

	int data, data2;
	buffer >> data >> data2;

	printf("%d %d\n",data, data2);
}
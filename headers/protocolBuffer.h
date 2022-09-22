#pragma once

#include <stdio.h>
#include <Windows.h>
#include <time.h>

class CProtocolBuffer {

public:

	CProtocolBuffer(unsigned int size);
   ~CProtocolBuffer();

#pragma region("operator<<")
	CProtocolBuffer& operator<<(char data);
	CProtocolBuffer& operator<<(unsigned char data);
	CProtocolBuffer& operator<<(bool data);

	CProtocolBuffer& operator<<(wchar_t data);
	CProtocolBuffer& operator<<(short data);
	CProtocolBuffer& operator<<(unsigned short data);

	CProtocolBuffer& operator<<(int data);
	CProtocolBuffer& operator<<(unsigned int data);

	CProtocolBuffer& operator<<(__int64 data);
	CProtocolBuffer& operator<<(unsigned __int64 data);

	CProtocolBuffer& operator<<(float data);
	CProtocolBuffer& operator<<(double data);
#pragma endregion

#pragma region("operator>>")
	CProtocolBuffer& operator>>(char& data);
	CProtocolBuffer& operator>>(unsigned char& data);
	CProtocolBuffer& operator>>(bool& data);

	CProtocolBuffer& operator>>(wchar_t& data);
	CProtocolBuffer& operator>>(short& data);
	CProtocolBuffer& operator>>(unsigned short& data);

	CProtocolBuffer& operator>>(int& data);
	CProtocolBuffer& operator>>(unsigned int& data);

	CProtocolBuffer& operator>>(__int64& data);
	CProtocolBuffer& operator>>(unsigned __int64& data);

	CProtocolBuffer& operator>>(float& data);
	CProtocolBuffer& operator>>(double& data);
#pragma endregion

	void putData(unsigned int size, const char* data);
	void putDataW(unsigned int size, const wchar_t* data);
	bool popData(unsigned int size, char* data);
	bool popDataW(unsigned int size, wchar_t* data);

	int getUsedSize();
	int getFreeSize();

	void moveRear(int addValue);
	void moveFront(int addValue);

	void clear();

	inline char* getFrontPtr(){
		return _buffer + _front;
	}
	inline char* getRearPtr(){
		return _buffer + _rear;
	}
	inline char* getBufStart(){
		return _buffer;
	}
	
	inline int getRear() {
		return _rear;
	}
	inline int getFront() {
		return _front;
	}


private:

	void resize(unsigned int cap, bool writeFile = true);

	char* _buffer;
	unsigned int _capacity;
	unsigned int _front;
	unsigned int _rear;

	static int _resizeLogCount;

};
#pragma once;

#include"Filter.h"

class EncodeFilter : Filter {
protected:
	int length;
public:
	EncodeFilter(char*); //has only one constructor because we must have an entered key for the encryption
	void Encode();
};
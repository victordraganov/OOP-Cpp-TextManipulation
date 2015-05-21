#pragma once;

#include"Filter.h"

class DecodeFilter : Filter {
protected:
	int length;
public:
	DecodeFilter(char*); 
	void Decode(char*);
};
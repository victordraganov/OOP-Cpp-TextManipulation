#pragma once;

#include<iostream>
#include<string>
#include<stdio.h>

using namespace std;

static const int MaxSymbolsPerLine = 100; //The number of the symbols of the biggest posible line the buffer can hold.
static const int InitialInputRows = 16; // The initial number of rows of the text buffer when a new Filter is created.
static const int InitialFilterLenght = 20; // 20 isn't the best value but it works

class Filter
{
protected:
	char *filterWord;
	char **text;
	int rowCount;
	int rowCapacity;
	void ResizeInput();
	void ResizeFilter(int);
public:
	Filter();
	Filter(const char*);
	~Filter();
	const Filter& operator=(const Filter&);
	bool operator==(const Filter&) const;
	bool operator!=(const Filter&) const;
	Filter& operator+=(const char);
	Filter& operator+=(const char*);
	//FilterChain& operator|(const Filter);
	void SetFilter(const char*, int);
	void ReadText();
	void FilterAndPrint();
	bool Contains(char*, char*);
	const char* GetName();
};
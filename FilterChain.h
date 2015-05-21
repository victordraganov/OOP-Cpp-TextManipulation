#pragma once

#include "Filter.h"

static const int InitialFilterCount = 4; //Initial count of the filters.

class FilterChain {
private:
	size_t filtersCount;
	size_t filtersCapacity;
	Filter*filters;

	void Resize(); //resizes the filters array
public:
	FilterChain();
	~FilterChain();
	FilterChain& operator=(const FilterChain&);
	bool operator==(const FilterChain &) const;
	bool operator!=(const FilterChain &) const;
	void operator+=(const Filter &);
	void operator-=(const Filter &);
	void ReadBinaryFile(); // reads input from binary file
	void DisplayFilters(); // shows the filers added
	void AddFilter(const Filter&); //adds a new filter
	void RemoveFilter(); //removes filter which
	//void AplyFiltersToText(); //aplies filters to text, filtering the text from lines which don't contain all filter words
};
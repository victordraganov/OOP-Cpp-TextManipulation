#include "FilterChain.h"

FilterChain::FilterChain()
{
	filtersCount = 0;
	filtersCapacity = InitialFilterCount;
	filters = new Filter[InitialFilterCount];
}

FilterChain::~FilterChain()
{
	delete [] filters;
}

FilterChain& FilterChain::operator=(const FilterChain&)
{
	return *this;
}

bool FilterChain::operator==(const FilterChain & other) const
{
	bool equal = false;
	
	for (size_t i = 0; i < other.filtersCount; i++)
	{
		for (size_t j = 0; j < (filtersCount); j++)
		{
			if (other.filters[i].GetName() == filters[j].GetName())
			{
				equal = true;
			}
		}
		if (equal == false)
		{
			return false;
		}
	}
	return equal;
}

bool FilterChain::operator!=(const FilterChain & other) const
{
	return !(*this == other);
}

void FilterChain::operator+=(const Filter & filter)
{
	AddFilter(filter);
}



void FilterChain::DisplayFilters()
{
	if (filtersCount == 0)
	{
		cout << "The filter list is empty!" << endl;
	}
	else
	{
		for (size_t i = 0; i < filtersCount; i++)
		{
			cout << filters[i].GetName() << endl;
		}
	}
}
void FilterChain::ReadBinaryFile()
{
	// TO DO
}

void FilterChain::Resize()
{
	Filter * newList = new Filter[filtersCapacity * 2];
	for (size_t i = 0; i < filtersCount; i++)
	{
		newList[i] = filters[i];
	}
	delete[] filters;
	filters = newList;
}

void FilterChain::AddFilter(const Filter& filter)
{
	if (filtersCapacity == filtersCount)
	{
		Resize();
	}
	filters[filtersCount] = filter;
	++filtersCount;
}
void FilterChain::RemoveFilter()
{
	if (filtersCount > 0)
	{
		delete[] &filters[filtersCount-1];
		filtersCount--;
	}
	else
	{
		cout<< "There are no filters in the chain!"<< endl;
	}
}

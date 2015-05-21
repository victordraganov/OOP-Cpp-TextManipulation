#include "Filter.h"

Filter::Filter() {
	rowCount = 0;
	rowCapacity = InitialInputRows;
	text = new char*[rowCapacity];
	for (int i = 0; i < rowCapacity; i++) {
		text[i] = new char[MaxSymbolsPerLine];
	}
	
	filterWord = new char[InitialFilterLenght]; 
	filterWord[0] = '\0';
}

Filter::Filter(const char* word) : Filter() {
	SetFilter(word, 1);
}

Filter::~Filter() {
	for (int i = 0; i < rowCapacity; i++) {
		delete[] text[i];
	}
	
	delete[] text;
}

const Filter& Filter::operator=(const Filter& filter) {
	return *this;
}

bool Filter::operator==(const Filter& other) const {
	return strcmp(filterWord, other.filterWord);
}

bool Filter::operator!=(const Filter& other) const {
	return !(*this == other);
}

Filter& Filter::operator+=(const char ch) {
	size_t len = strlen(filterWord);
	if (len % InitialFilterLenght == 0) {
		ResizeFilter(1);
	}
	
	filterWord[len] = ch;
	filterWord[len + 1] = '\0';

	return *this;
}

Filter& Filter::operator+=(const char* arr) {
	size_t bothLenght = strlen(filterWord) + strlen(arr);
	size_t newFilterWordLenght = InitialFilterLenght * (bothLenght / InitialFilterLenght);
	if (bothLenght % InitialFilterLenght != 0) {
		newFilterWordLenght += InitialFilterLenght;
	}

	char* newFilterWord = new char[newFilterWordLenght];
	size_t index = 0;
	for (size_t i = index; i < strlen(filterWord); i++) {
		if (filterWord[i] == '\0') {
			break;
		}
		
		newFilterWord[i] = filterWord[i];
		++index;
	}
	
	for (size_t i = 0; i < strlen(arr); i++) {
		if (arr[i] == '\0') {
			break;
		}
		
		newFilterWord[index] = arr[i];
		++index;
	}
	
	newFilterWord[bothLenght] = '\0';
	delete[] filterWord;
	filterWord = newFilterWord;
	return *this;
}

//FilterChain& Filter::operator|(const Filter) {
//
//}

void Filter::SetFilter(const char*word, int resizeIndex) {
	size_t len = strlen(word);
	if (len > InitialFilterLenght * resizeIndex) {
		ResizeFilter(resizeIndex);
		SetFilter(word, resizeIndex + 1);
	}

	for (size_t i = 0; i <= len; i++) {
		filterWord[i] = word[i];
		if (word[i] == '\0') {
			break;
		}
	}
}

void Filter::ReadText() {
	cout << "Enter text: ";
	int rowCounter = 0;
	int symbolCounter = 0;
	char ch;
	cin.get(ch);
	cin.get(ch);
	while (true) {
		if (cin.eof()) {
			break;
		}
		if (rowCounter == rowCapacity) {
			ResizeInput();
		}
		if (ch == '\n' || symbolCounter == MaxSymbolsPerLine) {
			text[rowCounter][symbolCounter] = '\0';
			rowCounter++;
			symbolCounter = 0;
		}
		else {
			text[rowCounter][symbolCounter] = ch;
			symbolCounter++;
		}
		cin.get(ch);
	}
	
	rowCount = rowCounter;
}

void Filter::FilterAndPrint() {
	for (size_t i = 0; i < rowCount; i++) {
		if (Contains(text[i], filterWord) || filterWord[0] == '\0') {
			for (size_t j = 0; text[i][j] != '\0'; j++) {
				cout << text[i][j];
			}
			
			cout << endl;
		}
	}
}

bool Filter::Contains(char*line, char*word) {
	int wordLen = strlen(word);
	bool result = false;
	for (size_t i = 0; i < strlen(line); i++) {
		if (line[i] == word[0]) {
			i++;
			result = true;
			for (size_t j = 1; j < wordLen && word[j] != '\0'; j++) {
				if (line[i] == word[j]) {
					i++;
				}
				else {
					result = false;
					break;
				}
			}
		}
	}
	
	return result;
}

void Filter::ResizeInput() {
	int newCapacity = rowCapacity * 2;
	char** buffer = new char*[newCapacity];

	for (int i = 0; i < newCapacity; i++) {
		buffer[i] = new char[MaxSymbolsPerLine];
		if (i < rowCapacity) {
			int counter = 0;
			while (true) {
				buffer[i][counter] = text[i][counter];
				if (text[i][counter] == '\0') {
					break;
				}
				
				++counter;
			}
			
			delete[] text[i];
			counter = 0;
		}
	}
	
	text = buffer;
	rowCapacity = newCapacity;
}

void Filter::ResizeFilter(int resizeIndex) {
	int len = InitialFilterLenght;
	char* newFilterWord = new char[len*(resizeIndex+1)];
	for (size_t i = 0; i < len; i++) {
		newFilterWord[i] = filterWord[i];
	}
	
	delete[] filterWord;
	filterWord = newFilterWord;
}

const char* Filter::GetName() {
	return filterWord;
}
#include"DecodeFilter.h"

DecodeFilter::DecodeFilter(char* key) : Filter(key){
	length = strlen(filterWord);
}
void DecodeFilter::Decode(char* key) { //We must have the key in order to decrypt text file

	int keyLengthCounter = 0;

	for (size_t i = 0; i < rowCount; i++)
	{
		if (Contains(text[i], filterWord) || filterWord[0] == '\0')
		{
			for (size_t j = 0; text[i][j] != '\0'; j++)
			{
				text[i][j] -= filterWord[keyLengthCounter];
				keyLengthCounter++;
				if (keyLengthCounter == length)
				{
					keyLengthCounter = 0;
				}
			}
		}
	}
}
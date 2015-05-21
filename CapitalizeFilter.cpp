#include"CapitalizeFilter.h"

CapitalizeFilter::CapitalizeFilter() : Filter() {

}

void CapitalizeFilter::Capitalize() {
	bool capitalize = true;
	for (size_t i = 0; i < rowCount; i++) {
		if (Contains(text[i], filterWord) || filterWord[0] == '\0') {
			for (size_t j = 0; text[i][j] != '\0'; j++) {
				if (text[i][j] == ' ') {
					capitalize = true;
				}
				if (capitalize) {
					if (text[i][j] >= 97 && text[i][j] <= 122) {
						text[i][j] += 30;
						capitalize = false;
					}
				}
			}
		}
	}
}
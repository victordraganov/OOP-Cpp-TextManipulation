#include"Filter.h"
#include"FilterChain.h"
#include<iostream>

int main()
{
	cout << "Enter wanted word(max 30 symbols): "; // The Initial filterWord lenght is 20 so you can check that the resize works.
	char word[30];
	cin.getline(word, 30);

 	Filter a(word);
	Filter b(word);

	a += "yyy";
	b = a;
	cout << (a == b);
	/*b += 'a';

	cout << a.GetName() << endl;
	cout << b.GetName() << endl;

	system("pause");
	a.ReadText();*/

	/*FilterChain chain;
	chain.AddFilter(a);
	chain.AddFilter(b);
	chain.DisplayFilters();*/


	//a.FilterAndPrint();
	system("pause");
	
	return 0;
}
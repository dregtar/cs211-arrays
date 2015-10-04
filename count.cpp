#include <string>
#include <cstdio>
#include <iostream>
using namespace std;

/* count digits, white space, others */

/* TODO: (1) fix all errors; 
 *       (2) add code for painting histogram in console,
 *           cf. picture in https://en.wikipedia.org/wiki/Histogram
 * 
 */

void print_column(int n){
	if (n < 10){
		for (int i = 1; i <= n; i += 1)
			cout << "==";
	}
	else {
		for (int i = 1; i <= n && i < 10; i += 1)
			cout << "==";
		for (int i = 10; i <= n; i += 1)
			cout << "===";
	}

	cout << endl;
}
int main()
{
	string src("12 plus 45 minus 39 is 18\n");
	int i, nwhite, nother;
	const int size = 10;
	int ndigit[size]{0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	nwhite = nother = 0;
	i = 0;
	char c;
	while ((c = src[i++]) != '\0')
		if (c >= '0' && c <= '9')
			ndigit[c - '1']+=1;
		else
		  if (c == ' ' || c == '\n' ||c == '\t')
			nwhite+=1;
		  else
			nother+=1;
	
	cout << "source string: " << src << endl << "digits =";
	for (int i = 0; i < size; ++i)
		cout << " " << ndigit[i];
	
	cout << ", white space = " << nwhite 
		 << ", other = " << nother << endl;
	cout << endl;

	cout << "            0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 " << endl;
	cout << "white space ";
	print_column(nwhite);
	cout << "   other    ";
	print_column(nother);

	
	for (i = 1; i < 10; i += 1){
		cout << "     " << i << "      ";
		print_column(ndigit[i - 1]);
	};
}

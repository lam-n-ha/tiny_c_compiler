#include <stdio.h>
#include <string.h>

int main()
{
	char s[80] = "int main() {\nreturn 2;\n}";
	char str[160] = "";
	int i = 0;
	int j = 0;
	while (i < 80) {
		if ((s[i] != '(') && (s[i] != ')') && (s[i] != '{') && (s[i] != '}') && (s[i] != ';')) {
			str[j] = s[i];
			i++;
			j++;
		}
		else {
			str[j] = ' ';
			str[j + 1] = s[i];
			str[j + 2] = ' ';
			j = j + 3;
			i++;
		}
	}
	const char delim[] = " \n";
	char* pre;
	char pret[10][80];
	pre = strtok(str, delim);
	int counter = 0;
	while (pre != NULL) {
		strcpy(pret[counter], pre);
		printf("\n%s", pret[counter]);
		pre = strtok(NULL, delim);
	}
	return 0;
}
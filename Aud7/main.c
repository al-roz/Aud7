#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void nullkol(int* mass)
{
	for (int i = 0; i < 255; i++)
		mass[i] = 0;
}

int main()
{
	char s[256];
	gets_s(s, 255);
	
	int kol[256] = { 0 };
	int ans;
	int maxSize = -1;

	int len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		int j = i;
		int ansSize = 0;
		while (kol[(int)s[j]] != 1 && j < len)
		{
			kol[(int)s[j]]++;
			j++;
			ansSize++;
		}
		if (ansSize > maxSize)
		{
			maxSize = ansSize;
			ansSize = 0;
			ans = i;
		}
		else ansSize = 0;
		nullkol(kol);


	}
	char st[256];
	printf("lenght = %d\n", maxSize);
	for (int i = 0; i < maxSize; i++)
	{
		st[i] = s[i + ans];
	}
	st[maxSize] = 0;
	printf("%s", st);
}

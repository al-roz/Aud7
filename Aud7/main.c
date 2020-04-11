//
//#ifndef UNICODE
//#define UNICODE
//#endif
//#pragma comment(lib, "advapi32.lib")
//#pragma comment(lib, "netapi32.lib")

#include <windows.h>
#include <stdio.h>
#include <assert.h>
#include <lm.h>
#include <sddl.h> 
#include <locale.h>
#include <string.h>
#include <conio.h>

void nullkol(int* mass)
{
	for (int i = 0; i < 255; i++)
		mass[i] = 0;
}

int main()
{
	//char s[256];
	//gets_s(s, 255);
	
	char* s = (char*)calloc(1, sizeof(char));

	int i = 0;
	while (1)
	{
		s[i] = _getche();

		if (s[i] == '\r')
		{
			s[i] = '\0';
			break;
		}

		if (s[i] == '\b')
		{
			if (i > 1)
			{
				i--;
				s[i] = '0';
				system("cls");
				printf("%s", s);
			}
			if (i <= 1)
			{
				i = 0;
				s = (char*)realloc(s, i + 1);
			}

		}
		i++;
		s = (char*)realloc(s, i + 1);
	}
	printf("%s\n", s);

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

	//_wsetlocale(LC_ALL, L"Russian");
	//setlocale(LC_ALL, "Russian");
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);
	//DWORD level = 2;
	//LPCWSTR servername = NULL;
	//wchar_t username[21];
	//NET_API_STATUS nStatus;
	//LPUSER_INFO_2 pBuf = NULL;

	//_getws_s(username, 20);

	//nStatus = NetUserGetInfo(servername, (wchar_t*)username, level, (LPBYTE*)&pBuf);

	//if (nStatus == NERR_Success)
	//{
	//	wprintf(L"User account name: %s\n", pBuf->usri2_name);
	//	wprintf(L"Password: %s\n", pBuf->usri2_password);
	//	wprintf(L"Password age (seconds): %d\n", pBuf->usri2_password_age);
	//	
	//	if (pBuf->usri2_priv == USER_PRIV_ADMIN)
	//		printf("Privilege level: Administrator\n");
	//	else if (pBuf->usri2_priv == USER_PRIV_USER)
	//		printf("Privilege level: User\n");
	//	else if (pBuf->usri2_priv == USER_PRIV_GUEST)
	//		printf("Privilege level: Guest\n");
	//	
	//	wprintf(L"Last logon (seconds since January 1, 1970 GMT): %d\n", pBuf->usri2_last_logon);
	//	wprintf(L"Last logoff (seconds since January 1, 1970 GMT): %d\n", pBuf->usri2_last_logoff);
	//	
	//	if (pBuf->usri2_acct_expires == TIMEQ_FOREVER)
	//		printf("Account expires(seconds since January 1, 1970 GMT): Never\n");
	//	else wprintf(L"Account expires (seconds since January 1, 1970 GMT): %d\n", pBuf->usri2_acct_expires);
	//	
	//	wprintf(L"Max storage: %d\n", pBuf->usri2_max_storage);
	//	wprintf(L"Bad password count: %d\n", pBuf->usri2_bad_pw_count);
	//	wprintf(L"Number of logons: %d\n", pBuf->usri2_num_logons);
	//	wprintf(L"Logon server: %s\n", pBuf->usri2_logon_server);
	//	wprintf(L"Country code: %d\n", pBuf->usri2_country_code);
	//	wprintf(L"Code page: %d\n", pBuf->usri2_code_page);
	//}
	//else if (nStatus == NERR_UserNotFound)
	//	printf("User can't be found\n");
	//else if (nStatus == ERROR_ACCESS_DENIED)
	//	printf("The user does not have access to the requested information.");
	//else if (nStatus == ERROR_INVALID_LEVEL)
	//	printf("The value specified for the level parameter is invalid.");
	//else if (nStatus == NERR_InvalidComputer)
	//	printf("The computer name is invalid.");

	//system("pause");
	//return 0;
}

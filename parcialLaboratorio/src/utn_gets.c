#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "utn_gets.h"

int utn_getNumber(int* pResult,
			   int maximum,
			   int minimum,
			   int reintentos,
			   char* pMessage,
			   char* pMessageErr)
{
	int i;
	int entry = *pResult;
	int retorno = -1;
	for(i=0; i < reintentos; i++)
	{
		printf("%s",pMessage);
		if(utn_getInt(&entry)==0 && entry <= maximum && entry >= minimum)
		{
			*pResult = entry;
			retorno = 0;
			break;
		}else
		{
			printf("%s", pMessageErr);
		}
	}
	return retorno;
}

int utn_getFloat(float* pResult,
				 float maximum,
				 float minimum,
				 int retry,
				 char* pMessage,
				 char* pMessageErr)
{
	int i;
	float entry = *pResult;
	int retorno = -1;
	for(i=0; i < retry; i++)
	{
		printf("%s", pMessage);
		__fpurge(stdin);
		if(utn_getFloatNumber(&entry)==0 && entry <= maximum && entry >= minimum)
		{
			*pResult = entry;
			retorno = 0;
			break;
		}else
		{
			printf("%s", pMessageErr);
		}
	}
	return retorno;
}

int utn_getChar(char* pMessage,char* pErrMessage, char* pChar)
{
	int retorno = -1;
	char buffer[3];
	if(pMessage != NULL)
	{
		printf("%s", pMessage);
		fgets(buffer, sizeof(buffer), stdin);
		strcpy(pChar, buffer);
		retorno = 0;
	}else{
		printf("%s", pErrMessage);
	}

	return retorno;
}

int utn_getString(char* pMessage,char* pErrMessage, char* pString)
{
	int retorno = -1;
	char buffer[1024];
	if(pMessage != NULL && pErrMessage != NULL)
	{
		printf("%s", pMessage);
		__fpurge(stdin);
		fgets(buffer, sizeof(buffer), stdin);
		buffer[strlen(buffer)-1]='\0';
		if(utn_isLetter(buffer)==1)
		{

		strcpy(pString, buffer);
		retorno = 0;
		}else
		{
			printf("%s", pErrMessage);
		}
	}
	return retorno;
}

int utn_getMail(char* pMessage,char* pErrMessage, char* pString)
{
	int retorno = -1;
	char buffer[1024];
	if(pMessage != NULL && pErrMessage != NULL)
	{
		printf("%s", pMessage);
		fgets(buffer, sizeof(buffer), stdin);
		buffer[strlen(buffer)-1]='\0';
		if(utn_isMail(buffer)==1)
		{
		strcpy(pString, buffer);
		retorno = 0;
		}else
		{
			printf("%s", pErrMessage);
		}
	}
	return retorno;
}

int utn_getTelephone(char* pMessage,char* pErrMessage, char* pString)
{
	int retorno = -1;
	char buffer[1024];
	if(pMessage != NULL && pErrMessage != NULL)
	{
		printf("%s", pMessage);
		fgets(buffer, sizeof(buffer), stdin);
		buffer[strlen(buffer)-1]='\0';
		if(utn_isTelephone(buffer)==1)
		{
		strcpy(pString, buffer);
		retorno = 0;
		}else
		{
			printf("%s", pErrMessage);
		}
	}
	return retorno;
}

int utn_getCuil(char* pMessage,char* pErrMessage, char* pString)
{
	int retorno = -1;
	char buffer[1024];
	if(pMessage != NULL && pErrMessage != NULL)
	{
		printf("%s", pMessage);
		fgets(buffer, sizeof(buffer), stdin);
		buffer[strlen(buffer)-1]='\0';
		if(utn_isCuil(buffer)==1)
		{
		strcpy(pString, buffer);
		retorno = 0;
		}else
		{
			printf("%s", pErrMessage);
		}
	}
	return retorno;
}

int utn_getInt(int* pResult)
{
	int retorno = -1;
	char buffer[1024];
	__fpurge(stdin);
	fgets(buffer,sizeof(buffer),stdin);
	buffer[strlen(buffer)-1]='\0';

	if(utn_isNumber(buffer)==1)
	{
		*pResult = atoi(buffer);
		retorno = 0;
	}
	return retorno;
}

int utn_getFloatNumber(float* pResult)
{
	int retorno = -1;
	char buffer[1024];
	__fpurge(stdin);
	fgets(buffer,sizeof(buffer),stdin);
	buffer[strlen(buffer)-1]='\0';

	if(utn_isFloatNumber(buffer)==1)
	{
		*pResult = atof(buffer);
		retorno = 0;
		}
	return retorno;
}

/*int utn_isNumber(char* array)
{
	int retorno = -1;
	int i;
	int lenght;
	lenght = strlen(array);
	for(i=0; i < lenght; i++)
	{
		if(array[i] < '0' || array[i] > '9')
		{
			break;
		}
		if(array[i]=='\0')
		{
			retorno = 0;
		}
	}
	return retorno;
}*/

int utn_isNumber(char* array)
{
	int retorno = 1;
	int i = 0;
	while(array[i]!= '\0')
	{
		if(array[i] < '0' || array[i] > '9')
		{
			retorno = 0;
		}
		i++;
	}
	return retorno;
}

int utn_isTelephone(char* array)
{
	int retorno = 1;
	int i = 0;
	while(array[i]!= '\0')
	{
		if((array[i] < '0' || array[i] > '9') &&
		 	array[i] != '-')
		{
			retorno = 0;
		}
		i++;
	}
	return retorno;
}

int utn_isFloatNumber(char* array)
{
	int retorno = 1;
	int i = 0;
	int counter = 0;
	while(array[i]!= '\0')
	{
		if((array[i] < '0' || array[i] > '9') && array[i] != '.')
		{
			retorno = 0;
		}
		/*if(array[i] == '.')
		{
			counter++;
		}
		if(counter != 1)
		{
			retorno = 0;
		}*/
		i++;
	}
	return retorno;
}

int utn_isAlphanumeric(char* array)
{
	int retorno = 1;
	int i = 0;
	while(array[i]!= '\0')
	{
		if((array[i] < '0' || array[i] > '9') &&
		   (array[i] < 'a' || array[i] > 'z') &&
		   (array[i] < 'A' || array[i] > 'Z'))
		{
			retorno = 0;
		}
		i++;
	}
	return retorno;
}

int utn_isLetter(char* string)
{
	int retorno = 1;
	int i = 0;
	while(string[i] != '\0')
	{
		if((string[i] < 'a' || string[i] > 'z') &&
		   (string[i] < 'A' || string[i] > 'Z') &&
		   (string[i] != ' '))
		{
			retorno = 0;
		}
		i++;
	}
	return retorno;
}

int utn_isMail(char* string)
{
	int retorno = 1;
	int i = 0;
	int counter = 0;
	while(string[i] != '\0')
	{
		if((string[i] < '0' || string[i] > '9') &&
		   (string[i] < 'a' || string[i] > 'z') &&
		   (string[i] < 'A' || string[i] > 'Z') &&
		   (string[i] != '@')  && (string[i] != '_') &&
		   (string[i] != '-') && (string[i] != '.'))
		{
			retorno = 0;
		}
		if(string[i] == '@')
		{
			counter++;
		}
		i++;
	}
		if(counter != 1)
		{
			retorno = 0;
		}
	return retorno;
}

int utn_isCuil(char* array)
{
	int retorno = 1;
	int i = 0;
	int counter = 0;
	while(array[i]!= '\0')
	{
		if(array[i] < '0' || array[i] > '9')
		{
			retorno = 1;
		}
		if(array[i] == '-')
		{
			counter++;
		}
		if(counter != 2)
		{
			retorno = 0;
		}
		i++;
	}
	return retorno;
}

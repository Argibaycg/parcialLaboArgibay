#ifndef UTN_H_
#define UTN_H_

int utn_getNumber(int*, int, int, int, char* pMessage,char* pErrMessage);
int utn_getFloat(float*, float, float, int, char* pMessage,char* pErrMessage);
int utn_getChar(char* pMessage,char* pErrMessage, char* pChar);
int utn_getString(char* pMessage,char* pErrMessage, char* pString);
int utn_getMail(char* pMessage,char* pErrMessage, char* pString);
int utn_getTelephone(char* pMessage,char* pErrMessage, char* pString);
int utn_getCuil(char* pMessage,char* pErrMessage, char* pString);
int utn_getInt(int* pResult);
int utn_getFloatNumber(float* pResult);
int utn_isNumber(char* array);
int utn_isFloatNumber(char* array);
int utn_isAlphanumeric(char* array);
int utn_isTelephone(char* array);
int utn_isLetter(char* string);
int utn_isMail(char* string);
int utn_isCuil(char* array);

#endif /* UTN_H_ */

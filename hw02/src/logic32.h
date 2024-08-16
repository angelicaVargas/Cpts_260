#ifndef _LOGIC_32_H_
#define _LOGIC_32_H_

/**
 * 32bit Logic
 */
void logic_AND32(char *a, char *b, char *y);
void logic_OR32(char *a, char *b, char *y);
void logic_NOT32(char *a, char *y);

/**
 * 32bit Arithmatic
 */
void logic_ADD32(char *a, char *b, char *s);
void logic_SUB32(char *a, char *b, char *s);
char logic_SLT32(char *a, char *b);
void logic_EXTEND(char e, int start, char *a, char *y);
void logic_MUX32_2_1(char s, char *d_1, char *d_0, char *y);
void logic_MUX32_4_1(char *s, char *d_3, char *d_2, char *d_1, char *d_0, char *y);
void logic_ALU(char *f, char *a, char *b, char *y);

#endif

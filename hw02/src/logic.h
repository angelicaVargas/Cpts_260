#ifndef _LOGIC_H_
#define _LOGIC_H_

/**
 * Logic Gates
 */
char logic_AND(char a, char b);
char logic_NAND(char a, char b);
char logic_OR(char a, char b);
char logic_NOR(char a, char b);
char logic_XOR(char a, char b);
char logic_NOT(char a);

/**
 * Complex Bit Building Blocks
 */
void logic_FULL_ADDR(char cin, char a, char b, char *cout, char *s);
char logic_MUX_2_1(char s, char d_1, char d_0);
char logic_MUX_4_1(char *s, char d_3, char d_2, char d_1, char d_0);
void logic_DECODER(char e, char a, char *y1, char *y0);

#endif
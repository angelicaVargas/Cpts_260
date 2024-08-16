#include <stdio.h>
#include <assert.h>

#include "logic32.h"

void test_logic_ADD32() {
    char a[33] = "00000000000000000000000000000001\0";
    char b[33] = "00000000000000000000000000000001\0";
    char s[33];

    for(int i = 0; i < 33; i++) {
        s[i] = '\0';
    }
    logic_ADD32(a, b, s); assert(s[30] == '1' && s[31] == '0');
}

void test_logic_SUB32() {
    char a[33] = "00000000000000000000000000000011\0";
    char b[33] = "00000000000000000000000000000001\0";
    char s[33];

    for(int i = 0; i < 33; i++) {
        s[i] = '\0';
    }
    logic_SUB32(a, b, s); assert(s[30] == '1' && s[31] == '0');
}

void test_logic_SLT32() {
    char a[33] = "00000000000000000000000000000011\0";
    char b[33] = "00000000000000000000000000000001\0";

    assert(logic_SLT32(a, b) == '0');
    assert(logic_SLT32(b, a) == '1');
}

void test_logic_AND32() {
    int i;
    char a[33] = "01010101010000001111111111111111\0";
    char b[33] = "00000000000000001111111111111111\0";
    char y[33];

    for(int i = 0; i < 33; i++) {
        y[i] = '\0';
    }
    logic_AND32(a, b, y);
    for(i = 0; i < 16; i++) {
        assert(y[i] == '0');
    }
    for(i = 16; i < 32; i++) {
        assert(y[i] == '1');
    }
}

void test_logic_OR32() {
    int i;
    char a[33] = "00000000000000001010101010101010\0";
    char b[33] = "00000000000000001111111101010101\0";
    char y[33];

    for(int i = 0; i < 33; i++) {
        y[i] = '\0';
    }
    logic_OR32(a, b, y);
    for(i = 0; i < 16; i++) {
        assert(y[i] == '0');
    }
    for(i = 16; i < 32; i++) {
        assert(y[i] == '1');
    }
}

void test_logic_NOT32() {
    int i;
    char a[33] = "00000000000000001010101010101010\0";
    char y[33];

    for(int i = 0; i < 33; i++) {
        y[i] = '\0';
    }
    logic_NOT32(a, y);
    for(i = 0; i < 16; i++) {
        assert(y[i] == '1');
    }
    for(i = 16; i < 32; i++) {
        if (i&1) {
            assert(y[i] == '1');
        } else {
            assert(y[i] == '0');
        }
    }
}

void test_logic_EXTEND() {
    int i;
    char a[33] = "00000000000000000000000000000001\0";
    char y[33];

    for(int i = 0; i < 33; i++) {
        y[i] = '\0';
    }
    logic_EXTEND('1', 1, a, y);
    for(i = 0; i < 32; i++) {
        assert(y[i] == '1');
    }
}

void test_logic_MUX32_2_1() {
    int i;
    char a[33] = "00000000000000000000000000000010\0";
    char b[33] = "00000000000000000000000000000001\0";
    char y[33];

    for(int i = 0; i < 33; i++) {
        y[i] = '\0';
    }
    logic_MUX32_2_1('0', a, b, y);
    for(i = 0; i < 30; i++) {
        assert(y[i] == '0');
    }
    assert(y[30] == '0' && y[31] == '1');
    logic_MUX32_2_1('1', a, b, y);
    for(i = 0; i < 30; i++) {
        assert(y[i] == '0');
    }
    assert(y[30] == '1' && y[31] == '0');
}

void test_logic_MUX32_4_1() {
    int i;
    char f[2];
    char d_3[33] = "00000000000000000000000000000011\0";
    char d_2[33] = "00000000000000000000000000000010\0";
    char d_1[33] = "00000000000000000000000000000001\0";
    char d_0[33] = "00000000000000000000000000000000\0";
    char y[33];

    for(int i = 0; i < 33; i++) {
        y[i] = '\0';
    }
    f[0] = '0', f[1] = '0'; logic_MUX32_4_1(f, d_3, d_2, d_1, d_0, y);
    for(i = 0; i < 32; i++) {
        assert(y[i] == '0');
    }
    f[0] = '0', f[1] = '1'; logic_MUX32_4_1(f, d_3, d_2, d_1, d_0, y);
    for(i = 0; i < 31; i++) {
        assert(y[i] == '0');
    }
    assert(y[31] == '1');
    f[0] = '1', f[1] = '0'; logic_MUX32_4_1(f, d_3, d_2, d_1, d_0, y);
    for(i = 0; i < 30; i++) {
        assert(y[i] == '0');
    }
    assert(y[30] == '1');
    assert(y[31] == '0');
    f[0] = '1', f[1] = '1'; logic_MUX32_4_1(f, d_3, d_2, d_1, d_0, y);
    for(i = 0; i < 30; i++) {
        assert(y[i] == '0');
    }
    assert(y[30] == '1');
    assert(y[31] == '1');
}

void test_logic_ALU() {
    int i;
    char f_and[4]  = "000\0";
    char f_or[4]   = "001\0";
    char f_add[4]  = "010\0";
    char f_nand[4] = "100\0";
    char f_nor[4]  = "101\0";
    char f_sub[4]  = "110\0";
    char f_slt[4]  = "111\0";
    char a[33] = "00000000000000000000000000000010\0";
    char b[33] = "00000000000000000000000000000001\0";
    char y[33];

    for(int i = 0; i < 33; i++) {
        y[i] = '\0';
    }

    logic_ALU(f_and, a, b, y);
    for(i = 0; i < 32; i++) {
        assert(y[i] == '0');
    }

    logic_ALU(f_or, a, b, y);
    for(i = 0; i < 30; i++) {
        assert(y[i] == '0');
    }
    assert(y[30] == '1');
    assert(y[31] == '1');

    logic_ALU(f_add, a, b, y);
    for(i = 0; i < 30; i++) {
        assert(y[i] == '0');
    }
    assert(y[30] == '1');
    assert(y[31] == '1');

    logic_ALU(f_nand, a, b, y);
    for(i = 0; i < 30; i++) {
        assert(y[i] == '0');
    }
    assert(y[30] == '1');
    assert(y[31] == '0');

    logic_ALU(f_nor, a, b, y);
    for(i = 0; i < 30; i++) {
        assert(y[i] == '1');
    }
    assert(y[30] == '1');
    assert(y[31] == '0');

    logic_ALU(f_sub, a, b, y);
    for(i = 0; i < 30; i++) {
        assert(y[i] == '0');
    }
    assert(y[30] == '0');
    assert(y[31] == '1');

    logic_ALU(f_slt, a, b, y);
    for(i = 0; i < 31; i++) {
        assert(y[i] == '0');
    }
    assert(y[31] == '1');
}

int main(int argc, char **argv) {
    test_logic_AND32();
    test_logic_OR32();
    test_logic_NOT32();
    test_logic_ADD32();
    test_logic_SUB32();
    test_logic_SLT32();
    test_logic_EXTEND();
    test_logic_MUX32_2_1();
    test_logic_MUX32_4_1();
    test_logic_ALU();
    return 0;
}

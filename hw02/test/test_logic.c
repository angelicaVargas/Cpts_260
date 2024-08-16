#include <stdio.h>
#include <assert.h>

#include "logic.h"

int main(int argc, char **argv) {
    char cout, s;
    char y1, y0;
    char ms[2];
    /**
     * Check the and output.
     */
    assert(logic_AND('0', '0') == '0');
    assert(logic_AND('0', '1') == '0');
    assert(logic_AND('1', '0') == '0');
    assert(logic_AND('1', '1') == '1');

    /**
     * Check the and output.
     */
    assert(logic_NAND('0', '0') == '1');
    assert(logic_NAND('0', '1') == '1');
    assert(logic_NAND('1', '0') == '1');
    assert(logic_NAND('1', '1') == '0');

    /**
     * Check the or output.
     */
    assert(logic_OR('0', '0') == '0');
    assert(logic_OR('0', '1') == '1');
    assert(logic_OR('1', '0') == '1');
    assert(logic_OR('1', '1') == '1');

    /**
     * Check the or output.
     */
    assert(logic_NOR('0', '0') == '1');
    assert(logic_NOR('0', '1') == '0');
    assert(logic_NOR('1', '0') == '0');
    assert(logic_NOR('1', '1') == '0');

    /**
     * Check the or output.
     */
    assert(logic_XOR('0', '0') == '0');
    assert(logic_XOR('0', '1') == '1');
    assert(logic_XOR('1', '0') == '1');
    assert(logic_XOR('1', '1') == '0');

    /**
     * Check the not output.
     */
    assert(logic_NOT('0') == '1');
    assert(logic_NOT('1') == '0');

    /**
     * Full Addr Truth Table.
     */
    logic_FULL_ADDR('0', '0', '0', &cout, &s); assert(cout == '0' && s == '0');
    logic_FULL_ADDR('0', '0', '1', &cout, &s); assert(cout == '0' && s == '1');
    logic_FULL_ADDR('0', '1', '0', &cout, &s); assert(cout == '0' && s == '1');
    logic_FULL_ADDR('0', '1', '1', &cout, &s); assert(cout == '1' && s == '0');
    logic_FULL_ADDR('1', '0', '0', &cout, &s); assert(cout == '0' && s == '1');
    logic_FULL_ADDR('1', '0', '1', &cout, &s); assert(cout == '1' && s == '0');
    logic_FULL_ADDR('1', '1', '0', &cout, &s); assert(cout == '1' && s == '0');
    logic_FULL_ADDR('1', '1', '1', &cout, &s); assert(cout == '1' && s == '1');

    /**
     * Multiplexer 2:1 Truth Table.
     */
    assert(logic_MUX_2_1('0', '0', '0') == '0');
    assert(logic_MUX_2_1('0', '0', '1') == '1');
    assert(logic_MUX_2_1('0', '1', '0') == '0');
    assert(logic_MUX_2_1('0', '1', '1') == '1');
    assert(logic_MUX_2_1('1', '0', '0') == '0');
    assert(logic_MUX_2_1('1', '0', '1') == '0');
    assert(logic_MUX_2_1('1', '1', '0') == '1');
    assert(logic_MUX_2_1('1', '1', '1') == '1');

    /**
     * Multiplexer 4:1 Truth Table.
     */
    ms[0] = '0'; ms[1] = '0'; assert(logic_MUX_4_1(ms, '0', '0', '0', '1') == '1');
    ms[0] = '0'; ms[1] = '1'; assert(logic_MUX_4_1(ms, '0', '0', '1', '0') == '1');
    ms[0] = '1'; ms[1] = '0'; assert(logic_MUX_4_1(ms, '0', '1', '0', '0') == '1');
    ms[0] = '1'; ms[1] = '1'; assert(logic_MUX_4_1(ms, '1', '0', '0', '0') == '1');
    ms[0] = '0'; ms[1] = '0'; assert(logic_MUX_4_1(ms, '1', '1', '1', '0') == '0');
    ms[0] = '0'; ms[1] = '1'; assert(logic_MUX_4_1(ms, '1', '1', '0', '1') == '0');
    ms[0] = '1'; ms[1] = '0'; assert(logic_MUX_4_1(ms, '1', '0', '1', '1') == '0');
    ms[0] = '1'; ms[1] = '1'; assert(logic_MUX_4_1(ms, '0', '1', '1', '1') == '0');

    /**
     * Decoder Truth Table.
     */
    logic_DECODER('0', '0', &y1, &y0); assert(y1 == '0' && y0 == '0');
    logic_DECODER('0', '1', &y1, &y0); assert(y1 == '0' && y0 == '0');
    logic_DECODER('1', '0', &y1, &y0); assert(y1 == '0' && y0 == '1');
    logic_DECODER('1', '1', &y1, &y0); assert(y1 == '1' && y0 == '0');
    return 0;
}

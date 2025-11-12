#include "acutest.h"
#include "game.h"
#include <string>

void test_parse_valid(void) {
    std::string s = "3x3 P=3\n1 0 2\n0 1 0\n2 0 1";
    Board b = parseBoard(s);
    TEST_CHECK(b.rows == 3);
    TEST_CHECK(b.cols == 3);
    TEST_CHECK(b.players == 3);
    TEST_CHECK(b.cells[0][0] == 1);
    TEST_CHECK(b.cells[2][2] == 1);
}

void test_parse_invalid(void) {
    std::string s = "2x2 P=3\n0 0\n0 0"; 
    try {
        Board b = parseBoard(s);
        TEST_CHECK(false); 
    } catch (const std::invalid_argument&) {
        TEST_CHECK(true);
    }
}

TEST_LIST = {
    { "parse: valid input", test_parse_valid },
    { "parse: invalid dimension", test_parse_invalid },
    { NULL, NULL }
};

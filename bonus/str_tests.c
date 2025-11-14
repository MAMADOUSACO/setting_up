#include <criterion/criterion.h>
#include "./../src/include/setting_up.h"

Test(string_comparison, equal_strings) {
    cr_expect_eq(str_cmp("hello", "hello"), 0);
    cr_expect_eq(str_cmp("", ""), 0);
}

Test(string_comparison, first_less_than_second) {
    cr_expect_lt(str_cmp("abc", "abd"), 0);
    cr_expect_lt(str_cmp("hello", "world"), 0);
}

Test(string_comparison, first_greater_than_second) {
    cr_expect_gt(str_cmp("abd", "abc"), 0);
    cr_expect_gt(str_cmp("zebra", "apple"), 0);
}

Test(string_comparison, different_lengths) {
    cr_expect_lt(str_cmp("he", "hello"), 0);
    cr_expect_gt(str_cmp("hello", "he"), 0);
    cr_expect_gt(str_cmp("hi", "hello"), 0);
    cr_expect_lt(str_cmp("hello", "hi"), 0);
}

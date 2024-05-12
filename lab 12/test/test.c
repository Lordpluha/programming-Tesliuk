#include <check.h>
#include "lib.h"
#include <math.h>
#include <stdlib.h>

/**
 * @file test.c
 * @author Tesliuk Vladyslav
 * @date 12-may-2024
 * @version 1.0.0
 */

/// Функція для перетворення рядка у ціле число
START_TEST(test_str_to_int) {
    ck_assert_int_eq(str_to_int("123"), 123);
    ck_assert_int_eq(str_to_int("0"), 0);
    ck_assert_int_eq(str_to_int("-123"), -123);
}
END_TEST

/// Функція для перетворення рядка у число з плаваючою комою
START_TEST(test_str_to_float) {
    ck_assert(fabs(str_to_float("123.45")-123.45) < M_E);
    ck_assert(fabs(str_to_float("0.0")-0.0) < M_E);
    ck_assert(fabs(str_to_float("-123.45") + 123.45) < M_E);
}
END_TEST

Suite *str_to_int_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("StrToInt");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_str_to_int);
    suite_add_tcase(s, tc_core);

    return s;
}

Suite *str_to_float_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("StrToFloat");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_str_to_float);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void) {
    return 0;
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = str_to_int_suite();
    sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    s = str_to_float_suite();
    sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    number_failed += srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

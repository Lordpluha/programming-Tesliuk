#include "../src/lib.h"
#include <check.h>


START_TEST(test_lib) {
    #define DATA_SIZE_SUM 3

	int input_data_1[] = { 3, 7, 24 };
	int input_data_2[] = { 2, 2, 3 };
	int input_data_3[] = { 1, 9, 5 };
	int input_data_4[] = { 0, 1, 4 };
	int input_data_5[] = { 2, 0, 10 };

    struct arrayParams actual_struct;
    actual_struct.lenght = 5;
	int expected_values[] = { 3, 3, 2 };
	
    for (int i = 0; i < DATA_SIZE_SUM; i++) {
        int arr[] = {
			input_data_1[i],
			input_data_2[i],
			input_data_3[i],
			input_data_4[i],
			input_data_5[i]
		};
		actual_struct.array = arr;
        int actual_value = countDescendOrderPairs(actual_struct);
		ck_assert_int_eq(expected_values[i], actual_value);
	}
}
END_TEST

int main(void) {
	Suite *s = suite_create("Programing");
	TCase *tc_core = tcase_create("lab09");
	tcase_add_test(tc_core, test_lib);
	suite_add_tcase(s, tc_core);
	SRunner *sr = srunner_create(s);
	srunner_run_all(sr, CK_VERBOSE);
	int number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
//vector_create
// Created by cubazis on 05.06.18.
//

#include <check.h>
#include "vector_int.h"
#include <stdlib.h>
#include "stdio.h"

START_TEST(test_vector_create)
    {
        size_t capacity = 50;
        struct Vector *v = vector_create_int(capacity);
        ck_assert_int_eq(50, (int) vector_get_capacity(v));
        ck_assert_int_eq(0, vector_get_size(v));
        ck_assert_int_eq(4, vector_get_item_size(v));
        ck_assert_int_eq((vector_get_end(v) - vector_get_begin(v)), 0);
        int b = 5;
        vector_push_back_int(v, b);
        ck_assert_int_eq((vector_get_end(v) - vector_get_begin(v)), 4);
        ck_assert_int_eq(1, vector_get_size(v));
        void *a = malloc(sizeof(int));

        ck_assert_int_eq(5, vector_pop_back_int(v));
        b = 10;
        vector_push_back_int(v, b);
        a = vector_get_element(v, 0);
        ck_assert_int_eq(10, *((int *) a));
    }
END_TEST


Suite *str_suite(void) {
    Suite *suite = suite_create("Lab Session 4");
    TCase *tcase = tcase_create("case");


    tcase_add_test(tcase, test_vector_create);

    suite_add_tcase(suite, tcase);
    return suite;
}

int main(int argc, char *argv[]) {
    int number_failed;
    Suite *suite = str_suite();
    SRunner *runner = srunner_create(suite);
    srunner_run_all(runner, CK_NORMAL);
    number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return number_failed;
}
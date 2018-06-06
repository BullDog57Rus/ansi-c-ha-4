//vector_create
// Created by cubazis on 05.06.18.
//

#include <check.h>
#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

START_TEST(test_vector_create)
    {
        size_t capacity = 50;
        struct Vector *v = vector_create(capacity, (size_t) sizeof(int));
        printf("%d\n", (int) vector_get_capacity(v));
        printf("%d\n", (int) vector_get_size(v));
        printf("%d\n", (int) vector_get_item_size(v));
        printf("%p\n", vector_get_begin(v));
        printf("%p\n", vector_get_end(v));
        int b = 5;
        vector_push_back(v, &b);
        printf("%d\n", (int) vector_get_size(v));
        printf("%p\n", vector_get_end(v));
        void *a = malloc(sizeof(int));
        vector_pop_back(v, a);

        printf("%d\n", *((int *) a));
        printf("%p\n", vector_get_end(v));
        b = 10;
        vector_push_back(v, &b);
        a = vector_get_element(v, 0);
        printf("%d\n", *((int *) a));
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
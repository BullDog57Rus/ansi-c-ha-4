//vector_create
// Created by cubazis on 05.06.18.
//

#include <check.h>
#include "vector_int.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int comp_vectors_int(const void *a, const void *b)
/* Returns -ve if a<b, 0 if a==b, +ve if a>b */
{
    return *(int *) a == *(int *) b ? 0 : *(int *) a > *(int *) b ? 1 : -1;
}

START_TEST(test_vector_qsort)
    {
        struct Vector *v;
        int our_size = 20;
        v = vector_create_int((size_t) our_size);
        int mod = 1000;
        srand((unsigned int) time(NULL));

        for (int i = 0; i < vector_get_capacity(v); ++i) {
            vector_push_back_int(v, rand() % mod);
        }
        void *ptr;
        printf("Size before quicksort: %zu\n", vector_get_size(v));
        for (int i = 0; i < vector_get_capacity(v); ++i) {
            ptr = vector_get_element(v, (size_t) i);
            printf("%d ", *(int *) ptr);
        }

        printf("\n");
        qsort(vector_get_begin(v), vector_get_capacity(v), vector_get_item_size(v), comp_vectors_int);
        printf("Size after quicksort: %zu\n", vector_get_size(v));
        void *prev;
        prev = vector_get_element(v, 0);
        for (int i = 1; i < vector_get_capacity(v); ++i) {
            ptr = vector_get_element(v, (size_t) i);
            ck_assert(ptr >= prev);
            prev = ptr;
            printf("%d ", *(int *) ptr);
        }
        printf("\n");
    }
END_TEST


Suite *str_suite(void) {
    Suite *suite = suite_create("Assignment 4");
    TCase *tcase = tcase_create("case");


    tcase_add_test(tcase, test_vector_qsort);

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
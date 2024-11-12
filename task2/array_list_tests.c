#include "checkit.h"
#include "array_list.h"
#include <stdlib.h>

void test1(void) {
    // ArrayList *array_list_new(void)
    ArrayList *test_list = array_list_new();

    checkit_boolean(test_list != NULL, 1);
    checkit_int((*test_list).capacity, 4);
    checkit_int((*test_list).element_count, 0);
    checkit_boolean((*test_list).array != NULL, 1);

    free(test_list);
}

void test2(void) {
    // void array_list_add_to_end(ArrayList *arraylist, char* new_string)
    ArrayList *test_list = array_list_new();
    char *check_words[] = {
        "Hello",
        "World",
        "HELLO",
        "WORLD",
        "hello",
        "world",
        "test",
        "TEST",
        "Test",
        "TeSt",
        "tEsT",
        "TESt"
    };

    checkit_boolean(test_list != NULL, 1);
    checkit_int((*test_list).capacity, 4);
    checkit_int((*test_list).element_count, 0);
    checkit_boolean((*test_list).array != NULL, 1);

    array_list_add_to_end(test_list, "Hello");
    array_list_add_to_end(test_list, "World");

    checkit_boolean(test_list != NULL, 1);
    checkit_int((*test_list).capacity, 4);
    checkit_int((*test_list).element_count, 2);

    array_list_add_to_end(test_list, "HELLO");
    array_list_add_to_end(test_list, "WORLD");

    checkit_boolean(test_list != NULL, 1);
    checkit_int((*test_list).capacity, 4);
    checkit_int((*test_list).element_count, 4);

    array_list_add_to_end(test_list, "hello");
    array_list_add_to_end(test_list, "world");

    checkit_boolean(test_list != NULL, 1);
    checkit_int((*test_list).capacity, 8);
    checkit_int((*test_list).element_count, 6);

    array_list_add_to_end(test_list, "test");
    array_list_add_to_end(test_list, "TEST");
    array_list_add_to_end(test_list, "Test");
    array_list_add_to_end(test_list, "TeSt");
    array_list_add_to_end(test_list, "tEsT");
    array_list_add_to_end(test_list, "TESt");

    checkit_boolean(test_list != NULL, 1);
    checkit_int((*test_list).capacity, 16);
    checkit_int((*test_list).element_count, 12);

    int i;
    for (i = 0; i < 12; i++) {
        //printf("%s\n", check_words[i]);
        checkit_string((*test_list).array[i], check_words[i]);
    }

    free((*test_list).array);
    free(test_list);
}

int main(void) {
   test1();
   test2();
   return 0;
}

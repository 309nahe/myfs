#include <check.c>
#include "../src/filesystem.c"

FileSystem fs;

void setup(void) {
    fs.files = NULL;
    fs.file_count = 0;
}

void teardown(void) {
    for (size_t i = 0; i < fs.file_count; i++) {
        free(fs.files[i].content);
    }
    free(fs.files);
    fs.files = NULL;
    fs.file_count = 0;
}

START_TEST(test_create_file) {
    create_file(&fs, "test.txt", "Hello, World!");
    ck_assert_int_eq(fs.file_count, 1);
    ck_assert_str_eq(fs.files[0].name, "test.txt");
    ck_assert_str_eq(fs.files[0].content, "Hello, World!");
}
END_TEST

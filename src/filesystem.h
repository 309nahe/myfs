#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <stddef.h>

typedef struct {
    char name[256];
    char *content;
    size_t size;
} File;

typedef struct {
    size_t file_count;
    File* files;
} FileSystem;

FileSystem* init_fs(void);
void fs_add_file(FileSystem *fs, File *file);
void fs_rm_file(FileSystem *fs, const char *name);
File* create_file(const char *name, const char *content);
void free_fs(FileSystem *fs);

#endif // FILESYSTEM_H
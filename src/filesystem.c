//TODO: includes
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "filesystem.h"

FileSystem* init_fs(void)
{
    FileSystem *fs = malloc(sizeof(FileSystem));
    fs->file_count = 0;
    fs->files = NULL;

    return fs;
}

void fs_add_file(FileSystem *fs, File *file)
{
    fs->files = realloc(fs->files, sizeof(File) * (fs->file_count + 1));
    strcpy(fs->files[fs->file_count].name, file->name);
    fs->files[fs->file_count].content = malloc(sizeof(char) * strlen(file->content) + 1);
    strcpy(fs->files[fs->file_count].content, file->content);
    

    printf("File Name: %s\n",  fs->files[fs->file_count].name);
    printf("File Content: %s\n", fs->files[fs->file_count].content);

    fs->file_count++;
    printf("Count: %ld\n", fs->file_count);

    
}

void fs_rm_file(FileSystem *fs, const char *name)
{
    for (size_t i = 0; i < fs->file_count; i++)
    {
        if (strcmp(fs->files[i].name, name) == 0)
        {
            free(fs->files[i].content);
            memmove(&fs->files[i], &fs->files[i + 1], sizeof(File) * (fs->file_count - i - 1));
            fs->file_count--;
            fs->files = realloc(fs->files, sizeof(File) * fs->file_count);
            return;
        }
    }
    printf("File not found: %s\n", name);
    return;
}

File* create_file(const char *name, const char *content)
{
    if(name == NULL)
    {
        printf("%s", "ERROR: The name pointer is null");
        return NULL;
    }
    if(content == NULL)
    {
        printf("%s", "ERROR: The content pointer is null");
        return NULL;
    }

    File *file = malloc(sizeof(File));
    file->content = malloc(sizeof(char) * strlen(content));
    strcpy(file->name, name);
    strcpy(file->content, content);
    file->size = strlen(content);

    return file;
}

void free_fs(FileSystem *fs)
{
    for (size_t i = 0; i < fs->file_count; i++)
    {
        free(fs->files[i].content);
    }
    free(fs->files);
    free(fs);
}

int main(void)
{
    FileSystem *fs = init_fs();
    File *file = create_file("hello.txt", "hello friends :)");
    File *file2 = create_file("bestcat.txt", "Firestar!!");
    fs_add_file(fs, file);
    fs_add_file(fs, file2);
    fs_rm_file(fs, "hello.txt");
    fs_rm_file(fs, "foo.txt");
    fs_add_file(fs, file);

    free(file->content);
    free(file);
    free(file2->content);
    free(file2);
    free_fs(fs);

    return 0;
}
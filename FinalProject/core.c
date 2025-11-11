#include "cs50.h"
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>   
#include <string.h>   
#include <sys/stat.h> 
#include <unistd.h>

int create_fullpath(string path);
long calculate_dir_size(const char *path);
int clear_directory(const char *path);

int read_and_clean(int *option)
{
    if (*option == 1) 
    {
        create_fullpath("Library/Caches");
        return 0;
    } else if (*option == 2)
    {
        create_fullpath("Library/Log");
        return 0;
    } else if (*option == 3)
    {
        create_fullpath("Library/Cookies");
        return 0;
    } else if (*option == 4)
    {
        create_fullpath("Library/Developer/Xcode/Archives/*");
        create_fullpath("Library/Developer/Xcode/DerivedData");
        return 0;
    }
    else if (*option == 5)
    {
        create_fullpath("Library/Caches");
        create_fullpath("Library/Log");
        create_fullpath("Library/Cookies");
        create_fullpath("Library/Developer/Xcode/Archives/*");
        create_fullpath("Library/Developer/Xcode/DerivedData");
        return 0;
    }
    

    return 0;
}

int create_fullpath(string path)
{
    const char *computerPath = getenv("HOME");
    if (!computerPath) {
        printf("Erro: HOME não encontrado.\n");
        return 1;
    }

    char path_space[512];

    snprintf(path_space, sizeof(path_space), "%s/%s", computerPath, path);

    long size = calculate_dir_size(path_space);
    printf("\033[0;32m-------------------------------\n");
    printf("Clean: %s\n", path);
    printf("Liberate Space: %ld bytes\n", size);

    clear_directory(path_space);
    printf("Clean Directory!\n");
    printf("-------------------------------\033[0m\n");

    return 0;
}

long calculate_dir_size(const char *path) {
    DIR *dir = opendir(path);
    if (!dir) {
        return 1;
    }

    struct dirent *entry;
    struct stat st;
    char fullpath[1024];
    long total_size = 0;

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);

        if (stat(fullpath, &st) == 0) {
            if (S_ISDIR(st.st_mode)) {
                total_size += calculate_dir_size(fullpath);
            } else if (S_ISREG(st.st_mode)) {
                total_size += st.st_size;
            }
        }
    }

    closedir(dir);
    return total_size;
}

int clear_directory(const char *path) {
    DIR *dir = opendir(path);
    if (!dir) {
        return 1;
    }

    struct dirent *entry;
    struct stat st;
    char fullpath[1024];

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);

        if (stat(fullpath, &st) == 0) {
            if (S_ISDIR(st.st_mode)) {
                clear_directory(fullpath);
                rmdir(fullpath);
            } else if (S_ISREG(st.st_mode)) {
                remove(fullpath);
            }
        }
    }

    closedir(dir);
    return 0;
}
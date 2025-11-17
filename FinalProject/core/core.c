#include "cs50.h"
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>   
#include <string.h>   
#include <sys/stat.h> 
#include <unistd.h>

#define YELLOW "\033[0;33m"
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"

#define XCODE_ARCHIVES "Library/Developer/Xcode/Archives"
#define XCODE_DERIVED_DATA "Library/Developer/Xcode/DerivedData"
#define XCODE_DEVICES "Library/Developer/CoreSimulator/Devices"
#define XCODE_CRASH_REPORTER "Library/Application Support/CrashReporter"
#define CACHES "Library/Caches"
#define LOG "Library/Logs"
#define COOKIES "Library/Cookies"


int clean_path(string path);
long calculate_dir_size(const char *path);
int clear_directory(const char *path);
bool confirm_action(void);
int confirm_and_clean(string path);

int read_and_clean(int *option)
{
    if (*option == 1) 
    {
        return confirm_and_clean(CACHES);
    } else if (*option == 2)
    {
        return confirm_and_clean(LOG);
    } else if (*option == 3)
    {
        return confirm_and_clean(COOKIES);
    } else if (*option == 4)
    {
        confirm_and_clean(XCODE_ARCHIVES);
        printf("\n");
        confirm_and_clean(XCODE_DERIVED_DATA);  
        printf("\n");
        confirm_and_clean(XCODE_CRASH_REPORTER);
        printf("\n");
        return confirm_and_clean(XCODE_DEVICES);
    }
    else if (*option == 5)
    {
        confirm_and_clean(CACHES);
        printf("\n");
        confirm_and_clean(LOG);
        printf("\n");
        confirm_and_clean(COOKIES);
        printf("\n");
        confirm_and_clean(XCODE_ARCHIVES);
        printf("\n");
        confirm_and_clean(XCODE_DERIVED_DATA);
        printf("\n");
        confirm_and_clean(XCODE_CRASH_REPORTER);
        printf("\n");
        return confirm_and_clean(XCODE_DEVICES);
    }
    else if (*option == 6)
    {
        system("du -sh ~/Library/*");
        return 0;
    }

    return 0;
}

int clean_path(string path)
{
    const char *home = getenv("HOME");
    if (!home) {
    printf(RED "Erro: HOME not found.\n" RESET);
        return 1;
    }

    char path_space[512];

    if (path[0] == '/')
    {
        snprintf(path_space, sizeof(path_space), "%s", path);
    }
    else
    {
        snprintf(path_space, sizeof(path_space), "%s/%s", home, path);
    }

    long before = calculate_dir_size(path_space);
    printf("\n");
    printf(GREEN "-------------------------------\n");
    printf("%s\n", path_space);

    // Progress calculating size
    printf(GREEN "Calculating size (may take some time)" RESET);
    for (int i = 0; i < 3; i++) {
        fflush(stdout);
        sleep(1);
        printf(".");
    }
    printf("\n");

    sleep(1);
    clear_directory(path_space);

    // Progress feedback
    printf(GREEN "Cleaning");
    for (int i = 0; i < 3; i++) {
        fflush(stdout);
        sleep(1);
        printf(".");
    }
    printf("\n"RESET);

    long after = calculate_dir_size(path_space);
    printf(GREEN "Freed: %.2f MB\n", (before - after) / (1024.0 * 1024.0));
    printf("Clean Directory!\n");
    printf("-------------------------------\n" RESET);

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

bool confirm_action(void)
{
    char answer;
    do
    {
        answer = get_char(RED "Are you sure you want to clean? (y/n): " RESET);
        if(answer == 'y' || answer == 'Y')
        { 
            return true; 
        }
        else if (answer == 'n'|| answer == 'N')
        {   printf(YELLOW "-----------------\n");
            printf("Action cancelled. \n");
            printf("-----------------" RESET);
            printf("\n");
            return false; 
        }
        else 
        {   printf(YELLOW "----------------------------------\n");
            printf("Invalid input, please type y or n. \n"); 
            printf("----------------------------------" RESET);
            printf("\n");
        }
            
    } while (true);
    
}

int confirm_and_clean(string path)
{
    if (!confirm_action()) {return 0;}
        clean_path(path);
            sleep(1);
        return 0;
}
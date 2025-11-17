# Mac Cleanup for iOS Developer in C
#### Video Demo: https://youtu.be/ZOA7sej3EOc
#### Description:

# Welcome to Mac Cleanup
Mac Cleanup is a command-line program written in C specifically designed for iOS developers who work with Xcode. Xcode is notorious for consuming large amounts of disk space due to its caches, DerivedData, device simulators, logs, cookies, and archived builds. Over time, this can lead to low disk space warnings, crashes, or slowdowns. Manually cleaning these directories is not only tedious but also risky if important files are accidentally removed.

This program automates the cleanup process, giving iOS developers a `safer, faster, and more user-friendly` way to free up disk space on their Mac. Inspired by the retro aesthetics of the 1980s, the program features a command-line interface (CLI) with an 80s arcade vibe, using ASCII art logos, color-coded messages, and dynamic prompts. Before any deletion, it asks for confirmation to prevent accidental loss of important data. 

```
                                ,----,.               
                              ,'   ,' |               
                            ,'   .'   |    ,----..    
                          ,----.'    .'   /   /   \   
                          |    |   .'    /   .     :  
                .--.--.   :    :  |--,  .   /   ;.  \ 
       ,---.   /  /    '  :    |  ;.' \.   ;   /  ` ; 
      /     \ |  :  /`./  |    |      |;   |  ; \ ; | 
     /    / ' |  :  ;_    `----'.'\   ;|   :  | ; | ' 
    .    ' /   \  \    `.   __  \  .  |.   |  ' ' ' : 
    '   ; :__   `----.   \/   /\/  /  :'   ;  \; /  | 
    '   | '.'| /  /`--'  / ,,/  ',-   . \   \  ',  /  
    |   :    :'--'.     /\ ''\       ;   ;   :    /   
     \   \  /   `--'---'  \   \    .'     \   \ .'    
      `----'               `--`-,-'        `---`      

```



# Key Features
## 1. User-Friendly Menu Interface
 - The program provides a simple command-line interface (CLI) where users can choose which type of cleanup to perform. The menu displays six options:
    - Cleanup Caches
    - Cleanup Logs
    - Cleanup Cookies
    - Cleanup Xcode-related directories
    - Deep Cleaning (all above)
    - Disk usage display

```
void show_menu(void)
{
    printf(GREEN "-----------------------\n");
    printf("| 1: Cleanup Caches    |\n");
    printf("| 2: Cleanup Logs      |\n");
    printf("| 3: Cleanup Cookies   |\n");
    printf("| 4: Cleanup Xcode     |\n");
    printf("| 5: Deep Cleaning     |\n");
    printf("| 0: Exit              |\n");
    printf("-----------------------" RESET);
}

````

## 2. Recursive Directory Scanning
The program uses recursion to calculate the size of directories and their contents. This is important for directories like DerivedData or CoreSimulator/Devices, which contain nested folders. The recursive function calculate_dir_size() traverses each folder and sums the sizes of all files:

```
long calculate_dir_size(const char *path)
{
    DIR *dir = opendir(path);
    struct dirent *entry;
    struct stat st;
    char fullpath[1024];
    long total_size = 0`

    while ((entry = readdir(dir)) != NULL)
    {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);

        if (stat(fullpath, &st) == 0)
        {
            if (S_ISDIR(st.st_mode))
                total_size += calculate_dir_size(fullpath);
            else if (S_ISREG(st.st_mode))
                total_size += st.st_size;
        }
    }

    closedir(dir);
    return total_size;
}
```

## 3. Safe Cleanup with Confirmation Prompts
Before deleting any files, the program asks the user for confirmation:
```
bool confirm_action(void)
{
    char answer;
    do
    {
        answer = get_char(RED "Are you sure you want to clean? (y/n): " RESET);
        if (answer == 'y' || answer == 'Y') return true;
        else if (answer == 'n' || answer == 'N') return false;
        else printf("Invalid input, type y or n.\n");
    } while(true);
}
```
 
## 4. Color-Coded Terminal Output
The program uses ANSI escape codes to display colored messages, improving readability:
 - Green: Success or important information
 - Yellow: Warnings or prompts
 - Red: Errors
```
#define YELLOW "\033[0;33m"
#define GREEN "\033[0;32m"
#define RESET "\033[0m"
```

# Libraries and Tools Used
- `cs50.h`: Used for simple input handling like `get_char()` and `get_string()`. 
- `unistd.h`: Provides the `sleep()` function to introduce delays, making the CLI more dynamic and visually interactive.
- `dirent.h` and `sys/stat.h`: Used for directory traversal and file status checks, enabling recursive scanning and cleanup.
- `stdio.h` and `stdlib.h`: Standard C libraries for `input/output` operations and `memory management`.

# Code Structure
The project is organized across several files for modularity and readability:
1. main.c
 - Entry point of the program
 - Displays the logo and welcome message
 - Handles the main loop of the menu
 - Delegates cleaning tasks to read_and_clean()
2. menu_cli.c
 - Displays the menu
 - Handles input validation
 - Shows welcome messages and user prompts
3. cleaner.c
 - Handles routing the user’s choice to the correct cleanup function.
 - Manages the program’s exit flow.
4. core.c
 - Performs directory scanning, size calculation, and cleanup
 - Handles the recursive functions for directory traversal
 - Confirms user actions before deletion
 - This separation of concerns ensures the program is maintainable, easy to read, and extendable.

## Example of Program Flow
- User opens the program → logo and welcome message appear
- User selects an option → e.g., Cleanup Caches
- Program asks for confirmation → user types 'y'
- Program calculates directory size → shows progress with dots
- Program deletes files → shows progress and freed space
- User returns to menu → repeats or exits


# Why This Project Matters
Xcode projects generate a lot of temporary and cached data. For developers working with multiple simulators or large projects, storage issues can slow down development or even crash the system. This tool automates the cleanup process safely, saving developers time while maintaining control over their files.

# Installation & Usage
1. Clone the repository:
```
git clone https://github.com/meunomeecris/Harvard-CS50.git
```
2. Navigate to the project directory and compile using the Makefile:
```
make
```
3. Run the program:
```
./run
```
4. Follow the menu prompts to clean directories safely.


# Contact me 
[Linkedin](https://www.linkedin.com/in/meunomeecris/) | 
 <a href="(meunomeecriss@gmail.com)"> Email </a>

Thanks to the entire CS50 crew for an amazing course. <3



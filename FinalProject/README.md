# Mac Cleanup for iOS Developer in C
#### Video Demo: <URL HERE>
#### Description:
                      
## Mac Cleanup in C (CLI)
- A friendly CLI UI (colored output, clear messages).
- Scans specific user folders (Caches, Logs, Cookies, CrashReporter, Xcode DerivedData, Xcode Archives).
- Computes sizes before and after cleanup.
- Safety-first: confirmation message before cleaning.

## Project Setup
- Project foundation & CLI menu
- Directory scanning and size calculation
- Cleaning process
- Map all targets & integrate menu
- Polish, testing & final checks

# Mac Cleanup has three main modules:
 - main.c: where everything starts. It calls menu_cli() (for user input) and then passes that choice to read_and_clean() (to execute the cleanup).
 - menu_cli.c: handles user experience (display, input, validation).
 - core.c: does the system work: builds paths, calculates sizes, and cleans directories.

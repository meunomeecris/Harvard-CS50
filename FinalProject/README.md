# MC Cleaner in C (CLI)
#### Video Demo: <URL HERE>
#### Description:

## MC Cleaner in C (CLI)
- Scans specific user folders (Caches, Logs, Cookies, CrashReporter, Xcode DerivedData, Xcode Archives).
- Computes sizes before and after cleanup.
- Supports a dry-run mode (simulate deletion) and a confirm/interactive mode (menu).
- Logs actions to a log file on the Desktop.
- Has friendly CLI UI (colored output, clear messages).
- Safety-first: never delete outside target paths; run tests in a temporary directory first.

## Project Setup
Week 1: Project foundation & CLI menu
Week 2: Directory scanning and size calculation
Week 3: Cleaning process (dry-run / real)
Week 4: Map all targets & integrate menu
Week 5: Logging & summary
Week 6: Polish, testing & final checks


cc cleaner.c -o cleaner cs50.c menu_cli.c core.c 

# Directory scanning and size calculation
Users/meunomeecris/Library/Caches

Cleaning MACBOOK
~/Library/Caches
~/Library/Logs
~/Library/Cookies

# Terminal commands
rm -rf ~/Library/Developer/Xcode/Archives/*
rm -rf ~/Library/Developer/Xcode/DerivedData
rm -rf ~/Library/Caches/com.apple.dt.Xcode


# Mac cleanup
# Cleanup Caches
echo "⏳ Cache size before:"
cache_before=$(get_size_bytes "$USER_HOME/Library/Caches")
du -sh "$USER_HOME/Library/Caches"
rm -rf "$USER_HOME/Library/Caches"/*
cache_after=$(get_size_bytes "$USER_HOME/Library/Caches")
freed_cache=$((cache_before - cache_after))
total_freed=$((total_freed + freed_cache))
echo "✨ Cache size after:"
du -sh "$USER_HOME/Library/Caches"
echo



--
Your program has three main modules:
main.c — where everything starts.
It calls menu_cli() (for user input) and then passes that choice to read_and_clean() (to execute the cleanup).
menu_cli.c — handles user experience (display, input, validation).
core.c — does the system work: builds paths, calculates sizes, and cleans directories.

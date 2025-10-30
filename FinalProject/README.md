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


cc cleaner.c -o cleaner cs50.c menu_cli.c
# Oolong No Idle Sleep
A CLI application to keep a Mac from sleeping.

The Mac has two ways to not sleep:
 - `kIOPMAssertionTypeNoIdleSleep` - Keeps the operating system running.
 - `kIOPMAssertionTypeNoDisplaySleep` - Keeps the display showing

This application doesn't stop display sleep but does stop idle sleep.
Quit the application with Ctrl-C.

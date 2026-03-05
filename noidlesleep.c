#include <CoreFoundation/CoreFoundation.h>
#include <IOKit/pwr_mgt/IOPMLib.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static IOPMAssertionID gAssertionID = kIOPMNullAssertionID;

static void cleanup_and_exit(int sig) {
    if (gAssertionID != kIOPMNullAssertionID) {
        IOPMAssertionRelease(gAssertionID);
        gAssertionID = kIOPMNullAssertionID;
    }
    _exit(128 + sig);
}

int main(void) {
    signal(SIGINT, cleanup_and_exit);
    signal(SIGTERM, cleanup_and_exit);

    CFStringRef reason = CFSTR("Keep Mac awake while this CLI runs");
    IOReturn rc = IOPMAssertionCreateWithName(
        kIOPMAssertionTypeNoIdleSleep,
        kIOPMAssertionLevelOn,
        reason,
        &gAssertionID
    );

    if (rc != kIOReturnSuccess) {
        fprintf(stderr, "Failed to create assertion: 0x%x\n", rc);
        return 1;
    }

    printf("NoIdleSleep assertion active. Press Ctrl-C to stop.\n");
    while (1) pause();
}

#ifdef _WIN32
#error "This should be used only on linux!"
#endif
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "ERROR: No file to run provided.\n");
        exit(1);
    }
    char ch_command[1024];
    snprintf(ch_command, 1024, "chmod +x %s", argv[1]);
    system(ch_command);
    
    char *terminal = getenv("TERMINAL");
    if (terminal == NULL) {
        terminal = "gnome-terminal";
    }

    char run_command[1024];
    snprintf(run_command, 1024, "%s -- %s -c '%s; bash -i'", terminal, getenv("SHELL"), argv[1]);
    system(run_command);

    return EXIT_SUCCESS;
}



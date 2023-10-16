#include <stdbool.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* find(char*, char*);

int main(void) {
    char* online = find("/sys/class/power_supply", "online"); // only one AC sysfs dir. TODO: true assumption?

    if (online != NULL) {
        printf("Found online file at: %s\n", online);
        free(online);
    }

    return 0;
}

/*
 * Recursively search a given path for a given file name
 * Returns allocated string representing full path to file, or NULL if not found
 */
char* find(char* path, char* name) {
    DIR* dir = opendir(path);

    if (dir == NULL) {
        fprintf(stderr, "Failed to open %s\n", path);
        return NULL;
    }

    bool found = false;
    char* rpath = NULL;
    struct dirent* entry;

    while ((entry = readdir(dir))) {
        if (strncmp(entry->d_name, ".", 1) == 0 || strncmp(entry->d_name, "..", 2) == 0)
            continue;

        if (entry->d_type == DT_REG && strcmp(entry->d_name, name) == 0) {
            found = true;
            break;
        }
        else if (entry->d_type == DT_DIR || entry->d_type == DT_LNK) {
            //                       v '/' char                  v '\0' NULL terminator
            int len = strlen(path) + 1 + strlen(entry->d_name) + 1;
            char* ndir = malloc(len * sizeof(char));
            
            snprintf(ndir, len, "%s/%s", path, entry->d_name);

            rpath = find(ndir, name);
            free(ndir);

            if (rpath != NULL) {
                found = true;
                break;
            }
        }
    }

    if (found && rpath == NULL) {
        //                       v '/' char         v '\0' NULL terminator
        int len = strlen(path) + 1 + strlen(name) + 1;
        rpath = malloc(len * sizeof(char));

        snprintf(rpath, len, "%s/%s", path, name);
    }

    closedir(dir);

    return rpath;
}

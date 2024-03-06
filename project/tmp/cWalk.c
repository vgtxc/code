#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

void traverse_dir(const char *dir_path);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    traverse_dir(argv[1]);

    return 0;
}

void traverse_dir(const char *dir_path) {
    DIR *dir;
    struct dirent *entry;
    struct stat st;
    char path[PATH_MAX];

    if ((dir = opendir(dir_path)) == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(path, sizeof(path), "%s/%s", dir_path, entry->d_name);
        if (lstat(path, &st) == -1) {
            perror("lstat");
            exit(EXIT_FAILURE);
        }

        printf("%s", path);
        if (S_ISDIR(st.st_mode)) {
            printf("/");
            traverse_dir(path);
        }
        printf("\n");
    }

    closedir(dir);
}

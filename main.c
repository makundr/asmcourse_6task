#include <string.h>

int main(int argc, char** argv) {
    for (int i = 0; i < argc; ++i) {
        if (!strcmp(argv[i], "--help")) {
            help();
        }
    }
}
#include "header.h"

int main(int argc, char** argv) {
    for (int i = 0; i < argc; ++i) {
        if (!strcmp(argv[i], "--help")) {
            help();
        } else if (!strcmp(argv[i], "--test_root")) {
            test_root();
        } else if (!strcmp(argv[i], "--test_integral")) {
            test_integral();
        }
    }

    return 0;
}
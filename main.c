#include "header.h"

int main(int argc, char** argv) {
    for (int i = 0; i < argc; ++i) {
        if (!strcmp(argv[i], "--help")) {
            help();
        } else if (!strcmp(argv[i], "--test_root")) {
            test_root();
        } else if (!strcmp(argv[i], "--test_integral")) {
            test_integral();
        } else if (!strcmp(argv[i], "--count_iterations")) {
            count_iterations();
        } else if (!strcmp(argv[i], "--print_absciss")) {
            print_absciss();
        }
    }

    return 0;
}
#include "header.h"

int main(int argc, char** argv) {
    if (argc == 1) {
        print_res();
    }
    for (int i = 1; i < argc; ++i) {
        printf("\t------------------------\n");
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
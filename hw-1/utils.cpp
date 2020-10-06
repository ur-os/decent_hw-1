//
// Created by ur0s on 10/1/20.
//
#include "utils.hpp"

std::string *parse_prog_args(int argc, char *argv[]) {
    auto *argsuments = new std::string[4];

    for (int i = 0, j = 0, k = 0; i < argc; i++) {
        if (strstr(argv[i], "--")) {
            while (j < i) {
                argsuments[k] += argv[j++];
                argsuments[k] += " ";
            }
            j = i + 1;
            k++;
        }
        if ((i == argc - 1) and j <= i)
            while (j <= i) {
                argsuments[k] += argv[j++];
            }
    }

    for (int i = 0; i < 4; i++) {
        argsuments[i].erase(std::remove(argsuments[i].begin(),
                                argsuments[i].end(), '\''),
                                argsuments[i].end());
        argsuments[i].erase(std::remove(argsuments[i].begin(),
                                argsuments[i].end(), '\\'),
                                argsuments[i].end());
        argsuments[i].erase(std::remove(argsuments[i].begin(),
                                argsuments[i].end(), '\"'),
                                argsuments[i].end());
    }
    args a = {
            &argsuments[1],
            std::stoi(argsuments[2]),
            std::stoi(argsuments[3])
    };

    return args;
}
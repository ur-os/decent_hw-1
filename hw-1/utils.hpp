//
// Created by ur0s on 10/6/20.
//

#ifndef MAIN_CPP_UTILS_HPP
#define MAIN_CPP_UTILS_HPP

#include <string>
#include <cstring>
#include <algorithm>

typedef struct args {
    std::string* path;
    int n_tickets;
    int seed_part;
} Args;

Args parse_prog_args(int argc, char *argv[]);

#endif //MAIN_CPP_UTILS_HPP

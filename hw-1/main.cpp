#include <iostream>
#include <string>
#include <fstream>
#include "aes256.hpp"
#include "utils.hpp"






//
//int main(int argc, char* argv[]) {
//    std::string* args = parse_prog_args(argc, argv);
//    srand(std::stoi(args[3]));
//    for (int i = 0; i < std::stoi(args[2]); ++i) {
//        std::cout << rand() % std::stoi(args[2]) + 1 << '\n';
//    }
//
//
//    return 0;
//}

int main(int argc, char *argv[]) {
    std::string *args = parse_prog_args(argc, argv);
    std::ifstream stud_names;
    stud_names.open(argv[1]);


    std::string stud_name;
    while (stud_names >> stud_name >> stud_name) {
        ByteArray salt;
        for (auto i: (std::string) argv[3])
            salt.push_back(i);

        ByteArray name;
        for (auto i: stud_name)
            name.push_back(i);
        for (auto i: name)
            std::cout << i;

        ByteArray result;
        Aes256::encrypt(salt, name, result);

        std::cout << ' ';
        std::string res, res2, res3;
        for (int j = 0; j < 18; j++) {
            res += std::to_string((int) result[j] % 10);
        }
        std::cout << std::stoul(res) % (std::stoi(argv[2])) << '\n';

        for (int j = 19; j < 38; j++) {
            res2 += std::to_string((int) result[j] % 10);
        }
        std::cout << (std::stoul(res) ^ std::stoul(res2)) % std::stoi(argv[2]) << '\n';

        for (int j = 39; j < 58; j++) {
            res3 += std::to_string((int) result[j] % 10);
        }
        std::cout << ((std::stoul(res)
                       ^ std::stoul(res2)
                       ^ std::stoul(res3))
                      % (std::stoi(argv[2]) + 1))
                  << '\n';
    }


    return 0;
}

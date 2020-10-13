#include <fstream>
#include "aes256.hpp"
#include "utils.hpp"

int main(int argc, char *argv[]) {
    args args = parse_prog_args(argc, argv);

    std::ifstream stud_names;
    stud_names.open(args.path);
    if (stud_names.is_open() == 0) {
        std::cout << "File not found" << ". Now path is: \"" << args.path << '\"';
        return 1;
    }

    std::string stud_name;
    while (stud_names.eof() != 1) {
        getline(stud_names, stud_name);
        ByteArray name;
        for (auto i: stud_name)
            name.push_back(i);
        for (auto i: name)
            std::cout << i;
        std::cout << ": ";

        ByteArray salt;
        for (auto i: std::to_string(args.seed_part))
            salt.push_back(i);

        ByteArray result;
        Aes256::encrypt(salt, name, result);
        std::string hash_part_1, hash_part_2, hash_part_3;
        for (int j = 0; j < 18; j++)
            hash_part_1 += std::to_string((int) result[j] % 10);
        for (int j = 19; j < 38; j++)
            hash_part_2 += std::to_string((int) result[j] % 10);
        for (int j = 39; j < 58; j++)
            hash_part_3 += std::to_string((int) result[j] % 10);

        std::cout << ((std::stoul(hash_part_1)
                       ^ std::stoul(hash_part_2)
                       ^ std::stoul(hash_part_3))
                      % (args.n_tickets + 1)) + 1
                  << '\n';
    }


    return 0;
}

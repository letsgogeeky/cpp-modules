#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./btc [path_to_input_file]" << std::endl;
        return 1;
    }
    std::string path = argv[1];
    std::string db_path = "db/data.csv";
    BitcoinExchange bitcoinExchange(db_path);
    bitcoinExchange.processInput(path);
    return 0;
}
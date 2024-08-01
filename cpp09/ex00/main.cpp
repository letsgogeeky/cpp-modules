#include <iostream>
#include "BitcoinExchange.hpp"

void logException(const std::exception &e)
{
	std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./btc [path_to_input_file]" << std::endl;
        return 1;
    }
    std::string path = argv[1];
    std::string db_path = "db/data.csv";
	try
	{
		BitcoinExchange bitcoinExchange(db_path);
		bitcoinExchange.processInput(path);
	}
	catch(const std::exception& e)
	{
		logException(e);
		return 1;
	}
	return 0;
}

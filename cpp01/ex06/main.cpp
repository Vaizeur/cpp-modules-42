
#include "Harl.hpp"

int main(int argc, char const *argv[])
{
    Harl harl;
 
    if (argc != 2)
    {
        harl.complain("");
        return (0);
    }
    std::string level = argv[1];
    harl.complain(level);
    return 0;
}
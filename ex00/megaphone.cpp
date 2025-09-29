#include <iostream>
#include <string>
#include <cctype>

std::string to_upper(const std::string& str)
{
    std::string result = str;
    for (size_t i = 0; i < result.length(); i++)
        result[i] = std::toupper(result[i]);
    return result;
}

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
            std::cout << to_upper(argv[i]);
        std::cout << std::endl;
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return 0;
}
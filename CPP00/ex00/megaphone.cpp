#include <iostream>
#include <cstdlib>

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        exit(1);
    }
    else
    {
        for (int i = 1; argv[i]; i++)
        {
            if (i != 1)
                std::cout << " ";
            for (int j = 0; argv[i][j]; j++)
            {
                if (argv[i][j] >= 97 && argv[i][j] <= 122)
                    argv[i][j] -= 32;
                std::cout << argv[i][j];
            }
        }
    }
    std::cout << std::endl;
}
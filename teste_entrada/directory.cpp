#include <string>
#include <vector>
#include <iostream>

std::vector<std::string> getLocations(const std::string& path)
{
    std::vector<std::string> locations;
    std::string current;
    size_t i = 0;

    while (i < path.length())
    {
        if (path[i] == '/')
        {
            size_t next = path.find('/', i + 1);
            if (next == std::string::npos)
                break;

            current = path.substr(0, next);
            locations.push_back(current);
            i = next;
        }
        else
            i++;
    }

    return locations;
}


int main (int argc, char **argv){
    std::vector<std::string> test = getLocations(argv[1]);

    for (size_t i = 0; i < test.size(); i++)
        std::cout << test[i] << std::endl;

}
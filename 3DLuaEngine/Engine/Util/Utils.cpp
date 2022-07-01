#include "Utils.h"

std::list<char*> Utils::readPathAsLines(char* path)
{
    std::list<char*> returnList;

    std::ifstream ifs = std::ifstream(path, std::ios_base::in);
    if (ifs.is_open() == true) {
        char c; int i = 0; char arr[100];
        while (ifs.get(c)) {
            arr[i] = c;
            i++;
        }
        ifs.close(); arr[i] = '\0'; std::cout << arr << std::endl;
        returnList.insert(returnList.begin(),
            std::begin(arr),
            std::end(arr));
    }
    else
        std::cout << "File could not be open!" << std::endl;

    return returnList;
}

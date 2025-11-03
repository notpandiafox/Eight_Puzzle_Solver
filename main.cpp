#include "lib/AStar.h"
#include "lib/interface.h"

int main(int argc, char const *argv[])

{
    std::vector<std::vector<char>> puzzle{
        {'a','b','c'},
        {'d','e','f'},
        {'g','h', 'i'}
    };

    introPrint();
    chooseWhere(puzzle);

    return 0;
}

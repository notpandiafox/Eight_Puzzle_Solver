#include "lib/AStar.h"
#include "lib/interface.h"

int main(int argc, char const *argv[])

{
    std::vector<std::vector<int>> DefaultPuzzle{
        {'a','b','c'},
        {'d','e','f'},
        {'g','h', 'i'}
    };

    std::vector<std::vector<int>> GoalPuzzle{
        {'1','2','3'},
        {'4','5','6'},
        {'7','8', ' '}
    };

    introPrint();
    chooseWhere(DefaultPuzzle);

    return 0;
}

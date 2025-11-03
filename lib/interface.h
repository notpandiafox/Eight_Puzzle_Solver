#include <iostream>
#include <vector>

void introPrint();
void printIntroMap(std::vector<std::vector<char>>& puzzle);
void printLongVert();
void chooseWhere(std::vector<std::vector<char>>& puzzle);

const char LONG_VERTICAL = '|';
const char LONG_HORIZONTAL = '-';

void introPrint()
{
    std::cout << "Welcome to Oscar's and Terek's eight puzzle solver" << std::endl;
}

//assuming that the 2d array is filled with letters and ready to be filled up.
void chooseWhere(std::vector<std::vector<char>>& puzzle)
{
    char input{};
    int count{1};

    while(count < 9)
    {
        printIntroMap(puzzle);
        std::cout << "where will you put " << count << ": (a - i only) ";
        std::cin >> input;

        if(input >= 'a' &&  input  <= 'i')
        {
            int index = input - 'a';
            int row = index / 3;
            int col = index % 3;

            if (puzzle[row][col] >= 'a' && puzzle[row][col] <= 'i')
            {
                puzzle[row][col] = '0' + count;  
                count++;
            }
            else
            {
                std::cout << "That spot is already taken!" << std::endl;;
            }
        }
        else
        {
            std::cout << "Invalid input! Enter letters a-i only." << std::endl;
            ;
        }
        
    }

}

void printIntroMap(std::vector<std::vector<char>>& puzzle)
{    

    for(int i = 0; i < 3; ++i)
    {
        printLongVert();
        std::cout << " " << puzzle[i][0] << " " << LONG_VERTICAL << " " << puzzle[i][1] 
        << " " << LONG_VERTICAL << " " << puzzle[i][2] << " " << std::endl;
        printLongVert();


        if(i <= 1)    
        {
            for(int j = 0; j < 11; ++j)
            {
                std::cout << LONG_HORIZONTAL;
                if(j == 10)
                    std::cout << std::endl;
            }
        }
    }
}

void printLongVert()
{
    std::cout << "   " << LONG_VERTICAL << "   " << LONG_VERTICAL << std::endl;
};
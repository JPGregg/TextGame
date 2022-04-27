/**********************************************************************************************************************
 * Name: Jonathan Gregg
 * Date: 12/03/2019
 * Description: main file for the iteration vs recursion program.
 *********************************************************************************************************************/

#include "Menu.hpp"
#include <cstdlib>
#include <ctime>

int main() {
    unsigned seed;
    seed = std::time(0);
    std::srand(seed);
Menu menu;
menu.start();
    return 0;
}
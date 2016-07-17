#include "cstdlib"
#include "ctime"
#include "iostream"
#include "TowersGrid.h"
#include "VectorFunctions.h"
using namespace std;

int main(int argc, char** argv)
{
    srand( time(0) );
    
	// make sure game size is given
	if (argc == 1)
	{
		cout << "usage: ./a.out <grid size>\n";
		return 1;
	}

    // declare the board
    TowersGrid game( atoi(argv[1]) );
    
    // generate the heights
    game.generate();
    
    // show the generated grid
    game.display();
}
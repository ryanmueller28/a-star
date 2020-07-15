#include "a-star.h"
using namespace astar;

int main(int argc, char** argv)
{
    //get arguments from command line
    int rows, columns, high, low, xStart, yStart, xEnd, yEnd, barriers;
    int arr[9];

    if(argc == 9){
        for(int i = 1; i < argc; i++){
            arr[i] = atoi(argv[i]); 
        }
    } else {
        std::cout << "You did not provide enough arguments to run a-star." << std::endl;
        std::cout << "The command to run a-star should be." << std::endl;
        std::cout << "./a-star rows columns high low xStart yStart xEnd yEnd barriers" << std::endl;
    }

    rows = arr[0];
    columns = arr[1];
    high = arr[2];
    low = arr[3];
    xStart = arr[4];
    yStart = arr[5];
    xEnd = arr[6];
    yEnd = arr[7];
    barriers = arr[8];

    //create grid of numbers
    std::vector<std::vector<int> > vect = createGrid(rows, columns, low, high);

    //add barriers (int high, int xStart, int yStart, int xEnd, int yEnd, int barriers
    vect = addBarriers(high, xStart, yStart, xEnd, yEnd, barriers, vect);

    return EXIT_SUCCESS;
}
#include "Util.h"
//#include "Cell.h"

Cell**** Util::init(int population_size,int z_dim,int y_dim,int x_dim)
{
//Creating dynamic Array of cells
    Cell ****array_of_cells = new Cell ***[z_dim];
    for (int k = 0; k < z_dim; k++)
    {
        array_of_cells[k] = new Cell **[y_dim];
        for(int j= 0; j < y_dim; j++)
        {
            array_of_cells[k][j] = new Cell *[x_dim];
            for (int i = 0; i < x_dim; i++ )
            {
                array_of_cells[k][j][i] = new Cell(k,j,i);
            }
        }
    }

    srand(time(NULL)); //Seed random

    int maxPop = y_dim * x_dim;
    int y_rand;
    int x_rand;
    int k = z_dim - 1;
    if (population_size > maxPop)population_size = maxPop;

    //Fill Array with initial population
for (int i =0;i<population_size;i++){
        do{
            x_rand = rand() % x_dim ;
            y_rand = rand() % y_dim;
        }while(!array_of_cells[k][y_rand][x_rand]->getMember());

        int k = 0; //TODO: this is the environment variable
        Person *myPerson = new Person;
        delete array_of_cells[k][y_rand][x_rand];
        array_of_cells[k][y_rand][x_rand] = new Cell(myPerson,k,y_rand,x_rand);
}


    return array_of_cells;
}

void Util::move_rand(Cell**** array_of_cells,int population_size,int z_dim,int y_dim,int x_dim)
{
    for (int i = 0; i < population_size; i++)
    {
        int x_rand = rand() % x_dim ;
        int y_rand = rand() % y_dim;
        int k = 0; //TODO: this is the environment variable
        Person *myPerson = new Person;
        array_of_cells[k][y_rand][x_rand]->clearCell();
        array_of_cells[k][y_rand][x_rand] = new Cell(myPerson,k,y_rand,x_rand);
    }//*/


}


void Util::move_up(Cell**** array_of_cells,Cell* cell,int y_dim)
{
    Position currPos = cell->getCellPosition();
    int k = currPos.z, j = currPos.y, i = currPos.x;
    if (j > 0 && (array_of_cells[k][j - 1][i]->getMember()) == -1)
    {
        *array_of_cells[k][j - 1][i]=*cell;
        cell->clearCell();
    }

    else if(j == 0 && array_of_cells[k][y_dim - 1][i]->getMember() == -1)
    {
        *array_of_cells[k][y_dim -1][i]=*cell;
        cell->clearCell();
    }

}

void Util::move_down(Cell ****array_of_cells,Cell *cell,int y_dim)
{
    Position currPos = cell->getCellPosition();
    int k = currPos.z, j = currPos.y, i = currPos.x;
    if (j < y_dim-1 && (array_of_cells[k][j + 1][i]->getMember()) == -1)
    {
        *array_of_cells[k][j + 1][i] = *cell;
        cell->clearCell();
    }

    else if(j == y_dim -1 && array_of_cells[k][0][i]->getMember() == -1)
    {
        *array_of_cells[k][0][i]=*cell;
        cell->clearCell();
    }

}

void Util::move_right(Cell****array_of_cells,Cell *cell,int x_dim)
{
    Position currPos = cell->getCellPosition();
    int k = currPos.z, j = currPos.y, i = currPos.x;
    if (i < x_dim - 1 && (array_of_cells[k][j][i + 1]->getMember()) == -1)
    {
        *array_of_cells[k][j][i + 1] = *cell;
        cell->clearCell();
    }
    else if(i == x_dim - 1 && (array_of_cells[k][j][0]->getMember()) == -1)
    {
        *array_of_cells[k][j][0] = *cell;
        cell->clearCell();
    }
}

void Util::move_left(Cell****array_of_cells,Cell *cell,int x_dim)
{
    Position currPos = cell->getCellPosition();
    int k = currPos.z, j = currPos.y, i = currPos.x;
    if (i > 0 && (array_of_cells[k][j][i - 1]->getMember()) == -1)
    {
        *array_of_cells[k][j][i - 1] = *cell;
        cell->clearCell();
    }
    else if(i == 0 && (array_of_cells[k][j][x_dim - 1]->getMember()) == -1)
    {
        *array_of_cells[k][j][x_dim -1] = *cell;
        cell->clearCell();

    }
}

void Util::move_cell(Cell**** array_of_cells,int z_dim,int y_dim,int x_dim)
{
    int x_rand = rand() % x_dim ;
    int y_rand = rand() % y_dim;
    int func_call = rand() % 3;

    if (!(array_of_cells[0][y_rand][x_rand]->getMember()))
    {
        switch(func_call)
        {
        case 0:
            move_up(array_of_cells,array_of_cells[0][y_rand][x_rand],y_dim);
            break;
        case 1:
            move_down(array_of_cells,array_of_cells[0][y_rand][x_rand],y_dim);
            break;
        case 2:
            move_left(array_of_cells,array_of_cells[0][y_rand][x_rand],x_dim);
            break;
        case 3:
            move_right(array_of_cells,array_of_cells[0][y_rand][x_rand],x_dim);
            break;
        default:
            break;
        }


    }
    else {;}

}






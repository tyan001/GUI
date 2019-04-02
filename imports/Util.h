#ifndef UTIL_H
#define UTIL_H
#include "Cell.h"

class Util{
    public:

typedef void(*func)(Cell****,Cell*,int);                                //Creates type (func)
func *functions = new func[3];


static Cell**** init(int,int,int,int);
static void move_cell(Cell****,int z_dim,int y_dim,int x_dim);
static void move_up(Cell****,Cell *,int);
static void move_down(Cell****,Cell* ,int);

static void move_right(Cell****,Cell* ,int);
static void move_left(Cell****,Cell* ,int);
void move_rand(Cell**** array_of_cells,int population_size,int x_dim,int y_dim,int z_dim);


};

#endif

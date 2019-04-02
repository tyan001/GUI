#ifndef CELL_H
#define CELL_H

#include "Person.h"
#include "Building.h"
#include "Position.h"

#define EMPTY -1
#define PERSON 0
#define HOUSE 1

class Cell{
    public:
        ~Cell(){}

        Cell(int,int,int);

        Cell(Person*,int, int, int);

        void addMember(int);

        wxBitmap getBitmap(void);
        void addMember(Person*);
        void addMember(Building*);
        void displayMember(void);
        void tick (void);
        void clearCell(void);
        Position getCellPosition(void);
        void setBitmap(wxBitmap);
        int getMember(void);
        //void operator =(Cell);

    private:
        wxBitmap bitmap = wxBitmap(wxT("./myImage.png"), wxBITMAP_TYPE_PNG);
        Position cell_position;
        Person *currPerson;
        Building *currBuilding;

        int member;


};

#endif // CELL_H

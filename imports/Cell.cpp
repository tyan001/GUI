#include "Cell.h"
Cell::Cell(Person*,int z, int y, int x){
    cell_position.x = x;
    cell_position.y = y;
    cell_position.z = z;
    bitmap = wxBitmap(wxT("./myImage.png"),wxBITMAP_TYPE_PNG);
    member = PERSON;
}

Cell::Cell(int z, int x,int y){
    cell_position.x = x;
    cell_position.y = y;
    cell_position.z = z;
    member = EMPTY;
    bitmap = wxBitmap(wxT("./cellBackground.png"),wxBITMAP_TYPE_PNG);
}

void Cell::addMember(int memberToAdd){
    switch(memberToAdd){
    case 0:
        member = PERSON;
        bitmap = wxBitmap(wxT("./myImage.png"),wxBITMAP_TYPE_PNG);
        break;
    case 1:
        member = HOUSE;
        bitmap = wxBitmap(wxT("./house.png"),wxBITMAP_TYPE_PNG);
        break;
    }
}

void Cell::addMember(Person* personToAdd){
    currPerson = personToAdd;
    member = PERSON;
}
void Cell::addMember(Building* buildingToAdd){
    currBuilding = buildingToAdd;
   // member = BUILDING;
}

void Cell::clearCell(){
    member = EMPTY;
    bitmap = wxBitmap(wxT("./cellBackground.png"),wxBITMAP_TYPE_PNG);
}

void Cell::displayMember(){
    wxMessageBox(wxT("text"));
}

int Cell::getMember(){
    return member;
}

Position Cell::getCellPosition(){
    return cell_position;
}

wxBitmap Cell::getBitmap(){
    return bitmap;

}

void Cell::setBitmap(wxBitmap bit){
    bitmap = bit;
}



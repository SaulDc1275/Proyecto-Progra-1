#include "Room.h"
int Room::TotalRooms = 1;

Room::Room()
{
    char Row = 'A';
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Columns; j++) {
            Seats[i][j] = new Seat('D', Row, j + 1);
        }
        Row++;
    }

    RoomNumber = TotalRooms ++;
}


Seat* Room::ShowRooms()
{
    ResetTotalRooms();
    printf(" A continuacion la sala #%i \n", RoomNumber);
    

    for (int i = 0; i < Rows; i++) {
        
        for (int j = 0; j < Columns; j++) {
            if (j == 4) {
                printf("\t");
            }
            Seats[i][j]->ShowSeat();

        }
        printf("\n");
    }
    printf("\n");
    printf("\t[_\t_\t_\t_\t_\tP\tA\tN\tT\tA\tL\tL\tA\t_\t_\t_\t_\t_\t_]\n");
    return nullptr;
}

void Room::ResetTotalRooms() {
    TotalRooms = 1;
}

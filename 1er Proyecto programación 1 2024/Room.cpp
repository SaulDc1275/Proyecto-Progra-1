#include "Room.h"
int Room::TotalRooms = 1;

Room::Room()
{
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Columns; j++) {
            Seats[i][j] = 'L';
        }
    }
    RoomNumber = TotalRooms ++;
    
}


void Room::ShowRooms()
{
    
    printf("A continuacion la sala numero: %i \n\t", RoomNumber);
    for (int i = 0; i < Rows; i++) {
        if (i + 1 < 10) {
            printf("  %i  ", i + 1);
        }
        else {
            printf(" %i  ", i + 1);
        }
    }
    printf("\n");

    for (int i = 0; i < Rows; i++) {
        printf("%i\t", i + 1);
        for (int j = 0; j < Columns; j++) {
            printf("| %c |", Seats[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void Room::ResetTotalRooms() {
    TotalRooms = 1;
}

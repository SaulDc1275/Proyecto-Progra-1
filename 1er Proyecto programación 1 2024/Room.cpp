#include "Room.h"


Room::Room()
{
    char Row = 'A';
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Columns; j++) {
            Seats[i][j] = new Seat('D', Row, j + 1);
        }
        Row++;
    }

    
}


Seat* Room::ShowRooms()
{
    
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

void Room::setRoomNumber(int number)
{
    RoomNumber = number;
}

int Room::getRoomNumber() const {
    return RoomNumber;
}


Seat* Room::getSeat(char row, int column) {
    
    int rowIndex = row - 'A';

    
    if (rowIndex >= 0 && rowIndex < Rows && column >= 1 && column <= Columns) {
        return Seats[rowIndex][column - 1];
    }
    else {
        printf(" Asiento invalido. Fila: %c, Columna: %d\n", row, column);
        return nullptr;
    }
}

void Room::ReserveSeat(char row, int column) {
    Seat* seat = getSeat(row, column);
    if (seat != nullptr) {
        seat->setDisponibility('R');
        printf(" El asiento %c-%d ha sido reservado.\n", row, column);
    }
    else {
        printf(" No se pudo reservar el asiento %c-%d.\n", row, column);
    }
}

void Room::OccupyReservedSeats() {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Columns; j++) {
            if (Seats[i][j]->getDisponibility() == 'R') {
                Seats[i][j]->setDisponibility('O');
                printf(" El asiento %c-%d ha sido ocupado.\n", 'A' + i, j + 1);
            }
        }
    }
}
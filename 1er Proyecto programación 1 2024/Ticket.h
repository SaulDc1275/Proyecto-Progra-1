#pragma once
#include "Movie.h"
#include "Room.h"

class Ticket {
private:
    Movie* ChosenMovie;
    Room* ChosenRoom;
    char* ReservedRows;
    int* ReservedColumns;
    int ReservedSeatsCount;
    char TicketCode[10];
    bool isPurchased;
    void GenerateTicketCode();

public:
    Ticket();
    ~Ticket();
    void setTicket(Movie* movie, Room* room, const char* rows, const int* columns, int count);
    void ShowTicket() const;
    const char* getTicketCode() const;
    bool getIsPurchased() const;
    void PurchaseTicket();
    int getReservedSeatsCount() const;
};

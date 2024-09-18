#include "Ticket.h"
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>

Ticket::Ticket(){
    ChosenMovie = nullptr;
    ReservedRows = nullptr;
    ReservedColumns = nullptr;
    ReservedSeatsCount = 0;
    GenerateTicketCode();
}

Ticket::~Ticket() {
    delete[] ReservedRows;
    delete[] ReservedColumns;
}

void Ticket::GenerateTicketCode() {
    const char* prefix = "NCSA";
    srand(static_cast<unsigned>(time(0)));
    int randomNumber = rand() % 1000;

    snprintf(TicketCode, sizeof(TicketCode), "%s%03d", prefix, randomNumber);
}

void Ticket::setTicket(Movie* movie, Room* room, const char* rows, const int* columns, int count) {
    ChosenMovie = movie;
    ChosenRoom = room;

    if (ReservedRows) {
        delete[] ReservedRows;
    }
    if (ReservedColumns) {
        delete[] ReservedColumns;
    }
    ReservedSeatsCount = count;
    ReservedRows = new char[count];
    ReservedColumns = new int[count];
    for (int i = 0; i < count; ++i) {
        ReservedRows[i] = rows[i];
        ReservedColumns[i] = columns[i];
    }
    snprintf(TicketCode, sizeof(TicketCode), "NCSA%03d", rand() % 1000);
    isPurchased = false;
}


void Ticket::ShowTicket() const {
    if (ChosenMovie && ChosenRoom) {
        printf(" Pelicula: %s\n", ChosenMovie->getName());
        printf(" Sala: %d\n", ChosenRoom->getRoomNumber());
        printf(" Asientos reservados:\n");

        for (int i = 0; i < ReservedSeatsCount; ++i) {
            printf(" Fila: %c, Columna: %d\n", ReservedRows[i], ReservedColumns[i]);
        }

        printf(" Codigo del ticket: %s\n", TicketCode);
    }
    else {
        printf(" No se ha asignado ninguna pelicula o sala al ticket.\n");
    }
}


const char* Ticket::getTicketCode() const {
    return TicketCode;
}

bool Ticket::getIsPurchased() const {
    return isPurchased;
}

void Ticket::PurchaseTicket() {
    isPurchased = true;
}

int Ticket::getReservedSeatsCount() const {
    return ReservedSeatsCount;
}

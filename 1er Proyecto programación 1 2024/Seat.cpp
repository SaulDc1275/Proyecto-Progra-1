#include "Seat.h"

Seat::Seat(char Disponibility, char Row, int Column)
{
	this->Disponibility = Disponibility;
	this->Row = Row;
	this->Column = Column;
}

void Seat::ShowSeat()
{
	printf(" [%c-%i \"%c\"] ", Row, Column, Disponibility);
}

void Seat::setDisponibility(char newDisponibility) {
	Disponibility = newDisponibility;
}

char Seat::getDisponibility() {
	return Disponibility;
}
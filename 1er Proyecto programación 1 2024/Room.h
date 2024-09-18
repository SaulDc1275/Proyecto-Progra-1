#pragma once
#include "Seat.h"
class Room
{
private:
	static const int Rows = 9;
	static const int Columns = 14;
	Seat* Seats[Rows][Columns];
	int RoomNumber;
	
public:
	Room();
	Seat* ShowRooms();
	void setRoomNumber(int number);
	int getRoomNumber() const;
	Seat* getSeat(char row, int column);
	void ReserveSeat(char row, int column);
	void OccupyReservedSeats();
};


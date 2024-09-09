#pragma once
#include "Seat.h"
class Room
{
private:
	static const int Rows = 9;
	static const int Columns = 14;
	Seat* Seats[Rows][Columns];
	int RoomNumber;
	static int TotalRooms;
public:
	Room();
	Seat* ShowRooms();
	static void ResetTotalRooms();
};


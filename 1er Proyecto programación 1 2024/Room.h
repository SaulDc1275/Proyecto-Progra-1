#pragma once
#include <stdio.h>
class Room
{
private:
	static const int Rows = 10;
	static const int Columns = 10;
	char Seats[Rows][Columns];
	int RoomNumber;
	static int TotalRooms;
public:
	Room();
	void ShowRooms();
	static void ResetTotalRooms();
};


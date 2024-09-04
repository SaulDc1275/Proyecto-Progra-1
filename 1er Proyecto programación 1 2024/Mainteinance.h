#pragma once
#include <string>
#include "Room.h"
using namespace std;

class Mainteinance : public Room
{
private:
	char Name[100];
	int Year;
	int DurationMins;
	char Country[50];
	char Review[500];
	int AssignedRoom;
	Room* Rooms;
	int RoomsQuantity;

public:
	Mainteinance();
	~Mainteinance();
	void CreateRooms();
	const char* getName();
	int getDuration();
	void SaveMovie();
	void SetMovie(char MovieName[100], int MovieYear, int MovieDurationMins, char MovieCountry[50], char MovieReview[500]);
	void ShowMovie();
	
	
};


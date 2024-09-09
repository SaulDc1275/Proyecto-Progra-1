#pragma once
#include <iostream>
using namespace std;
class Movie
{
private:
	char Name[300];
	int Year;
	int DurationMins;
	char Country[200];
	char Review[500];
	int AssignedRoom;
public:
	const char* getName();
	int getDuration();
	void SetMovie(char MovieName[300], int MovieYear, int MovieDurationMins, char MovieCountry[200], char MovieReview[500], int AssignedRoom);
	void SaveMovie();
	void ShowMovie();
	void setAssignedRoom(int AssignedRoom);
};


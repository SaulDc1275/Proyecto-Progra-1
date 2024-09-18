#pragma once
#include <iostream>
#include "Schedule.h"
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
	Schedule MovieSchedule;
	bool ReadyToSell;
public:
	Movie();
	const char* getName() const;
	int getDuration();
	void SetMovie(char MovieName[300], int MovieYear, int MovieDurationMins, char MovieCountry[200], char MovieReview[500], int AssignedRoom);
	void SaveMovie();
	void ShowMovie();
	void setAssignedRoom(int nAssignedRoom);
	int getAssigneedRoom();
	void AssignMovieSchedule(int day, int month, int year, int hour, int minute);
	void SetReady();
	bool GetReady();
};


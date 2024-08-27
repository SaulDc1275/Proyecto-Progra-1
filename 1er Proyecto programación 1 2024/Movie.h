#pragma once
#include <string>
using namespace std;
class Movie
{
private:
	char Name[100];
	int Year;
	int DurationMins;
	char Country[50];
	char Review[500];
	
public:
	const char* getName();
	int getYear();
	int getDuration();
	const char* getCountry();
	const char* getReview();
	void SaveMovie();
	void SetMovie(char MovieName[100], int MovieYear, int MovieDurationMins, char MovieCountry[50], char MovieReview[500]);
	void ShowMovie();
	
	
};


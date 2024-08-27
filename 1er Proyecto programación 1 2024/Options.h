#pragma once
#include <iostream>
#include <stdio.h>
#include "Movie.h"
class Options : public Movie
{

private:
	Movie* Movies;
	int MoviesQuantity;
	;
public:
	Options();
	~Options();
	int getMoviesQuantity();
	void AddMovie(const Movie& movie);
	int MainMenu(int &option, Options &Choser);
	int FileOption(int &option, Options &Choser);
	int MaintenanceOption(int &option, Options &Choser);
	void ReserveOption(int option, Options Choser);
	void BuyOption(int option, Options Choser);


	;
};


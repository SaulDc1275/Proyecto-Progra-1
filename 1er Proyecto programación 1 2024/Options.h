#pragma once
#include <iostream>
#include <stdio.h>
#include "Mainteinance.h"
class Options : public Mainteinance
{

private:
	Mainteinance* Movies;
	int MoviesQuantity;
	;
public:
	Options();
	~Options();
	int getMoviesQuantity();
	void AddMovie(const Mainteinance& movie, int &nMoviesQuantity);
	int MainMenu(int &option, Options &Choser);
	int FileOption(int &option, Options &Choser);
	int MaintenanceOption(int &option, Options &Choser);
	void ReserveOption(int option, Options Choser);
	void BuyOption(int option, Options Choser);


	;
};


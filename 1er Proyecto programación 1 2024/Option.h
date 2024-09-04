#pragma once
#include <iostream>
#include <stdio.h>
#include "Mainteinance.h"
class Option : public Mainteinance
{

private:
	Mainteinance* Movies;
	int MoviesQuantity;
	bool roomsCreated;
	;
public:
	Option();
	~Option();
	int getMoviesQuantity();
	void AddMovie(const Mainteinance& movie, int &nMoviesQuantity);
	int MainMenu(int &option, Option &Choser);
	int FileOption(int &option, Option &Choser);
	int MaintenanceOption(int &option, Option &Choser);
	void ReserveOption(int option, Option Choser);
	void BuyOption(int option, Option Choser);


	;
};


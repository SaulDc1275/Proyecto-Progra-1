#pragma once
#include <iostream>
#include <stdio.h>
#include "Movie.h"
#include "Mainteinance.h"
#include "Ticket.h"
class Option : public Mainteinance
{

private:
	bool roomsCreated;
	bool reservation;
	
public:
	Option();
	~Option();
	int MainMenu(int &option, Option &Choser);
	int FileOption(int &option, Option &Choser);
	int MaintenanceOption(int &option, Option &Choser);
	void ReserveOption(int option, Option Choser);
	void BuyOption(int option, Option Choser);
	
};


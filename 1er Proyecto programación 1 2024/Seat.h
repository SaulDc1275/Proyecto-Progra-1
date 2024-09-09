#pragma once
#include <stdio.h>
class Seat
{
private:
	char Disponibility;
	char Row;
	int Column;
public:
	Seat(char Disponibility,char Row,int Column);
	void ShowSeat();
};


#pragma once
#include "Room.h"
#include "Movie.h"
#include "Ticket.h"
using namespace std;

class Mainteinance 
{
protected:
	Movie* Movies;
	int MoviesQuantity;
	Movie* MoviesReadyToSell;
	int MoviesReadyToSellQuantity;
	Room* Rooms;
	int RoomsQuantity;
	Ticket* Tickets;
	int TicketsQuantity;

public:
	Mainteinance();
	~Mainteinance();
	void AddMovie(const Movie& movie);
	void AddTicket(const Ticket& ticket);
	void TransferToReadyMovies(const Movie& movie);
	int getMoviesQuantity();
	int getMoviesReadyToSellQuantity();
	void CreateRooms();
	void getMovie(int i);
	void getMovieReadyToSell(int i);
	void setMovieReadyToSell();
	void ShowAllMovies();
	void ShowAllReadyMovies();
	void AssingRoomToMovie();
	void AssignSchedule();
	void MakeAReservation();
	void BuyTicket();
};


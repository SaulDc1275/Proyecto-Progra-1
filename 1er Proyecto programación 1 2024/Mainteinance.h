#pragma once
#include "Room.h"
#include "Movie.h"
using namespace std;

class Mainteinance 
{
protected:
	Movie* Movies;
	int MoviesQuantity;
	Room* Rooms;
	int RoomsQuantity;
public:
	Mainteinance();
	~Mainteinance();
	void AddMovie(const Movie& movie);
	int getMoviesQuantity();
	void CreateRooms();
	void getMovie(int i);
	void ShowAllMovies();
	void AssingRoomToMovie();
	void AssignSchedule();
};


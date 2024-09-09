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
	void DeleteMovie();
	int getMoviesQuantity();
	void CreateRooms();
	void getMovie(int i);
	void ShowAllMovies();
	void AssingRoomToMovie();
	
	
};


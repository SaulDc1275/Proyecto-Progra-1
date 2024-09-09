#include "Mainteinance.h"

Mainteinance::Mainteinance()
{
	Rooms = nullptr;
	Movies = nullptr;
}
Mainteinance::~Mainteinance() {
	delete[] Rooms;
	delete[] Movies;
}



void Mainteinance::AddMovie(const Movie& movie) {
	int currentQuantity = getMoviesQuantity();
	Movie* newMovies = new Movie[currentQuantity + 1];
	for (int i = 0; i < currentQuantity; i++) {
		newMovies[i] = Movies[i];
	}
	newMovies[currentQuantity] = movie;
	delete[] Movies;
	Movies = newMovies;
	MoviesQuantity++;
}

void Mainteinance::DeleteMovie() {
	int movieToEliminate;
	printf("\n Que numero de pelicula desea eliminar?: ");
	scanf_s("%i", &movieToEliminate);
	if (movieToEliminate > 0 || movieToEliminate <= getMoviesQuantity()) {
		Movie* newMovies = new Movie[getMoviesQuantity() - 1];
		int j = 0;
		for (int i = 0; i < getMoviesQuantity(); i++) {
			if (i != movieToEliminate - 1) {
				newMovies[j] = Movies[i];
				j++;
			}
		}

		delete[] Movies;
		Movies = newMovies;
		MoviesQuantity--;
		printf(" La pelicula #%i se ha borrado exitosamente.\n", movieToEliminate);
	}
	else {
		printf(" El numero de pelicula que se ingreso es invalido\n");
	}
	
	
}


int Mainteinance::getMoviesQuantity()
{
	return MoviesQuantity;
}

Movie* Mainteinance::getMovie(int i) {

		Movies[i].ShowMovie();
		return nullptr;
}

Movie* Mainteinance::ShowAllMovies()
{
	printf(" A continuacion estas son todas las peliculas que se han ingresado al sistema:\n");
	for (int i = 0; i < MoviesQuantity; i++) {
		printf("\n Pelicula #%i\n", i + 1);
		Movies[i].ShowMovie();
		
	}
	return nullptr;
}



void Mainteinance::CreateRooms()
{
	
	printf(" Cuantas salas hay en el cine?\n ESTA RESPUESTA SE INGRESA UNA SOLA VEZ, NO SE PODRA CAMBIAR LA CANTIDAD DE SALAS!\n Digite su respuesta: ");
	scanf_s("%i", &RoomsQuantity);
	printf("\n");
	
	Rooms = new Room[RoomsQuantity];
	for (int i = 0; i < RoomsQuantity; i++) {
		Rooms[i].ShowRooms();
	}

}




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

int Mainteinance::getMoviesQuantity()
{
	return MoviesQuantity;
}

void Mainteinance::getMovie(int i) {

		Movies[i].ShowMovie();
		
}

void Mainteinance::ShowAllMovies()
{
	printf(" A continuacion estas son todas las peliculas que se han ingresado al sistema:\n");
	for (int i = 0; i < MoviesQuantity; i++) {
		printf("\n Pelicula #%i\n", i + 1);
		getMovie(i);
		
	}
	
}

void Mainteinance::AssingRoomToMovie()
{
	int RoomNumber = 0;
	int MovieNumber = 0;
	printf(" A que sala desea agregar una pelicula?: ");
	scanf_s("%i", &RoomNumber);
	if (RoomNumber > 0 && RoomNumber <= RoomsQuantity) {
		printf(" Que pelicula desea agregar a la sala #%i? \n\n", RoomNumber);
		for (int i = 0; i < MoviesQuantity; i++) {
			printf(" Pelicula #%i \n", i + 1);
			getMovie(i);
			printf("\n\n");
		}
		printf(" Digite su opcion: ");
		scanf_s("%i", &MovieNumber);
		if (MovieNumber > 0 && MovieNumber <= MoviesQuantity) {
			Movies[MovieNumber - 1].setAssignedRoom(RoomNumber);
			system("PAUSE");
			system("cls");
			printf(" La pelicula #%i ha sido asignada exitosamente a la sala #%i \n", MovieNumber, RoomNumber);
			getMovie(MovieNumber - 1);
		}
		else {
			printf(" El numero de pelicula que digito no existe\n");
		}
	}
	else {
		printf(" El numero de sala que digito no existe\n");
	}
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

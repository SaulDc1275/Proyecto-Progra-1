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
	int RoomNumber = -1;
	int MovieNumber = -1;
	printf(" A cual sala desea agregar una pelicula? \n\n");
	while (RoomNumber <= 0 || RoomNumber > RoomsQuantity) {
		printf(" Digite su opcion: ");
		scanf_s("%i", &RoomNumber);

		if (RoomNumber <= 0 || RoomNumber > RoomsQuantity) {
			printf(" El numero de pelicula que digito no existe. Por favor, ingrese un valor entre 1 y %i.\n", RoomsQuantity);
		}
	}
	system("cls");
	printf(" Que pelicula desea agregar a la sala #%i? \n\n", RoomNumber);
	for (int i = 0; i < MoviesQuantity; i++) {
		printf(" Pelicula #%i \n", i + 1);
		getMovie(i);
		printf("\n\n");
	}

	while (MovieNumber <= 0 || MovieNumber > MoviesQuantity) {
		printf(" Digite su opcion: ");
		scanf_s("%i", &MovieNumber);
		if (MovieNumber <= 0 || MovieNumber > MoviesQuantity) {
			printf(" El numero de pelicula que digito no existe. Por favor, ingrese un valor entre 1 y %i.\n", MoviesQuantity);
		}
	}

	Movies[MovieNumber - 1].setAssignedRoom(RoomNumber);
	system("cls");
	printf(" La pelicula #%i ha sido asignada exitosamente a la sala #%i \n", MovieNumber, RoomNumber);
	getMovie(MovieNumber - 1);	
}
	


void Mainteinance::AssignSchedule()
{
	int MovieNumber = -1;
	printf(" A que pelicula desea asignarle un horario?\n");
	for (int i = 0; i < MoviesQuantity; i++) {
		printf(" Pelicula #%i \n", i + 1);
		getMovie(i);
		printf("\n\n");
	}
	while (MovieNumber <= 0 || MovieNumber > MoviesQuantity) {
		printf(" Digite su opcion: ");
		scanf_s("%i", &MovieNumber);

		if (MovieNumber <= 0 || MovieNumber > MoviesQuantity) {
			printf(" El numero de pelicula que digito no existe. Por favor, ingrese un valor entre 1 y %i.\n", MoviesQuantity);
		}
	}

	int min = -1, hour = -1, day = -1, month = -1, year = -1;


	while (day < 1 || day > 31) {
		printf(" Ingrese el dia en el que va a ser presentada la pelicula (1-31): ");
		scanf_s("%i", &day);

		if (day < 1 || day > 31) {
			printf(" El dia ingresado no es valido. Por favor, ingrese un valor entre 1 y 31.\n");
		}
	}

	while (month < 1 || month > 12) {
		printf(" Ingrese el mes en el que va a ser presentada la pelicula (1-12): ");
		scanf_s("%i", &month);

		if (month < 1 || month > 12) {
			printf(" El mes ingresado no es valido. Por favor, ingrese un valor entre 1 y 12.\n");
		}
	}

	while (year <= 0) {
		printf(" Ingrese el anio en el que va a ser presentada la pelicula: ");
		scanf_s("%i", &year);

		if (year <= 0) {
			printf(" El anio ingresado no es valido. Por favor, ingrese un ano mayor que 0.\n");
		}
	}

	while (hour < 0 || hour >= 24){
		
		printf(" Ingrese la hora de inicio de la pelicula (en formato 24hrs, 0-23): ");
		scanf_s("%i", &hour);

		if (hour < 0 || hour >= 24) {
			printf(" La hora ingresada no es valida. Por favor, ingrese un valor entre 0 y 23.\n");
		}
	}
	while (min < 0 || min >= 60){
		printf(" Ingrese los minutos de inicio de la pelicula (0-59): ");
		scanf_s("%i", &min);

		if (min < 0 || min >= 60) {
			printf(" Los minutos ingresados no son validos. Por favor, ingrese un valor entre 0 y 59.\n");
		}
	}
	
	Movies[MovieNumber - 1].AssignMovieSchedule(day, month, year, hour, min);
	system("cls");
	printf(" A la pelicula #%i se le ha asignado un horario exitosamente\n", MovieNumber);
	getMovie(MovieNumber - 1);
}
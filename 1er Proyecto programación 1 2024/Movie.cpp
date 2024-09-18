#include "Movie.h"

Movie::Movie()
{
	ReadyToSell = false;
}

const char* Movie::getName() const {
	return Name;
}


int Movie::getDuration()
{
	return DurationMins;
}

void Movie::SetMovie(char MovieName[300], int MovieYear, int MovieDurationMins, char MovieCountry[200], char MovieReview[500], int AssignedRoom)
{
	for (int i = 0; i < 300; i++) {
		Name[i] = MovieName[i];
	}
	for (int i = 0; i < 200; i++) {
		Country[i] = MovieCountry[i];
	}
	for (int i = 0; i < 500; i++) {
		Review[i] = MovieReview[i];
	}
	DurationMins = MovieDurationMins;
	Year = MovieYear;
	this->AssignedRoom = AssignedRoom;
}
void Movie::SaveMovie()
{
	char MovieName[300];
	int MovieYear = 0;
	int MovieDurationMins = 0;
	char MovieCountry[200];
	char MovieReview[500];
	int MovieAssignedRoom = 0;
	printf(" Ingrese el nombre de la pelicula: ");
	scanf_s(" %[^\n]", MovieName, (unsigned)_countof(MovieName));
	printf(" Ingrese el anio de publicacion de la pelicula: ");
	scanf_s("%i", &MovieYear);
	printf(" Ingrese la duracion en minutos de la pelicula: ");
	scanf_s("%i", &MovieDurationMins);
	printf(" Ingrese el pais de origen de la pelicula: ");
	scanf_s(" %[^\n]", MovieCountry, (unsigned)_countof(MovieCountry));
	printf(" Ingrese una resenia de la pelicula : ");
	scanf_s(" %[^\n]", MovieReview, (unsigned)_countof(MovieReview));

	SetMovie(MovieName, MovieYear, MovieDurationMins, MovieCountry, MovieReview,MovieAssignedRoom);
}

void Movie::ShowMovie()
{
	printf(" Nombre: %s\n", Name);
	printf(" Anio: %d\n", Year);
	printf(" Duracion: %d minutos\n", DurationMins);
	printf(" Pais: %s\n", Country);
	printf(" Resenia: %s\n", Review);
	if (AssignedRoom > 0) {
		printf(" Sala asignada: %i\n", AssignedRoom);
	}
	MovieSchedule.ShowSchedule();
}

void Movie::setAssignedRoom(int nAssignedRoom) 
{
	AssignedRoom = nAssignedRoom;
}

int Movie::getAssigneedRoom()
{
	return AssignedRoom;
}

void Movie::AssignMovieSchedule(int day, int month, int year, int hour, int minute) {
	MovieSchedule.AssignSchedule(day, month, year, hour, minute);
}

void Movie::SetReady()
{
	if (AssignedRoom > 0 && MovieSchedule.getMinute() > -1) {
		ReadyToSell = true;
	}
}

bool Movie::GetReady()
{
	return ReadyToSell;
}

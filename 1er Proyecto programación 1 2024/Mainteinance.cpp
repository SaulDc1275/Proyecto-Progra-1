#include "Mainteinance.h"

const char* Mainteinance::getName()
{
	return Name;
}

int Mainteinance::getYear()
{
	return Year;
}

int Mainteinance::getDuration()
{
	return DurationMins;
}

const char* Mainteinance::getCountry()
{
	return Country;
}

const char* Mainteinance::getReview()
{
	return Review;
}

void Mainteinance::SaveMovie()
{
	char MovieName[100];
	int MovieYear = 0;
	int MovieDurationMins = 0;
	char MovieCountry[50];
	char MovieReview[500];

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

	SetMovie(MovieName,MovieYear,MovieDurationMins, MovieCountry, MovieReview);

}

void Mainteinance::SetMovie(char MovieName[100], int MovieYear, int MovieDurationMins, char MovieCountry[50], char MovieReview[500])
{
	for (int i = 0; i < 100; i++) {
		Name[i] = MovieName[i];
	}
	for (int i = 0; i < 50; i++) {
		Country[i] = MovieCountry[i];
	}
	for (int i = 0; i < 500; i++) {
		Review[i] = MovieReview[i];
	}
	DurationMins = MovieDurationMins;
	Year = MovieYear;
}

void Mainteinance::ShowMovie()
{
	
	printf(" Nombre: %s\n", Name);
	printf(" Anio: %d\n", Year);
	printf(" Duracion: %d minutos\n", DurationMins);
	printf(" Pais: %s\n", Country);
	printf(" Resenia: %s\n", Review); 
}



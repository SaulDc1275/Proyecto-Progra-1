#include "Options.h"
#include "Movie.h"
Options::Options() : Movies(nullptr), MoviesQuantity(0) {}
Options::~Options()
{
	delete[]Movies;
}
int Options::getMoviesQuantity()
{
	return MoviesQuantity;
}
void Options::AddMovie(const Movie& movie)
{
	Movie* newMovies = new Movie[MoviesQuantity + 1];
	for (int i = 0; i < MoviesQuantity; i++) {
		newMovies[i] = Movies[i];
	}
	newMovies[MoviesQuantity] = movie;
	delete[] Movies;
	Movies = newMovies;
	MoviesQuantity++;
}
int Options::MainMenu(int &option, Options &Chooser)
{
	option = 0;
	system("cls");
	bool leave = false;
	while (!leave) {
		option = 0;
		leave = false;
		printf("\tNUEVA CINEMA SA \n\t      MENU\n\n 1.Archivo\n 2.Mantenimiento\n 3.Reserva\n 4.Venta\n 5.Salir del programa\n Digite su opcion: ");
		scanf_s("%i", &option);
		if (option < 6 && option >0) {
			switch (option)
			{
			case 1:
				system("cls");
				Chooser.FileOption(option, Chooser);
				break;
			case 2:

				Chooser.MaintenanceOption(option, Chooser);
				break;
			case 3:
				Chooser.ReserveOption(option, Chooser);
				break;
			case 4:
				Chooser.BuyOption(option, Chooser);
				break;
			case 5:
				leave = true;
				printf("Saliendo del programa...\n");
				break;
			
			}
		}

		else {
			leave = true;
			printf(" La opcion que digito es incorrecta\n");

		}
	}
	return 0;
}

int Options::FileOption(int &option, Options &Chooser)
{
	bool BackToMainMenu = false;
	while (!BackToMainMenu) {
		
		option = 0;
		printf(" \n");
		printf(" Ha entrado al menu de Archivo.\n");
		printf(" 1.Acerca de\n 2.Volver al menu principal\n Digite su opcion: ");
		scanf_s("%i", &option);
		
		if (option < 3 && option >0) {
			switch (option)
			{
			case 1:
				system("cls");
				
				printf(" Programa echo por Saul Chinchilla Badilla en el anio 2024.\n Para la empresa NUEVA CINEMA SA.\n Atencion al cliente al numero: +506 8788 1170 \n Horario de atencion 9 a.m. - 5 p.m.\n ");
				break;
			case 2:
				system("cls");
				BackToMainMenu = true;
				printf(" Se ha digitado la opcion 2.\n Volviendo al menu principal...\n \n");
				
				break;
			
			}
		}
		else {
			BackToMainMenu = true;
			system("cls");
			printf(" La opcion que digito es incorrecta \n");
			
		}
	}
	return 0;
}

int Options::MaintenanceOption(int &option, Options &Choser)
{
	system("cls");
	bool BackToMainMenu = false;
	while (!BackToMainMenu) {
		option = 0;
		printf(" \n");
		printf(" Ha entrado al menu de Mantenimiento\n");
		printf(" 1. Peliculas\n 2. Salas\n 3.Horarios\n 4.Volver al menu principal\n Digite su opcion: ");
		scanf_s("%i", &option);
		switch (option)
		{
		case 1:
		{
			printf(" Se ha digitado la opcion para guardar una pelicula\n\n");
			Movie newMovie;
			newMovie.SaveMovie();
			AddMovie(newMovie);


			printf("\n\n Su pelicula se ha guardado correctamente, aqui se muestra la pelicula guardada: \n\n");
			if (getMoviesQuantity() > 0) {
				Movies[getMoviesQuantity() - 1].ShowMovie();
			}
			system("PAUSE");
			BackToMainMenu = true;
			system("cls");
		}
			break;
		case 2:
			
			break;
		case 3:
			printf(" Se ha digitado la opcion 3.\n");
			break;
		case 4: 
			system("cls");
			BackToMainMenu = true;
			printf(" Se ha digitado la opcion 4.\n Volviendo al menu principal...\n \n");
		default:
			break;
		}
	}
	return 0;
}

void Options::ReserveOption(int option, Options Choser)
{
	printf(" \n");
	printf(" Se ha digitado la opcion 3.\n");
}

void Options::BuyOption(int option, Options Choser)
{
	printf(" \n");
	printf(" Se ha digitado la opcion 4.\n");
}

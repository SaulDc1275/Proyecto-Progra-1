#include "Option.h"

Option::Option() {
	Movies = nullptr;
	MoviesQuantity = 0;
	roomsCreated = false;
}
Option::~Option()
{
	delete[]Movies;
}
int Option::getMoviesQuantity()
{
	return MoviesQuantity;
}
void Option::AddMovie(const Mainteinance& movie, int &nMoviesQuantity)
{
	Mainteinance* newMovies = new Mainteinance[MoviesQuantity + 1];
	for (int i = 0; i < MoviesQuantity; i++) {
		newMovies[i] = Movies[i];
	}
	newMovies[MoviesQuantity] = movie;
	delete[] Movies;
	Movies = newMovies;
	MoviesQuantity++;
}
int Option::MainMenu(int &option, Option &Chooser)
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

int Option::FileOption(int &option, Option &Chooser)
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
				
				printf("\n Programa echo por Saul Chinchilla Badilla en el anio 2024.\n Para la empresa NUEVA CINEMA SA.\n Atencion al cliente al numero: +506 8788 1170 \n Horario de atencion 9 a.m. - 5 p.m.\n ");
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

int Option::MaintenanceOption(int &option, Option &Choser)
{
	system("cls");
	bool BackToMainMenu = false;
	while (!BackToMainMenu) {
		option = 0;
		printf(" \n");
		printf(" Ha entrado al menu de Mantenimiento\n");
		printf(" 1. Peliculas\n 2. Salas\n 3.Horarios\n 4.Volver al menu principal\n Digite su opcion: ");
		scanf_s("%i", &option);


		if (option < 5 && option >0) {
			switch (option)
			{
			case 1:
			{
				printf(" Se ha digitado la opcion para guardar una pelicula\n\n");
				Mainteinance newMovie;
				newMovie.SaveMovie();
				AddMovie(newMovie, MoviesQuantity);


				printf("\n\n Su pelicula #%i se ha guardado correctamente, aqui se muestra la pelicula guardada: \n\n", MoviesQuantity);
				if (getMoviesQuantity() > 0) {
					Movies[getMoviesQuantity() - 1].ShowMovie();
				}
				system("PAUSE");
				system("cls");
			}
			break;
			case 2:
				printf(" Ha digitado la opcion para agregar una sala \n");
				if (MoviesQuantity != 0) {
					if (!roomsCreated){
						printf(" *ESTA OPCION ES DE UN SOLO USO*\n");
						CreateRooms();
						roomsCreated = true;
					}
					system("PAUSE");
					system("cls");
				}
				else {
					system("cls");
					printf(" No hay ninguna pelicula para agregar a las salas, debe crear una pelicula primero\n ");
					break;
				}

				break;
			case 3:
				printf(" Ha digitado la opcion para asignar los horarios\n");
				printf(" Esta opcion esta fuera de servicio\n");
				system("PAUSE");
				system("cls");
				break;
			case 4:
				system("cls");
				BackToMainMenu = true;
				printf(" Ha vuelto al menu principal\n \n");
			
			
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

void Option::ReserveOption(int option, Option Choser)
{
	printf(" \n");
	printf(" Se ha digitado la opcion 3.\n");
	printf(" Esta opcion esta fuera de servicio\n");
	system("PAUSE");
	system("cls");
}

void Option::BuyOption(int option, Option Choser)
{
	printf(" \n");
	printf(" Se ha digitado la opcion 4.\n");
	printf(" Esta opcion esta fuera de servicio\n");
	system("PAUSE");
	system("cls");
}

#include "Option.h"

Option::Option() {
	
	roomsCreated = false;
}
Option::~Option()
{
	
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
				int moviesOption = 0;
				printf(" Si desea guardar una pelicula digite \"1\", si desea eliminar una pelicula digite \"2\"\n");
				printf(" Digite su opcion: ");
				scanf_s("%i", &moviesOption);
				if (moviesOption == 1) {
					system("cls");
					printf(" Se ha digitado la opcion para guardar una pelicula\n\n");
					Movie newMovie;
					newMovie.SaveMovie();
					AddMovie(newMovie);


					printf("\n\n Su pelicula #%i se ha guardado correctamente, aqui se muestra la pelicula guardada: \n\n", getMoviesQuantity());
					if (getMoviesQuantity() > 0) {
						getMovie(getMoviesQuantity() - 1);
					}
					system("PAUSE");
					system("cls");
					ShowAllMovies();
					system("PAUSE");
					system("cls");
				}
				if (moviesOption == 2) {
					if (getMoviesQuantity() > 0) {
						system("cls");
						printf(" Se ha digitado la opcion para eliminar una pelicula\n\n");
						ShowAllMovies();
						DeleteMovie();
						system("PAUSE");
						system("cls");
						ShowAllMovies();
					}
					else {
						printf(" No hay ninguna pelicula para eliminar\n ");
					}
					system("PAUSE");
					system("cls");
				}
				
			}
			break;
			case 2:
				system("cls");
				printf(" Ha digitado la opcion para agregar una sala \n");
				if (getMoviesQuantity() != 0) {
					if (!roomsCreated){
						CreateRooms();
						roomsCreated = true;
					}
					system("PAUSE");
					AssingRoomToMovie();
					system("PAUSE");
					system("cls");
				}
				else {
					
					printf(" No hay ninguna pelicula para agregar a las salas, debe crear una pelicula primero\n ");
					system("PAUSE");
					system("cls");
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

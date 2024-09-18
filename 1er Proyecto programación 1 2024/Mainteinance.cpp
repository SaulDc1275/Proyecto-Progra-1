#include "Mainteinance.h"
#include <cstring>
Mainteinance::Mainteinance()
{
	Rooms = nullptr;
	Movies = nullptr;
	MoviesQuantity = 0;
	MoviesReadyToSell = nullptr;
	MoviesReadyToSellQuantity = 0;
}
Mainteinance::~Mainteinance() {
	delete[] Rooms;
	delete[] Movies;
	delete[] MoviesReadyToSell;
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

void Mainteinance::AddTicket(const Ticket& ticket) {
	int currentQuantity = TicketsQuantity;
	Ticket* newTickets = new Ticket[currentQuantity + 1];

	for (int i = 0; i < currentQuantity; i++) {
		newTickets[i] = Tickets[i];
	}
	newTickets[currentQuantity] = ticket;
	delete[] Tickets;
	Tickets = newTickets;
	TicketsQuantity++;
}

void Mainteinance::TransferToReadyMovies(const Movie& movie)
{
	int currentQuantity = MoviesReadyToSellQuantity;
	Movie* newMoviesReady = new Movie[currentQuantity + 1];

	for (int i = 0; i < currentQuantity; i++) {
		newMoviesReady[i] = MoviesReadyToSell[i];
	}
	newMoviesReady[currentQuantity] = movie;
	delete[] MoviesReadyToSell;
	MoviesReadyToSell = newMoviesReady;
	MoviesReadyToSellQuantity++;
}


int Mainteinance::getMoviesQuantity()
{
	return MoviesQuantity;
}

int Mainteinance::getMoviesReadyToSellQuantity()
{
	return MoviesReadyToSellQuantity;
}

void Mainteinance::CreateRooms()
{
	int roomNumber = 1;
	printf(" Cuantas salas hay en el cine?\n ESTA RESPUESTA SE INGRESA UNA SOLA VEZ, NO SE PODRA CAMBIAR LA CANTIDAD DE SALAS!\n Digite su respuesta: ");
	scanf_s("%i", &RoomsQuantity);
	printf("\n");

	Rooms = new Room[RoomsQuantity];
	for (int i = 0; i < RoomsQuantity; i++) {
		Rooms[i].setRoomNumber(roomNumber);
		Rooms[i].ShowRooms();
		roomNumber = roomNumber + 1;
	}

}

void Mainteinance::getMovie(int i) {

		Movies[i].ShowMovie();
		
}

void Mainteinance::getMovieReadyToSell(int i) {

	MoviesReadyToSell[i].ShowMovie();

}

void Mainteinance::setMovieReadyToSell()
{
	for (int i = 0; i < MoviesQuantity; i++) {
		if (Movies[i].GetReady() == true) {
			bool alreadyAdded = false;

			for (int j = 0; j < MoviesReadyToSellQuantity; j++) {
				if (MoviesReadyToSell[j].getName() == Movies[i].getName()) {
					alreadyAdded = true;
					break;
				}
			}

			if (!alreadyAdded) {
				TransferToReadyMovies(Movies[i]);
			}
		}
	}
	
}

void Mainteinance::ShowAllMovies()
{
	printf(" A continuacion estas son todas las peliculas que se han ingresado al sistema:\n");
	for (int i = 0; i < MoviesQuantity; i++) {
		printf("\n Pelicula #%i\n", i + 1);
		getMovie(i);
		
	}
	
}

void Mainteinance::ShowAllReadyMovies()
{
	printf(" A continuacion estas son todas las peliculas que estan disponibles:\n");
	for (int i = 0; i < MoviesReadyToSellQuantity; i++) {
		printf("\n Pelicula #%i\n", i + 1);
		getMovieReadyToSell(i);

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
	Movies[MovieNumber - 1].SetReady();
	setMovieReadyToSell();
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
	Movies[MovieNumber - 1].SetReady();
	setMovieReadyToSell();
}



void Mainteinance::MakeAReservation() {
	int MovieNumber = -1;
	ShowAllReadyMovies();
	printf("\n En que pelicula desea reservar sus asientos?\n Digite su opcion: ");
	scanf_s("%d", &MovieNumber);
	getchar();

	if (MovieNumber < 1 || MovieNumber > MoviesQuantity) {
		printf(" Numero de pelicula inválido.\n");
		return;
	}

	printf("\n Se ha elegido la pelicula a continuacion:\n\n");
	getMovieReadyToSell(MovieNumber - 1);
	int assignedRoom = MoviesReadyToSell[MovieNumber - 1].getAssigneedRoom();
	printf(" Y su sala es la siguiente:\n");
	Rooms[assignedRoom - 1].ShowRooms();
	printf("\n Que asientos desea agregar a su reserva? (Ingrese fila y número de asiento, 0 0 para terminar):\n");

	char row[2];
	int column;
	char* reservedRows = new char[100];
	int* reservedColumns = new int[100];
	int reservedSeatsCount = 0;
	bool leave = false;

	while (!leave) {
		printf(" Elija la fila (A-I): ");
		while (true) {
			fgets(row, sizeof(row), stdin);
			row[strcspn(row, "\n")] = '\0';

			if (strcmp(row, "0") == 0) {
				printf(" Está seguro que desea salir? (S/N): ");
				char confirm;
				scanf_s(" %c", &confirm);
				getchar();
				if (confirm == 'S' || confirm == 's') {
					leave = true;
					break;
				}
				else {
					printf(" Continuando...\n");
					printf(" Elija la fila (A-I): ");
				}
			}
			else if (row[0] >= 'A' && row[0] <= 'I' && row[1] == '\0') {
				break;
			}
			else {
				printf(" Entrada invalida. Elija una fila valida (A-I): ");
			}
		}

		if (leave) break;

		printf(" Elija la columna (1-14): ");
		while (true) {
			int result = scanf_s("%d", &column);
			if (result == 1 && column >= 1 && column <= 14) break;
			printf(" Entrada invalida. Elija una columna valida (1-14): ");
			while (getchar() != '\n');
		}

		reservedRows[reservedSeatsCount] = row[0];
		reservedColumns[reservedSeatsCount] = column;
		++reservedSeatsCount;

		Rooms[assignedRoom - 1].ReserveSeat(row[0], column);
		getchar();
	}

	Ticket ticket;
	ticket.setTicket(&MoviesReadyToSell[MovieNumber - 1], &Rooms[assignedRoom - 1], reservedRows, reservedColumns, reservedSeatsCount);

	ticket.ShowTicket();
	AddTicket(ticket);
	delete[] reservedRows;
	delete[] reservedColumns;
}

void Mainteinance::BuyTicket() {
	if (TicketsQuantity == 0) {
		printf(" No hay tickets generados.\n");
		return;
	}

	char inputCode[10];
	printf(" Ingrese el codigo del ticket: ");
	scanf_s("%s", inputCode, sizeof(inputCode));

	Ticket* foundTicket = nullptr;
	for (int i = 0; i < TicketsQuantity; ++i) {
		if (strcmp(Tickets[i].getTicketCode(), inputCode) == 0) {
			foundTicket = &Tickets[i];
			break;
		}
	}

	if (foundTicket == nullptr) {
		printf(" Codigo de ticket no encontrado.\n");
		return;
	}


	if (foundTicket->getIsPurchased()) {
		printf(" Este ticket ya ha sido comprado.\n");
		return;
	}


	foundTicket->ShowTicket();


	int totalPrice = foundTicket->getReservedSeatsCount() * 3000;
	printf(" El precio total es: %d colones.\n", totalPrice);


	printf(" Desea proceder con la compra? (S/N): ");
	char confirm;
	scanf_s(" %c", &confirm);

	if (confirm == 'S' || confirm == 's') {
		foundTicket->PurchaseTicket();
		printf(" Compra realizada con exito.\n");
	}
	else {
		printf(" Compra cancelada.\n");
	}
}
#include "Options.h"

int Options::FileOption(int option)
{
	option = 0;
	printf(" Se ha digitado la opcion 1.\n");
	printf(" 1.Acerca de\n 2.Salir\n Digite su opcion: ");
	scanf_s("%i", &option);
	if (option < 3 && option >0) {
		switch (option)
		{
		case 1:
			printf(" Se ha digitado la opcion 1.\n");
			printf(" Programa echo por Saul Chinchilla Badilla en el anio 2024.\n Para la empresa NUEVA CINEMA SA.\n Atencion al cliente al numero: +506 8788 1170 \n Horario de atencion 9 a.m. - 5 p.m.\n ");
			break;
		case 2:
			printf(" Se ha digitado la opcion 2.\n Saliendo del programa...\n");
			return 0;
			break;
		default:
			break;
		}
	}
	else {
		printf("El numero que digito es una opcion incorrecta\n");
		return 0;
	}
	return 0;
}

void Options::MaintenanceOption()
{
	printf(" Se ha digitado la opcion 2.\n");
}

void Options::ReserveOption()
{
	printf(" Se ha digitado la opcion 3.\n");
}

void Options::SellOption()
{
	printf(" Se ha digitado la opcion 4.\n");
}

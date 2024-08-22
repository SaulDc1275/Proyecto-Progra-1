#include <iostream>

int main()
{
	int option = 0;

	printf("\tNUEVA CINEMA SA \n\t      MENU\n\n 1.Archivo\n 2.Mantenimiento\n 3.Reserva\n 4.Venta\n Digite su opcion: ");
	scanf_s("%i", &option);

	if (option < 5 && option >0) {
		switch (option)
		{
		case 1:
		
			break;
		case 2:
		
			break;
		case 3:
		
			break;
		case 4:
		
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


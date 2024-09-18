#include "Schedule.h"


Schedule::Schedule() {
	Day = -1;
	Month = -1;
	Year = -1;
	Hour = -1;
	Minute = -1;
}

void Schedule::AssignSchedule(int day, int month, int year, int hour, int minute) {
	Day = day;
	Month = month;
	Year = year;
	Hour = hour;
	Minute = minute;
}

void Schedule::ShowSchedule() {
	if (Hour >= 0 && Minute >= 0) {
		printf(" La pelicula inicia a las ");
		if (Hour < 10) {
			printf("0%i:", Hour);
		}
		else {
			printf("%i:", Hour);
		}
		if (Minute < 10) {
			printf("0%i\n", Minute);
		}
		else {
			printf("%i\n", Minute);
		}
		printf(" En la fecha: %i/%i/%i\n", Day, Month, Year);
	}
}

int Schedule::getMinute()
{
	return Minute;
}

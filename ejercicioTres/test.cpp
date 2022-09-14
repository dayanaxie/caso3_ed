#include "Airport.h"
#include <iostream>

using namespace std;

int main() {
    int runways;
    cout << "Cantidad de pistas: ";
    cin >> runways;
    int vuelos;
    cout << "Cantidad de vuelos: ";
    cin >> vuelos;
    int starHour;
    cout << "Hora de inicio: ";
    cin >> starHour;
    int endHour;
    cout << "Hora de finalizacion: ";
    cin >> endHour;
    Airport* juanSantamaria = new Airport(runways);
    juanSantamaria->fillFlights(vuelos, starHour, endHour);
    juanSantamaria->startFlights();

}
#include <string>
#include "List.h"
#include "PriorityQueue.h"
#include "Flight.h"

#define DELAY 1020  // 17 minutos en segundos
using namespace std;

class Airport{
    private:
        string name;
        string location;
        List<PriorityQueue<Flight>>* Runways;
        
    public:
        Airport(int pRunway){
            Runways = new List<PriorityQueue<Flight>>();
            name = "";
            location = "";

            while(Runways->getSize() <= pRunway){
                PriorityQueue<Flight>* queue = new PriorityQueue<Flight>();
                Runways->add(queue, 0);
            }
        }
        void fillFlights(int pCantidad, int pStartHour, int pEndHour) {
            while(pCantidad > 0){
                for(int runway = 0; runway < Runways->getSize(); ++runway){
                    Flight* flight= new Flight((rand() % (pEndHour -1) + pStartHour), (rand() % 59 + 0));
                    if(flight->getHour() >= pStartHour * 3600 && flight->getHour() + DELAY <= pEndHour*3600){
                        Runways->find(runway)->enqueue(flight, flight->getIntTimeValue());
                    }
                    --pCantidad;
                }
            }
        }
        int findEarlierFlight(){
            int earlierFlight = 9999;
            for(int runway = 0; runway < Runways->getSize(); ++runway){
                for(int flight = 0; flight<Runways->find(runway)->getSize(); ++flight){
                    if(Runways->find(runway)->getFirst()->getPriority() < earlierFlight){
                        earlierFlight = Runways->find(runway)->getFirst()->getPriority();
                    }
                }
            }
            return earlierFlight;
        }
        void startFlights(){
            bool condition = false;
            while(condition == false){
                int earliestFlight = this->findEarlierFlight();
                for(int runway = 0; runway < Runways->getSize(); ++runway){
                    if(Runways->find(runway)){
                        if(Runways->find(runway)->getFirst()){
                            if(Runways->find(runway)->getFirst()->getPriority() <= earliestFlight){
                                cout << "VUELO: " << Runways->find(runway)->getFirst()->getData()->flightTimeString()<<endl <<
                                "desplegado en la pista" << runway << endl;
                                Runways->find(runway)->dequeue();
                            }
                        }
                    }
                }
                for(int runway = 0; runway < Runways->getSize(); ++runway){
                    if(Runways->find(runway)->isEmpty()){
                        condition = true;
                    }
                    else{
                        condition = false;
                    }
                }
            }
        }
};
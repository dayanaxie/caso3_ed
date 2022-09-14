#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>


using namespace std;


class Flight {

    private: 
        string airline;
        int flightNumber;
        int amountPassengers;
        time_t flightTime;
        int exitHour;
        int exitMinutes;

    public: 
        Flight(){
            
        }

        Flight(int pHour, int pMinutes) {
            exitHour = pHour;
            exitMinutes = pMinutes;
            flightNumber = 0;
            amountPassengers = 0;
            airline = "";
            this->flightTime = time(NULL);
            tm *currentTime = localtime(&this->flightTime);
            int currentHour = currentTime->tm_hour;
            int currentMinutes = currentTime->tm_min;
            this->flightTime -= currentHour * 3600;
            this->flightTime -= currentMinutes * 60;
            this->flightTime += exitHour * 3600;
            this->flightTime += pMinutes * 60;
        }

        char* flightTimeString() {
            char* result = ctime(&this->flightTime);
            return result;
        }

        int getIntTimeValue() {
            time_t beginning = time(NULL);
            tm *currentTime = localtime(&beginning);
            beginning -= currentTime->tm_hour * 3600;
            beginning -= currentTime->tm_min * 60;
            beginning -= currentTime->tm_sec;
            time_t ending = flightTime;
            int priority = difftime(ending, beginning);
            return priority;
        }

        time_t getHour(){
            return this->flightTime;
        }

        int getExitHour(){
            return this->exitHour;
        }

        int getExitMinutes(){
            return this->exitMinutes;
        }
};

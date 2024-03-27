#ifndef LEVELSENSOR_H
#define LEVELSENSOR_H

#include <string>
#include <vector>

using namespace std;


class LevelSensor {
    private:
        double capacity;
        vector<double> dati;
        double currentLevel;
        string unita;

    public:
        LevelSensor(string name,
                    string descrizione,
                    string logo_path,
                    string ID,
                    double capacity,
                    vector<double> dati,
                    double currentLevel,
                    string unita);
        double getCapacity();
        LevelSensor& setCapacity(double capacity);
        vector<double> getDati();
        double getCurrentlevel();
        string getUnita();
        LevelSensor& setUnita(string unita); 
};

#endif // LEVELSENSOR_H

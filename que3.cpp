#include <iostream>

using namespace std;

class Vehicle 
{
private:
    char model[50];
    double speed;

public:
    void setData(const char* m, double s) 
	{
        speed = s;
        int i = 0;
        while (m[i] != '\0' && i < 49) 
		{
            model[i] = m[i];
            i++;
        }
        model[i] = '\0';
    }

    double getSpeed() 
	{
        return speed;
    }

    void showModel() 
	{
        cout << "Model: " << model;
    }
};

class Car : public Vehicle 
{
public:
    void calculateTime(double distance) 
	{
        double time = distance / getSpeed();
        showModel();
        cout << " (Car) | Time for " << distance << "km: " << time << " hours" << endl;
    }
};

class Bike : public Vehicle 
{
public:
    void calculateTime(double distance) 
	{
        double time = distance / getSpeed();
        showModel();
        cout << " (Bike) | Time for " << distance << "km: " << time << " hours" << endl;
    }
};

int main() 
{
    Car myCar;
    myCar.setData("Tesla_Model_S", 120.0); 

    Bike myBike;
    myBike.setData("Yamaha_R1", 80.0); 

    double tripDistance = 240.0; 

    cout << "--- Travel Time Calculation ---" << endl;
    
    myCar.calculateTime(tripDistance);
    myBike.calculateTime(tripDistance);

    return 0;
}


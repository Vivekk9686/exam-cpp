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

    double getSpeed() { return speed; }
    char* getModel() { return model; }

    virtual void displayDetails() 
	{
        cout << "Vehicle Model: " << model << " | Speed: " << speed << " km/h" << endl;
    }
};

class Car : public Vehicle 
{
public:
    void displayDetails() 
	{
        cout << "[CAR] Model: " << getModel() << " | Max Speed: " << getSpeed() << " km/h" << endl;
    }
};

class Bike : public Vehicle 
{
public:
    void displayDetails() 
	{
        cout << "[BIKE] Model: " << getModel() << " | Max Speed: " << getSpeed() << " km/h" << endl;
    }
};

int main() 
{
    Car myCar;
    myCar.setData("Sedan_V8", 180.0);

    Bike myBike;
    myBike.setData("Sports_Bike", 120.0);

    Vehicle* garage[2];
    garage[0] = &myCar;
    garage[1] = &myBike;

    cout << "--- Displaying Details via Polymorphism ---" << endl;

    for (int i = 0; i < 2; i++) 
	{
        garage[i]->displayDetails(); 
    }

    return 0;
}


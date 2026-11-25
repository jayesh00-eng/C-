
#include <iostream>
using namespace std;


class Vehicle
{
protected:
    int id, year;
    string manufacturer, model;

public:
    static int total;

    Vehicle()
    {
        id = 0;
        year = 0;
    }

    void getVehicle()
    {
        cout << "Enter Vehicle ID: ";
        cin >> id;

        cout << "Enter Manufacturer: ";
        cin >> manufacturer;

        cout << "Enter Model: ";
        cin >> model;

        cout << "Enter Year: ";
        cin >> year;

        total++;
    }

    virtual void display()
    {
        cout << "\nVehicle ID: " << id;
        cout << "\nManufacturer: " << manufacturer;
        cout << "\nModel: " << model;
        cout << "\nYear: " << year;
    }

    int getID()
    {
        return id;
    }

    virtual ~Vehicle() {}
};

int Vehicle::total = 0;



class Car : public Vehicle
{
protected:
    string fuelType;

public:
    void getCar()
    {
        getVehicle();
        cout << "Enter Fuel Type: ";
        cin >> fuelType;
    }

    void display()
    {
        Vehicle::display();
        cout << "\nFuel Type: " << fuelType;
    }
};



class ElectricCar : public Car
{
protected:
    int battery;

public:
    void getElectric()
    {
        getCar();
        cout << "Enter Battery Capacity: ";
        cin >> battery;
    }

    void display()
    {
        Car::display();
        cout << "\nBattery Capacity: " << battery;
    }
};



class SportsCar : public ElectricCar
{
    int speed;

public:
    void getSports()
    {
        getElectric();
        cout << "Enter Top Speed: ";
        cin >> speed;
    }

    void display()
    {
        ElectricCar::display();
        cout << "\nTop Speed: " << speed;
    }
};



class Sedan : public Car
{
public:
    void display()
    {
        Car::display();
        cout << "\nType: Sedan";
    }
};



class SUV : public Car
{
public:
    void display()
    {
        Car::display();
        cout << "\nType: SUV";
    }
};



class Aircraft
{
protected:
    int flightRange;

public:
    void getRange()
    {
        cout << "Enter Flight Range: ";
        cin >> flightRange;
    }
};



class FlyingCar : public Car, public Aircraft
{
public:
    void getFlying()
    {
        getCar();
        getRange();
    }

    void display()
    {
        Car::display();
        cout << "\nFlight Range: " << flightRange;
    }
};



int main()
{
    Vehicle *v[50];
    int count = 0, choice, id;

    do
    {
        cout << "\n\n===== VEHICLE REGISTRY =====";
        cout << "\n1. Add Car";
        cout << "\n2. Add Electric Car";
        cout << "\n3. Add Sports Car";
        cout << "\n4. Add Sedan";
        cout << "\n5. Add SUV";
        cout << "\n6. Add Flying Car";
        cout << "\n7. Display All Vehicles";
        cout << "\n8. Search Vehicle";
        cout << "\n9. Exit";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                v[count] = new Car;
                ((Car*)v[count])->getCar();
                count++;
                break;

            case 2:
                v[count] = new ElectricCar;
                ((ElectricCar*)v[count])->getElectric();
                count++;
                break;

            case 3:
                v[count] = new SportsCar;
                ((SportsCar*)v[count])->getSports();
                count++;
                break;

            case 4:
                v[count] = new Sedan;
                ((Sedan*)v[count])->getCar();
                count++;
                break;

            case 5:
                v[count] = new SUV;
                ((SUV*)v[count])->getCar();
                count++;
                break;

            case 6:
                v[count] = new FlyingCar;
                ((FlyingCar*)v[count])->getFlying();
                count++;
                break;

            case 7:
                for(int i = 0; i < count; i++)
                {
                    cout << "\n\n--- Vehicle " << i+1 << " ---";
                    v[i]->display();
                }

                cout << "\nTotal Vehicles: " << count;
                break;

            case 8:
                cout << "Enter Vehicle ID: ";
                cin >> id;

                for(int i = 0; i < count; i++)
                {
                    if(v[i]->getID() == id)
                    {
                        cout << "\nVehicle Found!";
                        v[i]->display();
                        break;
                    }
                }
                break;

            case 9:
                cout << "\nThank You!";
                break;

            default:
                cout << "\nInvalid Choice!";
        }

    } while(choice != 9);

    for(int i = 0; i < count; i++)
    {
        delete v[i];
    }

    return 0;
}


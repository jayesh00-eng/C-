
#include <iostream>
#include <cstring>
using namespace std;

class Train
{
private:
    int trainNumber;
    char trainName[50];
    char source[50];
    char destination[50];
    char trainTime[10];

    static int trainCount;

public:

    // Default Constructor
    Train()
    {
        trainNumber = 0;
        strcpy(trainName, "");
        strcpy(source, "");
        strcpy(destination, "");
        strcpy(trainTime, "");

        trainCount++;
    }

    // Parameterized Constructor
    Train(int no, const char name[], const char src[],
          const char dest[], const char time[])
    {
        trainNumber = no;
        strcpy(trainName, name);
        strcpy(source, src);
        strcpy(destination, dest);
        strcpy(trainTime, time);

        trainCount++;
    }

    // Destructor
    ~Train()
    {
        trainCount--;
    }

    // Setters
    void setTrainNumber(int no)
    {
        trainNumber = no;
    }

    void setTrainName(const char name[])
    {
        strcpy(trainName, name);
    }

    void setSource(const char src[])
    {
        strcpy(source, src);
    }

    void setDestination(const char dest[])
    {
        strcpy(destination, dest);
    }

    void setTrainTime(const char time[])
    {
        strcpy(trainTime, time);
    }

    // Getters
    int getTrainNumber()
    {
        return trainNumber;
    }

    const char* getTrainName()
    {
        return trainName;
    }

    const char* getSource()
    {
        return source;
    }

    const char* getDestination()
    {
        return destination;
    }

    const char* getTrainTime()
    {
        return trainTime;
    }

    // Input Train Details
    void inputTrainDetails()
    {
        cout << "\nEnter Train Number: ";
        cin >> trainNumber;

        cin.ignore();

        cout << "Enter Train Name: ";
        cin.getline(trainName, 50);

        cout << "Enter Source: ";
        cin.getline(source, 50);

        cout << "Enter Destination: ";
        cin.getline(destination, 50);

        cout << "Enter Train Time: ";
        cin.getline(trainTime, 10);
    }

    // Display Train Details
    void displayTrainDetails()
    {
        cout << "\nTrain Number: " << trainNumber;
        cout << "\nTrain Name: " << trainName;
        cout << "\nSource: " << source;
        cout << "\nDestination: " << destination;
        cout << "\nTrain Time: " << trainTime;
        cout << "\n";
    }

    // Static Function
    static int getTrainCount()
    {
        return trainCount;
    }
};

// Initialize Static Member
int Train::trainCount = 0;


// Railway System Class
class RailwaySystem
{
private:
    Train trains[100];
    int totalTrains;

public:

    // Constructor
    RailwaySystem()
    {
        totalTrains = 0;

        // Initially Add 3 Train Records
        trains[totalTrains++] = Train(101, "Okha Express",
                                      "Surat", "Mumbai", "10 AM");

        trains[totalTrains++] = Train(102, "Gujarat Express",
                                      "Ahmedabad", "Mumbai", "2 PM");

        trains[totalTrains++] = Train(103, "Intercity Express",
                                      "Surat", "Ahmedabad", "6 AM");
    }

    // Add New Train
    void addTrain()
    {
        if (totalTrains >= 100)
        {
            cout << "\nTrain Record Limit Reached!";
            return;
        }

        cout << "\n--- Add New Train Record ---";

        trains[totalTrains].inputTrainDetails();
        totalTrains++;

        cout << "\nTrain Record Added Successfully!\n";
    }

    // Display All Trains
    void displayAllTrains()
    {
        if (totalTrains == 0)
        {
            cout << "\nNo Train Records Found!\n";
            return;
        }

        cout << "\n--- All Train Records ---\n";

        for (int i = 0; i < totalTrains; i++)
        {
            cout << "\nTrain " << i + 1 << " Details:";
            trains[i].displayTrainDetails();
        }

        cout << "\nTotal Trains: " << totalTrains << endl;
    }

    // Search Train By Number
    void searchTrainByNumber(int number)
    {
        bool found = false;

        for (int i = 0; i < totalTrains; i++)
        {
            if (trains[i].getTrainNumber() == number)
            {
                cout << "\n--- Train Found ---\n";

                trains[i].displayTrainDetails();

                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "\nTrain with number "
                 << number << " not found!\n";
        }
    }
};


// Main Function
int main()
{
    RailwaySystem railway;
    int choice;
    int number;

    do
    {
        cout << "\n================================";
        cout << "\n Railway Reservation System";
        cout << "\n================================";

        cout << "\n1. Add New Train Record";
        cout << "\n2. Display All Train Records";
        cout << "\n3. Search Train by Number";
        cout << "\n4. Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                railway.addTrain();
                break;

            case 2:
                railway.displayAllTrains();
                break;

            case 3:
                cout << "\nEnter Train Number to search: ";
                cin >> number;

                railway.searchTrainByNumber(number);
                break;

            case 4:
                cout << "\nExiting the system. Goodbye!\n";
                break;

            default:
                cout << "\nInvalid Choice! Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}


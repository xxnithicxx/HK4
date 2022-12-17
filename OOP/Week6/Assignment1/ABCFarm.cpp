#include "ABCFarm.h"

void ABCFarm::Input()
{
    int numCows, numGoats;
    cout << "Number of cows? ";
    cin >> numCows;
    cout << "Number of goats? ";
    cin >> numGoats;
    cout << endl;

    int age, weight;
    for (int i = 0; i < numCows; i++)
    {
        cout << "Cow " << i + 1 << endl;
        cout << "Age: ";
        cin >> age;
        cout << "Weight: ";
        cin >> weight;
        cout << endl;

        DairyCow cow(weight, age);
        cows.push_back(cow);
    }

    for (int i = 0; i < numGoats; i++)
    {
        cout << "Goat " << i + 1 << endl;
        cout << "Age: ";
        cin >> age;
        cout << "Weight: ";
        cin >> weight;
        cout << endl;

        Goat goat(weight, age);
        goats.push_back(goat);
    }
}

void ABCFarm::Output()
{
    cout << "Cows:" << endl;
    for (int i = 0; i < cows.size(); i++)
    {
        cout << cows[i].toString() << endl;
    }

    cout << "Goats:" << endl;
    for (int i = 0; i < goats.size(); i++)
    {
        cout << goats[i].toString() << endl;
    }

    cout << endl;
}

void ABCFarm::OutputByAge(int min, int max)
{
    cout << "Animal by age (" << min << "," << max << ")" << endl;
    cout << "Cows:" << endl;
    for (int i = 0; i < cows.size(); i++)
    {
        int age = cows[i].getAge();
        if (cows[i].getAge() >= min && cows[i].getAge() <= max)
        {
            cout << cows[i].toString() << endl;
        }
    }

    cout << "Goats:" << endl;
    for (int i = 0; i < goats.size(); i++)
    {
        if (goats[i].getAge() >= min && goats[i].getAge() <= max)
        {
            cout << goats[i].toString() << endl;
        }
    }

    cout << endl;
}
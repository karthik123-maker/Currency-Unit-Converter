#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

// Template Function
template <typename T>
T convertValue(T value, double factor)
{
    return value * factor;
}

// Abstract Base Class
class Converter
{
public:
    virtual void convert() = 0;
    virtual ~Converter() {}
};

// Currency Converter Class
class CurrencyConverter : public Converter
{
private:
    map<string, double> rates;

public:
    CurrencyConverter()
    {
        loadRates();
    }

    void loadRates()
    {
        ifstream file("rates.txt");

        if (!file)
        {
            throw runtime_error("Cannot open rates.txt");
        }

        string currency;
        double rate;

        while (file >> currency >> rate)
        {
            rates[currency] = rate;
        }

        file.close();
    }

    void convert() override
    {
        string from, to;
        double amount;

        cout << "\nEnter Source Currency: ";
        cin >> from;

        cout << "Enter Target Currency: ";
        cin >> to;

        cout << "Enter Amount: ";
        cin >> amount;

        if (rates.find(from) == rates.end() ||
            rates.find(to) == rates.end())
        {
            throw invalid_argument("Invalid Currency Code");
        }

        double usd = amount / rates[from];
        double result = usd * rates[to];

        cout << fixed << setprecision(2);
        cout << amount << " " << from
             << " = " << result << " "
             << to << endl;

        ofstream history("history.txt", ios::app);
        history << amount << " " << from
                << " -> " << result
                << " " << to << endl;
        history.close();
    }
};

// Length Converter
class LengthConverter : public Converter
{
public:
    void convert() override
    {
        double meters;

        cout << "\nEnter Length in Meters: ";
        cin >> meters;

        cout << "\n1. Kilometers\n";
        cout << "2. Centimeters\n";
        cout << "3. Feet\n";

        int choice;
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << meters / 1000 << " km\n";
                break;

            case 2:
                cout << meters * 100 << " cm\n";
                break;

            case 3:
                cout << meters * 3.28084 << " ft\n";
                break;

            default:
                cout << "Invalid Choice\n";
        }
    }
};

// Mass Converter
class MassConverter : public Converter
{
public:
    void convert() override
    {
        double kg;

        cout << "\nEnter Mass in Kilograms: ";
        cin >> kg;

        cout << "\n1. Grams\n";
        cout << "2. Pounds\n";

        int choice;
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << kg * 1000 << " g\n";
                break;

            case 2:
                cout << kg * 2.20462 << " lbs\n";
                break;

            default:
                cout << "Invalid Choice\n";
        }
    }
};

// Temperature Converter
class TemperatureConverter : public Converter
{
public:
    void convert() override
    {
        double celsius;

        cout << "\nEnter Temperature in Celsius: ";
        cin >> celsius;

        double fahrenheit =
            (celsius * 9.0 / 5.0) + 32;

        double kelvin =
            celsius + 273.15;

        cout << "Fahrenheit : "
             << fahrenheit << endl;

        cout << "Kelvin : "
             << kelvin << endl;
    }
};

// History Viewer
void showHistory()
{
    ifstream file("history.txt");

    if (!file)
    {
        cout << "No history found.\n";
        return;
    }

    string line;

    cout << "\n===== Conversion History =====\n";

    while (getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
}

int main()
{
    int choice;

    while (true)
    {
        cout << "\n=============================\n";
        cout << " Currency & Unit Converter\n";
        cout << "=============================\n";

        cout << "1. Currency Converter\n";
        cout << "2. Length Converter\n";
        cout << "3. Mass Converter\n";
        cout << "4. Temperature Converter\n";
        cout << "5. View History\n";
        cout << "6. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        try
        {
            Converter *converter = nullptr;

            switch(choice)
            {
                case 1:
                    converter = new CurrencyConverter();
                    break;

                case 2:
                    converter = new LengthConverter();
                    break;

                case 3:
                    converter = new MassConverter();
                    break;

                case 4:
                    converter = new TemperatureConverter();
                    break;

                case 5:
                    showHistory();
                    continue;

                case 6:
                    cout << "Thank You!\n";
                    return 0;

                default:
                    cout << "Invalid Choice\n";
                    continue;
            }

            converter->convert();
            delete converter;
        }

        catch(exception &e)
        {
            cout << "\nError: "
                 << e.what()
                 << endl;
        }
    }

    return 0;
}

Currency & Unit Converter

A console-based C++ application for converting Currency, Length, Mass, and Temperature using Object-Oriented Programming concepts. This project demonstrates inheritance, polymorphism, templates, STL containers, file handling, and exception handling.

---

📌 Project Description

The Currency & Unit Converter is a menu-driven console application developed in C++. It supports multiple categories of conversions through a class hierarchy. Currency exchange rates are loaded from a configuration file, allowing rates to be updated without recompiling the program.

The application also maintains a conversion history log and demonstrates real-world software engineering practices using OOP principles.

---

✨ Features

- Currency Conversion using configurable exchange rates
- Length Conversion (Meters, Kilometers, Centimeters, Feet)
- Mass Conversion (Kilograms, Grams, Pounds)
- Temperature Conversion (Celsius, Fahrenheit, Kelvin)
- File-based Currency Rate Management
- Conversion History Logging
- Exception Handling for Invalid Inputs
- Template Function for Generic Numeric Conversions
- Menu-Driven Console Interface

---

🛠 Technologies Used

- C++
- Object-Oriented Programming (OOP)
- STL Map
- Templates
- File Handling (fstream)
- Exception Handling

---

📂 Project Structure

CurrencyUnitConverter/
│
├── main.cpp
├── rates.txt
├── history.txt
└── README.md

---

🏗 Class Hierarchy

                Converter
                    |
     --------------------------------
     |         |         |          |
Currency   Length     Mass    Temperature
Converter Converter Converter Converter

Base Class

- Converter (Abstract Class)
- Pure Virtual Function: "convert()"

Derived Classes

- CurrencyConverter
- LengthConverter
- MassConverter
- TemperatureConverter

---

⚙️ Installation & Compilation

Linux / macOS

g++ main.cpp -o converter
./converter

Windows

g++ main.cpp -o converter.exe
converter.exe

---

📄 Currency Rate Configuration

Create a file named "rates.txt" in the project directory:

USD 1.0
INR 83.2
EUR 0.92
GBP 0.79
JPY 157.5

You can update exchange rates without modifying the source code.

---

▶️ Sample Output

=========================
 Currency & Unit Converter
=========================

1. Currency Converter
2. Length Converter
3. Mass Converter
4. Temperature Converter
5. View History
6. Exit

Enter Choice: 1

Enter Source Currency: USD
Enter Target Currency: INR
Enter Amount: 100

100 USD = 8320 INR

---

📜 Conversion History

All currency conversions are stored in:

history.txt

Example:

100 USD -> 8320 INR
50 EUR -> 4530 INR

---

🎯 OOP Concepts Implemented

Inheritance

All converter classes inherit from the abstract base class "Converter".

Polymorphism

The "convert()" method is overridden in each derived class and invoked through base-class pointers.

Abstraction

The abstract base class defines a common interface for all converters.

Templates

A generic template function performs numeric conversion operations.

Exception Handling

Invalid currency codes and file access errors are handled using C++ exceptions.

---

🚀 Future Enhancements

- Chained Conversion (A → B → C)
- Batch Conversion from Input Files
- Favorite Conversion Bookmarks
- Live Exchange Rate API Integration
- GUI Version using Qt
- User Authentication System
- Conversion Statistics Dashboard

---

👥 Suggested Team Roles

Role| Responsibility
OOP Developer| Class Design & Hierarchy
File Handling Developer| Configuration & Logging
Conversion Logic Developer| Conversion Algorithms

---

📚 Learning Outcomes

By completing this project, students will gain experience in:

- Object-Oriented Programming
- File Handling
- STL Containers
- Function Templates
- Exception Handling
- Software Design Principles
- GitHub Repository Management

---

📄 License

This project is intended for educational and academic purposes. Feel free to modify and extend it for learning and research.

---

👨‍💻 Author

Developed as a C++ OOP Mini Project for academic learning and software development practice.

⭐ If you found this project useful, consider giving it a star on GitHub.

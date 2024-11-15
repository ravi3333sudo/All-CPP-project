#include <iostream>
#include <iomanip>
#include <map>
#include <string>


void displayCurrencies() {
    std::cout << "Available currencies:\n";
    std::cout << "1. USD (United States Dollar)\n";
    std::cout << "2. EUR (Euro)\n";
    std::cout << "3. GBP (British Pound)\n";
    std::cout << "4. INR (Indian Rupee)\n";
    std::cout << "5. JPY (Japanese Yen)\n";
    std::cout << "6. AUD (Australian Dollar)\n";
}


void convertCurrency() {
    
    std::map<std::string, std::map<std::string, double>> exchangeRates = {
        {"USD", {{"EUR", 0.92}, {"GBP", 0.78}, {"INR", 82.0}, {"JPY", 150.3}, {"AUD", 1.56}}},
        {"EUR", {{"USD", 1.09}, {"GBP", 0.85}, {"INR", 89.0}, {"JPY", 163.0}, {"AUD", 1.70}}},
        {"GBP", {{"USD", 1.28}, {"EUR", 1.17}, {"INR", 104.5}, {"JPY", 192.3}, {"AUD", 2.0}}},
        {"INR", {{"USD", 0.012}, {"EUR", 0.011}, {"GBP", 0.0096}, {"JPY", 1.84}, {"AUD", 0.019}}},
        {"JPY", {{"USD", 0.0067}, {"EUR", 0.0061}, {"GBP", 0.0052}, {"INR", 0.54}, {"AUD", 0.010}}},
        {"AUD", {{"USD", 0.64}, {"EUR", 0.59}, {"GBP", 0.50}, {"INR", 53.0}, {"JPY", 95.0}}}
    };

    std::string fromCurrency, toCurrency;
    double amount;

    displayCurrencies();

    
    std::cout << "\nEnter the currency code you want to convert FROM (e.g., USD): ";
    std::cin >> fromCurrency;
    std::cout << "Enter the currency code you want to convert TO (e.g., EUR): ";
    std::cin >> toCurrency;
    std::cout << "Enter the amount in " << fromCurrency << ": ";
    std::cin >> amount;

    
    if (exchangeRates.find(fromCurrency) != exchangeRates.end() &&
        exchangeRates[fromCurrency].find(toCurrency) != exchangeRates[fromCurrency].end()) {
        
        double conversionRate = exchangeRates[fromCurrency][toCurrency];
        double convertedAmount = amount * conversionRate;

        
        std::cout << std::fixed << std::setprecision(2);
        std::cout << amount << " " << fromCurrency << " = " << convertedAmount << " " << toCurrency << std::endl;
    } else {
        std::cout << "Invalid currency code or conversion not available!" << std::endl;
    }
}

int main() {
    std::cout << "Welcome to the Currency Converter!\n";
    char choice;

    do {
        convertCurrency();
        std::cout << "\nDo you want to perform another conversion? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    std::cout << "Thank you for using the Currency Converter. Goodbye!\n";
    return 0;
}

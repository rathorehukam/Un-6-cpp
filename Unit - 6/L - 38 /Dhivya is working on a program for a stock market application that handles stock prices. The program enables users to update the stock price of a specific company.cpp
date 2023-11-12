


// You are using GCC
#include <iostream>
#include <stdexcept>
#include <string>

class CompanyNotFoundException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Company not found.";
    }
};

class InvalidStockPriceException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Invalid stock price.";
    }
};

class StockMarket {
private:
    static const int MAX_COMPANIES = 20;
    std::string companies[MAX_COMPANIES];
    double stockPrices[MAX_COMPANIES];
    int numCompanies;

public:
    StockMarket() : numCompanies(0) {}

    void updateStockPrice(const std::string& company, double price) {
        if (price < 0) {
            throw InvalidStockPriceException();
        }

        int foundIndex = -1;
        for (int i = 0; i < numCompanies; i++) {
            if (companies[i] == company) {
                foundIndex = i;
                break;
            }
        }

        if (foundIndex == -1) {
            throw CompanyNotFoundException();
        }

        stockPrices[foundIndex] = price;
        std::cout << "Stock price of " << company << " updated to " << price;
    }

    void addCompany(const std::string& company, double initialPrice) {
        if (numCompanies >= MAX_COMPANIES) {
            throw std::out_of_range("Error: Maximum number of companies reached.");
        }

        companies[numCompanies] = company;
        stockPrices[numCompanies] = initialPrice;
        numCompanies++;

        std::cout << "Company " << company << " added to the stock market with an initial price of " << initialPrice << std::endl;
    }
};

int main() {
    try {
        StockMarket market;

        int numCompanies;
        std::string company;
        double initialPrice;

        std::cin >> numCompanies;

        for (int i = 0; i < numCompanies; i++) {
            std::cin >> company;
            std::cin >> initialPrice;

            market.addCompany(company, initialPrice);
        }

        std::string updateCompany;
        double newPrice;
        std::cin >> updateCompany;
        std::cin >> newPrice;

        market.updateStockPrice(updateCompany, newPrice);
    }
    catch (const InvalidStockPriceException& e) {
        std::cout << "Exception caught. " << e.what();
    }
    catch (const CompanyNotFoundException& e) {
        std::cout << "Exception caught. " << e.what();
    }
    catch (const std::out_of_range& e) {
        std::cout << "Exception caught. " << e.what();
    }

    return 0;
}


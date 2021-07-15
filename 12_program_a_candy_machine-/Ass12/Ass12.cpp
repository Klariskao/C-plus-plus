#include <iostream>

class cashRegister {

private:

    int cashOnHand;

public:

    cashRegister() { cashOnHand = 500; }
    cashRegister(int x) { cashOnHand = x; }

    int getCurrentBalance() { return cashOnHand; }
    void acceptAmount(int y)
    {
        std::cin >> y;
        cashOnHand += y;
    }
};

class dispenserType {

private:

    int numberOfItems;
    int cost;

public:

    dispenserType() { cost = 50; numberOfItems = 50; }
    dispenserType(int x, int y) { cost = x; numberOfItems = y; }

    int getNoOfItems() { return numberOfItems; }
    int getCost() { return cost; }
    void makeSale() { numberOfItems--; }

};

void showSelection()
{
    std::cout << "Welcome to the candy machine store.\n";
    std::cout << "This machine sells the following items:\n";
    std::cout << "Candies, chips, gum and cookies.\n";
    std::cout << "Please select 1 for candies, 2 for chips, "
              << "3 for gum and 4 for cookies.\n";
}

void checkAvailability(int number, int price)
{
    if (number > 0) {
        std::cout << "Price for the selected product is " << price << "\n";
        std::cout << "Please insert cash.\n";
    }
    else {
        std::cout << "We are sorry, the selected item is not available.\n";
        exit(EXIT_SUCCESS);
    }
}

void sellProduct(int price)
{
    int cashInserted;
    std::cin >> cashInserted;
    cashRegister acceptAmount(cashInserted);
    
    if (cashInserted >= price)
    {
        std::cout << "Thank you for your purchase.\n";
        std::cout << "Please take your product.\n";
        std::cout << "Have a nice day.\n";
    }
    else
    {
        while (cashInserted < price)
        {
            std::cout << "To be inserted: " << price - cashInserted << "\n";
            int cashAdded;
            std::cin >> cashAdded;
            cashInserted += cashAdded;
            continue;
        }
     std::cout << "Thank you for your purchase.\n";
     std::cout << "Please take your product.\n";
     std::cout << "Have a nice day.\n";
    }
}

int main()
{
    cashRegister();
    dispenserType candies(30, 0);
    dispenserType chips(40, 50);
    dispenserType gum(10, 50);
    dispenserType cookies(50, 50);
    showSelection();
    int selection;
    int price;
   
    std::cin >> selection;
    
    switch (selection)
    {
        case 1:
             price = candies.getCost();
             checkAvailability(candies.getNoOfItems(), candies.getCost());
             sellProduct(candies.getCost());
             candies.makeSale();
             break;
        case 2:
            price = chips.getCost();
            checkAvailability(chips.getNoOfItems(), chips.getCost());
            sellProduct(chips.getCost());
            chips.makeSale();
            break;
        case 3:
            price = gum.getCost();
            checkAvailability(gum.getNoOfItems(), gum.getCost());
            sellProduct(gum.getCost());
            gum.makeSale();
            break;
        case 4:
            price = cookies.getCost();
            checkAvailability(cookies.getNoOfItems(), cookies.getCost());
            sellProduct(cookies.getCost());
            cookies.makeSale();
            break;
        default:
            std::cout << "Selected value not valid.\n";
    }
    
    return 0;
}
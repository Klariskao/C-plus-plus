#include <iostream>

int selection;
int quantity;
int topay;

class cashRegister {

private:

    int cashOnHand;

public:

    cashRegister() { cashOnHand = 500; }
    cashRegister(int x) { cashOnHand = x; }

    int getCurrentBalance() { return cashOnHand; }
    void acceptAmount(int y)
    {
        cashOnHand += y;
    }
    void returnAmount(int z)
    {
       cashOnHand -= z;
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
    void makeSale(int purchase) { numberOfItems -= purchase; }

};

dispenserType candies(30, 50);
dispenserType chips(40, 50);
dispenserType gum(10, 50);
dispenserType cookies(50, 50);

void machineLoop();

void showSelection()
{
    std::cout << "Welcome to the candy machine store.\n";
    std::cout << "This machine sells the following items:\n";
    std::cout << "Candies, chips, gum and cookies.\n";
    std::cout << "Please select 1 for candies, 2 for chips, "
              << "3 for gum and 4 for cookies.\n";
}

void makeSelection()
{
    std::cin >> selection;
    if (selection > 0 && selection < 5) {}
    else
    {
        std::cout << "Selected value not valid.\n";
        machineLoop();
    }
}

void selectQuantity()
{
    std::cout << "Enter quantity.\n";
    std::cin >> quantity;
    if (quantity > 0 && quantity < 10) {}
    else if (quantity < 0)
    {
        std::cout << "Invalid quantity entered.\n";
        machineLoop();
    }
    else
    {
        std::cout << "Purchase over 10 items not allowed.\n";
        machineLoop();
    }
}

void checkAvailability(int amount, int available)
{
    if (available >= amount) {}
    else
    {
        std::cout << "We are sorry, the selected item is not available.\n";
        machineLoop();
    }
}

void displayPrice(int amount, int price)
{
    if (amount > 1)
    {
        topay = amount * price;
        std::cout << "Price for the selected products is " << topay << "\n";
        std::cout << "Please insert cash.\n";
    }
    else if (amount == 1)
    {
        topay = price;
        std::cout << "Price for the selected product is " << topay << "\n";
        std::cout << "Please insert cash.\n";
    }
}

void acceptPayment(int total)
{
    int cashInserted;
    std::cin >> cashInserted;
    cashRegister acceptAmount(cashInserted);

    if (cashInserted == total) {}
    else if (cashInserted > total)
    {
        std::cout << "To be returned: " << cashInserted - total << "\n";
        std::cout << "Please take your change.\n";
        cashRegister returnAmount(cashInserted - total);
    }
    else
    {
        while (cashInserted < total)
        {
            std::cout << "To be inserted: " << total - cashInserted << "\n";
            int cashAdded;
            std::cin >> cashAdded;
            cashInserted += cashAdded;
            cashRegister acceptAmount(cashAdded);
            if (cashAdded > (total - cashInserted))
            {
                std::cout << "To be returned: " << cashInserted - total << "\n";
                std::cout << "Please take your change.\n";
                cashRegister returnAmount(cashInserted - total);
            }
        }
    }
}

void releaseItem(int amount)
{
    if (amount > 1)
    {
        std::cout << "Thank you for your purchase.\n";
        std::cout << "Please take your items.\n";
        std::cout << "Have a nice day.\n\n";
    }
    else
    {
        std::cout << "Thank you for your purchase.\n";
        std::cout << "Please take your item.\n";
        std::cout << "Have a nice day.\n\n";
    }
}

void machineLoop()
{
    while (candies.getNoOfItems() > 0 || chips.getNoOfItems() > 0 || gum.getNoOfItems() > 0 || cookies.getNoOfItems() > 0)
    {
        showSelection();
        makeSelection();
        selectQuantity();
        switch (selection)
        {
        case 1:
            checkAvailability(quantity, candies.getNoOfItems());
            displayPrice(quantity, candies.getCost());
            acceptPayment(topay);
            releaseItem(quantity);
            candies.makeSale(quantity);
            break;
        case 2:
            checkAvailability(quantity, chips.getNoOfItems());
            displayPrice(quantity, chips.getCost());
            acceptPayment(topay);
            releaseItem(quantity);
            chips.makeSale(quantity);
            break;
        case 3:
            checkAvailability(quantity, gum.getNoOfItems());
            displayPrice(quantity, gum.getCost());
            acceptPayment(topay);
            releaseItem(quantity);
            gum.makeSale(quantity);
            break;
        case 4:
            checkAvailability(quantity, cookies.getNoOfItems());
            displayPrice(quantity, cookies.getCost());
            acceptPayment(topay);
            releaseItem(quantity);
            cookies.makeSale(quantity);
        }
    }
}

int main()
{
    cashRegister();
    
    machineLoop();

    return 0;
}
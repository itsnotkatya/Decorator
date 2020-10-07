#include <iostream>
using namespace std;

class Coffee {
public:
    virtual unsigned int cost() = 0;
    virtual string ingridients()  = 0;
};

class Espresso : public Coffee {
    virtual unsigned int cost() override {
        return 70;
    }
    virtual string ingridients() override {
        return "Espresso";
    }
};

class CoffeeDecorator : public Coffee {
private:
    Coffee * coffee;
public:
    CoffeeDecorator(Coffee * coffee) {
        this -> coffee = coffee;
    }

    virtual unsigned int cost() override {
        return coffee->cost();
    }
    virtual string ingridients() override {
        return coffee->ingridients();
    }
};

class Milk : public CoffeeDecorator {
public:
    Milk(Coffee * coffee) : CoffeeDecorator(coffee) {};

    virtual unsigned int cost() override {
        return CoffeeDecorator :: cost() + 30;
    }
    virtual string ingridients() override {
        return CoffeeDecorator::ingridients() + ", Milk";
    }
};

class Chocolate : public CoffeeDecorator {
public:
    Chocolate(Coffee * coffee) : CoffeeDecorator(coffee) {};

    virtual unsigned int cost() override {
        return CoffeeDecorator :: cost() + 45;
    }
    virtual string ingridients() override {
        return CoffeeDecorator::ingridients() + ", Chocolate";
    }
};

class Whip : public CoffeeDecorator {
public:
    Whip(Coffee * coffee) : CoffeeDecorator(coffee) {};

    virtual unsigned int cost() override {
        return CoffeeDecorator :: cost() + 50;
    }
    virtual string ingridients() override {
        return CoffeeDecorator::ingridients() + ", Whip";
    }
};

int main() {

    Coffee * capuccino = new Milk(new Espresso);
    Coffee * capuccinoDouble = new Milk(capuccino);
    Coffee * mokko = new Chocolate(new Whip(new Espresso));

    cout << capuccino->cost() << " " << capuccino->ingridients() << endl;

    cout << capuccinoDouble->cost() << " " << capuccinoDouble->ingridients() << endl;

    cout << mokko->cost() << " " << mokko->ingridients() << endl;
    return 0;
}
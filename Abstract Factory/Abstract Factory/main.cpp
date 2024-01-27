//
//  main.cpp
//  Abstract Factory (Drink Factory)
//
//  Created by Alexander Poletajev on 27/01/24.
//

#include <iostream>
#include "HotDrink.hpp"
#include "HotDrinkFactory.hpp"
#include "DrinkFactory.hpp"

int main(int argc, const char * argv[]) {

    DrinkFactory df;
    
    auto tea = df.make_drink("Tea");
    auto coffee = df.make_drink("Coffee");

    return 0;
}

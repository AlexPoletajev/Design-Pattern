//
//  DrinkFactory.hpp
//  Abstract Factory
//
//  Created by Alexander Poletajev on 27/01/24.
//

#ifndef DrinkFactory_hpp
#define DrinkFactory_hpp

#include "HotDrink.hpp"
#include "HotDrinkFactory.hpp"
#include <map>


class DrinkFactory{
    
    std::map<std::string, std::unique_ptr<HotDrinkFactory>> hot_drink_factories;
    
public:
    DrinkFactory() {
        hot_drink_factories["Tea"] = std::make_unique<HotTeaFactory>();
        hot_drink_factories["Coffee"] = std::make_unique<HotCoffeeFactory>();
    }
    
    std::unique_ptr<HotDrink> make_drink(const std::string& drink) {
        return hot_drink_factories[drink]->make();
    }
};

#endif /* DrinkFactory_hpp */

//
//  HotDrinkFactory.hpp
//  Abstract Factory
//
//  Created by Alexander Poletajev on 27/01/24.
//

#ifndef HotDrinkFactory_hpp
#define HotDrinkFactory_hpp

#include "HotDrink.hpp"

struct HotDrinkFactory {
    virtual std::unique_ptr<HotDrink> make() = 0;
};

struct HotCoffeeFactory : HotDrinkFactory {
    
    virtual std::unique_ptr<HotDrink> make() override {
        
        auto coffee = std::make_unique<HotCoffee>();
        coffee->prepare(200);
        return coffee;
    }
};

struct HotTeaFactory : HotDrinkFactory {
    
    virtual std::unique_ptr<HotDrink> make() override {
        
        auto tea = std::make_unique<HotTea>();
        tea->prepare(100);
        return tea;
    }
};


#endif /* HotDrinkFactory_hpp */

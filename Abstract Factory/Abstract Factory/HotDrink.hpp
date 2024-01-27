//
//  HotDrink.hpp
//  Abstract Factory
//
//  Created by Alexander Poletajev on 27/01/24.
//

#ifndef HotDrink_hpp
#define HotDrink_hpp

#include <iostream>

struct HotDrink {
    
    virtual ~HotDrink() = default;
    virtual void prepare(int amount) = 0;
};

struct HotCoffee : public HotDrink {
    
    virtual void prepare(int amount) override {
        
        std::cout << "boil water, take cup, grind beans, pour " << amount
        << " water, add cream" << std::endl;
    }
};

struct HotTea : public HotDrink {
    
    virtual void prepare(int amount) override {
        
        std::cout << "boil Water, take cup, add tea bag, pour " << amount
        << " water, add lemon" << std::endl;
    }
};

#endif /* HotDrink_hpp */

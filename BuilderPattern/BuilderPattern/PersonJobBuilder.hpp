//
//  PersonJobBuilder.hpp
//  BuilderPattern
//
//  Created by Alexander Poletajev on 27/01/24.
//

#ifndef PersonJobBuilder_hpp
#define PersonJobBuilder_hpp

#include <stdio.h>
#include "PersonBuilder.hpp"



class PersonJobBuilder : public PersonBuilderBase {
    typedef PersonJobBuilder Self;
public:
    
    PersonJobBuilder(Person& p) : PersonBuilderBase(p){}
    
    Self& as(const std::string& position){
        p.position = position;
        return *this;
    }
    Self& at_company(const std::string& company){
        p.company = company;
        return *this;
    }
    Self& earning(const int& amount){
        p.salary = amount;
        return *this;
    }
};

#endif /* PersonJobBuilder_hpp */


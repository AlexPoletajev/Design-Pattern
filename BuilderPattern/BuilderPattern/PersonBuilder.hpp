//
//  PersonBuilder.hpp
//  BuilderPattern
//
//  Created by Alexander Poletajev on 27/01/24.
//

#ifndef PersonBuilder_hpp
#define PersonBuilder_hpp

#include "Person.hpp"

class PersonAddressBuilder;
class PersonJobBuilder;


class PersonBuilderBase{
  
protected:
    Person& p;
    PersonBuilderBase(Person& person);
public:
    operator Person() const {return std::move(p);}
    
    PersonAddressBuilder lives() const;
    PersonJobBuilder works() const;
};

class PersonBuilder : public PersonBuilderBase{
    Person p;
    
public:
    PersonBuilder();
};

#endif /* PersonBuilder_hpp */

//
//  PersonAdressBuilder.hpp
//  BuilderPattern
//
//  Created by Alexander Poletajev on 27/01/24.
//

#ifndef PersonAdressBuilder_hpp
#define PersonAdressBuilder_hpp

#include <stdio.h>
#include "PersonBuilder.hpp"



class PersonAddressBuilder : public PersonBuilderBase {
    typedef PersonAddressBuilder Self;
public:
    
    PersonAddressBuilder(Person& p) : PersonBuilderBase(p){}
    
    Self& at(const std::string& street){
        p.street_adress = street;
        return *this;
    }
    Self& in(const std::string& city){
        p.city = city;
        return *this;
    }
    Self& with_postal_code(const std::string& code){
        p.post_code = code;
        return *this;
    }
};

#endif /* PersonAdressBuilder_hpp */


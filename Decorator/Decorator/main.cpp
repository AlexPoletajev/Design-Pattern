//
//  main.cpp
//  Dynamic vs Static Decorator
//
//  Created by Alexander Poletajev on 28/01/24.
//

#include <iostream>
#include <string>

struct Shape {
    virtual void draw() = 0;
};

struct Circle : Shape {
    int radius{0};
    
    Circle(int radius) : radius{radius} {}
    
    virtual void draw() override {
        std::cout << "Drawing circle with radius " << radius;
    }
    
    void resize(int factor) {
        radius *= factor;
    }
};

struct Square : Shape {
    int side{0};

    Square(int side) : side{side} {}
    
    virtual void draw() override {
        std::cout << "Drawing square with side " << side;
    }
};

// Dynamic Decorators
struct ColoredShape : Shape {
    std::string color;
    Shape& shape;
    ColoredShape(Shape& shape, std::string color) : shape{shape}, color{color} {}
    
    virtual void draw() override {
        shape.draw();
        std::cout << " and color " << color;
    }
};

struct TransparentShape : Shape {
    uint8_t transparency;
    Shape& shape;

    TransparentShape(Shape& shape, uint8_t transparency) : shape{shape}, transparency{transparency} {}
    
    virtual void draw() override {
        float percent = static_cast<float>(transparency) / 255.f * 100.f;
        shape.draw();
        std::cout << " and transparency of " << percent << "%";
    }
};

//Static Decorators
template<typename T>
concept isShape = std::is_base_of<Shape, T> :: value;

template <isShape T>
struct ColoredShape2 : T {
    std::string color;
    ColoredShape2(){}
    
    template<typename...Args>
    ColoredShape2(const std::string& color, Args ...args)
    :T(std::forward<Args>(args)...), color{color} {}
    
    void draw() override {
        T::draw();
        std::cout << " and color " << color;
    }
};

template <isShape T>
struct TransparentShape2 : T {
    uint8_t transparency{0};
    TransparentShape2(){}
    
    template<typename...Args>
    TransparentShape2(uint8_t transparency, Args ...args)
    :T(std::forward<Args>(args)...), transparency(transparency) {}
    
    void draw() override {
        float percent = static_cast<float>(transparency) / 255.f * 100.f;
        T::draw();
        std::cout << " and transparency of " << percent << "%";
    }
};



int main(int argc, const char * argv[]) {

    Circle circle(5);
    
    // Dynamic Decoration:
    ColoredShape red_circle(circle, "red");
    TransparentShape trans_red_circle(red_circle, 51);
    trans_red_circle.draw();
    std::cout << std::endl;

    /*
    trans_red_circle.resize() - sub class methods are not accessable, limitation of Dynamic Decrator -> solved by Static Decorator..
    */
    
    
    // Static Decoration:
    TransparentShape2<ColoredShape2<Circle>> trans_red_circle2{255, "red", 5};
    trans_red_circle2.draw();
    std::cout << std::endl;
    
    trans_red_circle2.resize(5);
    trans_red_circle2.draw();
    std::cout << std::endl;
    
    // the following doesn't compile ( concept inforcement )
    /*
    class Foo {
        int foo{0};
        Foo(int num) :foo{num} {}
    };
    
    ColoredShape2<Foo> test{"green", 5};
    */
    
    return 0;
}

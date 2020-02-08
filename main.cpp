/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert all of the pointer usage (except for 'const char*') to reference types or const reference types ** WHERE POSSIBLE **
    hint: There is no reference equivalent to nullptr.  
    So don't try to convert nullptr, if nullptr is being returned anywhere
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 */

#include <iostream>
#include <string>
#include <cmath>

struct T
{
    T(float v, const char* n) : value(v), name(n) {}
    float value;
    std::string name;
};

struct Compare
{
    T* compare(T& a, T& b)
    {
        if (a.value < b.value) 
            return &a;
        if (a.value > b.value) 
            return &b;
        return nullptr;
    }
};

struct U
{
    float x { 0 }, y { 0 };
    float uFunc(const float& update)
    {
        std::cout << "U's x value: " << x << std::endl;
        x = update;
        std::cout << "U's x updated value: " << x << std::endl;

        while( std::abs(y - x) > 0.001f )
        {
            y += (std::abs(y - x))/2;
        }
        std::cout << "U's y updated value: " << y << std::endl;
        return y * x;
    }
};

struct S2
{
    static float s2Func(U& that, const float& update)
    {
        std::cout << "U's x value: " << that.x << std::endl;
        that.x = update;
        std::cout << "U's x updated value: " << that.x << std::endl;
        while( std::abs(that.y - that.x) > 0.001f )
        {
            that.y += (std::abs(that.y - that.x))/2;
        }
        //
        std::cout << "U's y updated value: " << that.y << std::endl;
        return that.y * that.x;
    }
};
        
int main()
{
    T one( 1, "one");
    T two( 2, "two");
    
    Compare f;
    auto* smaller = f.compare(one, two);
    if (smaller != nullptr)
    {
        std::cout << "the smaller one is << " << smaller->name << std::endl;
    }  
    
    U u3;
    float updatedValue = 5.0f;
    std::cout << "[static func] u3's multiplied values: " << S2::s2Func(u3, updatedValue) << std::endl;
    
    U u4;
    std::cout << "[member func] u4's multiplied values: " << u4.uFunc( updatedValue ) << std::endl;
}

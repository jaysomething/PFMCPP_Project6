/*
 Project 6: Part 1 / 2
 Video: Chapter 3 Part 2

Create a branch named Part1

 Pointers

 Please look at the screenshot in the files to see what happens if you copy this assignment into Xcode
 
 Task: replace all of the <place holder> with proper names and types that will make this program compile and run.
 
 steps:
 
 0) press the Compile, link and run... button and work your way through all of the error messages.
         you can click on them to be taken to the appropriate line number.
 
 1) finish implementing the constructor for T. the constructor parameters need to initialize 2) and 3)
 
 2) provide a member variable in T of a type of your choosing that works with the compare function below T
         note the name of the variable used in the compare function
 
 3) provide a member variable of type std::string in T that works with the *first* cout statement in main().
         note the name of the variable used in the *first* cout statement in main()
 
 4) finish defining the struct with the compare function
 5) provide proper types for the arguments to compare, and a proper return value
         be sure to make it work with the pointer semantics being used in the if statements.
         see 8) for a hint about what type to use.
 
 6) finish instantiating the two T instances being declared in main(), based on the constructor you finished implementing in T
 
 7) Declare 'f' with the proper type so the call to f.compare works
 
 8) call f.compare() with the correct arguments, based on 2) and 5)
 
 9) correct the cout that uses bigger's member variable with some safe pointer usage.
         the possible return values of the compare() function should give you a hint.
 
 10) complete the implementation for the static function in <structName2>
 
 11) call the <structName2> static function correctly in main()
 
 12) replicate the functionality of <structName2>'s static function by implementing a member function in U that does the same thing.
 
 After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
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
    T* compare(T* a, T* b)
    {
        if(a != nullptr && b != nullptr)
        {
            if( a->value < b->value ) return a;
            if( a->value > b->value ) return b;
        }
        return nullptr;
    }
};

struct U
{
    float x { 0 }, y { 0 };
    float uFunc(float* update)
    {
        if(update != nullptr)
        {
            std::cout << "U's x value: " << x << std::endl;
            x = *update;
            std::cout << "U's x updated value: " << x << std::endl;

            while( std::abs(y - x) > 0.001f )
            {
                y += (std::abs(y - x))/2;
            }
            std::cout << "U's y updated value: " << y << std::endl;
            return y * x;
        }
        std::cout << "Argument is a nullptr. Returning 0\n";
        return 0.0f;
    }
};

struct S2
{
    static float s2Func(U* that, float* update)
    {
        if(that != nullptr && update != nullptr)
        {
            std::cout << "U's x value: " << that->x << std::endl;
            that->x = *update;
            std::cout << "U's x updated value: " << that->x << std::endl;
            while( std::abs(that->y - that->x) > 0.001f )
            {
                that->y += (std::abs(that->y - that->x))/2;
            }
            //
            std::cout << "U's y updated value: " << that->y << std::endl;
            return that->y * that->x;
        }
        std::cout << "Arguments contain nullptrs. Returning 0\n";
        return 0.0f;
    }
};
        
int main()
{
    T one( 1, "one");
    T two( 2, "two");
    
    Compare f;
    auto* smaller = f.compare(&one, &two);
    if (smaller != nullptr)
    {
        std::cout << "the smaller one is << " << smaller->name << std::endl;
    }  
    
    U u3;
    float updatedValue = 5.f;
    std::cout << "[static func] u1's multiplied values: " << S2::s2Func(&u3, &updatedValue) << std::endl;
    
    U u4;
    std::cout << "[member func] u4's multiplied values: " << u4.uFunc( &updatedValue ) << std::endl;
}

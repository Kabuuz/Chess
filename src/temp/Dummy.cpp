#include <SFML/Graphics.hpp>
#include <iostream>
#include <mygame/temp/Dummy.hpp>

namespace temp
{
Dummy::Dummy() : dummy_(nullptr) {}

Dummy::Dummy(IDummy* dummy) : dummy_(dummy) {}

void Dummy::hello()
{
    if(dummy_ != nullptr)
    {
    dummy_->method1();    
    }
    
    std::cout << "Hello" << std::endl;
}

}   // namespace temp

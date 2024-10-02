#include <iostream>
#include <string>

#include "execute_sequence.hpp"

class ExecuteFirst final 
{
    public:
        ExecuteFirst(std::string &&text) 
            : text(std::move(text))
        {

        }

        void exec() 
        {
            std::cout << __PRETTY_FUNCTION__ << " result: " << text << " ptr: " << this << std::endl;
        }

    private: 
        std::string text;
};

class ExecuteSecond final
{
    public:
        ExecuteSecond(const float value)
            : value(value)
        {

        }

        void exec()
        {
            std::cout << __PRETTY_FUNCTION__ << " result: " << value << " ptr: " << this << std::endl;
        }

    private:
        const float value;
};

class ExecuteThird final 
{
    public:
        ExecuteThird(const int value)
            :value(value)
        {

        }

        void exec() 
        {
            std::cout << __PRETTY_FUNCTION__ << " result: " << value << " ptr: " << this << std::endl;
        }

    private:
        const int value;
};

int main()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    ExecuteSequence<ExecuteFirst, ExecuteSecond, ExecuteThird> sequnce;

    sequnce.makeSequence<ExecuteFirst>("essa tekst");
    sequnce.makeSequence<ExecuteSecond>(12.12);
    sequnce.makeSequence<ExecuteThird>(12);

    sequnce.execute();

    return 0;
}
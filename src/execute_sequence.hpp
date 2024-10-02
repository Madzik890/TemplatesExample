#ifndef EXECUTE_SEQUENCE_HPP
#define EXECUTE_SEQUENCE_HPP

#include <tuple>
#include <optional>

template<typename... Sequence>
class ExecuteSequence final
{
    public:
        template<typename Object, typename... Argc>
        void makeSequence(Argc &&... args)
        {
            auto &&object = std::get<std::optional<Object>>(mSequences);
            static_assert((std::is_constructible_v<Object, Argc&&> && ...));
            object.emplace(std::forward<Argc>(args)...);            
        }
        void execute()
        {
            (std::get<std::optional<Sequence>>(mSequences)->exec(), ...);
        }

    private:
        std::tuple<std::optional<Sequence>...> mSequences;
};

#endif
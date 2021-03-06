
#include "VectorMath.hpp"

sf::Vector2f normalize(sf::Vector2f input) {
    float m = getMagnitude(input);
    return sf::Vector2f(input.x/m, input.y/m);
}

float getMagnitude(sf::Vector2f input) {
    return std::sqrt(input.x*input.x + input.y*input.y);
}

float getSquareMagnitude(sf::Vector2f input) {
    return input.x*input.x + input.y*input.y;
}

sf::Vector2f scalar(sf::Vector2f in, float sca) {
    return sf::Vector2f(in.x*sca,in.y*sca);
}

Direction eighth(sf::Vector2f in) {
    in = normalize(in);
    return in.x > 0 ?
        (in.x >  cos1pi8 ? Direction::RIGHT : (in.x >  sin1pi8 ? (in.y > 0 ? Direction::DOWNRIGHT : Direction::UPRIGHT) : (in.y > 0 ? Direction::DOWN : Direction::UP))) :
        (in.x < -cos1pi8 ? Direction::LEFT  : (in.x < -sin1pi8 ? (in.y > 0 ? Direction::DOWNLEFT  : Direction::UPLEFT)  : (in.y > 0 ? Direction::DOWN : Direction::UP)));
}


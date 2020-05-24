#include "Level.h"

#include "types/Point.h"
#include "types/Length.h"
#include "types/Width.h"
#include "types/Hitpoints.h"

#include <iostream>
#include <sstream>

namespace bricks {

    using Point = types::Point;
    using Length = types::Length;
    using Width = types::Width;
    using Hitpoints = types::Hitpoints;

    std::istream &operator>>(std::istream &is, Level &obj)
    {      
        std::vector<Brick> bricks;
        std::vector<IndestructibleBrick> indestructibleBricks;

        std::string line;
        while(std::getline(is, line)) {

            if(impl::isComment(line)) {
                continue;
            }

            std::istringstream ist{line};

            Point point;
            ist >> point;
            if(!ist) {
                is.setstate(std::ios_base::failbit);
                return is;
            }

            Length length;
            ist >> length;
            if(!ist) {
                is.setstate(std::ios_base::failbit);
                return is;
            }

            Width width;
            ist >> width;
            if(!ist) {
                is.setstate(std::ios_base::failbit);
                return is;
            }

            Hitpoints hitpoints;
            ist >> hitpoints;
            if(!ist) {
                indestructibleBricks.emplace_back(
                    IndestructibleBrick{point, length, width}
                );
            }
            else {
                bricks.emplace_back(
                    Brick{point, length, width, hitpoints}
                );
            }
        }

        obj = std::move(Level{bricks, indestructibleBricks});
        return is;
    }

namespace impl{

    bool isComment(const std::string line)
    {
        std::istringstream ist{line};

        char c;
        ist >> c;
        if(c == '#') {
            return true;
        }
        return false;
    }

}

}
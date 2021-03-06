#include "gtest/gtest.h"

#include "../include/Level.h"

#include <iostream>
#include <sstream>

using namespace bricks;

TEST(LevelTest, defaultConstructor)
{
    Level level;

    EXPECT_EQ(level.gridWidth(), 0);
    EXPECT_EQ(level.gridHeight(), 0);
    EXPECT_TRUE(level.bricks.empty());
    EXPECT_TRUE(level.indestructibleBricks.empty());
}

TEST(LevelTest, operatorIsWorks1)
{
    std::string test{
        R"(W 10 H 20
# 
X 1.2 Y 3.4 W 5.6 H 7.8 HP 9
#
X 9.8 Y 7.6 W 5.4 H 3.2
#)"};

    std::istringstream ist{test};

    Level level;
    ist >> level;

    EXPECT_EQ(ist.rdbuf()->in_avail(), 0);

    auto wallThickness = level.leftWall().width();

    EXPECT_EQ(level.gridWidth(), 10 + 2 * wallThickness);
    EXPECT_EQ(level.gridHeight(), 20 + wallThickness);

    auto bricks = level.bricks;
    auto indestructibleBricks = level.indestructibleBricks;

    ASSERT_EQ(bricks.size(), 1);
    ASSERT_EQ(indestructibleBricks.size(), 1);

    EXPECT_EQ(bricks[0].topLeft().x, 1.2 + wallThickness);
    EXPECT_EQ(bricks[0].topLeft().y, 3.4 + wallThickness);
    EXPECT_EQ(bricks[0].width(), 5.6);
    EXPECT_EQ(bricks[0].height(), 7.8);
    EXPECT_EQ(bricks[0].hitpoints(), 9);

    EXPECT_EQ(indestructibleBricks[0].topLeft().x, 9.8 + wallThickness);
    EXPECT_EQ(indestructibleBricks[0].topLeft().y, 7.6 + wallThickness);
    EXPECT_EQ(indestructibleBricks[0].width(), 5.4);
    EXPECT_EQ(indestructibleBricks[0].height(), 3.2);
}

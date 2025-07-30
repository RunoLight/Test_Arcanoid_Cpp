#pragma once
#include <memory>
#include <vector>

#include "../Engine/GameObject.h"

enum
{
    BRICK_SPACING_Y = 3,
    BRICK_SPACING_X = 5,
    BRICK_WIDTH = 40,
    BRICK_HEIGHT = 20
};

#define PADDLE_WIDTH 100.0f
#define PADDLE_HEIGHT 20.0f
#define PADDLE_SPEED 300.0f

#define BALL_SPEED 400.0f
#define BALL_SIZE 10.0f

class ArkanoidGame
{
public:
    void initialize(std::vector<std::unique_ptr<GameObject>>& entities);
    void act(float dt);

private:
    void createBrick(std::vector<std::unique_ptr<GameObject>>& entities, float x, float y, unsigned int color) const;
    void spawnBricks(std::vector<std::unique_ptr<GameObject>>& entities, int rows) const;

    int ballsAmount = 0;
};

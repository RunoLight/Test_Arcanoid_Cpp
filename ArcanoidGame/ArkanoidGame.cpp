#include "ArkanoidGame.h"

#include "BallComponent.h"
#include "BrickComponent.h"
#include "PlatformComponent.h"
#include "RectangleRenderer.h"

#include "../Engine/BaseSolution/Engine.h"

void ArkanoidGame::initialize(std::vector<std::unique_ptr<GameObject>>& entities)
{
    const std::function<void()> onBallDestroyCallback = [&]() -> int
    {
        ballsAmount--;
        if (ballsAmount == 0)
        {
            schedule_quit_game();
        }

        return 0;
    };
    
    auto platformGameObject = std::make_unique<GameObject>(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 20, PADDLE_WIDTH,
                                                       PADDLE_HEIGHT);
    auto platform = std::make_unique<PlatformComponent>(PADDLE_SPEED, PADDLE_WIDTH, PADDLE_HEIGHT);
    auto platformRenderer = std::make_unique<RectangleRenderer>();

    platformGameObject->registerComponent(std::move(platform));
    platformGameObject->registerRenderer(std::move(platformRenderer));
    entities.push_back(std::move(platformGameObject));

    auto ballGameObject = std::make_unique<GameObject>(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, BALL_SIZE, BALL_SIZE);
    auto ball = std::make_unique<BallComponent>(BALL_SPEED);
    auto ballRenderer = std::make_unique<RectangleRenderer>();
    ballsAmount += 1;
    ballGameObject->setOnDestroyCallback(onBallDestroyCallback);

    ballGameObject->registerComponent(std::move(ball));
    ballGameObject->registerRenderer(std::move(ballRenderer));
    entities.push_back(std::move(ballGameObject));
    
    spawnBricks(entities, 4);
}

void ArkanoidGame::act(float dt)
{
    
}

void ArkanoidGame::createBrick(std::vector<std::unique_ptr<GameObject>>& entities, float x, float y, unsigned color) const
{
    auto go = std::make_unique<GameObject>(x, y, BRICK_WIDTH, BRICK_HEIGHT);
    auto brick = std::make_unique<BrickComponent>();
    auto renderer = std::make_unique<RectangleRenderer>(color);
    go->registerComponent(std::move(brick));
    go->registerRenderer(std::move(renderer));
    entities.push_back(std::move(go));
}

void ArkanoidGame::spawnBricks(std::vector<std::unique_ptr<GameObject>>& entities, int rows) const
{
    unsigned int defaultColor = 0x0000DFFF;
    float currentY = BRICK_SPACING_Y + BRICK_HEIGHT;
    for (int i = 0; i < rows; i++)
    {
        float currentX = BRICK_SPACING_X + BRICK_WIDTH;
        while (currentX <= SCREEN_WIDTH)
        {
            createBrick(entities, currentX, currentY, defaultColor);
            currentX += BRICK_SPACING_X + BRICK_WIDTH;
        }

        defaultColor -= 0x00003000;
        currentY += BRICK_SPACING_Y + BRICK_HEIGHT;
    }
}
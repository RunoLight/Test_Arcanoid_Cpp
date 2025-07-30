#include "BallComponent.h"

#include "../Engine/BaseSolution/Engine.h"
#include "../Engine/GameObject.h"

void BallComponent::act(GameObject& gameObject, float dt)
{
    hadCollision = false;
    float x = gameObject.getX();
    float y = gameObject.getY();
    x += dt * speed * dirX;
    y += dt * speed * dirY;

    gameObject.setPosition(x, y);

    // Ball collision with walls
    const float size = gameObject.getSize().first;
    if (x - size / 2 <= 0 || x + size / 2 >= SCREEN_WIDTH - 1)
        dirX = -dirX;
    if (y - size / 2 <= 0)
        dirY = -dirY;
    if (y + size / 2 >= SCREEN_HEIGHT)
        gameObject.destroy();
}

void BallComponent::onCollision(GameObject& gameObject, GameObject& other)
{
    if (hadCollision)
        return;
    hadCollision = true;
    dirY = -dirY;
}

#include "PlatformComponent.h"

#include "../Engine/BaseSolution/Engine.h"
#include "../Engine/GameObject.h"

void PlatformComponent::act(GameObject& gameObject, float dt)
{
    const float y = gameObject.getY();

    if (is_key_pressed(VK_LEFT))
    {
        if (gameObject.getX() - myWidth / 2.0f > 0)
        {
            gameObject.setPosition(gameObject.getX() - dt * speed, y);
        }
    }
    if (is_key_pressed(VK_RIGHT))
    {
        if (gameObject.getX() + myWidth / 2.0f < SCREEN_WIDTH - 1)
        {
            gameObject.setPosition(gameObject.getX() + dt * speed, y);
        }
    }
}

float PlatformComponent::getWidth() const
{
    return myWidth;
}

float PlatformComponent::getHeight() const
{
    return myHeight;
}

#include "BrickComponent.h"

#include "../Engine/GameObject.h"

void BrickComponent::act(GameObject& gameObject, float dt)
{
}

void BrickComponent::onCollision(GameObject& gameObject, GameObject& other)
{
    gameObject.destroy();
}

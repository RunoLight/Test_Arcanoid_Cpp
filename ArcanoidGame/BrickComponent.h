#pragma once
#include "../Engine/Component.h"

class BrickComponent : public Component
{
public:
    void act(GameObject& gameObject, float dt) override;

    void onCollision(GameObject& gameObject, GameObject& other) override;
};

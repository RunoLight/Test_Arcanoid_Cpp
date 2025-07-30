#pragma once

#pragma once
#include "../Engine/Component.h"

class BallComponent : public Component
{
public:
    BallComponent(float speed) : speed(speed), dirX(1), dirY(-1)
    {
    }

    void act(GameObject& gameObject, float dt) override;

    void onCollision(GameObject& gameObject, GameObject& other) override;

private:
    float speed;
    float dirX;
    float dirY;

    // todo: hack
    bool hadCollision = false;
};

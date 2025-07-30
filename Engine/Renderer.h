#pragma once

class GameObject;

class Renderer
{
public:
    virtual ~Renderer() = default;
    virtual void render(const GameObject& gameObject) const = 0;
};

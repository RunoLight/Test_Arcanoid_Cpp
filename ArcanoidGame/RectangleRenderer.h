#pragma once

#include "../Engine/Renderer.h"

class RectangleRenderer : public Renderer
{
public:
    RectangleRenderer(unsigned int color = 0xFFFFFFFF);

    void render(const GameObject& gameObject) const override;

private:
    unsigned int myColor;
};

#include "RectangleRenderer.h"

#include "../Engine/BaseSolution/Engine.h"
#include "../Engine/GameObject.h"

RectangleRenderer::RectangleRenderer(const unsigned int color) : myColor(color)
{
}

void RectangleRenderer::render(const GameObject& gameObject) const
{
    const int leftBorder = static_cast<int>(gameObject.getX() - gameObject.getWidth() / 2.0f);
    const int rightBorder = static_cast<int>(gameObject.getX() + gameObject.getWidth() / 2.0f);
    const int topBorder = static_cast<int>(gameObject.getY() + gameObject.getHeight() / 2.0f);
    const int bottomBorder = static_cast<int>(gameObject.getY() - gameObject.getHeight() / 2.0f);

    for (int x = leftBorder; x < rightBorder; x++)
    {
        for (int y = bottomBorder; y < topBorder; y++)
        {
            buffer[y][x] = myColor;
        }
    }
}

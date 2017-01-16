#include "Animation.h"

#include <iostream>

void Animation::addFrame(const sf::IntRect& frame, float timeToNextFrame)
{
    if (timeToNextFrame > m_longestFrameTime)
        m_longestFrameTime = timeToNextFrame;

    m_frames.emplace_back(frame, timeToNextFrame);
}

const sf::IntRect Animation::getFrame()
{
    if (m_timer.getElapsedTime().asSeconds() >= m_frames[m_currentFrame].timeToNextFrame)
    {
        m_currentFrame++;
        if (m_currentFrame == m_frames.size() )
            m_currentFrame = 0;
        m_timer.restart().asSeconds();
    }

    return  m_frames[m_currentFrame].frame;
}

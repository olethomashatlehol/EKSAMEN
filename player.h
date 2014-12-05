#ifndef PLAYER_H
#define PLAYER_H

#include "Ogre.h"
#include "OgreFramework.h"
class Player
{
public:
    Player();
    ~Player();
    void Update(const Ogre::FrameEvent &evt);
    Ogre::Vector3 getPlayerPosition();
};

#endif // PLAYER_H

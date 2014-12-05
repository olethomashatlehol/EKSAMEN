#ifndef PLAYER_H
#define PLAYER_H

#include "OgreFramework.h"
#include "Ogre.h"
#include "OIS.h"


class Player
{
public:
    Player(Ogre::String name, Ogre::SceneManager *sceneMgr);
    ~Player();
    Ogre::Vector3 getPlayerPosition();

protected:
     Ogre::SceneNode* playernode;
     Ogre::Entity* playerent;
};

#endif // PLAYER_H

#ifndef PLAYER_H
#define PLAYER_H

#include "Ogre.h"
#include "OgreFramework.h"
class Player
{
public:
    Player(Ogre::String name, Ogre::SceneManager *sceneMgr);
    ~Player();
    void Update(const Ogre::FrameEvent &evt);
    Ogre::Vector3 getPlayerPosition();
    void Movement();
    void setPlayerPosition(Ogre::Vector3 pos);

    Ogre::SceneNode *playernode;
    Ogre::Entity *playerent;
    Ogre::SceneManager *mscenemgr;
    Ogre::AnimationState *mAnimationState;
    Ogre::Real playermove;

    bool backwards;
    bool forward;
    bool left;
    bool right;
};

#endif // PLAYER_H

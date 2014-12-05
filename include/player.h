#ifndef PLAYER_H
#define PLAYER_H

#include "Ogre.h"

class Player
{
public:
    Player(Ogre::String name, Ogre::SceneManager *sceneMgr);
    ~Player();
    void Update(const Ogre::FrameEvent &evt);
    Ogre::Vector3 getPlayerPosition();
    void Movement();
    void setPlayerPosition(Ogre::Vector3 pos);
    Ogre::Vector3 getSightNode();

    Ogre::SceneNode *playernode;
    Ogre::SceneNode *sightnode;
    Ogre::Entity *playerent;
    Ogre::SceneManager *mscenemgr;
    Ogre::AnimationState *mAnimationState;
    Ogre::Real playermove;
    int *mPlayerWalkSpeed;
    Ogre::Entity *getEntity();

    bool backwards = false;
    bool forward = false;
    bool left = false;
    bool right = false;
};

#endif // PLAYER_H

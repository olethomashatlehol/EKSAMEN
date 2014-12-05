#ifndef ENEMY_H
#define ENEMY_H

#include "Ogre.h"

class Enemy
{
public:
    Enemy(Ogre::String name, Ogre::SceneManager *scenemgr);
    ~Enemy();
    void update(const Ogre::FrameEvent &evt);
    void movement();
    void setEnemyPosition();
    Ogre::Entity *getEntity();
    bool nextLocation();
    Ogre::Vector3 getEnemyPosition();

    Ogre::SceneNode *enemynode;
    Ogre::Entity *enemyent;
    Ogre::SceneManager *mscenemgr;

    Ogre::Real mDistance;
    Ogre::Vector3 mDirection;
    Ogre::Vector3 mDestination;
    std::deque<Ogre::Vector3> mWalkList;
    int mListIterator;
    Ogre::Real mEnemyWalkSpeed;
};

#endif // ENEMY_H

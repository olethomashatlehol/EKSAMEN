#ifndef ENEMY_H
#define ENEMY_H
#include "OgreFramework.h"
#include "Ogre.h"
class Enemy
{
public:
    Enemy(Ogre::String name, Ogre::SceneManager *scenemgr);
    ~Enemy();
    void update(const Ogre::FrameEvent &evt);
    void movement();
    void setEnemyPosition();
    Ogre::Vector3 getEnemyPosition();

    Ogre::SceneNode *enemynode;
    Ogre::Entity *enemyent;
    Ogre::SceneManager *mscenemgr;
};

#endif // ENEMY_H

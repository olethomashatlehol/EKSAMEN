#include "enemy.h"

Enemy::Enemy(Ogre::String name, Ogre::SceneManager *scenemgr)
{
    mscenemgr = scenemgr;
    enemyent = mscenemgr->createEntity((name, "ogrehead.mesh"));
    enemyent->setCastShadows(true);
    enemynode = mscenemgr->getRootSceneNode()->createChildSceneNode("enemynode",Ogre::Vector3(0.0f, 2.0f, 0.0f));
    enemynode->attachObject(enemyent);
    enemynode->scale(0.1f, 0.1f, 0.1f);


}
Enemy::~Enemy()
{

}

void Enemy::update(const Ogre::FrameEvent &evt)
{

}

void Enemy::movement()
{

}

Ogre::Vector3 Enemy::getEnemyPosition()
{

    return enemynode->getPosition();
}

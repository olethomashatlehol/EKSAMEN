#include "enemy.h"

Enemy::Enemy(Ogre::String name, Ogre::SceneManager *scenemgr)
{
    mscenemgr = scenemgr;
    enemyent = mscenemgr->createEntity((name, "ogrehead.mesh"));
    enemyent->setCastShadows(true);
    enemynode = mscenemgr->getRootSceneNode()->createChildSceneNode("enemynode",Ogre::Vector3(0.0f, 2.0f, 0.0f));
    enemynode->attachObject(enemyent);
    enemynode->scale(0.1f, 0.1f, 0.1f);

    mWalkList.push_back(Ogre::Vector3(18.0f,   2.0f,  18.0f ));
    mWalkList.push_back(Ogre::Vector3(9.0f,   2.0f,  9.0f ));
    mWalkList.push_back(Ogre::Vector3(-18.0f,  2.0f, 18.0f));
    mWalkList.push_back(Ogre::Vector3(-9.0f,   2.0f,  9.0f ));
    mWalkList.push_back(Ogre::Vector3(0.0f,  2.0f, 0.0f));
    mWalkList.push_back(Ogre::Vector3(18.0f,  2.0f, -18.0f));
    mWalkList.push_back(Ogre::Vector3(9.0f,   2.0f,  -9.0f ));
    mWalkList.push_back(Ogre::Vector3(-18.0f,  2.0f, -18.0f));
    mWalkList.push_back(Ogre::Vector3(-9.0f,   2.0f,  -9.0f ));
    mListIterator = 0;

    mEnemyWalkSpeed = 45.0f;
    mDirection = Ogre::Vector3::ZERO;
}
Enemy::~Enemy()
{

}
bool Enemy::nextLocation(){
    if (mWalkList.empty()) return false;
    mDestination = mWalkList[mListIterator];  // this gets a position from the list
    mDirection = mDestination - enemynode->getPosition();
    mDistance = mDirection.normalise();
    mListIterator = rand()% mWalkList.size();

    return true;
}
void Enemy::update(const Ogre::FrameEvent &evt)
{

     movement();


    if (mDirection == Ogre::Vector3::ZERO) {
        nextLocation();
        std::cout<<"next"<<std::endl;
    }else{
        Ogre::Real enemyMove = mEnemyWalkSpeed * evt.timeSinceLastFrame;
        mDistance -= enemyMove;
        if (mDistance <= 0.0f){
            enemynode->setPosition(mDestination);
            mDirection = Ogre::Vector3::ZERO;
            if (nextLocation()){
                // Correct Rotation Code will go here later
                Ogre::Vector3 src = enemynode->getOrientation() * Ogre::Vector3::UNIT_X;
                if ((1.0f + src.dotProduct(mDirection)) < 0.0001f) {
                    enemynode->yaw(Ogre::Degree(180));
                }else{
                    Ogre::Quaternion quat = src.getRotationTo(mDirection);
                    enemynode->rotate(quat);
                } // else
            }//if
        }else{
            enemynode->translate(mDirection * enemyMove);
        } // else
    } // else

}

void Enemy::movement()
{
    nextLocation();
}

Ogre::Entity *Enemy::getEntity()
{
    return enemyent;
}

Ogre::Vector3 Enemy::getEnemyPosition()
{

    return enemynode->getPosition();
}

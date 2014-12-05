
#include "player.h"

Player::Player(Ogre::String name, Ogre::SceneManager *sceneMgr)
{
    playerent = sceneMgr->createEntity(("name", "penguin.mesh"));
    playerent->setCastShadows(true);
    playernode = sceneMgr->getRootSceneNode()->createChildSceneNode("playernode",Ogre::Vector3(-40.0f, 5.0f, 0.0f));
    playernode->attachObject(playerent);
    playernode->scale(0.2f, 0.2f, 0.2f);
    playernode->rotate(Ogre::Vector3::UNIT_Y, Ogre::Degree(90));

    //playernode = sceneMgr->



}
Player::~Player(){
}

Ogre::Vector3 Player::getPlayerPosition()
{

    return playernode->getPosition();
}

void Player::movement(const Ogre::FrameEvent &evt)
{
      //Ogre::Real playerMove = 10 * elapsedTime;

    if(forward){
        playernode->translate(0.0, 0.0, -1.0 * 10);
    }
    if(backwards){
        playernode->translate(0.0, 0.0, 1.0 * 10);
    }
    if(left){
        playernode->translate(-1.0 * 10, 0.0, 0.0);
        }
    if(right){
        playernode->translate(1.0 * 10, 0.0, 0.0);
}
}
/*

// Set walking animation
mAnimationState = ogreHead->getAnimationState("amuse");
mAnimationState->setLoop(true);
mAnimationState->setEnabled(true);*/

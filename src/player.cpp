
#include "player.h"

Player::Player(Ogre::String name, Ogre::SceneManager *sceneMgr)
{
    mscenemgr =sceneMgr;
    playerent = mscenemgr->createEntity(("name", "penguin.mesh"));
    playerent->setCastShadows(true);
    playernode = mscenemgr->getRootSceneNode()->createChildSceneNode("playernode",Ogre::Vector3(-40.0f, 5.0f, 0.0f));
    playernode->attachObject(playerent);
    playernode->scale(0.2f, 0.2f, 0.2f);
    playernode->rotate(Ogre::Vector3::UNIT_Y, Ogre::Degree(90));

    mAnimationState = playerent->getAnimationState("amuse");
    mAnimationState->setLoop(true);
    mAnimationState->setEnabled(true);



}
Player::~Player(){
}

Ogre::Vector3 Player::getPlayerPosition()
{

    return playernode->getPosition();
}

void Player::Movement()
{
    if(forward){
        playernode->translate(0.0, 0.0, -1.0 * playermove);
    }
    if(backwards){
        playernode->translate(0.0, 0.0, 1.0 * playermove);
    }
    if(left){
        playernode->translate(-1.0 * playermove, 0.0, 0.0);
        }
    if(right){
        playernode->translate(1.0 * playermove, 0.0, 0.0);
    }
}

void Player::setPlayerPosition(Ogre::Vector3 pos)
{
    playernode->setPosition(pos);
}

void Player::Update(const Ogre::FrameEvent &evt)
{
      playermove = 10 * evt.timeSinceLastFrame;
      Movement();

        mAnimationState->addTime(evt.timeSinceLastFrame);
}


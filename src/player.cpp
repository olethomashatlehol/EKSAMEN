
#include "player.h"
///THE PLAYER CLASS WITH MOVEMENT
Player::Player(Ogre::String name, Ogre::SceneManager *sceneMgr)
{

    /// CREATE PLAYER AND PLAYERNODE
    mscenemgr =sceneMgr;
    playerent = mscenemgr->createEntity((name, "penguin.mesh"));
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
    /// THIS IS WHERE THE MOVEMENT HAPPENS
    if(forward){
        playernode->translate(1.0 * playermove, 0.0, 0);
    }
    if(backwards){
        playernode->translate(-1.0 * playermove, 0.0,0 );
    }
    if(left){
        playernode->translate(0, 0.0, -1.0 * playermove);
        }
    if(right){
        playernode->translate(0, 0.0,1.0 * playermove);
    }
}

void Player::setPlayerPosition(Ogre::Vector3 pos)
{
    ///SETPLAYERPOS
    playernode->setPosition(pos);
}

Ogre::Vector3 Player::getSightNode()
{
    return sightnode->getPosition();
}

Ogre::Entity *Player::getEntity()
{
    ///GET ENTITY FROM HERE, COLLISIONS ETC.
    return playerent;
}

void Player::Update(const Ogre::FrameEvent &evt)
{
    ///UPDATES ANIMATIONS AND MOVEMENT OF PLAYER
      playermove = 10 * evt.timeSinceLastFrame;
      Movement();

      mAnimationState->addTime(evt.timeSinceLastFrame);
}


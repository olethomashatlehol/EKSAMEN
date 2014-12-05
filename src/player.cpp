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


/*
Ogre::Entity* ogreHead = mSceneMgr->createEntity("Head", "penguin.mesh");
ogreHead->setCastShadows(true);
// Create a SceneNode and attach the Entity to it
playerNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("HeadNode", Ogre::Vector3(-40.0f, 5.0f, 0.0f));
playerNode->attachObject(ogreHead);
playerNode->scale(0.2f, 0.2f, 0.2f);
playerNode->rotate(Ogre::Vector3::UNIT_Y, Ogre::Degree(90));
// Set walking animation
mAnimationState = ogreHead->getAnimationState("amuse");
mAnimationState->setLoop(true);
mAnimationState->setEnabled(true);*/

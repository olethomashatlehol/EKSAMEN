#include "EksamensApp.h"

//-------------------------------------------------------------------------------------
EksamensApp::EksamensApp(void)
{
    mPickups = 0;
}
//-------------------------------------------------------------------------------------
EksamensApp::~EksamensApp(void)
{

}

//-------------------------------------------------------------------------------------
void EksamensApp::createScene(void)
{
   /// creating the scene here.

    /// Set the scene's ambient light
    mSceneMgr->setAmbientLight(Ogre::ColourValue(0.4f, 0.4f, 0.4f));
    mSceneMgr->setShadowTechnique(Ogre::SHADOWTYPE_TEXTURE_ADDITIVE);

   ///Skybox
    mSceneMgr->setSkyBox(true, "Examples/SpaceSkyBox", 500, false);

    /// Create the player
    player = new Player("player",mSceneMgr);

    /// Create the enemy
    enemy = new Enemy("enemy", mSceneMgr);

    ///Create 3rd person camera
    camera = new Camera ("Extended Camera", mSceneMgr, mCamera);
    /// Create the goal
    Ogre::Entity* mEntGoal = mSceneMgr->createEntity("Goal", "athene.mesh");
    mGoalNode = mSceneMgr->getRootSceneNode()->
            createChildSceneNode("GoalNode", Ogre::Vector3(50.0f, 8.0f, 0.0f));
    mGoalNode->attachObject(mEntGoal);
    mGoalNode->scale(0.1f, 0.1f, 0.1f);
    mGoalNode->rotate(Ogre::Vector3::UNIT_Y, Ogre::Degree(-90));
 
    ///Create a Light and set its position
    Ogre::Light* light = mSceneMgr->createLight("MainLight");
    light->setPosition(2.0f, 25.0f, 22.0f);


    ///Create floor
    Ogre::Plane plane(Ogre::Vector3::UNIT_Y, 0);
    Ogre::MeshManager::getSingleton().createPlane("ground", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
                                                  plane, 300, 50, 10, 5, true, 1, 8, 1, Ogre::Vector3::UNIT_Z);

    Ogre::Entity* entGround = mSceneMgr->createEntity("GroundEntity", "ground");
    Ogre::SceneNode* groundNode =mSceneMgr->getRootSceneNode()->createChildSceneNode("GroundNode");
    groundNode->attachObject(entGround);
    entGround->setMaterialName("Examples/Rockwall");
    entGround->setCastShadows(false);
    groundNode->setPosition(0.0, -0.0, 0.0);



    /// Create pickups:
    Ogre::Entity* entPickup = mSceneMgr->createEntity("PickupEntity1", "Barrel.mesh");
    mPickupNode1 = mSceneMgr->getRootSceneNode()->
            createChildSceneNode("PickupNode1", Ogre::Vector3(20.0f, 3.0f, 20.0f));
    mPickupNode1->attachObject(entPickup);
    mPickupNode1->scale(0.9f, 0.9f, 0.9f);

    entPickup = mSceneMgr->createEntity("PickupEntity2", "Barrel.mesh");
    mPickupNode2 = mSceneMgr->getRootSceneNode()->
            createChildSceneNode("PickupNode2", Ogre::Vector3(-20.0f, 3.0f, 20.0f));
    mPickupNode2->attachObject(entPickup);
    mPickupNode2->scale(0.9f, 0.9f, 0.9f);

    entPickup = mSceneMgr->createEntity("PickupEntity3", "Barrel.mesh");
    mPickupNode3 = mSceneMgr->getRootSceneNode()->
            createChildSceneNode("PickupNode3", Ogre::Vector3(20.0f, 3.0f, -20.0f));
    mPickupNode3->attachObject(entPickup);
    mPickupNode3->scale(0.9f, 0.9f, 0.9f);

    entPickup = mSceneMgr->createEntity("PickupEntity4", "Barrel.mesh");
    mPickupNode4 = mSceneMgr->getRootSceneNode()->
            createChildSceneNode("PickupNode4", Ogre::Vector3(-20.0f, 3.0f, -20.0f));
    mPickupNode4->attachObject(entPickup);
    mPickupNode4->scale(0.9f, 0.9f, 0.9f);

}



bool EksamensApp::keyPressed(const OIS::KeyEvent &arg)
{

    ///KEY INPUT - Pressed
    switch (arg.key)
    {
    case OIS::KC_ESCAPE:
        mShutDown = true;
        break;

    case OIS::KC_UP:
        player->forward = true;
        break;

    case OIS::KC_DOWN:
        player->backwards = true;
        break;

    case OIS::KC_LEFT:
        player->left = true;
        break;

    case OIS::KC_RIGHT:
        player->right = true;
        break;
    case OIS::KC_RETURN:
        //reset penguin
        if (enemy->mEnemyWalkSpeed == 0 && mPickups != 10)
        {
            enemy->mEnemyWalkSpeed = 45;
            player->setPlayerPosition(Ogre::Vector3(-40.0f, 5.0f, 0.0f));
            mSceneMgr->setAmbientLight(Ogre::ColourValue(0.4f, 0.4f, 0.4f));
        }
        break;
    default:
        OgreFramework::keyPressed(arg);
    }
    return true;
}

bool EksamensApp::keyReleased(const OIS::KeyEvent &arg)
{

    ///KEY INPUT - released
    switch (arg.key)
    {
    case OIS::KC_UP:

        player->forward = false;
        break;

    case OIS::KC_DOWN:

        player->backwards = false;
        break;

    case OIS::KC_LEFT:

        player->left = false;
        break;

    case OIS::KC_RIGHT:

        player->right = false;
        break;
    default:
        OgreFramework::keyReleased(arg);
    }
    return true;
}

bool EksamensApp::mouseMoved(const OIS::MouseEvent &arg)
{
    return true;
}

void EksamensApp::checkCollisions()
{
    ///CHECKING COLLISIONS HERE
    if (player->getPlayerPosition().z < -25){
        player->playernode->translate(0.0, -2.0 * player->playermove, 0.0);
    }
    if (player->getPlayerPosition().z > 25) {
        player->playernode->translate(0.0, -2.0 * player->playermove, 0.0);
    }
    if (player->getPlayerPosition().y < -30) {
       ///Could take damage or reset game or something here...
        player->playernode->setPosition(Ogre::Vector3(-40.0f, 5.0f, 0.0f));
    }

    ///Pickups
    if(player->getEntity()->
            getWorldBoundingBox().intersects(mSceneMgr->getEntity("PickupEntity1")->getWorldBoundingBox()))
    {
        if (mSceneMgr->getEntity("PickupEntity1")->isVisible())
        {
            mSceneMgr->getEntity("PickupEntity1")->setVisible(false);
            mPickups ++;
        }
    }
    if(player->getEntity()->
            getWorldBoundingBox().intersects(mSceneMgr->getEntity("PickupEntity2")->getWorldBoundingBox()))
    {
        if (mSceneMgr->getEntity("PickupEntity2")->isVisible())
        {
            mSceneMgr->getEntity("PickupEntity2")->setVisible(false);
            mPickups ++;
        }
    }
    if(player->getEntity()->
            getWorldBoundingBox().intersects(mSceneMgr->getEntity("PickupEntity3")->getWorldBoundingBox()))
    {
        if (mSceneMgr->getEntity("PickupEntity3")->isVisible())
        {
            mSceneMgr->getEntity("PickupEntity3")->setVisible(false);
            mPickups ++;
        }
    }
    if(player->getEntity()->
            getWorldBoundingBox().intersects(mSceneMgr->getEntity("PickupEntity4")->getWorldBoundingBox()))
    {
        if (mSceneMgr->getEntity("PickupEntity4")->isVisible())
        {
            mSceneMgr->getEntity("PickupEntity4")->setVisible(false);
            mPickups ++;
        }
    }

  ///Goal
    if(player->getEntity()->
            getWorldBoundingBox().intersects(mSceneMgr->getEntity("Goal")->getWorldBoundingBox()))
    {
        if (mPickups == 4 && player->mPlayerWalkSpeed != 0)
        {
            player->mPlayerWalkSpeed = 0;
            enemy->mEnemyWalkSpeed = 0;
            mPickups = 10; //no reset
        }
    }

    ///Enemy
    if(player->getEntity()->
            getWorldBoundingBox().intersects(enemy->getEntity()->getWorldBoundingBox()))
    {
        //mSceneMgr->setAmbientLight(Ogre::ColourValue(0.9f, 0.1f, 0.1f));
        player->mPlayerWalkSpeed = 0;
        enemy->mEnemyWalkSpeed = 0;
    }


}



void EksamensApp::createFrameListener(void){
    OgreFramework::createFrameListener();

}

void EksamensApp::createCamera(void)
{
    /// create the camera
    mCamera = mSceneMgr->createCamera("PlayerCam");

}

bool EksamensApp::frameRenderingQueued(const Ogre::FrameEvent &evt){

    ///update player
    player->Update(evt);
   ///update enemy
    enemy->update(evt);
    ///update camera
    camera->update(evt, player->getPlayerPosition());


    ///Collisions
    checkCollisions();


  return OgreFramework::frameRenderingQueued(evt);
}


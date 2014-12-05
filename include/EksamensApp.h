#ifndef __EksamensApp_h_
#define __EksamensApp_h_

#include "OgreFramework.h"
#include "player.h"
#include "enemy.h"
#include "camera.h"
class EksamensApp : public OgreFramework
{
public:
    EksamensApp(void);
    ~EksamensApp(void);

    void createCamera();
protected:
     void createScene(void);
     bool keyPressed( const OIS::KeyEvent &arg );
     bool keyReleased( const OIS::KeyEvent &arg );
     bool mouseMoved( const OIS::MouseEvent &arg );


    void checkCollisions();
    Ogre::SceneNode* mGoalNode;
    Ogre::SceneNode* mPickupNode1;
    Ogre::SceneNode* mPickupNode2;
    Ogre::SceneNode* mPickupNode3;
    Ogre::SceneNode* mPickupNode4;
    int mPickups;
////////////////////////////////////////////////////////////////////

  //NEW
    Player *player;
    Enemy *enemy;
    Camera *camera;



    ////////////////////////////////////////////


    Ogre::ParticleSystem* mWinParticles;

    void createFrameListener();
    bool frameRenderingQueued(const Ogre::FrameEvent &evt);


};

#endif // #ifndef __EksamensApp_h_

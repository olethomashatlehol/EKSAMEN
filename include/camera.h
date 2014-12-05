#ifndef CAMERA_H
#define CAMERA_H

#include "Ogre.h"
class Camera
{
public:
    Camera(Ogre::String name, Ogre::SceneManager *sceneMgr, Ogre::Camera *camera = 0);
    ~Camera();
    //void setTarget(Ogre::Vector3 target);

    void setTightness (Ogre::Real tightness);
    Ogre::Real getTightness ();
    Ogre::Vector3 getCameraPosition ();
    void SetCameraPosition(Ogre::Vector3 pos);
    void instantUpdate (Ogre::Vector3 cameraPosition, Ogre::Vector3 targetPosition);


    void update (const Ogre::FrameEvent &evt, Ogre::Vector3 targetpos);

    Ogre::SceneNode *mTargetNode; /// The camera target
    Ogre::SceneNode *mCameraNode; /// The camera itself
    Ogre::Camera *mCamera; /// Ogre camea
    Ogre::SceneManager *mSceneMgr;
    Ogre::String mName;

    bool mOwnCamera;

    Ogre::Real mTightness;
};

#endif // CAMERA_H

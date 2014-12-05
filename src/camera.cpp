#include "camera.h"

Camera::Camera(Ogre::String name, Ogre::SceneManager *sceneMgr, Ogre::Camera *camera)
{
    mName = name;
    mSceneMgr = sceneMgr;


    mCameraNode = mSceneMgr->getRootSceneNode ()->createChildSceneNode (mName);
    mTargetNode = mSceneMgr->getRootSceneNode ()->createChildSceneNode (mName + "_target");
    mCameraNode->setAutoTracking (true, mTargetNode); // alltid se på target
    mCameraNode->setFixedYawAxis (true);


    if (camera == 0) {
        mCamera = mSceneMgr->createCamera (mName);
        mOwnCamera = true;
    }
    else {
        mCamera = camera;

        mCamera->setPosition(0.0,0.0,0.0);
        mOwnCamera = false;
    }

    mCameraNode->attachObject (mCamera);
    mTightness = 0.009f;
    mCamera->setPosition(Ogre::Vector3(10,0,5));
    mCamera->setNearClipDistance(5);
    mCamera->setFarClipDistance(15000.0f);

}

Camera::~Camera()
{

}

void Camera::setTightness(Ogre::Real tightness)
{
    mTightness = tightness;
}

Ogre::Real Camera::getTightness()
{
    return mTightness;
}

Ogre::Vector3 Camera::getCameraPosition()
{
    return mCameraNode->getPosition ();
}

void Camera::SetCameraPosition(Ogre::Vector3 pos)
{
    mCamera->setPosition(pos);
}

void Camera::instantUpdate(Ogre::Vector3 cameraPosition, Ogre::Vector3 targetPosition)
{

}

void Camera::update(const Ogre::FrameEvent &evt,Ogre::Vector3 targetpos)
{

    std::cout<<"CAMERA"<<std::endl;
    Ogre::Vector3 campos;
    campos = targetpos + Ogre::Vector3(-35,10,-10);

    mCameraNode->setPosition(campos);
    mCamera->lookAt(targetpos);
}

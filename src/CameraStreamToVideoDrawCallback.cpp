#include <iostream>

#include <osg/RenderInfo>

#include "CameraStreamToVideoDrawCallback.h"

CameraStreamToVideoDrawCallback::CameraStreamToVideoDrawCallback(osg::Image* image) :
  _image(image)
{

}

void CameraStreamToVideoDrawCallback::operator()(osg::RenderInfo &renderInfo) const
{
  int width;
  int height;
  osg::GraphicsContext* gc = renderInfo.getState()->getGraphicsContext();
  
  read_size(gc, width, height);
  
  _image.get()->readPixels(0, 0, width, height, GL_BGRA, GL_UNSIGNED_BYTE);
  
}

void CameraStreamToVideoDrawCallback::read_size(osg::GraphicsContext* gc, int& width, int& height) const
{
  
  if(gc->getTraits())
  {
    width  = gc->getTraits()->width;
    height = gc->getTraits()->height;
  }

}

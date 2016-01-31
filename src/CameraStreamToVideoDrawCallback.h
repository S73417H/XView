#include <osg/Camera>

class CameraStreamToVideoDrawCallback : public osg::Camera::DrawCallback
{

  public:
    CameraStreamToVideoDrawCallback(osg::Image* image);
    void operator()(osg::RenderInfo &renderInfo) const;

  private:
    osg::ref_ptr<osg::Image> _image;

    void read_size(osg::GraphicsContext* gc, int& width, int& height) const;
};

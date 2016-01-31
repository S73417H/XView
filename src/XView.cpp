#include <stdio.h>

#include <osg/ArgumentParser>
#include <osgViewer/Viewer>
#include <osgViewer/ViewerEventHandlers>
#include <osgEarth/mapNode>
#include <osgEarth/map>
#include <osgEarthUtil/EarthManipulator>
#include <osgEarthUtil/Controls>
#include <osgEarthDrivers/sky_simple/SimpleSkyOptions>
#include <osgEarthDrivers/tms/TMSOptions>
#include <osgEarthDrivers/arcgis/ArcGISOptions>
#include <osgEarthSymbology/Color>

#include "CameraStreamToVideoDrawCallback.h"
using namespace std;

using namespace osg;
using namespace osgDB;
using namespace osgEarth;
using namespace osgViewer;
using namespace osgEarth::Symbology;
using namespace osgEarth::Drivers;
using namespace osgEarth::Drivers::SimpleSky;
using namespace osgEarth::Util;
using namespace osgEarth::Util::Controls;

int main(int argc, char **argv)
{
  osg::ArgumentParser arguments(&argc, argv);

  arguments.getApplicationUsage()->setCommandLineUsage(arguments.getApplicationName() + " [options]");
  arguments.getApplicationUsage()->addCommandLineOption("-h or --help", "Display this information");
  
  if(arguments.read("-h") || arguments.read("--help"))
  {
    cout << arguments.getApplicationUsage()->getCommandLineUsage() << endl;
    arguments.getApplicationUsage()->write(cout, arguments.getApplicationUsage()->getCommandLineOptions());
    return 1;
  }
  
  Viewer viewer(arguments);
  Node* node = osgDB::readNodeFiles(arguments);

  viewer.setSceneData(node);
  
  viewer.setCameraManipulator(new EarthManipulator);
  viewer.addEventHandler(new StatsHandler());
  viewer.addEventHandler(new WindowSizeHandler());
  viewer.addEventHandler(new LODScaleHandler());

  osg::ref_ptr<osg::Image> image = new osg::Image();
  viewer.getCamera()->setPostDrawCallback(new CameraStreamToVideoDrawCallback(image.get()));
  
  viewer.run();
  
  return 0;
}

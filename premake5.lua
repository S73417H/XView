workspace "XView"
    configurations { "Debug", "Release" }

project "XView"
    kind "ConsoleApp"
    language "C++"
    targetdir "bin/%{cfg.buildcfg}"

    files { "**.h", "**.cpp" }

    filter "configurations:Debug"
        defines { "DEBUG" }
        flags { "Symbols" }
        links {
           "osgEarthd",
           "osgEarthUtild",
           "osgd",
           "osgViewerd",
           "osgDBd",
           "OpenThreadsd"
        }
        
    filter "configurations:Release"
        defines { "NDEBUG" }
        flags { "Symbols" }
        optimize "On"
        links {
           "osgEarth",
           "osgEarthUtil",
           "osg",
           "osgViewer",
           "osgDB",
           "OpenThreads"
        }

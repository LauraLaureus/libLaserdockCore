#add_library(opencv SHARED IMPORTED)

if(WIN32)
    set(OpenCV_DIR "${CMAKE_CURRENT_LIST_DIR}/win")
endif()

if(APPLE)
    set(OpenCV_DIR "${CMAKE_CURRENT_LIST_DIR}/mac/share")
endif()

if(ANDROID)
    set(OpenCV_DIR "${CMAKE_CURRENT_LIST_DIR}/android/sdk/native/jni")
endif()

set(CMAKE_PREFIX_PATH ${OpenCV_DIR})
find_package(OpenCV REQUIRED opencv_core opencv_imgproc opencv_videoio opencv_highgui opencv_imgcodecs)



cmake_minimum_required(VERSION 3.5)

project(ELO-Admin LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check https://doc.qt.io/qt/deployment-android.html for more information.
# They need to be set before the find_package( ...) calls below.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets LinguistTools REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets LinguistTools REQUIRED)

set(TS_FILES ELO-Admin_de_DE.ts)

set(PROJECT_SOURCES
        main.cpp
        eloadmin.cpp
        eloadmin.h
        eloadmin.ui
        gitoliteConf.h
        ${TS_FILES}
        # use files from ELO
        ../ELO/user.h
        ../ELO/user.cpp
        ../ELO/gitcom.h
        ../ELO/gitcom.cpp
        ../ELO/processdialog.h
        ../ELO/processdialog.cpp
        ../ELO/qblowfish.h
        ../ELO/qblowfish_p.h
        ../ELO/qblowfish.cpp
        ../ELO/resources.qrc
        ../ELO/elo.rc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ELO-Admin
        ${PROJECT_SOURCES}
    )

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(ELO-Admin SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(ELO-Admin
            ${PROJECT_SOURCES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_link_libraries(ELO-Admin PRIVATE Qt${QT_VERSION_MAJOR}::Widgets git2 ssh)

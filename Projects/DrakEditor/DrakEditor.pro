###############################################################################
#
#                               Drakkar Editor
#
###############################################################################

QT              += core gui widgets opengl
DEFINES         += QT_DEPRECATED_WARNINGS LOG2

TARGET          = DrakEditor
TEMPLATE        = app

CONFIG          -= debug_and_release debug_and_release_target
QMAKE_CXXFLAGS  *= /std:c++17
QMAKE_CXXFLAGS  -= -Zc:strictStrings

###############################################################################

DKBIN       = "../../Binaries"

CONFIG(debug, debug|release) {
    DESTDIR = $$DKBIN/Debug/x64
}
CONFIG(release, debug|release) {
    DESTDIR = $$DKBIN/Release/x64
}

###############################################################################

LIBS        +=                                      \
            $$DESTDIR/DrakEngine.lib                \

###############################################################################

DKSRC       = "../../Source"

INCLUDEPATH += $$DKSRC
DEPENDPATH  += $$DKSRC

SOURCES     +=                                      \
            $$DKSRC/Editor/DarkStyle.cpp            \
            $$DKSRC/Editor/framelesswindow.cpp      \
            $$DKSRC/Editor/windowdragger.cpp        \
            $$DKSRC/Editor/main.cpp                 \
            $$DKSRC/Editor/Editor.cpp               \
            $$DKSRC/Editor/GLEditorWidget.cpp       \
            $$DKSRC/Editor/TransformWidget.cpp      \
            $$DKSRC/Editor/SceneGraphWidget.cpp     \
            $$DKSRC/Editor/InspectorWidget.cpp      \
            $$DKSRC/Editor/BoxColliderWidget.cpp    \
            $$DKSRC/Editor/RigidBodyWidget.cpp      \

HEADERS     +=                                      \
            $$DKSRC/Editor/DarkStyle.h              \
            $$DKSRC/Editor/framelesswindow.h        \
            $$DKSRC/Editor/windowdragger.h          \
            $$DKSRC/Editor/Editor.hpp               \
            $$DKSRC/Editor/GLEditorWidget.hpp       \
            $$DKSRC/Editor/TransformWidget.hpp      \
            $$DKSRC/Editor/SceneGraphWidget.hpp     \
            $$DKSRC/Editor/InspectorWidget.hpp      \
            $$DKSRC/Editor/BoxColliderWidget.hpp    \
            $$DKSRC/Editor/RigidBodyWidget.hpp      \
            $$DKSRC/Engine/Engine.hpp               \
            $$DKSRC/Engine/Scene/LevelSystem.hpp    \
            $$DKSRC/Engine/GameObject.hpp           \
            $$DKSRC/Engine/Components/TransformComponent.hpp    \

###############################################################################

RSRCDIR     = "Resources"

RESOURCES   +=                                      \
            $$RSRCDIR/darkstyle.qrc                 \
            $$RSRCDIR/framelesswindow.qrc           \

RC_ICONS    +=                                      \
            $$RSRCDIR/Drakkar.ico                   \

###############################################################################

FORMDIR     = "Forms"

FORMS       +=                                      \
            $$FORMDIR/framelesswindow.ui            \
            $$FORMDIR/Editor.ui                     \
            $$FORMDIR/TransformWidget.ui            \
            $$FORMDIR/BoxColliderWidget.ui          \
            $$FORMDIR/RigidBodyWidget.ui            \

###############################################################################

TEMPDIR     = "Intermediate"

OBJECTS_DIR = $$TEMPDIR/obj
MOC_DIR     = $$TEMPDIR/moc
RCC_DIR     = $$TEMPDIR/qrc
UI_DIR      = $$DKSRC/Editor

###############################################################################

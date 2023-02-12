QT       += core gui network multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Models/MultiPageController.cpp \
    Models/NotificationTool.cpp \
    Models/UIHelper.cpp \
    NetWork/Actions/GetMusicInfoAction.cpp \
    NetWork/Actions/PlayMusicAction.cpp \
    NetWork/networkmanager.cpp \
    UIConmponents/UIControlers/MuiscListCard.cpp \
    UIControllers/Album.cpp \
    UIControllers/HomePage.cpp \
    UIControllers/MyPage.cpp \
    UIControllers/PlayListPage.cpp \
    UIControllers/SearchDisplay.cpp \
    main.cpp \
    UIControllers/MainWindow.cpp \
    Models/MusicPlayer.cpp

HEADERS += \
    Models/MultiPageController.h \
    Models/NotificationTool.h \
    Models/Page.h \
    Models/UIContextMenu.h \
    Models/UIHelper.h \
    NetWork/Actions/GetMusicInfoAction.h \
    NetWork/Actions/PlayMusicAction.h \
    NetWork/Actions/SearchMusicAction.h \
    NetWork/NetWorkAction.h \
    NetWork/networkmanager.h \
    UIConmponents/UIControlers/MuiscListCard.h \
    UIControllers/Album.h \
    UIControllers/ContextMenus/PlayerContextMenu.h \
    UIControllers/ContextMenus/TaskBarContextMenu.h \
    UIControllers/HomePage.h \
    UIControllers/MainWindow.h\
    Models/MusicPlayer.h \
    UIControllers/MyPage.h \
    UIControllers/PlayListPage.h \
    UIControllers/SearchDisplay.h

FORMS += \
    UIConmponents/Views/MuiscListCard.ui \
    Views/Album.ui \
    Views/MyPage.ui \
    Views/PlayListPage.ui \
    Views/SearchDisplay.ui \
    Views/HomePage.ui \
    Views/MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RC_ICONS = Images/FMusic.ico

RESOURCES += \
    Assets.qrc

DISTFILES += \
    Texts/ContextMenu.qss \
    Texts/FUI3.qss \
    Texts/IconButton.qss \
    Texts/TabStyle.qss

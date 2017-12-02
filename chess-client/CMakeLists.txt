CMAKE_MINIMUM_REQUIRED (VERSION 3.5)
PROJECT (chess-client)

SET (SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
SET (COMMON_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../common/src)
SET (COMMON_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../common/include)

SET (SOURCES
        ${SRC_DIR}/main.cpp
        # Common
        ${COMMON_SRC_DIR}/MemoryStream.cpp
    )

SET (CMAKE_AUTOMOC ON)
SET (CMAKE_AUTORCC ON)

FIND_PACKAGE (Qt5 COMPONENTS Quick Qml Widgets)
qt5_add_resources (RESOURCES ${CMAKE_CURRENT_SOURCE_DIR}/resources.qrc)

ADD_EXECUTABLE (chess-client ${SOURCES} ${RESOURCES})
TARGET_INCLUDE_DIRECTORIES (chess-client PRIVATE ${COMMON_INCLUDE_DIR})
TARGET_LINK_LIBRARIES (chess-client Qt5::Quick Qt5::Qml Qt5::Widgets chess-server)

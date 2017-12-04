CMAKE_MINIMUM_REQUIRED (VERSION 3.5)
PROJECT (chess-client)

SET (SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
SET (COMMON_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../common/src)
SET (COMMON_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../common/include)

SET (SOURCES
        ${SRC_DIR}/main.cpp
        ${SRC_DIR}/ChessClient.cpp
        ${SRC_DIR}/GameController.cpp
        ${SRC_DIR}/ClientBoard.cpp
        # Common
        ${COMMON_SRC_DIR}/MemoryStream.cpp
        ${COMMON_SRC_DIR}/GameObject.cpp
        ${COMMON_SRC_DIR}/Figure.cpp
        ${COMMON_SRC_DIR}/Board.cpp
        ${COMMON_SRC_DIR}/figures/Bishop.cpp
        ${COMMON_SRC_DIR}/figures/King.cpp
        ${COMMON_SRC_DIR}/figures/Knight.cpp
        ${COMMON_SRC_DIR}/figures/Pawn.cpp
        ${COMMON_SRC_DIR}/figures/Queen.cpp
        ${COMMON_SRC_DIR}/figures/Rook.cpp
    )

SET (CMAKE_AUTOMOC ON)
SET (CMAKE_AUTORCC ON)

FIND_PACKAGE (Qt5 COMPONENTS Quick Qml Widgets)
qt5_add_resources (RESOURCES ${CMAKE_CURRENT_SOURCE_DIR}/resources.qrc)

ADD_EXECUTABLE (chess-client ${SOURCES} ${RESOURCES})
TARGET_INCLUDE_DIRECTORIES (chess-client PRIVATE ${COMMON_INCLUDE_DIR})
TARGET_LINK_LIBRARIES (chess-client Qt5::Quick Qt5::Qml Qt5::Widgets chess-server)

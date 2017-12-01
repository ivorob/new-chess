CMAKE_MINIMUM_REQUIRED (VERSION 3.5)
PROJECT (chess-server)

SET (SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
SET (COMMON_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../common/src)

SET (SOURCES
        # common code
        ${COMMON_SRC_DIR}/Figure.cpp
        ${COMMON_SRC_DIR}/MemoryStream.cpp
        ${COMMON_SRC_DIR}/GameObject.cpp
        ${COMMON_SRC_DIR}/figures/Bishop.cpp
        ${COMMON_SRC_DIR}/figures/King.cpp
        ${COMMON_SRC_DIR}/figures/Knight.cpp
        ${COMMON_SRC_DIR}/figures/Pawn.cpp
        ${COMMON_SRC_DIR}/figures/Queen.cpp
        ${COMMON_SRC_DIR}/figures/Rook.cpp
        # main code
        ${SRC_DIR}/ConcreteNetworkManager.cpp
        # interface
        ${SRC_DIR}/ChessServer.cpp
    )

ADD_LIBRARY (chess-server SHARED ${SOURCES})
TARGET_INCLUDE_DIRECTORIES (chess-server PRIVATE 
        ${CMAKE_CURRENT_SOURCE_DIR}/../common/include
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    )
TARGET_INCLUDE_DIRECTORIES (chess-server PUBLIC  ${CMAKE_CURRENT_SOURCE_DIR}/interface)

ENABLE_TESTING ()

ADD_SUBDIRECTORY (${CMAKE_CURRENT_SOURCE_DIR}/tests ${CMAKE_CURRENT_BINARY_DIR}/tests)
ADD_TEST (NAME chess-server COMMAND tests/chess-server-tests)


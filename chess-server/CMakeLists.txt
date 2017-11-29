CMAKE_MINIMUM_REQUIRED (VERSION 3.5)
PROJECT (chess-server)

SET (SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
SET (SOURCES
        ${SRC_DIR}/figures/Bishop.cpp
        ${SRC_DIR}/figures/King.cpp
        ${SRC_DIR}/figures/Knight.cpp
        ${SRC_DIR}/figures/Pawn.cpp
        ${SRC_DIR}/figures/Queen.cpp
        ${SRC_DIR}/figures/Rook.cpp
    )

ADD_LIBRARY (chess-server ${SOURCES})
TARGET_INCLUDE_DIRECTORIES (chess-server PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

ENABLE_TESTING ()

ADD_SUBDIRECTORY (${CMAKE_CURRENT_SOURCE_DIR}/tests ${CMAKE_CURRENT_BINARY_DIR}/tests)
ADD_TEST (NAME chess-server COMMAND tests/chess-server-tests)


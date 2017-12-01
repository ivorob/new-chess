CMAKE_MINIMUM_REQUIRED (VERSION 3.0)
PROJECT (chess-server-tests)

STRING (REGEX REPLACE "/MDd" "/MTd" CMAKE_CXX_FLAGS_DEBUG ${CMAKE_CXX_FLAGS_DEBUG})

SET (SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/)
SET (COMMON_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../common/src)
SET (COMMON_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../common/include)

SET (SOURCES
        ${SRC_DIR}/tests.cpp
        ${SRC_DIR}/MemoryStreamTest.cpp
        ${SRC_DIR}/GameObjectTest.cpp
        ${SRC_DIR}/FigureTest.cpp
        ${SRC_DIR}/FiguresTest.cpp
        ${SRC_DIR}/BoardTest.cpp
        # COMMON SOURCES
        ${COMMON_SRC_DIR}/MemoryStream.cpp
        ${COMMON_SRC_DIR}/GameObject.cpp
        ${COMMON_SRC_DIR}/Figure.cpp
        ${COMMON_SRC_DIR}/Board.cpp
        # figures
        ${COMMON_SRC_DIR}/figures/Bishop.cpp
        ${COMMON_SRC_DIR}/figures/King.cpp
        ${COMMON_SRC_DIR}/figures/Knight.cpp
        ${COMMON_SRC_DIR}/figures/Pawn.cpp
        ${COMMON_SRC_DIR}/figures/Queen.cpp
        ${COMMON_SRC_DIR}/figures/Rook.cpp
    )

ADD_SUBDIRECTORY (
    ${CMAKE_CURRENT_SOURCE_DIR}/../thirdparty/googletest
    ${CMAKE_CURRENT_BINARY_DIR}/thirdparty/googletest)

ADD_EXECUTABLE (chess-server-tests ${SOURCES})
TARGET_INCLUDE_DIRECTORIES (chess-server-tests PRIVATE ${COMMON_INCLUDE_DIR})
TARGET_LINK_LIBRARIES (chess-server-tests gtest)

PROJECT(sample)

SET(LIB_NAME bindclass)

#########################################################################################
## FILES
#########################################################################################

SET(MASTER_SRC_LIST
    main.cpp
)
SOURCE_GROUP("" FILES ${MASTER_SRC_LIST})

ADD_EXECUTABLE(${LIB_NAME} 
#   \\
    ${MASTER_SRC_LIST}
)

#########################################################################################
## INCLUDE & LINK
#########################################################################################

TARGET_LINK_LIBRARIES(${LIB_NAME} libscript)
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/src)
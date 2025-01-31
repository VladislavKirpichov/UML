project(API)

# set executable files
set(MANAGERS IManager.hpp question/QuestionManager.hpp registration/RegistrationManager.hpp auth/AuthManager.hpp user/UserManager.hpp page/PageManager.hpp)
set(CREATORS question/QuestionManagerCreator.hpp registration/RegistrationManagerCreator.hpp auth/AuthManagerCreator.hpp user/UserManagerCreator.hpp page/PageManagerCreator.hpp)

add_library(${PROJECT_NAME} INTERFACE)
target_sources(${PROJECT_NAME} INTERFACE ${MANAGERS} ${CREATORS})
target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR} registration auth user page question)

target_link_libraries(${PROJECT_NAME} INTERFACE Json http_parser entities Logger DB storage)

# Packages
target_link_libraries(${PROJECT_NAME} INTERFACE ${Boost_LIBRARIES} nlohmann_json::nlohmann_json)
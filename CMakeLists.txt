cmake_minimum_required(VERSION 3.20)

project(cmake-jni-example)

enable_testing()

find_package(Java COMPONENTS Development REQUIRED)
find_package(JNI REQUIRED)
include(UseJava)

add_jar(foo 
   SOURCES foo.java 
   GENERATE_NATIVE_HEADERS foo-native
)
add_library(boo SHARED 
   boo.cpp
)
target_include_directories(boo 
   PRIVATE ${JNI_INCLUDE_DIRS}
)
target_link_libraries(boo 
   PRIVATE ${JNI_LIBRARIES} foo-native
)

get_target_property(_FOO_JAR_FILE foo JAR_FILE)

add_test(NAME test_foo COMMAND ${Java_JAVA_EXECUTABLE} -Djava.library.path=$<TARGET_FILE_DIR:boo> -cp ${_FOO_JAR_FILE} foo WORKING_DIRECTORY)
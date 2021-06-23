# cmake-jni-example

Before run ensure that the JAVA_HOME environment variable is set and points to a valid JDK location

```
cmake -S . -B build
cmake --build build --config Release
ctest --test-dir build -C Release
```
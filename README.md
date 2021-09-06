# Mia-Platform Oat Cpp Hello World Example

Based on oat++

## Overview

### Project layout

```bash
|- CMakeLists.txt                        // projects CMakeLists.txt
|- src/
|    |
|    |- controller/                      // Folder containing HelloWorldController where all endpoints are declared
|    |- dto/                             // DTOs are declared here
|    |- AppComponent.hpp                 // Service config
|    |- App.cpp                          // main() is here
|
|- test/                                 // test folder
|- util/install-modules.sh      // utility script to install required oatpp-modules.  
```

### Build and Run

- `oatpp` module installed. You may run `util/install-modules.sh`
script to install required oatpp modules.

```bash
  mkdir build && cd build
  cmake ..
  make
  ./mia-platform-cpp-helloworld-exe  

```

Now, if you launch the following command on your terminal (remember to replace <YOUR_PROJECT_HOST> with the real host of your project):

`curl <YOUR_PROJECT_HOST>/hello`

you should see the following message:

`{"message":"Hello World"}`

#### In Docker

```bash
  docker build -t oatpp-starter .
  docker run -p 8000:8000 -t oatpp-starter
```

### Remarks

 Disable object counting for release builds using '-D OATPP_DISABLE_ENV_OBJECT_COUNTERS' flag for better performance.

## Others implementations

In May 2020 will be available also 

- https://github.com/ipkn/crow (attenzione che deriva da nginx)
- https://github.com/uNetworking/uWebSockets
- https://github.com/yhirose/cpp-httplib
- https://github.com/netty/netty/blob/4.1/example/src/main/java/io/netty/example/http/helloworld/HttpHelloWorldServer.java

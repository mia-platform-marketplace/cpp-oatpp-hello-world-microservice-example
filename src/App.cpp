/*
 * Copyright 2020 Mia srl
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * 
 * This project is a derivative work from oatpp-web-starter
 */

#include "./controller/HelloController.hpp"
#include "./controller/StatusController.hpp"
#include "./AppComponent.hpp"

#include "oatpp/network/server/Server.hpp"


#include <iostream>

void run() {

  AppComponent components;

  OATPP_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, router);


  auto statusController = std::make_shared<StatusController>();
  statusController->addEndpointsToRouter(router);

  auto swaggerController = oatpp::swagger::Controller::createShared(<list-of-endpoints-to-document>);
  swaggerController->addEndpointsToRouter(router);

  auto helloController = std::make_shared<HelloController>();
  helloController->addEndpointsToRouter(router);

  OATPP_COMPONENT(std::shared_ptr<oatpp::network::server::ConnectionHandler>, connectionHandler);
  OATPP_COMPONENT(std::shared_ptr<oatpp::network::ServerConnectionProvider>, connectionProvider);

  oatpp::network::server::Server server(connectionProvider, connectionHandler);
  OATPP_LOGI("Mia-Platform Hello World Example Server", "Server running on port %s", connectionProvider->getProperty("port").getData());
 
  server.run();
  
}

/**
 *  main
 */
int main(int argc, const char * argv[]) {

  oatpp::base::Environment::init();

  run();
  
  // Print how much objects were created during app running, and what have left-probably leaked
  // Disable object counting for release builds using '-D OATPP_DISABLE_ENV_OBJECT_COUNTERS' flag for better performance
  std::cout << "\nEnvironment:\n";
  std::cout << "objectsCount = " << oatpp::base::Environment::getObjectsCount() << "\n";
  std::cout << "objectsCreated = " << oatpp::base::Environment::getObjectsCreated() << "\n\n";
  
  oatpp::base::Environment::destroy();
  
  return 0;
}

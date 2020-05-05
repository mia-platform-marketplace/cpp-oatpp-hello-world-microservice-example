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

#ifndef StatusController_hpp
#define StatusController_hpp

#include "dto/StatusDto.hpp"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"


class StatusController : public oatpp::web::server::api::ApiController {
public:
  /**
   * Constructor with object mapper.
   * @param objectMapper - default object mapper used to serialize/deserialize DTOs.
   */
  StatusController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
    : oatpp::web::server::api::ApiController(objectMapper)
  {}
  
public:
  
/**
 *  Begin ENDPOINTs generation ('ApiController' codegen)
 */
#include OATPP_CODEGEN_BEGIN(ApiController)
  
  ENDPOINT("GET", "/-/ready", ready) {
    auto dto = StatusDto::createShared();
    dto->statusOK = true;
    return createDtoResponse(Status::CODE_200, dto);
  }
  
  ENDPOINT("GET", "/-/healthz", healthz) {
    auto dto = StatusDto::createShared();
    dto->statusOK = true;
    return createDtoResponse(Status::CODE_200, dto);
  }

  ENDPOINT("GET", "/-/check-up", checkup) {
    auto dto = StatusDto::createShared();
    dto->statusOK = true;
    return createDtoResponse(Status::CODE_200, dto);
  }
  
/**
 *  Finish ENDPOINTs generation ('ApiController' codegen)
 */
#include OATPP_CODEGEN_END(ApiController)
  
};

#endif /* StatusController_hpp */

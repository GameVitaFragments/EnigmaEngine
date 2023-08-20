#pragma once
#include <cstdint>
#include <glm/glm.hpp>

typedef struct Position
{
   glm::vec3 pos;
   int32_t parentEntity;//Parent Entity of component
   int32_t bitMask;//Stores the bitmask of the component
   
   void init()
   {
      parentEntity = '\0';
      bitMask = 1<<1;
      pos = glm::vec3(0.0f,0.0f,0.0f);
   }
}Position;

typedef struct Rotation
{
   glm::vec3 rot;
   int32_t parentEntity;//Parent Entity of component
   int32_t bitMask;//Stores the bitmask of the component
   
   void init()
   {
      parentEntity = '\0';
      bitMask = 1<<2;
      rot = glm::vec3(0.0f,0.0f,0.0f);
   }
}Rotation;

typedef struct Scale
{
   glm::vec3 scale;
   int32_t parentEntity;//Parent Entity of component
   int32_t bitMask;//Stores the bitmask of the component
   
   void init()
   {
      parentEntity = '\0';
      bitMask = 1<<3;
      scale = glm::vec3(0.0f,0.0f,0.0f);
   }
}Scale;

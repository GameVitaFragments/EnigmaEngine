#include "../../Image/Image.hpp"
#include <memory>
#include <glm/glm.hpp>

struct Sprite 
{
   std::unique_ptr<EE::IMAGE> image;
   bool flipX;
   bool flipY;
   glm::vec4 color;
   int32_t parentEntity;//Parent Entity of component
   int64_t bitMask;//Stores the bitmask of "the component"
   
   void init()
   {
      bitMask = 1<<0;
      parentEntity = '\0';
      image = nullptr;
      color = glm::vec4(0.0f,0.0f,0.0f,0.0f);
      flipX = false;
      flipY = false;
   }
};

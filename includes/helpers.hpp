#ifndef __CHEERPS_HELPERS_HPP__
#define __CHEERPS_HELPERS_HPP__

#include <cheerp/client.h>
#include <cheerp/clientlib.h>

namespace [[cheerp::genericjs]] VanillaJS
{
  using namespace client;

  template<typename HTMLElement = client::HTMLElement>
  inline HTMLElement* FindElementById(const client::String &id) noexcept
  {
    return static_cast<HTMLElement*>(
      client::document.getElementById(id)
    );
  }

  template<typename HTMLElement = client::HTMLElement>
  inline HTMLElement* CreateElement(const client::String &tag_name) noexcept
  {
    return static_cast<HTMLElement*>(
      client::document.createElement(tag_name)
    );
  }
}

#endif // !__CHEERPS_HELPERS_HPP__

#ifndef __CHEERPS_VANILLAJS_CLIENT_HPP__
#define __CHEERPS_VANILLAJS_CLIENT_HPP__

#include <cheerp/client.h>
#include <cheerp/clientlib.h>
#include "dom_ext.hpp"

namespace [[cheerp::genericjs]] VanillaJS
{
  template<typename HTMLElement = client::HTMLElement>
  inline HTMLElement* FindElementById(const client::String &element_id) noexcept
  {
    return static_cast<HTMLElement*>( client::document.getElementById(element_id) );
  }

  template<typename HTMLElement = client::HTMLElement>
  inline HTMLElement* CreateElement(const client::String &tag_name) noexcept
  {
    return static_cast<HTMLElement*>( client::document.createElement(tag_name) );
  }

  inline client::Text* CreateTextNode(const client::String &text_data) noexcept
  {
    return client::document.createTextNode(text_data);
  }

  inline client::HTMLBodyElement* GetBody() noexcept
  {
    return static_cast<client::HTMLBodyElement*>( client::document.get_body() );
  }
}

#endif // !__CHEERPS_VANILLAJS_CLIENT_HPP__

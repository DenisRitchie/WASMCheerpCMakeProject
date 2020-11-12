#ifndef __CHEERPS_VANILLAJS_DOM_PIPES_HPP__
#define __CHEERPS_VANILLAJS_DOM_PIPES_HPP__

#include <sstream>
#include <string>
#include "dom.hpp"

namespace [[cheerp::genericjs]] VanillaJS
{
  struct { } to_html_wrapper;

  template<typename ElementType>
  inline auto operator|(ElementType element, decltype(to_html_wrapper)) noexcept
  -> HTMLElement<
      std::remove_pointer_t<
        std::remove_reference_t<
          std::remove_cv_t<ElementType>>>>
  {
    return element;
  }

  struct 
  {
    inline client::String* operator()(const std::wostringstream &data) const noexcept
    {
      return new client::String(data.str().c_str());
    }

    inline client::String* operator()(const std::wstring &text) const noexcept
    {
      return new client::String(text.c_str());
    }

    inline client::String* operator()(const wchar_t *const text) const noexcept
    {
      return new client::String(text);
    }
  } DOMString;

  inline client::String* operator""_DOMString(const wchar_t *__restrict text, size_t) noexcept
  {
    return new client::String(text);
  }

  inline client::String* operator+(const client::String &left, const client::String &right) noexcept
  {
    client::String *text;
    __asm__("%1 + %2" : "=r"(text) : "r"(&left), "r"(&right));
    return text;
  }

  client::String* operator+=(client::String &object, const client::String &data) noexcept
  {
    __asm__("%0 += %1" : : "r"(&object), "r"(&data));
    return &object;
  }
}

#endif // !__CHEERPS_VANILLAJS_DOM_PIPES_HPP__
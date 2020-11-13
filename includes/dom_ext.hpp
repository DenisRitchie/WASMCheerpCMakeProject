#ifndef __CHEERPS_VANILLAJS_DOM_PIPES_HPP__
#define __CHEERPS_VANILLAJS_DOM_PIPES_HPP__

#include <iostream>
#include <sstream>
#include <string>
#include <memory>
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
    inline client::String* operator()(std::wostream &out) const noexcept
    {
      using iterator_t = std::istreambuf_iterator<std::wostream::char_type, std::wostream::traits_type>;

      iterator_t in(out.rdbuf()), eof;
      client::String* data = new client::String();

      for(; in != eof ; ++in)
        data = data->concat(*client::String::fromCharCode(*in));

      return data;
    }

    inline client::String* operator()(const std::wstringstream &data) const noexcept
    {
      return new client::String(data.str().c_str());
    }

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

  inline client::String* operator+(const client::String &left, client::Any right) noexcept
  {
    client::String *text;
    __asm__("%1 + %2" : "=r"(text) : "r"(&left), "r"(right));
    return text;
  }

  inline client::String* operator+(client::Any left, const client::String &right) noexcept
  {
    client::String *text;
    __asm__("%1 + %2" : "=r"(text) : "r"(left), "r"(&right));
    return text;
  }

  client::String* operator+=(client::String &object, client::Any data) noexcept
  {
    return ({ __asm__("%0 += %1" : : "r"(&object), "r"(data)); &object; });
  }
}

#endif // !__CHEERPS_VANILLAJS_DOM_PIPES_HPP__
#ifndef __CHEERPS_VANILLAJS_DOM_HPP__
#define __CHEERPS_VANILLAJS_DOM_HPP__

#include <cheerp/client.h>
#include <cheerp/clientlib.h>

namespace [[cheerp::genericjs]] VanillaJS
{
  template<typename Element = client::HTMLElement>
  class HTMLElement
  {
  public:
    inline HTMLElement() noexcept : m_Element{ nullptr }
    {
    }

    inline HTMLElement(Element *element) noexcept : m_Element{ element }
    {
    }

    inline operator Element*() const noexcept
    {
      return this->m_Element;
    }

    inline Element* operator->() const noexcept
    {
      return this->m_Element;
    }

    inline Element* operator&() const noexcept
    {
      return this->m_Element;
    }

    inline bool operator!() const noexcept
    {
      return this->m_Element == nullptr;
    }

    inline Element& operator*() noexcept
    {
      return *this->m_Element;
    }

    inline operator bool() const noexcept
    {
      return this->m_Element != nullptr;
    }

    inline client::CSSStyleDeclaration* Style() const noexcept
    {
      return this->m_Element->get_style();
    }

    inline client::CSSStyleDeclaration* GetComputedStyle() const noexcept
    {
      return client::getComputedStyle(this->m_Element);
    }

    inline client::CSSStyleDeclaration* GetComputedStyle(const client::String &pseudo_element) const noexcept
    {
      return client::getComputedStyle(this->m_Element, pseudo_element);
    }

    template<typename HTMLChildElement>
    inline HTMLChildElement* AppendChild(const client::String &tag_name) noexcept
    {
      auto *child_element = client::document.createElement(tag_name);
      return static_cast<HTMLChildElement*>( m_Element->appendChild(child_element) );
    }

    inline client::Text* AppendTextNode(const client::String &text_data) noexcept
    {
      auto *text_node = client::document.createTextNode(text_data);
      return static_cast<client::Text*>( m_Element->appendChild(text_node) );
    }

  protected:
    Element *m_Element; 
  };

  using HTMLBody    = HTMLElement<client::HTMLBodyElement>;
  using HTMLDiv     = HTMLElement<client::HTMLDivElement>;
  using HTMLHeading = HTMLElement<client::HTMLHeadingElement>;
  using HTMLUList   = HTMLElement<client::HTMLUListElement>;
  using HTMLOList   = HTMLElement<client::HTMLOListElement>;
  using HTMLLI      = HTMLElement<client::HTMLLIElement>;
}

#endif // !__CHEERPS_VANILLAJS_DOM_HPP__
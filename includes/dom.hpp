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

namespace [[cheerp::genericjs]] client
{
  class AbstractRange : public Object
  {
  public:
    bool get_collapsed();
    Node* get_startContainer();
    Node* get_endContainer();
    Long get_startOffset();
    Long get_endOffset();
  };

  ///
  /// https://dom.spec.whatwg.org/#interface-staticrange
  ///
  class StaticRangeInit : public Object
  {
  public:
    Node* get_startContainer();
    Node* get_endContainer();
    Long get_startOffset();
    Long get_endOffset();

    void set_startContainer(Node*);
    void set_endContainer(Node*);
    void set_startOffset(Long);
    void set_endOffset(Long);
  };

  ///
  /// https://developer.mozilla.org/en-US/docs/Web/API/StaticRange/StaticRange
  /// https://dom.spec.whatwg.org/#interface-staticrange
  ///
  class StaticRange : public AbstractRange
  {
  public:
    StaticRange(StaticRangeInit*);
    Range* toRange();

    bool get_collapsed();
    Node* get_startContainer();
    Node* get_endContainer();
    Long get_startOffset(); 
    Long get_endOffset();
    StaticRange* get_prototype();

    void set_prototype(StaticRange*);
  };

  ///
  /// https://developer.mozilla.org/en-US/docs/Web/API/InputEvent/InputEvent
  ///
  class InputEventInit : public UIEventInit
  {
  public:
    String* get_inputType();
    void set_inputType(const String&);

    String* get_data();
    void set_data(const String&);

    DataTransfer* get_dataTransfer();
    void set_dataTransfer(DataTransfer*);

    bool get_isComposing();
    void set_isComposing(bool);

    StaticRange* get_ranges();
    void set_ranges(StaticRange*);
  };

  ///
  /// https://developer.mozilla.org/en-US/docs/Web/API/InputEvent
  /// https://rawgit.com/w3c/input-events/v1/index.html#interface-InputEvent-Attributes
  /// https://developer.mozilla.org/en-US/docs/Web/API/InputEvent/InputEvent
  /// 
  class InputEvent : public UIEvent
  {
  public:
    InputEvent(const String& type_arg);
    InputEvent(const String& type_arg, InputEventInit* event_init);
    StaticRange* getTargetRanges();

    String* get_data();
    DataTransfer* get_dataTransfer();
    String* get_inputType();
    bool get_isComposing();
    InputEvent* get_prototype();

    void set_prototype(InputEvent*);
  };
} // namespace client

#endif // !__CHEERPS_VANILLAJS_DOM_HPP__
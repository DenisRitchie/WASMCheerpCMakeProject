#pragma once

#include <cheerp/client.h>
#include <cheerp/clientlib.h>
#include <emscripten.h>
#include <functional>

#define Class(constructor) ({ client::Function *ctor; __asm__( #constructor : "=r"(ctor) : ); ctor; })

namespace [[cheerp::genericjs]] VanillaJS
{
  using namespace client;

  namespace [[cheerp::genericjs]] Detail
  {
    Boolean Instanceof(Object *object, Function *constructor) noexcept
    {
      Boolean result;
      __asm__("%1 != null && typeof Symbol !== 'undefined' && %1 [Symbol.hasInstance]" : "=r"(result) : "r"(constructor));
      
      if (result)
        __asm__("!! %2 [Symbol.hasInstance](%1)" : "=r"(result) : "r"(object), "r"(constructor));
      else
        __asm__("%1 instanceof %2" : "=r"(result) : "r"(object), "r"(constructor));

      return result;
    }

    String* Typeof(Object *object) noexcept
    {
      static const auto _typeof = [](Object *object) noexcept -> std::function<String*(Object*)>
      {
        Boolean support_typeof;
        __asm__("typeof Symbol === 'function' && typeof Symbol.iterator === 'symbol'" : "=r"(support_typeof));

        auto _typeof = [](Object *object)
        {
          String *type_name;
          __asm__("typeof %1" : "=r"(type_name) : "r"(object));
          return type_name;
        };

        if (support_typeof)
        {
          return _typeof;
        }
        else
        {
          return [_typeof](Object *object)
          {
            Boolean is_symbol;
            __asm__("%1 && typeof Symbol === 'function' && %1.constructor === Symbol && %1 !== Symbol.prototype" : "=r"(is_symbol) : "r"(object));

            if (is_symbol)
              return new String(L"symbol");

            return _typeof(object);
          };
        }
      }(object);

      return _typeof(object);
    }
  
    void ClassCallCheck(Object *object, Function *constructor) noexcept
    {
      if (!Instanceof(object, constructor))
        __asm__("throw new TypeError('Cannot call a class as a function')");
    }
  
    Boolean IsNativeFunction(Function *constructor)
    {
      Boolean is_native;
      __asm__("Function.toString.call(%1).indexOf('[native code]') !== -1" : "=r"(is_native) : "r"(constructor));
      return is_native;
    }
  
    Object* SetPrototypeOf(Object *object, Object *prototype)
    {
      EventListener *set_prototype_of;
      __asm__("Object.setPrototypeOf || function (object, prototype) { object.__proto__ = prototype; return object; }" : "=r"(set_prototype_of));
      return reinterpret_cast<Object*(*)(Object*, Object*)>(set_prototype_of)(object, prototype);
    }

    Object* GetPrototypeOf(Object *object)
    {
      return nullptr;
    }
  }

  template<typename Derived, typename Base>
  class Client : public Base
  {
  public:
    Client(Function* _class) noexcept : m_class{ _class }
    {
    }

    virtual void Constructor() { }
    virtual void ConnectedCallback() { }
    virtual void DisconnectedCallback() { }
    virtual void AttributeChangedCallback() { }
    virtual void AdoptedCallback() { }

    inline operator Derived*() const noexcept
    {
      return self;
    }

    inline Derived* operator->() noexcept
    {
      return &static_cast<Derived&>(*this);
    }

    inline const Derived* operator->() const noexcept
    {
      return &static_cast<Derived&>(*this);
    }

  protected:
    Base *super, *base;
    Derived *self, *me;

  private:
    Function *m_class;
  };
} // namespace VainillaJs


// https://www.fluentcpp.com/2018/08/28/removing-duplicates-crtp-base-classes/
// https://www.fluentcpp.com/2018/06/22/variadic-crtp-opt-in-for-class-features-at-compile-time/
// https://www.fluentcpp.com/2017/05/16/what-the-crtp-brings-to-code/

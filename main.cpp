#include <cheerp/client.h>
#include <cheerp/clientlib.h>
#include "includes/helpers.hpp"
#include <string>
#include <sstream>
#include <cstdio>
#include <functional>

namespace VanillaJS::DOMEventConstants
{
  constexpr const wchar_t *DOMContentLoaded = L"DOMContentLoaded";
}

[[cheerp::genericjs]]
void OnDOMContentLoaded([[maybe_unused]] client::MutationEvent* EventInfo)
{
  using namespace VanillaJS;
  auto body = (HTMLBodyElement*)document.get_body();

  // Function *function;
  // __asm__("function(value){ alert(value); }" : "=r"(function));

  EventListener* function = cheerp::Callback([](String const& msg)
  {
    EventListener* inner = cheerp::Callback([]
    {
    });

    console.log(msg);
    return inner;
  });

  body->appendChild(document.createElement(L"h1"));
  body->get_lastChild()->set_textContent(L"Hello, World!");
  reinterpret_cast<void(*)(String const&)>(function)(L"Hello, World!");
}

int main()
{
  using namespace client;
  client::document.addEventListener(
    VanillaJS::DOMEventConstants::DOMContentLoaded,
    cheerp::Callback(OnDOMContentLoaded));

  // client::Object *obj;
  // __asm__("Object.create(%1.prototype)" : "=r"(obj) : "r"(CustomHtml));
  // obj->set_("Property", 30);
  // __asm__("console.log(%0)" : : "r"(obj));

  return 0;
}

// https://caniuse.com/


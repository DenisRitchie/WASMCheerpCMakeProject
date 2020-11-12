#include <cheerp/client.h>
#include <cheerp/clientlib.h>

#include "includes/client2.hpp"
#include "includes/events.hpp"
#include "includes/dom.hpp"
#include "includes/dom_ext.hpp"

#include <cstdio>
#include <cstdlib>
#include <string>
#include <sstream>
#include <functional>

[[cheerp::genericjs]]
void OnDOMContentLoaded([[maybe_unused]] client::MutationEvent* EventInfo)
{
  using namespace client;
  using namespace VanillaJS;

  HTMLBody body = GetBody();
  auto text_node = body.AppendTextNode(L"Texto de prueba");
  text_node->appendData(L", otros datos añadidos");

  auto h1 = body.AppendChild<client::HTMLHeadingElement>(L"h1") | to_html_wrapper;
  h1->set_textContent(L"Este es el contenido del h1");

  // https://developer.mozilla.org/en-US/docs/Web/HTML/Element/a
  auto ejemplo = body.AppendChild<client::HTMLAnchorElement>(L"a") | to_html_wrapper;
  ejemplo->set_href(L"examples/events/Event_PreventDefault");
  ejemplo->set_target(L"_blank");
  ejemplo->set_textContent(L"Dale Click para que veas el ejemplo #1");
}

int main()
{
  using namespace client;
  using namespace VanillaJS;

  document.addEventListener(VanillaJS::Events::DOMMutation::DOMContentLoaded, cheerp::Callback(OnDOMContentLoaded));
  return EXIT_SUCCESS;
}

// https://caniuse.com/

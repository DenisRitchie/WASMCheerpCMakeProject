#include <cheerp/client.h>
#include <cheerp/clientlib.h>

#include "includes/client2.hpp"
#include "includes/events.hpp"
#include "includes/dom.hpp"

#include <sstream>

void Test1()
{
  using namespace client;
  using namespace VanillaJS;

  document.querySelector(L"#check-box-id")
  ->addEventListener(Events::Standard::click, cheerp::Callback([index = 0](MouseEvent *event) mutable
  {
    *document.getElementById(L"output-box")->get_innerHTML() += DOMString(
      std::wostringstream()
        << L"#" << ++index
        << L" - ¡Lo siento!, <code>PreventDefault</code> ¡No te dejaré aprobar esto!<br/>"
    );
    event->preventDefault();
  }));
}

void Test2()
{
  using namespace client;
  using namespace VanillaJS;

  auto my_textbox = document.getElementById("my-textbox");

  double warning_timeout;
  auto warning_box = CreateElement<>(L"div");
  warning_box->set_className(L"warning");

  auto DisplayWarning = [&](const String &message)
  {
    warning_box->set_innerHTML(message);

    if (GetBody()->contains(warning_box))
      window.clearTimeout(warning_timeout);
    else
    {
      // Insert warning_box after my_textbox
      my_textbox->get_parentNode()->insertBefore(
        warning_box, my_textbox->get_nextSibling());
    }

    warning_timeout = window.setTimeout(cheerp::Callback([&]
    {
      warning_box->get_parentNode()->removeChild(warning_box);
      warning_timeout = -1;
    }), 2'000);
  };

  auto CheckName = cheerp::Callback([&](InputEvent *event)
  {
    if (auto data = event->get_data(); data != nullptr)
    {
      if (Long char_code = data->charCodeAt(0);
          char_code < 97 || char_code > 122)
      {
        event->preventDefault();
        DisplayWarning(DOMString(
          std::wstringstream()
            << L"Por favor, sólo use letras minúsculas.\n"
            << L"CharCode: " << static_cast<Long>(char_code)
            << std::endl
        ));
      }
    }
    else
    {
      event->preventDefault();
    }
  });

  my_textbox->addEventListener(Events::Standard::input, CheckName);
}

int main()
{
  using namespace client;
  using namespace VanillaJS;

  // https://developer.mozilla.org/en-US/docs/Web/API/Event/preventDefault

  document.addEventListener(Events::DOMMutation::DOMContentLoaded, cheerp::Callback([](MutationEvent *event)
  {
    Test1();
    Test2();
  }));

  return EXIT_SUCCESS;
}

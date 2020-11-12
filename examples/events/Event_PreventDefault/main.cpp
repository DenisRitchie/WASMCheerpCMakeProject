#include <cheerp/client.h>
#include <cheerp/clientlib.h>
#include <sstream>
#include "includes/client2.hpp"

int main()
{
  using namespace client;
  using namespace VanillaJS;

  document.querySelector(L"#check-box-id")
  ->addEventListener(L"click", cheerp::Callback([index = 0](MouseEvent *event) mutable
  {
    *document.getElementById(L"output-box")->get_innerHTML() += DOMString(
      std::wostringstream()
        << L"#" << ++index 
        << L" - ¡Lo siento!, <code>PreventDefault</code> ¡No te dejaré aprobar esto!<br/>"
    );
    event->preventDefault();
  }), false);

  return EXIT_SUCCESS;
}

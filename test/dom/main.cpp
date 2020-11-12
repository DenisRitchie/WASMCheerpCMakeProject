#include <cheerp/client.h>
#include <cheerp/clientlib.h>

/*
"C:\Program Files\CMake\bin\cmake.EXE"
--no-warn-unused-cli
-DCMAKE_INSTALL_PREFIX:STRING=c:/Projects/CheerpCMake
-DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE
-DCMAKE_BUILD_TYPE:STRING=Debug
-DCMAKE_TOOLCHAIN_FILE:FILEPATH=C:\cheerp\share\cmake\Modules\CheerpToolchain.cmake
-Hc:/Projects/CheerpCMake
-Bc:/Projects/CheerpCMake/build
-G "Unix Makefiles"
*/

/*
"C:\Program Files\CMake\bin\cmake.EXE"
--build c:/Projects/CheerpCMake/build
--config Debug
--target all 
-- -j 6
*/

/*
"C:\Program Files\CMake\bin\cmake.EXE"
--build c:/Projects/CheerpCMake/build
--config Debug
--target install 
-- -j 6
*/

template<typename HTMLElement = client::HTMLElement>
[[cheerp::genericjs]] HTMLElement* FindElementById(const client::String &element_tag_id) noexcept
{
    return static_cast<HTMLElement*>(client::document.getElementById(element_tag_id));
}

template<typename HTMLElement = client::HTMLElement>
[[cheerp::genericjs]] HTMLElement* CreateElement(const client::String &element_tag_name) noexcept
{
    return static_cast<HTMLElement*>(client::document.createElement(element_tag_name));
}

template<typename... Ts>
struct Overloader : Ts...
{
    using Ts::operator()...;
};

template <typename... T>
Overloader(T...) -> Overloader<T...>;

class [[cheerp::genericjs]] AttributeId
{
private:
    client::String *m_value;
};

class [[cheerp::genericjs]] HtmlButton
{
public:
    inline HtmlButton() noexcept : m_Button{ CreateElement<client::HTMLInputElement>("input") }
    {
        m_Button->set_type("button");
    }

    inline client::HTMLInputElement* operator->() const noexcept
    {
        return m_Button;
    }

    inline operator client::HTMLInputElement*() const noexcept
    {
        return m_Button;
    }

private:
    client::HTMLInputElement *m_Button;
};

class [[cheerp::genericjs]] HtmlTable
{
public:
    HtmlTable()
    {
    }

private:
    client::HTMLTableElement *m_table;
    // https://developer.mozilla.org/en-US/docs/Web/API/HTMLTableElement
    // https://developer.mozilla.org/en-US/docs/Web/API/HTMLTableElement/insertRow
    // https://developer.mozilla.org/en-US/docs/Web/API/HTMLTableRowElement/insertCell
    // https://developer.mozilla.org/en-US/docs/Web/API/HTMLTableElement/deleteRow
    // https://developer.mozilla.org/en-US/docs/Web/HTML/Element
    // https://developer.mozilla.org/en-US/docs/Web/HTML/Element/col
};

int main()
{
    using namespace client;

    document.get_body()->get_style()->set_background("black");

    auto root = FindElementById<>(L"root");
    auto h1   = CreateElement<>(L"h1");

    h1->set_textContent(L"Hola Mundo Denis Claro que si");
    h1->get_style()->set_color("white");

    HtmlButton button;
    button->set_value(L"Presióname");
    button->addEventListener(L"click", cheerp::Callback([](client::Event*)
    {
        alert(new String(L"Funciona"));
    }));

    root->appendChild(h1);
    root->appendChild(button);

    return 0;
}

/*
https://en.cppreference.com/w/cpp/language/derived_class
https://en.cppreference.com/w/cpp/language/using_declaration
https://en.cppreference.com/w/cpp/language/constructor
https://en.cppreference.com/w/cpp/language/lookup
https://en.cppreference.com/w/cpp/language/lambda
https://en.cppreference.com/w/cpp/language/fold
https://en.cppreference.com/w/cpp/language/sizeof...
https://en.cppreference.com/w/cpp/language/parameter_pack
https://en.cppreference.com/w/cpp/language/templates
https://en.cppreference.com/w/cpp/language/final
https://en.cppreference.com/w/cpp/language/dependent_name
https://en.cppreference.com/w/cpp/utility/variadic
*/

/*
https://brskari.wordpress.com/2013/07/31/using-c11-variadic-templates-to-create-a-type-safe-and-injection-safe-database-interface-part-2/
https://brskari.wordpress.com/2013/05/15/using-c11-variadic-templates-to-create-a-type-safe-and-injection-safe-database-interface/
https://www.fluentcpp.com/2018/07/03/how-to-reduce-the-code-bloat-of-a-variadic-crtp/
https://stackoverflow.com/questions/32054116/c11-variadic-template-inheritance
*/


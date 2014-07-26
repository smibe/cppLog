#include <string>
#include <type_traits>
#include <stdexcept>
#include <stdarg.h>

namespace StringUtils
{
	template <class T>
	typename std::enable_if<std::is_integral<T>::value, long>::type
		normalizeArg(T arg) { return arg; }

	//template <class T>
	//typename std::enable_if<std::is_integral<T>::value, int>::type
	//	normalizeArg(T arg) { return arg; }

	template <class T>
	typename std::enable_if<std::is_floating_point<T>::value, double>::type
		normalizeArg(T arg) { return arg; }

	template <class T>
	typename std::enable_if<std::is_pointer<T>::value, T>::type
		normalizeArg(T arg) { return arg; }

	const wchar_t* normalizeArg(std::wstring const& arg) { return arg.c_str(); }

	void CheckFormat(wchar_t const *f)
	{
		for (; *f; ++f)
		{
			if (*f != '%' || *++f == '%') continue;
			throw std::runtime_error("Bad format");
		}
	}

	template< class T >
	struct is_integer : std::integral_constant <
		bool,
		std::is_same<int, typename std::remove_cv<T>::type>::value ||
		std::is_same<long, typename std::remove_cv<T>::type>::value
	> {};

	template <typename T, typename... Ts>
	void CheckFormat(wchar_t const *f, const T& t, const Ts&... ts)
	{
		bool parsingPlaceholder = false;
		for (; *f; ++f)
		{

			if (!parsingPlaceholder && (*f != '%' || *++f == '%'))
			{
				continue;
			}
			 
			parsingPlaceholder = false;
			switch (*f)
			{
			case 'f': case 'g':
				if (!(std::is_floating_point<T>::value))
					throw std::runtime_error("Expected: floating point argument");
				break;
			case 'd': case 'x':
				if (!(is_integer<T>::value))
					throw std::runtime_error("Expected: integer argument");
				break;
			case 's':
				break;
			default:
				if (::iswalpha(*f))
				{
					throw std::runtime_error(std::string("Invalid format char: ") + (char)*f);
				}
				parsingPlaceholder = true;
			}
			if (!parsingPlaceholder)
			{
				return CheckFormat(++f, ts...);
			}
		}
		throw std::runtime_error("Too few format specifiers.");
	}

	size_t GetSize(const wchar_t*f, ...)
	{
		va_list args;
		va_start(args, f);
		size_t size = _vscwprintf(f, args) + 1;
		va_end(args);
		return size;
	}

	template <typename... Ts>
	std::wstring FormatString(const wchar_t * f,
		const Ts&... ts)
	{
		CheckFormat(f, normalizeArg(ts)...);
		size_t size = GetSize(f, normalizeArg(ts)...);

		std::wstring message;
		message.resize(size);

		swprintf_s(&message[0], size, f, normalizeArg(ts)...);
		message.resize(wcslen(message.c_str()));
		return message;
	}
}
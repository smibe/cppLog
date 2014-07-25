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

	int CheckFormat(wchar_t const *f)
	{
		int len = 0;
		for (; *f; ++f)
		{
			len++;
			if (*f != '%' || *++f == '%') continue;
			throw std::runtime_error("Bad format");
		}
		return len;
	}

	int MaxLen(int value)
	{
		return 10;
	}

	template< class T >
	struct is_integer : std::integral_constant<
		bool,
		std::is_same<int, typename std::remove_cv<T>::type>::value ||
		std::is_same<long, typename std::remove_cv<T>::type>::value
	> {};

	int MaxLen(const wchar_t* value)
	{
		return wcslen(value);
	}

	template <typename T, typename... Ts>
	int CheckFormat(wchar_t const *f, const T& t, const Ts&... ts)
	{
		int len = 0;
		for (; *f; ++f)
		{
			if (*f != '%' || *++f == '%')
			{
				len++;
				continue;
			}

			len += MaxLen(t);
			switch (*f)
			{
			case 'f': case 'g':
				if (!(std::is_floating_point<T>::value))
					throw std::runtime_error("Expected: floating point argument");
				break;
			case 'd': case 'x':
				if (!(is_integer<T>::value))
					throw std::runtime_error("Expected: floating point argument");
				break;
			case 's':
				break;
			default:
				throw std::runtime_error(std::string("Invalid format char: ") + (char)*f);
			}
			len += CheckFormat(++f, ts...);
			return len;
		}
		throw std::runtime_error("Too few format specifiers.");
	}

	template <typename... Ts>
	int safe_printf(wchar_t const *f, Ts&... ts)
	{
		check_printf(f, normalizeArg(ts)...);
		return printf(f, normalizeArg(ts)...);
	}

	template <typename... Ts>
	std::wstring FormatString(const wchar_t * f,
		const Ts&... ts) 
	{
		std::wstring message;
		CheckFormat(f, normalizeArg(ts)...);
		va_list args;
		va_start(args, f);
		size_t size = _vscwprintf(f, args);
		va_end(args);
		message.resize(size);
		swprintf_s(&message[0], size, f, normalizeArg(ts)...);
		message.resize(wcslen(message.c_str()));
		return message;
	}
}
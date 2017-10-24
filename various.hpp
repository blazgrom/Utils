#ifndef VARIOUS_HPP
#define VARIOUS_HPP
namespace Utils
{
	template<typename... Ts>
	struct type_container{};
	template<typename T>
	struct always_false
	{
		static constexpr bool value=false;
	};
}
#endif // !VARIOUS_HPP

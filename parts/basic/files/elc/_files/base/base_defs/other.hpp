//other.hpp
//at namespace elc::defs::base
/*
未完成的elc解释器base文件
由steve02081504与Alex0125设计、编写
转载时请在不对此文件做任何修改的同时注明出处
项目地址：https://github.com/steve02081504/ELC
*/
template<typename T>
inline T&assign(T&a,const T b)noexcept_as(declvalue(T&)=declvalue(const T)){//为绕过条件内赋值时の警告而使用
	a=b;
	return a;
}

template<typename T>
inline void discard(T&&){}//fucking nodiscard.

template<typename T>
class maybe_fail_reference{
	T*_ref_to;
public:
	constexpr maybe_fail_reference(T&a):_ref_to(&a){}
	constexpr maybe_fail_reference(note::fail_t):_ref_to(nullptr){}

	bool not_fail()noexcept{return _ref_to;}
	T&get_ref()noexcept{return*_ref_to;}
};

/*
typedef int64_t elint;
typedef double elfloat;
typedef uint64_t eluint;
static_assert(sizeof(elfloat)==sizeof(elint),"size error");
*/

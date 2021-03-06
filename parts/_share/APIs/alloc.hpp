//alloc.hpp
/*
未完成的elc解释器_share文件
由steve02081504与Alex0125设计、编写
转载时请在不对此文件做任何修改的同时注明出处
项目地址：https://github.com/steve02081504/ELC
*/
/*
APIs说明
elc依赖的基础函数.
调整这些,实现快速移植,快速优化与行为自定义.
*/
#if !defined(ELC_APIS_alloc)
	#define ELC_APIS_alloc
	#include<cstdlib>
	namespace elc::APIs::alloc{
		[[nodiscard]]inline void*realloc(void*ptr,size_t nsize)noexcept{
			//return空指针被允许，但ptr值必须保持有效以保证gc后再次realloc有效
			//new_size被保证不为0
			return::std::realloc(ptr,nsize);
		}
		[[nodiscard]]inline void*aligned_alloc(size_t align,size_t size)noexcept{
			//return空指针被允许
			//size被保证不为0
			return::std::aligned_alloc(align,size);
		}
		inline void free(void*p,size_t size)noexcept{
			//传入需释放的数据块起始点与大小（字节）
			::std::free(p);
		}
	}
#endif

//file_end


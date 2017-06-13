#pragma once
#ifndef MICRO_DEF_H_
#define MICRO_DEF_H_

#include "typedef.h"
//定义版本号 大版本 小版本 微版本
#define COM_VERSION(Classname,max,min,micro) \
	const DWORD Classname##_VERSION = （max << 24） | (min << 16） | micro
//判断是否为空指针，如果是，则返回
#define CHECK_NULL_RETURN(ptr,ErrCode)  \
	do{								\
		if (nullptr == ptr)			\
		{							\
			return ErrCode;			\
		}							\
	}while(0)
//判断是否为0，如果不是，则返回
#define CHECK_ERR_RETURN(val,ErrCode)  \
	do{								\
		if (0 != （val))				\
		{							\
			return ErrCode;			\
		}							\
	}while(0)
//判断是否相等，如果不是，则返回
#define RETURN_IF_NE(para1,para2,ret)  \
	do{								\
		if ((para1) != (para2))				\
		{							\
			return (ret);			\
		}							\
	}while(0)
//判断是否等于预期值，如果不是，则返回
#define CHECK_IF_NE(var,expect,ret)  \
	do{								\
		if ((var) != (expect))				\
		{							\
			return (ret);			\
		}							\
	}while(0)
//判断是否等于预期值，如果不是，则返回
#define IF_FALSE_RETURN(expr,value)  \
	do{								\
		if (!(expr))				\
		{							\
			return (value);			\
		}							\
	}while(0)
//判断表达式为真，则调用函数
#define IF_CALL_FUNC(expr,Func)  \
	if ((expr))				\
	{							\
		(void)(Func);			\
	}							
//调用函数，并判断执行结果
#define CALL_FAIL_RETURN_RESULT(Func,ErrCode)  \
	DWORD dwRet = (DWORD)(Func); \
	if (dwRet)				\
	{							\
		return ErrCode;			\
	}

#define UNUSED_PARA(a)  ((void)(a))
#define COUNTOF(a) (sizeof(a)/sizeof(a[0]))

//读寄存器
#define REG_READ(Type,addr) (*(volatile Type *const)(addr))
//写寄存器
#define REG_READ(Type,addr,value) (*(volatile Type *const)(addr) = (value))
//删除单个对象
#define DELETE_OBJ(obj)			\
	do{								\
		if (nullptr != obj)			\
		{							\
			delete obj;				\
			obj = nullptr;			\
		}							\
	}while(0)
//删除数组对象
#define DELETE_ARRAY_OBJ(obj)	\
	do{								\
		if (nullptr != obj)			\
		{							\
			delete [] obj;			\
			obj = nullptr;			\
		}							\
	}while(0)

//单件例化
#define SINGLE_CLASS_DEFINE(className) \
	public: \
		static className* Instance(); \
	private: \
		static className* m_Instance; \
		className(); \
		className(const className &); \
		className & operator = (const className &); \

#define SINGLE_CLASS_INSTANCE(className) \
	className* className::m_Instance = nullptr; \
	className* className::Instance() \
	{
		if (nullptr == m_Instance) \
		{
			m_Instance = new className; \
		}	\
		return m_Instance; \
	}

#endif // MICRO_DEF_H_
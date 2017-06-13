#pragma once
#ifndef MICRO_DEF_H_
#define MICRO_DEF_H_

#include "typedef.h"
//����汾�� ��汾 С�汾 ΢�汾
#define COM_VERSION(Classname,max,min,micro) \
	const DWORD Classname##_VERSION = ��max << 24�� | (min << 16�� | micro
//�ж��Ƿ�Ϊ��ָ�룬����ǣ��򷵻�
#define CHECK_NULL_RETURN(ptr,ErrCode)  \
	do{								\
		if (nullptr == ptr)			\
		{							\
			return ErrCode;			\
		}							\
	}while(0)
//�ж��Ƿ�Ϊ0��������ǣ��򷵻�
#define CHECK_ERR_RETURN(val,ErrCode)  \
	do{								\
		if (0 != ��val))				\
		{							\
			return ErrCode;			\
		}							\
	}while(0)
//�ж��Ƿ���ȣ�������ǣ��򷵻�
#define RETURN_IF_NE(para1,para2,ret)  \
	do{								\
		if ((para1) != (para2))				\
		{							\
			return (ret);			\
		}							\
	}while(0)
//�ж��Ƿ����Ԥ��ֵ��������ǣ��򷵻�
#define CHECK_IF_NE(var,expect,ret)  \
	do{								\
		if ((var) != (expect))				\
		{							\
			return (ret);			\
		}							\
	}while(0)
//�ж��Ƿ����Ԥ��ֵ��������ǣ��򷵻�
#define IF_FALSE_RETURN(expr,value)  \
	do{								\
		if (!(expr))				\
		{							\
			return (value);			\
		}							\
	}while(0)
//�жϱ��ʽΪ�棬����ú���
#define IF_CALL_FUNC(expr,Func)  \
	if ((expr))				\
	{							\
		(void)(Func);			\
	}							
//���ú��������ж�ִ�н��
#define CALL_FAIL_RETURN_RESULT(Func,ErrCode)  \
	DWORD dwRet = (DWORD)(Func); \
	if (dwRet)				\
	{							\
		return ErrCode;			\
	}

#define UNUSED_PARA(a)  ((void)(a))
#define COUNTOF(a) (sizeof(a)/sizeof(a[0]))

//���Ĵ���
#define REG_READ(Type,addr) (*(volatile Type *const)(addr))
//д�Ĵ���
#define REG_READ(Type,addr,value) (*(volatile Type *const)(addr) = (value))
//ɾ����������
#define DELETE_OBJ(obj)			\
	do{								\
		if (nullptr != obj)			\
		{							\
			delete obj;				\
			obj = nullptr;			\
		}							\
	}while(0)
//ɾ���������
#define DELETE_ARRAY_OBJ(obj)	\
	do{								\
		if (nullptr != obj)			\
		{							\
			delete [] obj;			\
			obj = nullptr;			\
		}							\
	}while(0)

//��������
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
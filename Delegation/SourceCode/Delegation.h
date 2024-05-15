#pragma once
void FreeFunction(int)
{
	// do something
}

class AbstractBase
{
public:
	virtual void CallFunction(int ARG0) = 0;
};
template <class C>
class MemberFunctionWrapper : public AbstractBase
{
	typedef void (C::* MemberFunction)(int);
public:
	MemberFunctionWrapper(MemberFunction memberFunction) {
		m_memberFunction = memberFunction;
	}
	virtual void CallFunction(int ARG0)
	{
		(m_instance->*m_memberFunction)(ARG0);
	}
private:
	C* m_instance;
	MemberFunction m_memberFunction;
};

void WrapFreeFunction(void* instance, void (*freeFunction)(int), int ARG0)
{
	// instance is unused
	(freeFunction)(ARG0);
}
template <class C>
void WrapMemberFunction(C * instance, void (C:: * memberFunction)(int), int ARG0)
{
	(instance->*memberFunction)(ARG0);
}

class Class
{
public:
	typedef void (Class::*Some)(int);
	//void Some() {};
	void MemberFunction(int) {};   // type: void (Class::*)(int)
};

class Delegation
{
	typedef void (*FreeFunction)(int);
public:
	void Bind(FreeFunction function) {
		m_function = function;
	}
	void Invoke(int ARG0) {
		(m_function)(ARG0);
	}
private:
	FreeFunction m_function;
};


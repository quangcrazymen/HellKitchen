#pragma once
#include <utility>
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

class Delegate
{
	typedef void* InstancePtr;
	typedef void (*InternalFunction)(InstancePtr, int);
		typedef std::pair<InstancePtr, InternalFunction> Stub;

		
	// turns a free function into our internal function stub
	template <void (*Function)(int)>
	static inline void FunctionStub(InstancePtr, int ARG0)
	{
		// we don't need the instance pointer because we're dealing with free functions
		return (Function)(ARG0);
	}

	// turns a member function into our internal function stub
	template <class C, void (C::* Function)(int)>
	static inline void ClassMethodStub(InstancePtr instance, int ARG0)
	{
		// cast the instance pointer back into the original class instance
		return (static_cast<C*>(instance)->*Function)(ARG0);
	}

public:
	Delegate(void)
		: m_stub(nullptr, nullptr)
	{
	}

	/// Binds a free function
	template <void (*Function)(int)>
	void Bind(void)
	{
		m_stub.first = nullptr;
		m_stub.second = &FunctionStub<Function>;
	}

	/// Binds a class method
	template <class C, void (C::* Function)(int)>
	void Bind(C* instance)
	{
		m_stub.first = instance;
		m_stub.second = &ClassMethodStub<C, Function>;
	}

	/// Invokes the delegate
	void Invoke(int ARG0) const
	{
		//ME_ASSERT(m_stub.second != nullptr, "Cannot invoke unbound delegate. Call Bind() first.")();
		return m_stub.second(m_stub.first, ARG0);
	}

private:
	Stub m_stub;
};
